#ifndef GLUT_FRAMEWORK_H
#define GLUT_FRAMEWORK_H
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<stdio.h>
#include<iostream>
#include<string.h>

class GlutFramework{
	private:
		double frameTimeElapsed;
	protected:
		std::string title;
		static GlutFramework *instance;
		int window;

	public:
		//constants
		const static int FPS=60;
		const static int WIDTH=640;
		const static int HEIGHT=480;
		const static int X_POSITION=100;
		const static int Y_POSITION=100;
		const static double FRAME_TIME;
		static GLfloat gProjectionScale;


		GlutFramework();
		//virtual ~GlutFramework();
		void startFramework(int argc, char *argv[]);
		virtual void load();
		virtual void display();
		virtual void reshape(int width,int height);
		virtual void mouseButtonPress(int button,int state,int x,int y);
		virtual void mouseMove(int x,int y);
		virtual void handleKeys(unsigned char key,int x,int y);
		void setDisplayMatricies();
		void setupLights();
		void setTitle(std::string theTitle);
		void init();
		void setInstance();
		void run();
		void displayFramework();
		//static function - that are passed to glut func callbacks
		static void displayWrapper();
		static void reshapeWrapper(int width,int heitht);
		static void runWrapper();
		static void keysWrapper(unsigned char key,int x,int y);
		static void mouseButtonPressWrapper(int button,int state,int x,int y);
		static void mouseMoveWrapper(int x,int y);
};

#endif
