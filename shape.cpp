#include"shape.h"

shape::shape(){

	setLookAt(0.0,0.0,0.0,1.0,1.0,1.0,0.0,1.0,0.0);
	p1=new point(-1.0f,0.0f,1.0f);
	p2=new point(1.0f,0.0f,1.0f);
}
void shape::display(){
	std::cout<<p1->x<<" "<<p1->y<<" "<<p1->z<<"\t"<<p1->w<<" inital point1"<<std::endl;
	std::cout<<p2->x<<" "<<p2->y<<" "<<p2->z<<"\t"<<p2->w<<" inital point2"<<std::endl;
	toViewCord(p1);
	p1->normalize();
	toViewCord(p2);
	p2->normalize();
	p1->rotatez(45*3.14/180);
	p2->rotatez(45*3.14/180);
	drawLine(p1,p2);
	std::cout<<p1->x<<" "<<p1->y<<" "<<p1->z<<" final point1"<<std::endl;
	std::cout<<p2->x<<" "<<p2->y<<" "<<p2->z<<" final point2"<<std::endl;

	/*
	glRotatef(rtri,0.0f,1.0f,0.0f);
	glBegin(GL_LINES);		   // draw polygon
	glColor3f(1.0f,0.0f,0.0f);	   // red
	//front face
	glVertex3f(0.0f,1.0f,0.0f);	  
	glVertex3f(1.0f,-1.0f,1.0f);	   // right

	glVertex3f(1.0f,-1.0f,1.0f);	  
	glVertex3f(-1.0f,-1.0f,1.0f);	   // bottom 

	glVertex3f(-1.0f,-1.0f,1.0f);	   // left
	glVertex3f(0.0f,1.0f,0.0f);

	//right face
	glVertex3f(0.0f,1.0f,0.0f);	  
	glVertex3f(1.0f,-1.0f,-1.0f);	   // bottom

	glVertex3f(1.0f,-1.0f,-1.0f);	  
	glVertex3f(1.0f,-1.0f,1.0f);	   // bottom 


	//left face
	glVertex3f(0.0f,1.0f,0.0f);	  
	glVertex3f(-1.0f,-1.0f,-1.0f);	   // bottom

	glVertex3f(-1.0f,-1.0f,-1.0f);	  
	glVertex3f(-1.0f,-1.0f,1.0f);	   // bottom 


	//back face
	glVertex3f(-1.0f,-1.0f,-1.0f);	   // left
	glVertex3f(1.0f,-1.0f,-1.0f);

	glEnd();
	rtri+=3.0f;
	*/
}
/*
void shape::reshape(int width,int height){
}*/
void shape::load(){
}
void shape::toViewCord(point *p){
	p->translate(-centerVector.x,-centerVector.y,-centerVector.z);

	//std::cout<<p->x<<" "<<p->y<<" "<<p->z<<" "<<p->w<<"point in toView after translate"<<std::endl;
	eyeVector.showVector();
	centerVector.showVector();
	vector n(eyeVector,centerVector);
	vector V(upVector.x,upVector.y,upVector.z);
	vector u=V.cross(n);
	n.normalize();
	n.showVector();
	u.normalize();
	vector v=n.cross(u);
	//std::cout<<u.x<<'\t'<<u.y<<'\t'<<u.z<<std::endl;
	float rmat[4][4]={{u.x,u.y,u.z,0.0},
		{v.x,v.y,v.z,0.0},
		{n.x,n.y,n.z,0.0},
		{0.0,0.0,0.0,1.0}
	};
	p->transform(rmat);
	//std::cout<<p->x<<" "<<p->y<<" "<<p->z<<" "<<p->w<<"point in toView"<<std::endl;
}
void shape::drawLine(point *p1,point *p2){
	glBegin(GL_LINES);
	glColor3f(1.0,0.0,0.0);
	glVertex3f(p1->x,p1->y,p1->z);
	glVertex3f(p2->x,p2->y,p2->z);
	glEnd();
}
//void handleKeys(unsigned char key ,int x,int y){
