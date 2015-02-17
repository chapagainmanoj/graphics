#include "object.h"
#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
object::object(){


}
void object::showVTable(){
        for(int i=0;i<pointTable.size();i++){
                std::cout<<"v"<<i<<":";
                pointTable[i].showPoint();
        }
}
void object::showETable(){
        for(int i=0;i<edgeTable.size();i++){
                std::cout<<"E"<<i<<":";
                edgeTable[i].showEdge();
        }
}
void object::vTable(point &p){
        pointTable.push_back(p);
}
void object::eTable(edge &e){
        edgeTable.push_back(e);
}
//void object::sTable(trisurface &s){
  //      surfaceTable.push_back(s);
//}
void object::loadObject(){
}
void object::draw(){
for(int i=0;i<edgeTable.size();i++){
                edgeTable[i].drawEdge();
}
}
void edge::showEdge(){
        p1->showPoint();
        std::cout<<" to ";
        p2->showPoint();
}
edge::edge(point *a,point *b){
	p1=a;
	p2=b;
}
void edge::drawEdge(){
	glBegin(GL_LINES);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(p1->x,p1->y);
	glVertex2f(p2->x,p2->y);
	glEnd();
}
/*trisurface::trisurface(edge *a,edge *b,edge *c){
        e1=a;e2=b;e3=c;
}*/
