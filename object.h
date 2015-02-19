#include <iostream>
#include "point.h"
#include <vector>
struct edge{
	point *p1;
	point *p2;
        public:
        edge(point *a,point *b);
        void showEdge();
        void drawEdge();
};

/*struct trisurface{
        edge *e1,*e2,*e3;
        public:
        trisurface(edge *a,edge *b,edge *c)
};*/
class object{
	public:

                point *p[4];
                std::vector<point> pointTable;
                std::vector<edge> edgeTable;
                //std::vector<trisurface> surfaceTable;
        public:
        object();
        void showVTable();
        void showETable();
        void draw();
        void vTable(point&);
        void eTable(edge&);
        //void sTable(trisurface&);
        void loadObject();
};
