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

Node* initScene1();

void SceneManager::initScenes()
{
	Camera* cam = new Camera();
	CameraController* camController = new MouseKeyboardCameraController(cam);
	Q_UNUSED(camController);
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

	Drawable* PlayerObject = new Drawable(new SimpleCube(1.0, 0.5, 1.0));

	Color* c;
	c = PlayerObject->getProperty<Color>();
	c->setValue(1.0, 1.0, 0.0, 1.0);

	Node* PlayerNode = new Node(PlayerObject);




	//QImage* heightmap_image = new QImage("://images/sam.bmp");
	//QImage* heightmap_image = new QImage("://images/sw.bmp");
	//QImage* heightmap_image = new QImage("://images/terrain.bmp");
	//QImage* heightmap_image = new QImage("://images/logo.bmp");
	QImage* heightmap_image = new QImage("://images/Katze.jpg");

	unsigned int width = heightmap_image->width();
	unsigned int height = heightmap_image->height();
	unsigned int scale = (width>height) ? width : height;
	float size = 10.f;

	/*
	std::cout << "width: " << width << std::endl;
	std::cout << "height: " << height << std::endl;
	*/



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

	root->addChild(node_kt_heightmap);
	node_kt_heightmap->addChild(node_heightmap_offset);
	node_heightmap_offset->addChild(new Node(heightmap_drawable));
	return (root);
}
