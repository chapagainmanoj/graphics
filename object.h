#include <iostream>
#include "point.h"
#include <vector>
struct edge{
	point *p1;
	point *p2;
	public:
        void showEdge();
	//edge(point &a,point &b);
	//edge(float x1,float y1,float z1,float x2,float y2,float z2);
};
/*
edge::edge(point a,point b){
	p1=new point(a.x,a.y,a.z);
	p2=new point(b.x,b.y,b.z);
}
edge::edge(float a,float b,float c,float d,float e,float f){
	p1=new point(a,b,c);
	p2=new point(d,e,f);
}
*/
struct trisurface{
        edge *e1,*e2,*e3;
        public:
        trisurface(edge&,edge&,edge&);
};
class object{
	protected:
                std::vector<point> pointTable;
                std::vector<edge> edgeTable;
                std::vector<trisurface> surfaceTable;
        public:
        object();
        void vTable(point*);
        void eTable(edge);
        void sTable(trisurface);
        void loadObject();
};
