#include "point.h"
#include <math.h>

point::point():x(0.0),y(0.0),z(0.0),w(1.0){
}
point::point(float px,float py,float pz):x(px),y(py),z(pz),w(1.0){
}
point::point(float px,float py,float pz,float pw):x(px),y(py),z(pz),w(pw){
}
point& point::operator=(const point &rhs) {
	if(this==&rhs)
		return *this;
	x=rhs.x;
	y=rhs.y;
	z=rhs.z;
	w=rhs.w;
	return *this;
}
void point::showPoint(){

	std::cout<<x<<" "<<y<<" "<<z<<" "<<w<<std::endl;
}
void point::transform(float matrix[4][4]){
	float value[]={0,0,0,1};
	value[0] = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3] * w;
	value[1] = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3] * w;
	value[2] = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3] * w;
	this->x = value[0];
	this->y = value[1];
	this->z = value[2];
	this->w = 1.0;
}

void point::multMat(float matrix[4][4]){
	float value[]={0,0,0,0};
	value[0] = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3] * w;
	value[1] = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3] * w;
	value[2] = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3] * w;
	value[3] = matrix[3][0] * x + matrix[3][1] *y + matrix[3][2]*z + matrix[3][3]*w;
	this->x = value[0];
	this->y = value[1];
	this->z = value[2];
	this->w = value[3];
}


void point::normalize() {
	float length =sqrt( this->x*this->x + this->y*this->y + this->z*this->z );
	if( length != 0 ) { /* Prevent divide by zero */
		this->x /= length;
		this->y /= length;
		this->z /= length;
	} else { 
		//printf( "VECTOR DIVIDE BY ZERO ERROR\n" );
	}
}
void point::translate(float tx,float ty,float tz){
	this->x=x+tx;
	this->y=y+ty;
	this->z=z+tz;
}

void point::scale(float sx,float sy,float sz){
	this->x=x*sx;
	this->y=y*sy;
	this->z=z*sz;
}
void point::rotatex(float theta){
	this->y=cos(theta)*y-sin(theta)*z;
	this->z=sin(theta)*y+cos(theta)*z;
}
void point::rotatey(float theta){
	this->x=cos(theta)*x+sin(theta)*z;
	this->z=-1*sin(theta)*x+cos(theta)*z;
}
void point::rotatez(float theta){
	this->x=cos(theta)*x-sin(theta)*y;
	this->y=sin(theta)*x+cos(theta)*y;
}

