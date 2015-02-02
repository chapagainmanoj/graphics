#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include "GlutFramework.h"
#include "vector.h"
#include "point.h"
class shape:public GlutFramework {
	private:
		float rtri;
	public:
		shape();
		//~shape();
		void display();
		void reshape(int width,int height);
		void load();
		void drawLine(point<float> p1,point<float> p2);
		//void mouseButtonPress(int button,int state,int x,int y);
		//void mouseMove(int x,int y);
		//void handleKeys(unsigned char key,int x,int y);
};
#endif
