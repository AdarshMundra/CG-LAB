#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y1,y2;
void display(void)  //Calling display function
{
	float dy,dx,step,x,y,k,Xin,Yin;
	dx=x2-x1;    // Difference between two end points on X axis
	dy=y2-y1;   // Difference between two end points Y axis
	if(abs(dx)> abs(dy))
	{
		step = abs(dx);  //assigning the values of step
	}
	else
	{
		step = abs(dy);   //assigning the values of steps
	}	
	Xin = dx/step;  //Calculate  Xin
	Yin = dy/step;  //Calculate  Yin

	x= x1;
	y=y1;
	glBegin(GL_POINTS);  // Begin points
	glVertex2i(x,y);   // point of x and y start point
	glEnd(); //End the point.
	for (k=1 ;k<=step;k++) // For initializing points
	{
		x= x + Xin;
		y= y + Yin;
		glColor3f(0,0,100);  // Indicates color
		glBegin(GL_POINTS);   // Begin points

		glVertex2i(x,y);  For drawing points of X and Y
		glEnd();  //End the point.
	}
	glFlush();  // empties all the buffers
}

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0); //specifies red,green,blue and alpha (opacity) values used by glclear to clear the color buffers

	glMatrixMode(GL_PROJECTION);  // Switches to the Projection matrix
	glLoadIdentity();   //replaces current matrix with identity matrix
	gluOrtho2D(-100,100,-100,100);  // for 2D projection matrix
}
int main(int argc, char** argv) 
{
	printf("Enter the value of x1,x2,y1,y2 : ");
	scanf("%f",&x1);
	scanf("%f",&y1);
	scanf("%f",&x2);
	scanf("%f",&y2);    // Taking end points from user
	glutInit(&argc, argv);  // initialize the toolkit
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  // set the display mode
	glutInitWindowSize (500, 500);  // Set window size
	glutInitWindowPosition (100,100);  //set window position on screeen
	glutCreateWindow (" Bresenham's Line Drawing ");  // create window with title
	init(); //Call init function
	glutDisplayFunc(display);  //sets display calback for current window
	glutMainLoop();  // Enter the infinite event-processing loop
	return 0;
}
