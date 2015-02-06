#include "vector.h"
//#include "point.h"
vector::vector(){
}
vector::vector(float x,float y,float z):x(x),y(y),z(z){
}

vector::vector(const vector &v){
	this->x=v.x;
	this->y=v.y;
	this->z=v.z;
}

vector::vector(vector p1,vector p2):x(p1.x-p2.x),y(p1.y-p2.y),z(p1.z-p2.z){
}

vector& vector::operator+(const vector &other) const{
	vector result;
	result.x=this->x+other.x;
	result.y=this->y+other.y;
	result.z=this->z+other.z;
	return result;
}
void vector::showVector(){
	std::cout<<x<<" "<<y<<" "<<z<<std::endl;
}
vector& vector::operator=( const vector &other ) {
	if( this == &other ) {
		return *this;
	}
	setVector( other.x, other.y, other.z );
	return *this;
}
float vector::dot(const vector &v1) const{
	return(this->x*v1.x+this->y*v1.y+this->z*v1.z);
}

float vector::dot(point v1) const{
	return(this->x*v1.x+this->y*v1.y+this->z*v1.z);
}

vector vector::cross(const vector &v)const{
	vector result;
	result.x=(this->y*v.z-this->z*v.y);
	result.y=-(this->x*v.z-this->z*v.x);
	result.z=(this->x*v.y-this->y*v.x);
	return result;
}
float vector::length() const {
	return sqrt( this->x*this->x + this->y*this->y + this->z*this->z );
}

void vector::normalize() {
	float length = this->length(); /* Compute the magnitude */
	
	if( length != 0 ) { /* Prevent divide by zero */
		this->x /= length;
		this->y /= length;
		this->z /= length;
	} else { 
		//printf( "VECTOR DIVIDE BY ZERO ERROR\n" );
	}
}
void vector::reverse() {
	this->x *= -1;
	this->y *= -1;
	this->z *= -1;
}
void vector::setVector( float xx, float yy, float zz ) {
	this->x = xx;
	this->y = yy;
	this->z = zz;
}
void vector::setVector( const point &p1, const point &p2 ) {
	setVector( (p1.x - p2.x), (p1.y - p2.y), (p1.z - p2.z));
}
