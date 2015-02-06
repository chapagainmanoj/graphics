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

	init();//initialize
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

	//glViewport(0,0,(GLsizei)width,(GLsizei)height);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluPerspective(45.0f,aspectRatio,0.1f,100.0f);
	//glMatrixMode(GL_MODELVIEW);
}
void GlutFramework::mouseButtonPress(int button,int state,int x,int y){
	printf("mouseButtonPress: x:%d y:%d \n",x,y);
}
void GlutFramework::mouseMove(int x,int y){
	printf("mouse MOve: x: %d y: %d \n",x,y);
}
// ********Graphics Helper Routines *******
void GlutFramework::setDisplayMatricies(){
	int width=glutGet(GLUT_WINDOW_WIDTH);
	int height=glutGet(GLUT_WINDOW_HEIGHT);
	float aspectRatio=width/height;
	//glViewport(0,0,width,height);
	//initilize matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(0.0,WIDTH,HEIGHT,0.0,1.0,-1.0);
	gluPerspective(45.0f,aspectRatio,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void GlutFramework::setupLights(){
	GLfloat light1_position[] = { 0.0, 1.0, 1.0, 0.0 };
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat ambient_light[] = { 0.8, 0.8, 0.8, 1.0 };
	
	glLightfv( GL_LIGHT0, GL_POSITION, light1_position );
	glLightfv( GL_LIGHT0, GL_AMBIENT, ambient_light );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, white_light );
	glLightfv( GL_LIGHT0, GL_SPECULAR, white_light );
	
	glLightModelfv( GL_LIGHT_MODEL_AMBIENT, lmodel_ambient );
}

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
// GLut SetUp functions
void GlutFramework::init(){

	//glClearColor(0.0,0.0,0.0,0.0); //black
	//glClearDepth(1.0);
	//glDepthFunc(GL_LESS);
	//glShadeModel(GL_SMOOTH);
	//glEnable(GL_DEPTH_TEST); // it does the stuff

	//setDisplayMatricies();	 //sets matrix identity

	//load();
}
void GlutFramework::setInstance(){
	std::cout<<"glutFramework::SetInstance()"<<std::endl;
	instance=this;
}
void GlutFramework::run(){
}
void GlutFramework::displayFramework(){
	//glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	//setupLights();
	//setDisplayMatricies();
	//glTranslatef(0.f,0.f,-5.0f);
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
