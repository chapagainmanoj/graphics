#include "object.h"
object::object(){

}
void object::vTable(point *p){
        std::vector<point>::push_back(p);
}
void object::loadObject(){
}
void edge::showEdge(){
        p1->showPoint();
        std::cout<<" to ";
        p2->showPoint();
}
