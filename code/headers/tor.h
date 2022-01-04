#ifndef TOR_H
#define TOR_H

#include "transformation.h"

class Tor{
	public:
		Tor(Transformation* node, float posY_input, int form) : tor_transform(node), posY(posY_input), tor_form(form) {};
		void update(int spieler_form){ 
			if (spieler_form == tor_form) {
                if (posY > -2.0f) {
					tor_transform->resetTrafo();  //auf 0,0,0 zurücksetzen
					tor_transform->translate(0,posY,0);  //absoluten wert setzen
                    posY -= 0.1f;
                }
            }
            else {
                if (posY < 0.0f) {
					tor_transform->resetTrafo();  //auf 0,0,0 zurücksetzen
					tor_transform->translate(0,posY,0);  //absoluten wert setzen
                    posY += 0.1f;
                }
            }
		};
private:
	Transformation* tor_transform; //Transformation Node des Tores in der Hierachie
	float posY; //Höhe des Tores
    int tor_form;
};
#endif
