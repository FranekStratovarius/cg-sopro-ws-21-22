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

#include "headers/characterticker.h"

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


	Drawable* plane = new Drawable(new SimplePlane(10,10));
	Node* planeNode = new Node(plane);

	plane->getProperty<ModelTransformation>()->rotate(90, 1.f, 0.f, 0.f);
	plane->setStaticGeometry(true);
	PhysicObject* planePhys = v_PhysicEngine->createNewPhysicObject(plane);
	PhysicObjectConstructionInfo* ConstructionInfo = new PhysicObjectConstructionInfo();
	ConstructionInfo->setCollisionHull(CollisionHull::BoxAABB); // Automatische generierung einer Box
	planePhys->setConstructionInfo(ConstructionInfo);
	planePhys->registerPhysicObject();

	Color* c = plane->getProperty<Color>();
	c->setValue(1.0, 0.0, 0.0, 1.0);

	root->addChild(planeNode);
	return (root);
}
