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

#include "physicaccessablecamera.h"
#include "headers/characterticker.h"

Node* initScene1();

void SceneManager::initScenes()
{
	//Camera* cam = new Camera();
	//CameraController* camController = new MouseKeyboardCameraController(cam);
	//Q_UNUSED(camController);

	PhysicAccessableCamera* cam = new PhysicAccessableCamera;

	RenderingContext* myContext = new RenderingContext(cam);
	unsigned int myContextNr = SceneManager::instance()->addContext(myContext);
	unsigned int myScene = SceneManager::instance()->addScene(initScene1());
	ScreenRenderer* myRenderer = new ScreenRenderer(myContextNr, myScene);
	Q_UNUSED(myRenderer);

	//MouseKeyboardCameraController Test1(cam);

	// Vorsicht: Die Szene muss initialisiert sein, bevor das Fenster verändert wird (Fullscreen)
	SceneManager::instance()->setActiveScene(myScene);
	SceneManager::instance()->setActiveContext(myContextNr);
	//SceneManager::instance()->setFullScreen();
}

Node* initScene1()
{
	Node* root = new Node();

	// Physic Engine Erzeugen und einen Pointer auf Instanz holen
	int v_Slot = PhysicEngineManager::createNewPhysicEngineSlot(PhysicEngineName::BulletPhysicsLibrary);
	PhysicEngine* v_PhysicEngine = PhysicEngineManager::getPhysicEngineBySlot(v_Slot);


	Drawable* PlayerObject = new Drawable(new SimpleCube(1.0, 1.0, 1.0));
	Color* c;
	c = PlayerObject->getProperty<Color>();
	c->setValue(1.0, 1.0, 0.0, 1.0);
	Node* PlayerNode = new Node(PlayerObject);

	//Das Playerobjekt nach oben verschieben, damit er nicht in der Plane drinnen ist
	ModelTransformation* modelTransform;
	modelTransform = PlayerObject->getProperty<ModelTransformation>();
	modelTransform->translate(0.f, 1.f, 0.f);
	root->addChild(PlayerNode);

	// Character Objekt erzeugen mit einer Verfolgerkamera
	DynamicCharacterWithCam* CharacterWithCam = v_PhysicEngine->createNewDynamicCharacterWithCam(PlayerObject);
	// Kamera anhängen, die bestimmung der kameraposition wird nun komplett von dem character übernommen,  allein
	// die x achsendrehung kann noch beeinflusst werden
	CharacterWithCam->setCam(dynamic_cast<PhysicAccessableCamera*>(SceneManager::instance()->getActiveContext()->getCamera()));
	// Relative Kameraposition zum Drawable setzen
	CharacterWithCam->setRelativeCamPosition(0.f, 4.f, 5.f);	//macht noch garnichts
	CharacterWithCam->setUpDownView(-30.0F);					//macht noch garnichts
	// Physic Object registrieren
	PlayerObject->getPhysicObject()->registerPhysicObject();


	// Character Ticker der für die Steuerung unser Charaktere veranwortlich ist
	CharacterTicker* test = new CharacterTicker(CharacterWithCam);

//-------------------------------------------------------------------------------------------------------------------------------------------------------


	Drawable* plane = new Drawable(new SimplePlane(10,10));
	Node* planeNode = new Node(plane);

	plane->getProperty<ModelTransformation>()->rotate(90, 1.f, 0.f, 0.f);
	plane->setStaticGeometry(true);
	PhysicObject* planePhys = v_PhysicEngine->createNewPhysicObject(plane);
	PhysicObjectConstructionInfo* ConstructionInfo = new PhysicObjectConstructionInfo();
	ConstructionInfo->setCollisionHull(CollisionHull::BoxAABB); // Automatische generierung einer Box
	planePhys->setConstructionInfo(ConstructionInfo);
	planePhys->registerPhysicObject();

	c = plane->getProperty<Color>();
	c->setValue(1.0, 0.0, 0.0, 1.0);

	root->addChild(planeNode);
	return (root);
}
