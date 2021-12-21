#include "scenemanager.h"
#include "screenrenderer.h"
#include "mousekeyboardcameracontroller.h"
#include "simpleplane.h"
#include "shadertimed.h"
#include "transformation.h"
#include "shadermanager.h"
#include "keyboardtransformation.h"
#include "modeltransformation.h"
#include "headers/Heightmap.h"
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



	//QImage* heightmap_image = new QImage("://images/sam.bmp");
	//QImage* heightmap_image = new QImage("://images/sw.bmp");
	//QImage* heightmap_image = new QImage("://images/terrain.bmp");
	//QImage* heightmap_image = new QImage("://images/logo.bmp");
	QImage* heightmap_image = new QImage("://images/Katze.jpg");

	unsigned int width = heightmap_image->width();
	unsigned int height = heightmap_image->height();
	unsigned int scale = (width>height) ? width : height;
	float size = 10.f;




	Heightmap* heightmap = new Heightmap(width,height,scale,heightmap_image);
	heightmap->set_heightscale(10.f);
	Drawable *heightmap_drawable = new Drawable(heightmap);
	Shader *s = ShaderManager::getShader("://shaders/basiccolor.vert", "://shader/basic.frag");
	heightmap_drawable->setShader(s);
	heightmap_drawable->getProperty<ModelTransformation>()->scale(size/scale,size/scale,size/scale);

	KeyboardTransformation *kt_heightmap = new KeyboardTransformation();
	kt_heightmap->setRotKeys(
		'k','i',
		'l','j',
		'u','o'
	);



	kt_heightmap->setRotspeed(0.5f);
	Transformation* heightmap_offset=new Transformation();
	heightmap_offset->translate(
		(-size*(width<height ? width/(float)height : 1))/2,
		0.0f,
		(-size*(height<width ? height/(float)width : 1))/2
	);
	Node* node_kt_heightmap=new Node(kt_heightmap);
	Node* node_heightmap_offset=new Node(heightmap_offset);

	
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


	root->addChild(node_kt_heightmap);
	node_kt_heightmap->addChild(node_heightmap_offset);
	node_heightmap_offset->addChild(new Node(heightmap_drawable));
	return (root);
}
