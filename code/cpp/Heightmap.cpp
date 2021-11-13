#include "scenemanager.h"
#include "headers/Heightmap.h"

Heightmap::Heightmap(unsigned int w,unsigned int h,unsigned int div,QImage* heightmap_image) : SimplePlane(w,h,div){
	this->heightmap_image = heightmap_image;
}

void Heightmap::fillColors(QVector<QVector4D>& colors){
	colors.clear();
	for(unsigned int y = 0; y < mDivs; y++){
		for(unsigned int x = 0; x <= mDivs; x++){
			int local_x  = x / (float)mDivs * mXSize;
			int local_y1 = (y + 1) / (float)mDivs * mYSize;
			int local_y2 = y / (float)mDivs * mYSize;

			QColor color = heightmap_image->pixelColor(
				(local_x<mXSize) ? local_x : mXSize-1,
				(local_y1<mYSize) ? local_y1 : mYSize-1
			);
			QColor color2 = heightmap_image->pixelColor(
				(local_x<mXSize) ? local_x : mXSize-1,
				(local_y2<mYSize) ? local_y2 : mYSize-1
			);

			colors.append(QVector4D(color.red()/255.f,color.green()/255.f,color.blue()/255.f,color.alpha()/255.f));
			colors.append(QVector4D(color2.red()/255.f,color2.green()/255.f,color2.blue()/255.f,color2.alpha()/255.f));
		}
	}
}

void Heightmap::fillVertices(QVector<QVector4D>& vertices){
	vertices.clear();
	for(unsigned int y = 0; y < mDivs; y++){
		for(unsigned int x = 0; x <= mDivs; x++){
			int local_x  = x / (float)mDivs * mXSize;
			int local_y1 = (y + 1) / (float)mDivs * mYSize;
			int local_y2 = y / (float)mDivs * mYSize;

			QColor color = heightmap_image->pixelColor(
				(local_x<mXSize) ? local_x : mXSize-1,
				(local_y1<mYSize) ? local_y1 : mYSize-1
			);
			QColor color2 = heightmap_image->pixelColor(
				(local_x<mXSize) ? local_x : mXSize-1,
				(local_y2<mYSize) ? local_y2 : mYSize-1
			);

			vertices.append(QVector4D(
				local_x,	//x
				(color.red()+color.green()+color.blue()+color.alpha())/255.f*heightscale,	//y
				local_y1,	//z
				1.f
			));
			vertices.append(QVector4D(
				local_x,	//x
				(color2.red()+color2.green()+color2.blue()+color2.alpha())/255.f*heightscale,	//y
				local_y2,	//z
				1.f
			));
		}
	}
}

void Heightmap::set_heightscale(float heightscale){
	this->heightscale = heightscale;
}
