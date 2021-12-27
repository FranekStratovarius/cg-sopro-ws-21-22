#include "characterticker.h"
#include "inputregistry.h"

CharacterTicker::CharacterTicker(Node* root,PhysicEngine* physics_engine):IdleObserver(){
	m_Timer.restart();
	a = new QTimer();

	this->physics_engine=physics_engine;

	shader_normal = ShaderManager::getShader(":/shaders/basic.vert", ":/shaders/basic.frag");
	shader_transparent = ShaderManager::getShader(":/shaders/basic.vert", ":/shaders/transparent.frag");

	Color* c;
	Geometry* g;
	ModelTransformation* modelTransform;

	models=new Drawable*[5];

	g=new TriangleMesh(":/models/wuerfel.obj");
	models[0]=new Drawable(g);
	g=new TriangleMesh(":/models/pyramide.obj");
	models[1]=new Drawable(g);
	g=new TriangleMesh(":/models/mondsichel.obj");
	models[2]=new Drawable(g);
	g=new TriangleMesh(":/models/stern.obj");
	models[3]=new Drawable(g);
	g=new TriangleMesh(":/models/herz.obj");
	models[4]=new Drawable(g);

	for(int i=0;i<5;i++){
		c = models[i]->getProperty<Color>();
		c->setValue(colors[i][0],colors[i][1],colors[i][2],colors[i][3]);
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
	modelTransform->translate(0.f, 1.f, 0.f);
	player_model->setTransparent(true);
	player_model->setShader(shader_transparent);
	root->addChild(new Node(player_model));
	c=player_model->getProperty<Color>();
	c->setValue(1.0,1.0,0.0,1.0);
	character = physics_engine->createNewDynamicCharacterWithCam(player_model);
	character->setCam(dynamic_cast<PhysicAccessableCamera*>(SceneManager::instance()->getActiveContext()->getCamera()));
	character->setRelativeCamPosition(0.f, 4.f, 5.f);
	character->setUpDownView(-30.0F);
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
		current_character=0;
	}
	if(keyIn->isKeyPressed('2')){
		current_character=1;
	}
	if(keyIn->isKeyPressed('3')){
		current_character=2;
	}
	if(keyIn->isKeyPressed('4')){
		current_character=3;
	}
	if(keyIn->isKeyPressed('5')){
		current_character=4;
	}

	character->moveCharacter(time, v_MoveFlagsDynCh);
	change_visibility(current_character);
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
