#include "characterticker.h"
#include "inputregistry.h"

CharacterTicker::CharacterTicker(Node* root,PhysicEngine* physics_engine):IdleObserver(){
	m_Timer.restart();
	a = new QTimer();

	this->physics_engine=physics_engine;

	//shader_normal = ShaderManager::getShader(":/shaders/basic.vert", ":/shaders/basic.frag");
	shader_normal = ShaderManager::getShader(":/shaders/my_phong.vert", ":/shaders/my_phong.frag");
	shader_transparent = ShaderManager::getShader(":/shaders/basic.vert", ":/shaders/transparent.frag");

	Color* c;
	Geometry* g;
	ModelTransformation* modelTransform;
	Material* m;

	models=new Drawable*[5];

    g=new TriangleMesh(":/models/spieler_meshes/wuerfel.obj");
	models[0]=new Drawable(g);
    g=new TriangleMesh(":/models/spieler_meshes/pyramide.obj");
	models[1]=new Drawable(g);
    g=new TriangleMesh(":/models/spieler_meshes/mondsichel.obj");
	models[2]=new Drawable(g);
    g=new TriangleMesh(":/models/spieler_meshes/stern.obj");
	models[3]=new Drawable(g);
    g=new TriangleMesh(":/models/spieler_meshes/herz.obj");
	models[4]=new Drawable(g);

	for(int i=0;i<5;i++){
		//c = models[i]->getProperty<Color>();
		//c->setValue(colors[i][0],colors[i][1],colors[i][2],colors[i][3]);
    	m = models[i]->getProperty<Material>();
	    m->setDiffuse(colors[i][0],colors[i][1],colors[i][2],colors[i][3]);
	    m->setAmbient(colors[i][0],colors[i][1],colors[i][2],colors[i][3]);
	    m->setSpecular(colors[i][0],colors[i][1],colors[i][2],colors[i][3]);
	    m->setShininess(8.);
		models[i]->setTransparent(false);
		models[i]->setShader(shader_normal);
		//models[i]->setTransparent(true);
		//models[i]->setShader(shader_transparent);
		modelTransform = models[i]->getProperty<ModelTransformation>();
		modelTransform->translate(0.f,1.0f,0.0f);
		root->addChild(new Node(models[i]));
	}

	player_model=new Drawable(new SimpleCube(1.0,1.0,1.0));
	modelTransform=player_model->getProperty<ModelTransformation>();
    modelTransform->translate(0.f, 0.6f, 0.f);
	player_model->setTransparent(true);
	player_model->setShader(shader_transparent);
	root->addChild(new Node(player_model));
	c=player_model->getProperty<Color>();
	c->setValue(1.0,1.0,0.0,1.0);
	character = physics_engine->createNewDynamicCharacterWithCam(player_model);
	character->setCam(dynamic_cast<PhysicAccessableCamera*>(SceneManager::instance()->getActiveContext()->getCamera()));
    character->setRelativeCamPosition(0.f, 7.f, 5.f);
    character->setUpDownView(-50.0f);
	player_model->getPhysicObject()->registerPhysicObject();

	change_visibility(0);
}


void CharacterTicker::doIt(){
	long long time = m_Timer.restart();
	// Flags sammeln in welche richtungen der Character gehen soll
	unsigned long long v_MoveFlagsDynCh = 0;
	KeyboardInput* keyIn = InputRegistry::getInstance().getKeyboardInput();

	// Für Charakter mit verfolgerkamera
	v_MoveFlagsDynCh = 0;
	// wasd space zur steuerung, in dem Enum Movement flag stehen noch weitere bewegungen die der character machen kann
	if (keyIn->isKeyPressed('w')){
		v_MoveFlagsDynCh |= MovementFlag::Forward;
	}
	if (keyIn->isKeyPressed('a')){
		v_MoveFlagsDynCh |= MovementFlag::TurnLeft;
	}
	if (keyIn->isKeyPressed('s')){
		v_MoveFlagsDynCh |= MovementFlag::Backward;
	}
	if (keyIn->isKeyPressed('d')){
		v_MoveFlagsDynCh |= MovementFlag::TurnRight;
	}

	if(keyIn->isKeyPressed('1')){
		aktuelle_form=0;
	}
	if(keyIn->isKeyPressed('2')){
		aktuelle_form=1;
	}
	if(keyIn->isKeyPressed('3')){
		aktuelle_form=2;
	}
	if(keyIn->isKeyPressed('4')){
		aktuelle_form=3;
	}
	if(keyIn->isKeyPressed('5')){
		aktuelle_form=4;
	}

    if(keyIn->isKeyPressed('8')){
        //--> Kamerawinkel soll 10° ins Minus gehen (nach oben zur Vogelperspektive), aber 2 Probleme!!!
        //--> 1.) Werte abfragen ___ 2.) Kamera-Abstand (Radius)
    }
    if(keyIn->isKeyPressed('5')){
        //--> Selbiges Problem!!!
    }

	character->moveCharacter(time, v_MoveFlagsDynCh);
	change_visibility(aktuelle_form);

	//alle tore updaten
	Torliste* aktuelles_tor=tore;
	while(aktuelles_tor!=nullptr){
		aktuelles_tor->tor->update(aktuelle_form);
		aktuelles_tor=aktuelles_tor->next;
	}

	QVector3D position=character->getPosition3DVector();

	//alle trigger updaten
	FormTriggerliste* aktueller_trigger=trigger;
	while(aktueller_trigger!=nullptr){
		int form=aktueller_trigger->trigger->update(position);
		if(form!=-1){	//falls brauchbare form zurückgegeben->form annehmen
			aktuelle_form=form;
		}
		aktueller_trigger=aktueller_trigger->next;
	}

	//alle Sternteiltrigger updaten
	SternteilTriggerListe* aktuelles_sternteil = sternteil;
	while (aktuelles_sternteil != nullptr && sternteilRaetselGeloest == false) {
		gesammelteSternteile += aktuelles_sternteil->sternteil->update(position);
		aktuelles_sternteil = aktuelles_sternteil->next;
		if (gesammelteSternteile == 5) {
			bool sternteilRaetselGeloest = true;
			//TODO: Stern-Pickup transformieren hier
		}
	}

	//alle Farbtrigger updaten
	if (farbRaetselGeloest == false) {
		bool alleFarbenPassen = true;
		int sollFarbe = 0;
		FarbTriggerListe* aktuelle_farbe = farbe;
		while (aktuelle_farbe != nullptr) {
			int istFarbe = aktuelle_farbe->farbe->update(position);
			if (istFarbe != sollFarbe) {
				alleFarbenPassen = false;
			}
			sollFarbe++;
			aktuelle_farbe = aktuelle_farbe->next;
		}
		if (alleFarbenPassen == true) {
			aktuelle_farbe = farbe;
			while (aktuelle_farbe != nullptr) {
				aktuelle_farbe->farbe->solved();
				aktuelle_farbe = aktuelle_farbe->next;
			}
			farbRaetselGeloest = true;
			//TODO: Mondsichel-Pickup 1 transformieren hier
		}
	}

	//alle Schlusstrigger updaten
	SchlussTriggerListe* aktuell_schluss = schluss;
	while (aktuell_schluss != nullptr && schlussRaetselGeloest == false) {
		gesammelteBoxen += aktuell_schluss->schluss->update(position);
		aktuell_schluss = aktuell_schluss->next;
		if (gesammelteBoxen == 3) {
			bool schlussRaetselGeloest = true;
			//TODO: Stern-Pickup transformieren hier
		}
	}
}

void CharacterTicker::change_visibility(int idx){
	for(int i=0;i<5;i++){
		if(i==idx){
			models[i]->setTransparent(false);
			models[i]->setShader(shader_normal);
			ModelTransformation* modelTransform;
			modelTransform = models[i]->getProperty<ModelTransformation>();
			modelTransform->resetTrafo();
			QVector3D position=character->getPosition3DVector();
			modelTransform->translate(position.x(),position.y()-0.5f,position.z());
			modelTransform->rotate(character->getYRotationDegrees(),0.0f,1.0f,0.0f);
		}else{
			models[i]->setTransparent(true);
			models[i]->setShader(shader_transparent);
		}
	}
}

void CharacterTicker::register_tor(Tor* tor){
	Torliste* lokale_torliste=new Torliste{tor,tore};
	tore=lokale_torliste;
}

void CharacterTicker::register_trigger(FormTrigger* l_trigger) {
	FormTriggerliste* lokale_triggerliste = new FormTriggerliste{ l_trigger,trigger };
	trigger = lokale_triggerliste;
}

void CharacterTicker::register_sternteil(SternTrigger* l_sternteil)
{
	SternteilTriggerListe* lokale_sternteiltriggerliste = new SternteilTriggerListe{ l_sternteil, sternteil };
	sternteil = lokale_sternteiltriggerliste;
}

void CharacterTicker::register_farbe(FarbTrigger* l_farbe)
{
	FarbTriggerListe* lokale_farbtriggerliste = new FarbTriggerListe{ l_farbe, farbe };
	farbe = lokale_farbtriggerliste;
}

void CharacterTicker::register_schluss(SternTrigger* l_schluss)
{
	SchlussTriggerListe* lokale_schlusstriggerliste = new SchlussTriggerListe{ l_schluss, schluss };
	schluss = lokale_schlusstriggerliste;
}
