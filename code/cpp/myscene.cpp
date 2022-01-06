#include "scenemanager.h"
#include "screenrenderer.h"
#include "mousekeyboardcameracontroller.h"
#include "simpleplane.h"
#include "shadertimed.h"
#include "transformation.h"
#include "shadermanager.h"
#include "keyboardtransformation.h"
#include "modeltransformation.h"
#include "simplecube.h"
#include "color.h"
#include "sunlight.h"

#include "headers/characterticker.h"
#include "headers/form_trigger.h"
#include "headers/stern_trigger.h"
#include "headers/farb_trigger.h"
#include "headers/tor.h"

void setColor(Drawable* model,double r,double g,double b,double a,double shiny){
	Material* m;
    m = model->getProperty<Material>();
	m->setDiffuse(r,g,b,a);
	m->setAmbient(r,g,b,a);
	m->setSpecular(r,g,b,a);
	m->setShininess(8.);
	model->setTransparent(false);
	model->setShader(ShaderManager::getShader(":/shaders/my_phong.vert", ":/shaders/my_phong.frag"));
}

Node* initScene1();

void SceneManager::initScenes()
{
	PhysicAccessableCamera* cam = new PhysicAccessableCamera;
	RenderingContext* myContext = new RenderingContext(cam);
	unsigned int myContextNr = SceneManager::instance()->addContext(myContext);
	unsigned int myScene = SceneManager::instance()->addScene(initScene1());
	ScreenRenderer* myRenderer = new ScreenRenderer(myContextNr, myScene);
	Q_UNUSED(myRenderer);

	// Vorsicht: Die Szene muss initialisiert sein, bevor das Fenster verändert wird (Fullscreen)
	SceneManager::instance()->setActiveScene(myScene);
	SceneManager::instance()->setActiveContext(myContextNr);
	SceneManager::instance()->setFullScreen();
}

Node* initScene1()
{
	Node* root = new Node();

	// Physic Engine Erzeugen und einen Pointer auf Instanz holen
	int v_Slot = PhysicEngineManager::createNewPhysicEngineSlot(PhysicEngineName::BulletPhysicsLibrary);
	PhysicEngine* v_PhysicEngine = PhysicEngineManager::getPhysicEngineBySlot(v_Slot);

	CharacterTicker* spieler = new CharacterTicker(root,v_PhysicEngine);

//-------------------------------------------------------------------------------------------------------------------------------------------------------

	Color* c;

    //BODEN
    Drawable* boden = new Drawable(new TriangleMesh(":/models/level_static/Boden.obj"));
    Node* bodenNode = new Node(boden);
    boden->setStaticGeometry(true);
    PhysicObject* bodenObject = v_PhysicEngine->createNewPhysicObject(boden);
    PhysicObjectConstructionInfo* bodenInfo = new PhysicObjectConstructionInfo();
    bodenInfo->setCollisionHull(CollisionHull::BoxAABB);
    bodenObject->setConstructionInfo(bodenInfo);
    bodenObject->registerPhysicObject();
	setColor(boden,0.5,0.0,0.3,1.0,0.8);
    //c = boden->getProperty<Color>();
    //c->setValue(0.5, 0.0, 0.3, 1.0);

    //WAENDE
    Drawable* waende = new Drawable(new TriangleMesh(":/models/level_static/Grundwaende.obj"));
    Node* waendeNode = new Node(waende);
    waende->setStaticGeometry(true);
    PhysicObject* waendeObject = v_PhysicEngine->createNewPhysicObject(waende);
    PhysicObjectConstructionInfo* waendeInfo = new PhysicObjectConstructionInfo();
    waendeInfo->setCollisionHull(CollisionHull::BVHTriangleMesh);
    waendeObject->setConstructionInfo(waendeInfo);
    waendeObject->registerPhysicObject();
	setColor(waende,0.3,0.5,0.7,1.0,0.8);
    //c = waende->getProperty<Color>();
    //c->setValue(0.3, 0.5, 0.7, 1.0);

    //TORHINWEISE
    Drawable* hinweisWuerfel = new Drawable(new TriangleMesh(":/models/level_static/TorHinweisWuerfel.obj"));
    Node* hWNode = new Node(hinweisWuerfel);
    c = hinweisWuerfel->getProperty<Color>();
    c->setValue(0.0, 1.0, 0.0, 1.0);

    Drawable* hinweisPyramide = new Drawable(new TriangleMesh(":/models/level_static/TorHinweisPyramide.obj"));
    Node* hPNode = new Node(hinweisPyramide);
    c = hinweisPyramide->getProperty<Color>();
    c->setValue(0.0, 0.0, 1.0, 1.0);

    Drawable* hinweisMondsichel = new Drawable(new TriangleMesh(":/models/level_static/TorHinweisMond.obj"));
    Node* hMNode = new Node(hinweisMondsichel);
    c = hinweisMondsichel->getProperty<Color>();
    c->setValue(0.7, 0.7, 0.7, 1.0);

    Drawable* hinweisStern = new Drawable(new TriangleMesh(":/models/level_static/TorHinweisStern.obj"));
    Node* hSNode = new Node(hinweisStern);
    c = hinweisStern->getProperty<Color>();
    c->setValue(1.0, 1.0, 0.0, 1.0);

//-------------------------------------------------------------------------------------------------------------------------------------------------------

    //RAETSEL II
        //Statisch, farblich änderbar
    Drawable* r2_farbe1 = new Drawable(new TriangleMesh(":/models/R2/R2_Farbobjekt1.obj"));
    Node* r2fo1Node = new Node(r2_farbe1);
    c = r2_farbe1->getProperty<Color>();
    c->setValue(1.0, 0.0, 0.0, 1.0);

    Drawable* r2_farbe2 = new Drawable(new TriangleMesh(":/models/R2/R2_Farbobjekt2.obj"));
    Node* r2fo2Node = new Node(r2_farbe2);
    c = r2_farbe2->getProperty<Color>();
    c->setValue(0.0, 1.0, 0.0, 1.0);

    Drawable* r2_farbe3 = new Drawable(new TriangleMesh(":/models/R2/R2_Farbobjekt3.obj"));
    Node* r2fo3Node = new Node(r2_farbe3);
    c = r2_farbe3->getProperty<Color>();
    c->setValue(0.0, 0.0, 1.0, 1.0);

        //Statisch
    Drawable* r2_static1 = new Drawable(new TriangleMesh(":/models/R2/R2_Vorgabe1_Rot.obj"));
    Node* r2s1 = new Node(r2_static1);
    c = r2_static1->getProperty<Color>();
    c->setValue(1.0, 0.0, 0.0, 1.0);

    Drawable* r2_static2 = new Drawable(new TriangleMesh(":/models/R2/R2_Vorgabe2_Gruen.obj"));
    Node* r2s2 = new Node(r2_static2);
    c = r2_static2->getProperty<Color>();
    c->setValue(0.0, 1.0, 0.0, 1.0);

    Drawable* r2_static3 = new Drawable(new TriangleMesh(":/models/R2/R2_Vorgabe3_Blau.obj"));
    Node* r2s3 = new Node(r2_static3);
    c = r2_static3->getProperty<Color>();
    c->setValue(0.0, 0.0, 1.0, 1.0);

        //Trigger
    Drawable* triggerBox = new Drawable(new TriangleMesh(":/models/R2/TriggerBox.obj"));
    c = triggerBox->getProperty<Color>();
    c->setValue(1.0, 1.0, 1.0, 1.0);
    Node* r2t1 = new Node(triggerBox);
    Transformation* r2t1Trans = new Transformation();
    r2t1Trans->translate(-67.2, 0.7, -35);
    Node* r2t1TransNode = new Node(r2t1Trans);

    Node* r2t2 = new Node(triggerBox);
    Transformation* r2t2Trans = new Transformation();
    r2t2Trans->translate(-63.5, 0.7, -46.5);
    Node* r2t2TransNode = new Node(r2t2Trans);

    Node* r2t3 = new Node(triggerBox);
    Transformation* r2t3Trans = new Transformation();
    r2t3Trans->translate(-77.8, 0.7, -34.5);
    Node* r2t3TransNode = new Node(r2t3Trans);

//-------------------------------------------------------------------------------------------------------------------------------------------------------

    //RAETSEL III
    Drawable* sternteil = new Drawable(new TriangleMesh(":/models/R3/Sternenteil.obj"));
    c = sternteil->getProperty<Color>();
    c->setValue(1.0, 1.0, 0.0, 1.0);
    Node* r3t1 = new Node(sternteil);
    Transformation* r3t1Trans = new Transformation();
    r3t1Trans->translate(-37, 0.7, -44);
    Node* r3t1TransNode = new Node(r3t1Trans);

    Node* r3t2 = new Node(sternteil);
    Transformation* r3t2Trans = new Transformation();
    r3t2Trans->translate(-26.5, 0.7, -88);
    Node* r3t2TransNode = new Node(r3t2Trans);

    Node* r3t3 = new Node(sternteil);
    Transformation* r3t3Trans = new Transformation();
    r3t3Trans->translate(6, 0.7, -61);
    Node* r3t3TransNode = new Node(r3t3Trans);

    Node* r3t4 = new Node(sternteil);
    Transformation* r3t4Trans = new Transformation();
    r3t4Trans->translate(55.5, 0.7, -79.5);
    Node* r3t4TransNode = new Node(r3t4Trans);

    Node* r3t5 = new Node(sternteil);
    Transformation* r3t5Trans = new Transformation();
    r3t5Trans->translate(71.9, 0.7, -29.4);
    Node* r3t5TransNode = new Node(r3t5Trans);

//-------------------------------------------------------------------------------------------------------------------------------------------------------

    //RAETSEL IV
    Node* r4t1 = new Node(triggerBox);
    Transformation* r4t1Trans = new Transformation();
    r4t1Trans->translate(29.1, 0.7, 27.3);
    Node* r4t1TransNode = new Node(r4t1Trans);

    Node* r4t2 = new Node(triggerBox);
    Transformation* r4t2Trans = new Transformation();
    r4t2Trans->translate(49.5, 0.7, 44);
    Node* r4t2TransNode = new Node(r4t2Trans);

    Node* r4t3 = new Node(triggerBox);
    Transformation* r4t3Trans = new Transformation();
    r4t3Trans->translate(61.8, 0.7, 42);
    Node* r4t3TransNode = new Node(r4t3Trans);


//-------------------------------------------------------------------------------------------------------------------------------------------------------

    //FORMTRIGGER
        //Wuerfel
    Drawable* wuerfelTriggerBox = new Drawable(new TriangleMesh(":/models/form_trigger/Wuerfelform_Trigger.obj"));
    c = wuerfelTriggerBox->getProperty<Color>();
    c->setValue(1.0, 1.0, 1.0, 1.0);
    Node* wuerfelTrigger = new Node(wuerfelTriggerBox);
    Transformation* wuerfelTriggerTrans = new Transformation();
    wuerfelTriggerTrans->translate(68.9, 0.7, 27);
    Node* wuerfelTriggerNode = new Node(wuerfelTriggerTrans);

        //Pyramide
    Drawable* pyramideTriggerBox = new Drawable(new TriangleMesh(":/models/form_trigger/Pyramideform_Trigger.obj"));
    c = pyramideTriggerBox->getProperty<Color>();
    c->setValue(1.0, 1.0, 1.0, 1.0);
    Node* pyramideTrigger1 = new Node(pyramideTriggerBox);
    Transformation* pyramideTrigger1Trans = new Transformation();
    pyramideTrigger1Trans->translate(-58, 0.7, -1.3);
    Node* pyramideTrigger1Node = new Node(pyramideTrigger1Trans);

    Node* pyramideTrigger2 = new Node(pyramideTriggerBox);
    Transformation* pyramideTrigger2Trans = new Transformation();
    pyramideTrigger2Trans->translate(10.5, 0.7, 44);
    Node* pyramideTrigger2Node = new Node(pyramideTrigger2Trans);

        //Mondsichel
    Drawable* mondTriggerBox = new Drawable(new TriangleMesh(":/models/form_trigger/Mondsichelform_Trigger.obj"));
    c = mondTriggerBox->getProperty<Color>();
    c->setValue(1.0, 1.0, 1.0, 1.0);
    Node* mondTrigger1 = new Node(mondTriggerBox);
    Transformation* mondTrigger1Trans = new Transformation();
    mondTrigger1Trans->translate(-73, -10.7, -57);
    Node* mondTrigger1Node = new Node(mondTrigger1Trans);

    Node* mondTrigger2 = new Node(mondTriggerBox);
    Transformation* mondTrigger2Trans = new Transformation();
    mondTrigger2Trans->translate(27.8, 0.7, 42.7);
    Node* mondTrigger2Node = new Node(mondTrigger2Trans);

        //Stern
    Drawable* sternTriggerBox = new Drawable(new TriangleMesh(":/models/form_trigger/Sternform_Trigger.obj"));
    c = sternTriggerBox->getProperty<Color>();
    c->setValue(1.0, 1.0, 1.0, 1.0);
    Node* sternTrigger1 = new Node(sternTriggerBox);
    Transformation* sternTrigger1Trans = new Transformation();
    sternTrigger1Trans->translate(72, -10.7, -21);
    Node* sternTrigger1Node = new Node(sternTrigger1Trans);

    Node* sternTrigger2 = new Node(sternTriggerBox);
    Transformation* sternTrigger2Trans = new Transformation();
    sternTrigger2Trans->translate(38, 0.7, 27);
    Node* sternTrigger2Node = new Node(sternTrigger2Trans);

        //Herz
    Drawable* herzTriggerBox = new Drawable(new TriangleMesh(":/models/form_trigger/Herzform_Trigger.obj"));
    c = herzTriggerBox->getProperty<Color>();
    c->setValue(1.0, 1.0, 1.0, 1.0);
    Node* herzTrigger = new Node(herzTriggerBox);
    Transformation* herzTriggerTrans = new Transformation();
    herzTriggerTrans->translate(-18.5, 0.7, 59.5);
    Node* herzTriggerNode = new Node(herzTriggerTrans);

//-------------------------------------------------------------------------------------------------------------------------------------------------------

    //BLOCKADEN

    Drawable* wuerfelBlockade = new Drawable(new TriangleMesh(":/models/blockaden/Blockade_Wuerfel.obj"));
    Node* wuerfelBlockadeNode = new Node(wuerfelBlockade);
    c = wuerfelBlockade->getProperty<Color>();
    c->setValue(0.1, 0.1, 0.1, 1.0);
    wuerfelBlockade->setStaticGeometry(true);
    PhysicObject* wuerfelBlockadeObject = v_PhysicEngine->createNewPhysicObject(wuerfelBlockade);
    PhysicObjectConstructionInfo* wuerfelInfo = new PhysicObjectConstructionInfo();
    wuerfelInfo->setCollisionHull(CollisionHull::BVHTriangleMesh);
    wuerfelBlockadeObject->setConstructionInfo(wuerfelInfo);
    wuerfelBlockadeObject->registerPhysicObject();
    Transformation* wuerfelBlockadeTrans= new Transformation();
    Node* wuerfelBlockadeTransNode = new Node(wuerfelBlockadeTrans);

    Drawable* pyramideBlockade = new Drawable(new TriangleMesh(":/models/blockaden/Blockade_Pyramide.obj"));
    Node* pyramideBlockadeNode = new Node(pyramideBlockade);
    c = pyramideBlockade->getProperty<Color>();
    c->setValue(0.1, 0.1, 0.1, 1.0);
    pyramideBlockade->setStaticGeometry(true);
    PhysicObject* pyramideBlockadeObject = v_PhysicEngine->createNewPhysicObject(pyramideBlockade);
    PhysicObjectConstructionInfo* pyramideInfo = new PhysicObjectConstructionInfo();
    pyramideInfo->setCollisionHull(CollisionHull::BVHTriangleMesh);
    pyramideBlockadeObject->setConstructionInfo(pyramideInfo);
    pyramideBlockadeObject->registerPhysicObject();
    Transformation* pyramideBlockadeTrans = new Transformation();
    Node* pyramideBlockadeTransNode = new Node(pyramideBlockadeTrans);

    Drawable* mondBlockade = new Drawable(new TriangleMesh(":/models/blockaden/Blockade_Mondsichel.obj"));
    Node* mondBlockadeNode = new Node(mondBlockade);
    c = mondBlockade->getProperty<Color>();
    c->setValue(0.1, 0.1, 0.1, 1.0);
    mondBlockade->setStaticGeometry(true);
    PhysicObject* mondBlockadeObject = v_PhysicEngine->createNewPhysicObject(mondBlockade);
    PhysicObjectConstructionInfo* mondInfo = new PhysicObjectConstructionInfo();
    mondInfo->setCollisionHull(CollisionHull::BVHTriangleMesh);
    mondBlockadeObject->setConstructionInfo(mondInfo);
    mondBlockadeObject->registerPhysicObject();
    Transformation* mondBlockadeTrans = new Transformation();
    Node* mondBlockadeTransNode = new Node(mondBlockadeTrans);

    Drawable* sternBlockade = new Drawable(new TriangleMesh(":/models/blockaden/Blockade_Stern.obj"));
    Node* sternBlockadeNode = new Node(sternBlockade);
    c = sternBlockade->getProperty<Color>();
    c->setValue(0.1, 0.1, 0.1, 1.0);
    sternBlockade->setStaticGeometry(true);
    PhysicObject* sternBlockadeObject = v_PhysicEngine->createNewPhysicObject(sternBlockade);
    PhysicObjectConstructionInfo* sternInfo = new PhysicObjectConstructionInfo();
    sternInfo->setCollisionHull(CollisionHull::BVHTriangleMesh);
    sternBlockadeObject->setConstructionInfo(sternInfo);
    sternBlockadeObject->registerPhysicObject();
    Transformation* sternBlockadeTrans = new Transformation();
    Node* sternBlockadeTransNode = new Node(sternBlockadeTrans);

    Drawable* endeBlockade = new Drawable(new TriangleMesh(":/models/blockaden/Blockade_Ende.obj"));
    Node* endeBlockadeNode = new Node(endeBlockade);
    c = endeBlockade->getProperty<Color>();
    c->setValue(0.1, 0.1, 0.1, 1.0);
    endeBlockade->setStaticGeometry(true);
    PhysicObject* endeBlockadeObject = v_PhysicEngine->createNewPhysicObject(endeBlockade);
    PhysicObjectConstructionInfo* endeInfo = new PhysicObjectConstructionInfo();
    endeInfo->setCollisionHull(CollisionHull::BVHTriangleMesh);
    endeBlockadeObject->setConstructionInfo(endeInfo);
    endeBlockadeObject->registerPhysicObject();
    Transformation* endeBlockadeTrans = new Transformation();
    Node* endeBlockadeTransNode = new Node(endeBlockadeTrans);

//------------------------------------------------------------------------------------------------------------------------------------------------------ -
   //FORM-TRIGGER Positionen zuweisen und registrieren beim Charakter + TOR-Trigger
   float bb = 1.0f; //Halbe Seitenlänge des Bounding-Box-Würfel
   FormTrigger* TriggerObj1 = new FormTrigger(QVector3D(68.9, 0.7, 27), 0, bb);
   FormTrigger* TriggerObj2 = new FormTrigger(QVector3D(-58, 0.7, -1.3), 1, bb);
   FormTrigger* TriggerObj3 = new FormTrigger(QVector3D(10.5, 0.7, 44), 1, bb);
   FormTrigger* TriggerObj4 = new FormTrigger(QVector3D(-73, -10.7, -57), 2, bb);
   FormTrigger* TriggerObj5 = new FormTrigger(QVector3D(27.8, 0.7, 42.7), 2, bb);
   FormTrigger* TriggerObj6 = new FormTrigger(QVector3D(72, -10.7, -21), 3, bb);
   FormTrigger* TriggerObj7 = new FormTrigger(QVector3D(38, 0.7, 27), 3, bb);
   FormTrigger* TriggerObj8 = new FormTrigger(QVector3D(-18.5, 0.7, 59.5), 4, bb);
   spieler->register_trigger(TriggerObj1);
   spieler->register_trigger(TriggerObj2);
   spieler->register_trigger(TriggerObj3);
   spieler->register_trigger(TriggerObj4);
   spieler->register_trigger(TriggerObj5);
   spieler->register_trigger(TriggerObj6);
   spieler->register_trigger(TriggerObj7);
   spieler->register_trigger(TriggerObj8);

   //TORE registrieren
   Tor* TorObj1 = new Tor(wuerfelBlockadeTrans, 0.7f, 0);
   Tor* TorObj2 = new Tor(pyramideBlockadeTrans, 0.7f, 1);
   Tor* TorObj3 = new Tor(mondBlockadeTrans, 0.7f, 2);
   Tor* TorObj4 = new Tor(sternBlockadeTrans, 0.7f, 3);
   Tor* TorObj5 = new Tor(endeBlockadeTrans, 0.7f, 4);
   spieler->register_tor(TorObj1);
   spieler->register_tor(TorObj2);
   spieler->register_tor(TorObj3);
   spieler->register_tor(TorObj4);
   spieler->register_tor(TorObj5);

   //STERNTEILE registrieren
   SternTrigger* SternteilObj1 = new SternTrigger(r3t1Trans, QVector3D(-37, 0.7, -44), bb);
   SternTrigger* SternteilObj2 = new SternTrigger(r3t2Trans, QVector3D(-26.5, 0.7, -88), bb);
   SternTrigger* SternteilObj3 = new SternTrigger(r3t3Trans, QVector3D(6, 0.7, -61), bb);
   SternTrigger* SternteilObj4 = new SternTrigger(r3t4Trans, QVector3D(55.5, 0.7, -79.5), bb);
   SternTrigger* SternteilObj5 = new SternTrigger(r3t5Trans, QVector3D(71.9, 0.7, -29.4), bb);
   spieler->register_sternteil(SternteilObj1);
   spieler->register_sternteil(SternteilObj2);
   spieler->register_sternteil(SternteilObj3);
   spieler->register_sternteil(SternteilObj4);
   spieler->register_sternteil(SternteilObj5);

   //FARBTRIGGER registrieren
   FarbTrigger* FarbObj1 = new FarbTrigger(r2_farbe1, QVector3D(-67.2, 0.7, -35), r2t1Trans, bb, 0);
   FarbTrigger* FarbObj2 = new FarbTrigger(r2_farbe2, QVector3D(-63.5, 0.7, -46.5), r2t2Trans, bb, 1);
   FarbTrigger* FarbObj3 = new FarbTrigger(r2_farbe3, QVector3D(-77.8, 0.7, -34.5), r2t3Trans, bb, 2);
   spieler->register_farbe(FarbObj1);
   spieler->register_farbe(FarbObj2);
   spieler->register_farbe(FarbObj3);

   //SCHLUSSTRIGGER REGISTRIEREN
   SternTrigger* SchlussObj1 = new SternTrigger(r4t1Trans, QVector3D(29.1, 0.7, 27.3), bb);
   SternTrigger* SchlussObj2 = new SternTrigger(r4t2Trans, QVector3D(49.5, 0.7, 44), bb);
   SternTrigger* SchlussObj3 = new SternTrigger(r4t3Trans, QVector3D(61.8, 0.7, 42), bb);
   spieler->register_schluss(SchlussObj1);
   spieler->register_schluss(SchlussObj2);
   spieler->register_schluss(SchlussObj3);

   //CHARAKTER Varibalen zuweisen
   spieler->sternPickupTransform = sternTrigger1Trans;
   spieler->mondPickupTransform = mondTrigger1Trans;
   spieler->schlussBlockade = endeBlockadeTrans;
//-------------------------------------------------------------------------------------------------------------------------------------------------------

    //HIERACHIE
        //Level
    root->addChild(bodenNode);
    root->addChild(waendeNode);
    root->addChild(hWNode);
    root->addChild(hPNode);
    root->addChild(hMNode);
    root->addChild(hSNode);

        //R2
    root->addChild(r2fo1Node);
    root->addChild(r2fo2Node);
    root->addChild(r2fo3Node);

    root->addChild(r2s1);
    root->addChild(r2s2);
    root->addChild(r2s3);

    root->addChild(r2t1TransNode);
    r2t1TransNode->addChild(r2t1);
    root->addChild(r2t2TransNode);
    r2t2TransNode->addChild(r2t2);
    root->addChild(r2t3TransNode);
    r2t3TransNode->addChild(r2t3);

        //R3
    root->addChild(r3t1TransNode);
    r3t1TransNode->addChild(r3t1);
    root->addChild(r3t2TransNode);
    r3t2TransNode->addChild(r3t2);
    root->addChild(r3t3TransNode);
    r3t3TransNode->addChild(r3t3);
    root->addChild(r3t4TransNode);
    r3t4TransNode->addChild(r3t4);
    root->addChild(r3t5TransNode);
    r3t5TransNode->addChild(r3t5);

        //R4
    root->addChild(r4t1TransNode);
    r4t1TransNode->addChild(r4t1);
    root->addChild(r4t2TransNode);
    r4t2TransNode->addChild(r4t2);
    root->addChild(r4t3TransNode);
    r4t3TransNode->addChild(r4t3);

        //Formtrigger
    root->addChild(wuerfelTriggerNode);
    wuerfelTriggerNode->addChild(wuerfelTrigger);
    root->addChild(pyramideTrigger1Node);
    pyramideTrigger1Node->addChild(pyramideTrigger1);
    root->addChild(pyramideTrigger2Node);
    pyramideTrigger2Node->addChild(pyramideTrigger2);
    root->addChild(mondTrigger1Node);
    mondTrigger1Node->addChild(mondTrigger1);
    root->addChild(mondTrigger2Node);
    mondTrigger2Node->addChild(mondTrigger2);
    root->addChild(sternTrigger1Node);
    sternTrigger1Node->addChild(sternTrigger1);
    root->addChild(sternTrigger2Node);
    sternTrigger2Node->addChild(sternTrigger2);
    root->addChild(herzTriggerNode);
    herzTriggerNode->addChild(herzTrigger);

        //Blockaden
    root->addChild(wuerfelBlockadeTransNode);
    root->addChild(pyramideBlockadeTransNode);
    root->addChild(mondBlockadeTransNode);
    root->addChild(sternBlockadeTransNode);
    root->addChild(endeBlockadeTransNode);
    wuerfelBlockadeTransNode->addChild(wuerfelBlockadeNode);
    pyramideBlockadeTransNode->addChild(pyramideBlockadeNode);
    mondBlockadeTransNode->addChild(mondBlockadeNode);
    sternBlockadeTransNode->addChild(sternBlockadeNode);
    endeBlockadeTransNode->addChild(endeBlockadeNode);

		//sonnenlicht
    SunLight* light = new SunLight;
    light->setDiffuse(0.7, 0.7, 0.7);
    light->setSpecular(0.6, 0.6, 0.6);
    light->setAmbient(0.6, 0.6, 0.6);
    light->turnOn();
    Node *lightNode = new Node(light);
	root->addChild(lightNode);

    return (root);
}
