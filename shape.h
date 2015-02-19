#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include "GlutFramework.h"
#include "vector.h"
#include <vector>
#include "point.h"
#include "object.h"

class shape:public GlutFramework {
	private:
		//float rtri;
		float zvp;
		float zprp;
                //object *b;
                std::vector<point> points;
	public:
		shape();
		//~shape();
		void display();
		//void reshape(int width,int height);
		void load();

		void triangleFill(point *p1,point *p2,point *p3,point *colorRGBA);
		void pptiveProjxn(point &p,float zvp,float zprp);
		void toViewCord(point &p);
		void drawLine(point &p1,point &p2);
		//void mouseButtonPress(int button,int state,int x,int y);
		//void mouseMove(int x,int y);
};
#endif
