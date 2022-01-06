#ifndef FARB_TRIGGER_H
#define FARB_TRIGGER_H
class FarbTrigger{
	public:
		FarbTrigger(Drawable* node,  QVector3D pos, Transformation* transform, int bb, int color) : anmalobjekt(node), farbe_transform(transform), farbe_pos(pos), bbSize(bb), color_counter(color), triggerActivatedOnce(false) {};
		int update(QVector3D spieler_pos){
			if (triggerActivatedOnce == false && spieler_pos.x() >= farbe_pos.x() - bbSize && spieler_pos.x() <= farbe_pos.x() + bbSize && spieler_pos.y() >= farbe_pos.y() - bbSize && spieler_pos.y() <= farbe_pos.y() + bbSize && spieler_pos.z() >= farbe_pos.z() - bbSize && spieler_pos.z() <= farbe_pos.z() + bbSize) {
				switch (color_counter)
				{
					case 0:
					anmalobjekt->getProperty<Color>()->setValue(0.0, 0.1, 0.0, 1.0);
					color_counter++; break;
					case 1:
					anmalobjekt->getProperty<Color>()->setValue(0.0, 0.0, 0.1, 1.0);
					color_counter++; break;
					case 2:
					anmalobjekt->getProperty<Color>()->setValue(1.0, 0.0, 0.0, 1.0);
					color_counter = 0; break;
				}
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
		int color_counter; //0 = red, 1 = green, 2 = blue
		int bbSize; //Ausdehnung der Bounding Box
		bool triggerActivatedOnce;
		QVector3D farbe_pos;
		Transformation* farbe_transform;
		Drawable* anmalobjekt;
};
#endif
