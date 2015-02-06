#include "point.h"
#include <iostream>
using namespace std;
int main(){
	point p1(1.0,0.0,0.0);
	point p2(0.0,1.0,0.0);
	p1.showPoint();p2.showPoint();
	p2.rotatez(-90.0*3.14/180);
	p2.showPoint();
	p1.rotatez(-90.0*3.14/180);
	p1.showPoint();
	p1.rotatez(-90.0*3.14/180);
	p1.showPoint();
	p1.rotatez(-90.0*3.14/180);
	p2.translate(5.0,5.0,5.0);
	p1.showPoint();p2.showPoint();
	return 0;
}
