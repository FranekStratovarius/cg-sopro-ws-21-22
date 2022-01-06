#ifndef STERN_TRIGGER_H
#define STERN_TRIGGER_H
class SternTrigger{
	public:
		SternTrigger(Transformation* node,  QVector3D pos, int bb) : sternteil_transform(node), sternteil_pos(pos), bbSize(bb), pickedUp(false) {};
		int update(QVector3D spieler_pos){
			if (spieler_pos.x() >= sternteil_pos.x() - bbSize && spieler_pos.x() <= sternteil_pos.x() + bbSize && spieler_pos.y() >= sternteil_pos.y() - bbSize && spieler_pos.y() <= sternteil_pos.y() + bbSize && spieler_pos.z() >= sternteil_pos.z() - bbSize && spieler_pos.z() <= sternteil_pos.z() + bbSize) {
				sternteil_transform->translate(0, -10, 0);
				pickedUp=true;
			}
			return pickedUp;
		};
	private:
		bool pickedUp=false;
		int bbSize; //Ausdehnung der Bounding Box
		QVector3D sternteil_pos;
		Transformation* sternteil_transform;
};
#endif
