#include "Control.h"
#include "Position.h"
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <vector>
#include <iostream>



const int  NUM_OF_BIRDS = 140;
const int  NUM_OF_FLOCKS =  7;
const int NUM_OF_BIRDS_PER_FLOCK = NUM_OF_BIRDS / NUM_OF_FLOCKS;
/**
The Following code was customized from a guide given by the TA https://www.badprog.com/c-opengl-setting-up-visual-studio
* glVertex2f(float x, float y).
* The point (0.0, 0.0) represents the middle of the window (not the top left corner).
* The "2f" suffix means 2 values of float type (x and y).
*/
Control control;

void redrawBirds() {
	control.birds;
	for (auto i = 0; i < control.birds.size(); i++) {
		glVertex2f(control.birds[i].position.x, control.birds[i].position.y);                    // bottom left
		glVertex2f(Bird::Size, 0);                    // bottom right
		glVertex2f(Bird::Size, Bird::Size);                    // top right
		glVertex2f(0, Bird::Size);// top left		
	}
	
}

void displayFrame() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);

	for (auto i = 0; i < control.birds.size(); i++) {
		Bird bird = control.birds[i];
		bird.position = Euclidean::Position(2 + i,3,4);
	}
	redrawBirds();             // top left
	glEnd();
	glFlush();
}


void displayLoop(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1024, 768);                    // window size
	glutInitWindowPosition(500, 500);                // distance from the top-left screen
	glutCreateWindow("Boids");						// message displayed on top bar window
	glutDisplayFunc(displayFrame);
	glutMainLoop();

}


void Control::initBirds() {
	FlockNames name = FlockNames::A;

	for (int i = FlockNames::A; i < NUM_OF_FLOCKS; i++) {
		Flock flock(i, i+1, i-1, i); //TODO use weighted mean to set flock position
		for (int j = 0; j < NUM_OF_BIRDS_PER_FLOCK; j++) {
			Bird bird;
			bird.flockName = FlockNames(i);
			this->birds.push_back(bird);
		}
		std::cout << flock.getName() << '\n';

	}
}
Control::Control()
{
	//this->flocks.push_back(Flock());
}


Control::~Control()
{
}



int main(int argc, char** argv) {
	
	control.initBirds();

		displayLoop(argc, argv);
	return 0;
}