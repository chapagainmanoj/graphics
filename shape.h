#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include "GlutFramework.h"
#include "vector.h"
#include "point.h"
/*struct edge{
	point<T> p1,p2;
};*/
class shape:public GlutFramework {
	private:
		float rtri;
		point *p1;
		point *p2;
	public:
		shape();
		//~shape();
		void display();
		//void reshape(int width,int height);
		void load();

		void toViewCord(point *p);
		void drawLine(point *p1,point *p2);
		//void mouseButtonPress(int button,int state,int x,int y);
		//void mouseMove(int x,int y);
		//void handleKeys(unsigned char key,int x,int y);
};
#endif
