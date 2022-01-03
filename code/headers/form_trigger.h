#ifndef FORM_TRIGGER_H
#define FORM_TRIGGER_H
class FormTrigger{
	public:
		FormTrigger(QVector3D pos, int form_input, int bb) : form_pos(pos), form_input(form), bbSize(bb) {};
		int update(QVector3D spieler_pos){
			if(spieler_pos.x >= form_pos.x - bbSize && spieler_pos.x <= form_pos.x + bbSize && spieler_pos.y >= form_pos.y - bbSize && spieler_pos.y <= form_pos.y + bbSize && spieler_pos.z >= form_pos.z - bbSize && spieler_pos.z <= form_pos.z + bbSize) {
				return form;
			}
			return -1;
		};
	private:
		int bbSize; //Ausdehnung der Bounding Box
		int form;
		QVector3D form_pos;
};
#endif
