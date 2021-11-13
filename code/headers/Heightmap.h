#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include "simpleplane.h"

class Heightmap : public SimplePlane{
	public:
		Heightmap(unsigned int w,unsigned int h,unsigned int div,QImage* heightmap_image);
		void set_heightscale(float heightscale);
	protected:
		virtual void fillColors(QVector<QVector4D>& colors) override;
		virtual void fillVertices(QVector<QVector4D>& vertices) override;
	private:
		QImage* heightmap_image;
		float heightscale = 5.f;
};

#endif
