#include "shape.h"
shape::shape(){
        //rtri=0.0;

	setLookAt(1.0,0.0,2.0,0.0,0.0,0.0,0.0,1.0,0.0);
	
        b=new object();

        p1=new point(1.0f,1.0f,-1.0f);
	p2=new point(1.0f,-1.0f,-1.0f);
	p3=new point(-1.0f,-1.0f,1.0f);
	p4=new point(1.0f,-1.0f,1.0f);
	toViewCord(p1);
	toViewCord(p2);
	toViewCord(p3);
	toViewCord(p4);
	pptiveProjxn(p1,zvp,zprp);
	pptiveProjxn(p2,zvp,zprp);
	pptiveProjxn(p3,zvp,zprp);
	pptiveProjxn(p4,zvp,zprp);

        b->vTable(*p1);
        b->vTable(*p2);
        b->vTable(*p3);
        b->vTable(*p4);

        edge *e1,*e2,*e3,*e4;
        e1=new edge(p1,p2);
        e2=new edge(p2,p3);
        e3=new edge(p3,p4);
        e4=new edge(p4,p1);
        b->eTable(*e1);
        b->eTable(*e2);
        b->eTable(*e3);       
        b->eTable(*e4);

	zvp=-1;zprp=6;

}
void shape::display(){

        //rtri+=5.0;
        b->draw();
        b->showETable();
        b->showVTable();
        point *color1=new point(0.0,1.0,0.0);
        point *color2=new point(1.0,1.0,0.0);
        point *color3=new point(0.0,0.0,1.0);
        //triangleFill(p1,p2,p3,color1);
        //triangleFill(p1,p3,p4,color2);

/*
        triangleFill(p1,p3,p5,color3);
        triangleFill(p1,p2,p4,color1);
        triangleFill(p1,p4,p5,color2);
        triangleFill(p1,p2,p3,color2);

	*/
}
/*
void shape::reshape(int width,int height){
}*/
void shape::load(){
}

void shape::triangleFill(point *p1,point *p2,point *p3,point *color){
	point *a,*b,*c;
        
	//sorting according to highest value of y
	if(p1->y>p2->y){
		if(p1->y>p3->y){
			a=p1;
			if(p2->y>p3->y){
				b=p2;
				c=p3;
			}
			else{
				b=p3;
				c=p2;
			}
		}
		else{
			a=p3;
			b=p1;
			c=p2;

		}
	}
	else{
		if(p2->y>p3->y){
			a=p2;
			if(p1->y>p3->y){
				b=p1;
				c=p3;
			}
			else{
				b=p3;
				c=p1;
			}
		}
		else{
			a=p3;
			b=p2;
			c=p1;
		}
	}
	float slopeAB=(b->y-a->y)/(b->x-a->x);//paxi hataula 
        float slopeAC=(c->y-a->y)/(c->x-a->x);
        float slopeBC=(c->y-b->y)/(c->x-b->x);
        float x1=a->x,x2=a->x;
        float y=a->y;
        while(y-c->y>=0.004){
                y-=0.004;
                x1-=0.004/slopeAC;
                if(y<=b->y){    //for bc line
                        slopeAB=slopeBC;
                        //x2=b->x;
                }
                x2-=0.004/slopeAB;
                glBegin(GL_LINES);
                glColor3f(color->x,color->y,color->z);
                glVertex2f(x1,y);
                glVertex2f(x2,y);
                glEnd();
        }
}
void shape::toViewCord(point *p){
	p->translate(-centerVector.x,-centerVector.y,-centerVector.z);

	vector n(eyeVector,centerVector);
	vector V(upVector.x,upVector.y,upVector.z);
	vector u=V.cross(n);
	n.normalize();
	u.normalize();
	vector v=n.cross(u);
	float rmat[4][4]={{u.x,u.y,u.z,0.0},
		{v.x,v.y,v.z,0.0},
		{n.x,n.y,n.z,0.0},
		{0.0,0.0,0.0,1.0}
	};
	p->transform(rmat);
	p->normalize();
}
void shape::pptiveProjxn(point *p,float zvp,float zprp){
	float dp=zprp-zvp;
	float pmat[4][4]={{1,0,0,0},
			{0,1,0,0},
			{0,0,-zvp/dp,zvp*(zprp/dp)},
			{0,0,-1/dp,zprp/dp}
	};
	p->multMat(pmat);
	p->x /=p->w;
	p->y /=p->w;
	p->z /=p->w;
	p->w /=p->w;
	
}
void shape::drawLine(point *p1,point *p2){
	glBegin(GL_LINES);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(p1->x,p1->y);
	glVertex2f(p2->x,p2->y);
	glEnd();
}
