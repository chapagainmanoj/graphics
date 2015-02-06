#ifndef POINT_H
#define POINT_H

#include<string>
#include<iostream>
class point{
	public:
		float x;
		float y;
		float z;
		float w;
	public:
		point();
		void showPoint();
		point(float x,float y,float z);
		point(float x,float y,float z,float w);
		point& operator=(const point &rhs);
		void transform(float matrix[4][4]);
		void multMat(float matrix[4][4]);
		void normalize();
		void rotatex(float theta);
		void rotatey(float theta);
		void rotatez(float theta);
		void scale(float sx,float sy,float sz);
		void translate(float tx,float ty,float tz);
};
#endif
