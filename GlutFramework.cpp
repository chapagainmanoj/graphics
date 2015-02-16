#include "GlutFramework.h"
//set constants
GLfloat GlutFramework::gProjectionScale=1.f;
const double GlutFramework::FRAME_TIME=1.0/GlutFramework::FPS*1000.0;

	GlutFramework *GlutFramework::instance=NULL;
GlutFramework::GlutFramework(){
	frameTimeElapsed=0;
	title="Yo Sab Kera Ho";
}
//GlutFramework::~GlutFramework(){
//}
void GlutFramework::startFramework(int argc,char *argv[]){
	setInstance();//used in callback wrapper functions
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE |GLUT_DEPTH | GLUT_ALPHA );
	glutInitWindowPosition(X_POSITION,Y_POSITION);
	glutInitWindowSize(WIDTH,HEIGHT);

	window=glutCreateWindow(title.c_str());

	//func callbacks with wrapper
	glutReshapeFunc(reshapeWrapper);
	glutKeyboardFunc(keysWrapper);
	glutDisplayFunc(displayWrapper);
	glutMouseFunc(mouseButtonPressWrapper);
	glutMotionFunc(mouseMoveWrapper);
	//glutIdleFunc(displayWrapper);//program run loop

	//init();//initialize
	glutMainLoop();//start the main glut thread
}
void GlutFramework::load(){
	//subclass and override this method
}
void GlutFramework::display(void){
	//subclass and override this method
}
void GlutFramework::reshape(int width,int height){
	if(height==0)
		height=1;
	float aspectRatio=width/height;
}
void GlutFramework::mouseButtonPress(int button,int state,int x,int y){
	printf("mouseButtonPress: x:%d y:%d \n",x,y);
}
void GlutFramework::mouseMove(int x,int y){
	printf("mouse MOve: x: %d y: %d \n",x,y);
}

// ********Graphics Helper Routines *******
void GlutFramework::setLookAt(float eyeX, float eyeY, float eyeZ,
		float centerX, float centerY, float centerZ,
		float upX, float upY, float upZ){
	eyeVector=vector(eyeX,eyeY,eyeZ);
	centerVector=vector(centerX,centerY,centerZ);
	upVector=vector(upX,upY,upZ);
}
vector GlutFramework::getEyeVector() const{
	return eyeVector;
}
void GlutFramework::setTitle(std::string theTitle){
	title=theTitle;
}
void GlutFramework::setInstance(){
	std::cout<<"glutFramework::SetInstance()"<<std::endl;
	instance=this;
}
void GlutFramework::run(){
}
void GlutFramework::displayFramework(){
	display();
	glutSwapBuffers();
}
void GlutFramework::handleKeys(unsigned char key,int x,int y){
	if(key==27){
		glutDestroyWindow(window);
		exit(0);
	}
}
//********static func in Glut func callbacks*****
void GlutFramework::displayWrapper(){
	instance->displayFramework();
}
void GlutFramework::reshapeWrapper(int width, int height) {
		instance->reshape(width, height);
	}
	
void GlutFramework::runWrapper() {
		instance->run();
	}
	
void GlutFramework::mouseButtonPressWrapper(int button, int state, int x, int y) {
		instance->mouseButtonPress(button, state, x, y);
	}
	
void GlutFramework::mouseMoveWrapper(int x, int y) {
		instance->mouseMove(x, y);
	}
void GlutFramework::keysWrapper(unsigned char key,int x,int y){
	instance->handleKeys(key,x,y);
}
