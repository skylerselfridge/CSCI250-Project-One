// Project 1: Getting Started 
// Programmer: Skyler Selfridge
// Date: 2/13/18 
// String Art Program: Program uses opengl/GLUT to draw simple string art to a window
// various variables can be changed to manipulate the design of the string art
// these include divisions (determines the total number of sections that will be drawn, this MUST BE A EVEN NUMBER)
// STRING_ONE (determines how many strings will be drawn (the number specified - 1) to side one of each section) use 1 instead of 0
// STRING_TWO (determines how many strings will be drawn (the number specified - 1) to side two of each section) use 1 instead of 0

#include <iostream>
#include "glut.h"


#include <stdio.h>
#include <math.h>
#include <vector>
#define PI 3.14159265
const int STRING_ONE = 36; //define number of segments per line to be attached to one another -- side one
const int STRING_TWO = 36; //define number of segments per line to be attached to one another -- side two
int divisions = 6;// define # of divisions must be an even number

float r = .85; //define r




void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);


	for (int i = 0; i < divisions; i++) { //draw triangular divisions
		glColor3f(0.0, 0.0, 1.0);	// blue
		//draw first line
		glVertex2f(0, 0);
		glVertex2f(r*cos(i*(PI / (divisions / 2))), r*sin(i*(PI / (divisions / 2))));
		//draw second line
		glVertex2f(r*cos(i*(PI / (divisions / 2))), r*sin(i*(PI / (divisions / 2))));
		glVertex2f(r*cos((i + 1)*(PI / (divisions / 2))), r*sin((i + 1)*(PI / (divisions / 2))));


		//draw strings for side one ----

		float line_one_seg_x = (r*cos(i * (PI / (divisions / 2)))) / STRING_ONE;
		float line_one_seg_y = (r*sin(i * (PI / (divisions / 2)))) / STRING_ONE;
		//declare arrays to hold x and y coords for first line
		float loxp[STRING_ONE];
		float loyp[STRING_ONE];
		for (int j = 0; j < STRING_ONE; j++) {
			if (j != 0) {
				loxp[j] = loxp[j - 1] + line_one_seg_x;
				loyp[j] = loyp[j - 1] + line_one_seg_y;
			}
			else { //this line always begins at the origin
				loxp[j] = 0 + line_one_seg_x;
				loyp[j] = 0 + line_one_seg_y;
			}
		}

		float line_two_length_x = (r*cos((i + 1)*(PI / (divisions / 2)))) - (r*cos(i * (PI / (divisions / 2))));
		float line_two_length_y = (r*sin((i + 1)*(PI / (divisions / 2)))) - (r*sin(i * (PI / (divisions / 2))));

		float line_two_seg_x = line_two_length_x / STRING_ONE;
		float line_two_seg_y = line_two_length_y / STRING_ONE;

		//declare arrays to hold x and y coords for second line
		float ltxp[STRING_ONE];
		float ltyp[STRING_ONE];
		ltxp[0] = (r*cos(i * (PI / (divisions / 2)))) + line_two_seg_x;
		ltyp[0] = (r*sin(i * (PI / (divisions / 2)))) + line_two_seg_y;
		for (int j = 1; j < STRING_ONE; j++) {

			ltxp[j] = ltxp[j - 1] + line_two_seg_x;
			ltyp[j] = ltyp[j - 1] + line_two_seg_y;
		}

		glColor3f(1.0, 0.0, 0.0);	// red

		for (int j = 0; j < STRING_ONE - 1; j++) {//draw first connections
			glVertex2f(loxp[j], loyp[j]);
			glVertex2f(ltxp[j], ltyp[j]);
		}

		//end draw strings for side one

	}

	for (int i = 0; i < divisions; i++) {// this section was taken out of the main loop to make sure that it would be drawn on top of everything else
		//Draw strings for side two----


		float line_one_seg_x = (r*cos(i * (PI / (divisions / 2)))) / STRING_TWO;
		float line_one_seg_y = (r*sin(i * (PI / (divisions / 2)))) / STRING_TWO;

		//declare arrays to hold x and y coords for first line
		float tloxp[STRING_TWO];
		float tloyp[STRING_TWO];

		for (int j = 0; j < STRING_TWO; j++) {
			if (j != 0) {
				tloxp[j] = tloxp[j - 1] + line_one_seg_x;
				tloyp[j] = tloyp[j - 1] + line_one_seg_y;
			}
			else { //this line always begins at the origin
				tloxp[j] = 0 + line_one_seg_x;
				tloyp[j] = 0 + line_one_seg_y;
			}
		}

		float line_two_length_x;
		float line_two_length_y;

		//second line
		if (i != 0) {
			line_two_length_x = (r*cos((i - 1)*(PI / (divisions / 2)))) - (r*cos(i * (PI / (divisions / 2))));
			line_two_length_y = (r*sin((i - 1)*(PI / (divisions / 2)))) - (r*sin(i * (PI / (divisions / 2))));
		}
		else { // this is the origin so it should be set to the max aka work backwards
			line_two_length_x = (r*cos((divisions - 1)*(PI / (divisions / 2)))) - (r*cos(i * (PI / (divisions / 2))));
			line_two_length_y = (r*sin((divisions - 1)*(PI / (divisions / 2)))) - (r*sin(i * (PI / (divisions / 2))));
		}
		float line_two_seg_x = line_two_length_x / STRING_TWO;
		float line_two_seg_y = line_two_length_y / STRING_TWO;

		//declare arrays to hold x and y coords for second line
		float tltxp[STRING_TWO];
		float tltyp[STRING_TWO];
		tltxp[0] = (r*cos(i * (PI / (divisions / 2)))) + line_two_seg_x;
		tltyp[0] = (r*sin(i * (PI / (divisions / 2)))) + line_two_seg_y;
		for (int j = 1; j < STRING_TWO; j++) {

			tltxp[j] = tltxp[j - 1] + line_two_seg_x;
			tltyp[j] = tltyp[j - 1] + line_two_seg_y;
		}

		glColor3f(0.0, 1.0, 0.0);	// green

		for (int j = 0; j < STRING_TWO - 1; j++) {//draw first connections
			glVertex2f(tloxp[j], tloyp[j]);
			glVertex2f(tltxp[j], tltyp[j]);
		}
	}






	glEnd();
	glFlush();
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutCreateWindow("String Art - Skyler Selfridge");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}