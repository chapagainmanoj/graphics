#include"shape.h"
shape::shape(){
	
shape::rtri=0.0f;
}
void shape::display(){
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
}
void shape::reshape(int width,int height){
}
void shape::load(){
}
//void handleKeys(unsigned char key ,int x,int y){
//}
