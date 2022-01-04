#ifndef TOR_H
#define TOR_H

#include "transformation.h"

class Tor{
	public:
		Tor(Transformation* node, float posY_input, int form) : tor_transform(node), posY(posY_input), tor_form(form) {};
		void update(int spieler_form){ 
            if (spieler_form == tor_form) {
                if (posY <= 0.7f && pos > -10.7f) {
                    tor_transform->translate(0, -0.01f, 0);
                    posY -= 0.01f;
                }
            }
            else {
                if (posY >= -10.7f && posY < 0.7f) {
                    tor_transform->translate(0, 0.01f, 0);
                    posY += 0.01f;
                }
            }
		};
private:
	Transformation* tor_transform; //Transformation Node des Tores in der Hierachie
	float posY; //Höhe des Tores
    int tor_form;
};
#endif
