#include<gl/GL.h>    
#include<gl/GLU.h>    
#include<gl/glut.h> 
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int h, k, r;
void scanline(int, int);// scanline function defined
void circle(void);//  circle function defined
void Axes(void);// function for axes defined
void display(void) // display function defined
{
	glClear(GL_COLOR_BUFFER_BIT);//clears the buffer
	glColor3f(0.5, 0.0, 1.0); //dark purple
	glBegin(GL_POINTS); //delimit the vertices of a primitive or a group of like primitives

	circle(); //function for circle
	glEnd();
	glFlush(); // For empties all the commands in buffer
}
void scanline(int ax, int by)//run scanline algo
{
	int varx;
	for (varx = h + ax; varx >= (h - ax); varx--)
		glVertex2s(varx, by);
}
void circle(void) // circle function 
{
	double XEnd, J; 
	int i, j;
	XEnd = (r / 1.414);
	for (i = 0; i <= XEnd; i++)
	{
		J = sqrt(r*r - i*i);
		j = (int)(J);
		scanline(i, j); // scanline function
		scanline(j, i);
		scanline(j, -i);
		scanline(i, -j);
	}
	Axes(); // define function for the axes
	glVertex3s(h, k, -25);//specify vertex
}
void Axes(void) // axes function 
{
	int i;
	glColor3f(0.0, 0.0, 0.0); // Black
	for (i = -100; i <= 100; i++)
	{
		glVertex2s(i, 0); //specify the vertex 
		glVertex2s(0, i);
	}
	for (i = -2; i <= 2; i++)
	{
		glVertex2s(95 + i, 4 + i);
		glVertex2s(95 - i, 4 + i);
	}
	for (i = 0; i <= 2; i++)
	{
		glVertex2s(4 + i, 95 + i);
		glVertex2s(4 - i, 95 + i);
		glVertex2s(4, 95 - i);
	}
}
void init(void) // does not return a value to the object that invoked it
{
	glClearColor(1.0, 1.0, 1.0, 1.0);// specify clear values for color objects
	glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);//describes transformation producing parallel effect
}
int main(int argc, char** argv)// the main function defined
{
	glutInit(&argc, argv);//  allows application to get command line arguments and initializes system
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // specifies whether to use an RGBA or colorindex color model

	glutInitWindowSize(640, 480); //  in pixels
	glutInitWindowPosition(0, 0); // from top left corner of display
	printf("Enter the center of circle:\n");//user prompted to enter center of circle
	scanf("%d %d", &h, &k);// reads the center
	printf("Enter the radius:\n");// user prompted to enter radius
	scanf("%d", &r);// reads radius
	glutCreateWindow("Circle : Scanline Filling Method ");// create window
	init();
	glutDisplayFunc(display); sets the display callback for the current window
	glutMainLoop();// enters the GLUT event processing loop
	return 0;
}
