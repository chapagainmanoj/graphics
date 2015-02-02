#ifndef POINT_H
#define POINT_H

#include<string>
#include<iostream>
#include<math.h>
//namespace point3D{
template<class T>
class point{
	public:
		T x;
		T y;
		T z;
		T w;
	public:
		point();
		point(T x,T y,T z);
		point(T x,T y,T z,T w);
		point<T>& operator=(const point<T> &rhs);
		void transform(T matrix[4][4]);
		void setPoint(T x,T y,T z,T w);

		void rotate(T xr,T yr,T theta);
		void scale(T sx,T sy,T sz);
		void translate(T tx,T ty,T tz);
};

template <class T>
point<T>::point(){
	setPoint(0.0,0.0,0.0,1.0);
}
template <class T>
point<T>::point(T x,T y,T z){
	setPoint(x,y,z,1.0);
}
template <class T>
point<T>::point(T x,T y,T z,T w){
	setPoint(x,y,z,w);
}
template <class T>
point<T>& point<T>::operator=(const point &rhs) {
	if(this==&rhs)
		return *this;
	x=rhs.x;
	y=rhs.y;
	z=rhs.z;
	w=rhs.w;
	return *this;
}
template <class T>
void point<T>::transform(T matrix[4][4]){
	T value[]={0,0,0,1};
	value[0] = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3] * w;
	value[1] = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3] * w;
	value[2] = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3] * w;
	x = value[0];
	y = value[1];
	z = value[2];
	w = 1.0;
}

template <class T>
void point<T>::setPoint( T x, T y, T z, T w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

template <class T>
void point<T>::translate(T tx,T ty,T tz){
	this->x=x+tx;
	this->y=y+ty;
	this->z=z+tz;
}

template <class T>
void point<T>::scale(T sx,T sy,T sz){
	this->x=x*sx;
	this->y=y*sy;
	this->z=z*sz;
}

template <class T>
void point<T>::rotate(T xr,T yr,T theta){

	T rmat[3][3] ={
	{cos(theta),-sin(theta),xr*(1-cos(theta))+yr*sin(theta)},
	{cos(theta),-sin(theta),xr*(1-cos(theta))+yr*sin(theta)},
	{cos(theta),-sin(theta),xr*(1-cos(theta))+yr*sin(theta)}
	};

	transform(rmat);
}
//}
#endif
