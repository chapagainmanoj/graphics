#include <iostream>
#include "object.h"
#include "point.h"

int main(){

        object *b;
        b=new object();
        point *p1,*p2,*p3,*p4;

        p1=new point(1.0f,1.0f,-1.0f);
	p2=new point(1.0f,-1.0f,-1.0f);
	p3=new point(-1.0f,-1.0f,1.0f);
	p4=new point(1.0f,-1.0f,1.0f);

        b->vTable(*p1);
        b->vTable(*p2);
        b->vTable(*p3);
        b->vTable(*p4);

        edge *e1,*e2,*e3,*e4;
        e1=new edge(p1,p2);
        e2=new edge(p2,p3);
        e3=new edge(p3,p4);
        e4=new edge(p4,p1);
        b->eTable(*e1);
        b->eTable(*e2);
        b->eTable(*e3);       
        b->eTable(*e4);

        b->showETable();
        b->showVTable();
	return 0;
}

