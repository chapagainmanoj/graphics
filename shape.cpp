#include"shape.h"
shape::shape(){
	
shape::rtri=0.0f;
}
point<float> p1(0.0f,1.0f,0.0f);
point<float> p2(1.0f,-1.0f,1.0f);
void shape::display(){

	drawLine(p1,p2);
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
void shape::reshape(int width,int height){
}
void shape::load(){
}
void shape::drawLine(point<float> p1,point<float> p2){
	glBegin(GL_LINES);
	glVertex3f(p1.x,p1.y,p1.z);
	glVertex3f(p2.x,p2.y,p2.z);
	glEnd();
}
//void handleKeys(unsigned char key ,int x,int y){
//}
