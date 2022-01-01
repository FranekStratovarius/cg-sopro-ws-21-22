#ifndef CHARACTERTICKER_H
#define CHARACTERTICKER_H

#include "idleobserver.h"
#include "physics.h"
#include "scenemanager.h"
#include "simplesphere.h"
#include "simplecube.h"
#include "modeltransformation.h"
#include "color.h"
#include "physicaccessablecamera.h"
#include "shadermanager.h"
#include "trianglemesh.h"
#include <QElapsedTimer>
#include <qtimer.h>

// Klasse um unsere beiden Charaktere zu steuern
class CharacterTicker : public IdleObserver{
	public:
		CharacterTicker(Node* root,PhysicEngine* physics_engine);
		void doIt();	
	private:
		void change_visibility(int idx);

		DynamicCharacterWithCam* character;
		int current_character=0;
		// Timer für genaue Delta Zeitberechnung
		QElapsedTimer m_Timer;
		QTimer* a;

		double colors[5][4] = {
            {0.0,1.0,0.0,1.0},
            {0.0,0.0,1.0,1.0},
            {0.7,0.7,0.7,1.0},
            {1.0,1.0,0.0,1.0},
            {1.0,0.0,0.0,1.0}
		};
	
		Node* root;
		PhysicEngine* physics_engine;

		Drawable* player_model;
		Drawable** models;
		Node* player_node;

		Shader* shader_normal;
		Shader* shader_transparent;
};

#endif // CHARACTERTICKER_H
