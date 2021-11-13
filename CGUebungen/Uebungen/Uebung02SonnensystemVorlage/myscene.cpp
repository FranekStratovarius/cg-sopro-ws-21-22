#include "opengl.h"
#include "openglwidget.h"
#include "screenrenderer.h"
#include "scenemanager.h"
#include "transformation.h"
#include "keyboardtransformation.h"
#include "mousekeyboardcameracontroller.h"
#include "planet.h"
#include "color.h"

#include "ui_dockwidget.h"

Node *initScene1();

void SceneManager::initScenes()
{
    Ui_FPSWidget *lDock;
    QDockWidget *lDockWidget = new QDockWidget(QString("FPS"), SceneManager::getMainWindow());

    Camera* cam = new Camera();
    CameraController* camController = new MouseKeyboardCameraController(cam);
    Q_UNUSED(camController);
    RenderingContext *myContext=new RenderingContext(cam);
    unsigned int myContextNr = SceneManager::instance()->addContext(myContext);
    unsigned int myScene = SceneManager::instance()->addScene(initScene1());
    ScreenRenderer *myRenderer = new ScreenRenderer(myContextNr, myScene);

    //Vorsicht: Die Szene muss initialisiert sein, bevor das Fenster verändert wird (Fullscreen)
    SceneManager::instance()->setActiveScene(myScene);
    SceneManager::instance()->setActiveContext(myContextNr);
//    SceneManager::instance()->setFullScreen();

    lDock = new Ui_FPSWidget();
    lDock->setupUi(lDockWidget);
    lDockWidget->resize(200,100);
    SceneManager::getMainWindow()->addDockWidget(Qt::RightDockWidgetArea, lDockWidget);
    lDockWidget->show();
    QObject::connect(OpenGLWidget::getInstance(), SIGNAL(sigFPS(int)), lDock->lcdNumber, SLOT(display(int)));
}

Node *initScene1()
{
//    Objekte anlegen
    Planet *sonne = new Planet(1.0);
    KeyboardTransformation *sonnensystem = new KeyboardTransformation();
    Color *c;
    float umlaufspeed=2.0f;

    //Farben
    c = sonne->getProperty<Color>();
    c->setValue(1.0,1.0,0.0,1.0);

    //Damit man die Drehungen sieht, Gitternetz aktivieren
    sonne->deactivateFill();

    //Keys belegen
    sonnensystem->setRotKeys(KeyboardTransformation::NoKey,
                             KeyboardTransformation::NoKey,
                             'r', 'R',
                             KeyboardTransformation::NoKey,
                             KeyboardTransformation::NoKey);
    sonnensystem->setRotspeed(umlaufspeed);

    //Vorsicht beim ändern von Rot. und Trans. derselben Transformation:
    //Die Reihenfolge ist wichtig!
    sonnensystem->rotate(45.0,1.0,0.0,0.0); //Neigen, damit man die Umlaufbahn besser sieht

    //Szenengraph aufbauen
    Node *sonnensystemNode = new Node(sonnensystem);

    sonnensystemNode->addChild(new Node(sonne));

    return(sonnensystemNode);
}
