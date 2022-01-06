#ifndef FARB_TRIGGER_H
#define FARB_TRIGGER_H
class FarbTrigger{
	public:
		FarbTrigger(Drawable* node,  QVector3D pos, Transformation* transform, int bb, int color) : anmalobjekt(node), farbe_transform(transform), farbe_pos(pos), bbSize(bb), color_counter(color), triggerActivatedOnce(false) {};
		int update(QVector3D spieler_pos){
			if (triggerActivatedOnce == false && spieler_pos.x() >= farbe_pos.x() - bbSize && spieler_pos.x() <= farbe_pos.x() + bbSize && spieler_pos.y() >= farbe_pos.y() - bbSize && spieler_pos.y() <= farbe_pos.y() + bbSize && spieler_pos.z() >= farbe_pos.z() - bbSize && spieler_pos.z() <= farbe_pos.z() + bbSize) {
				color_counter=(color_counter+1)%3;

				Material* m;
			    m = anmalobjekt->getProperty<Material>();
				m->setDiffuse(colors[color_counter][0],colors[color_counter][1],colors[color_counter][2],colors[color_counter][3]);
				m->setAmbient(colors[color_counter][0],colors[color_counter][1],colors[color_counter][2],colors[color_counter][3]);
				m->setSpecular(colors[color_counter][0],colors[color_counter][1],colors[color_counter][2],colors[color_counter][3]);
				triggerActivatedOnce = true;
			}
			if (!(spieler_pos.x() >= farbe_pos.x() - bbSize && spieler_pos.x() <= farbe_pos.x() + bbSize && spieler_pos.y() >= farbe_pos.y() - bbSize && spieler_pos.y() <= farbe_pos.y() + bbSize && spieler_pos.z() >= farbe_pos.z() - bbSize && spieler_pos.z() <= farbe_pos.z() + bbSize)) {
				triggerActivatedOnce = false;
			};
			return color_counter;
		};

		void solved() {
			farbe_transform->translate(0, -10, 0);
		};
	private:
		double colors[3][4] = {
            {1.0,0.0,0.0,1.0},
            {0.0,1.0,0.0,1.0},
            {0.0,0.0,1.0,1.0}
		};
		int color_counter; //0 = red, 1 = green, 2 = blue
		int bbSize; //Ausdehnung der Bounding Box
		bool triggerActivatedOnce;
		QVector3D farbe_pos;
		Transformation* farbe_transform;
		Drawable* anmalobjekt;
};
#endif
