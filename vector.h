#ifndef VECTOR_H
#define VECTOR_H
#include <math.h>
#include "point.h"

class vector{
	public:
		float x;
		float y;
		float z;
	public:
		vector();
		vector(float x,float y,float z);
		vector(const vector &v);
		vector(vector p1,vector p2);
		float dot(const vector & v1) const;
		float dot(point p1) const;
		vector cross(const vector &v1) const;
		vector &operator=( const vector &other );
		vector &operator+(const vector &other) const;
		float length() const;
		void normalize();
		void reverse();
		void showVector();
		vector reflect(const vector &source,const vector &normal);
		void setVector(float x,float y,float z);
		void setVector(const point &p1,const point &p2);

};

#endif
