#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y1,y2;
void display(void){
	float dy,dx,step,x,y,k,Xin,Yin,p0,x_end;
	dx=abs(x2-x1);
	dy=abs(y2-y1);  // Calculate the value of constants dx, dy, 2dy, and (2dy – 2dx)
	p0 = 2*dy-dx;  //get the first value for the decision parameter
	Xin = 2*dx;
	Yin=2*(dy-dx);
	if(x1>x2){
		x=x2;
		y=y2;
		x_end=x1;
	}
	else{
		x=x1;   // For getting all points along the line
		y=y1;
		x_end=x2;	
	}
	glBegin(GL_POINTS);  // Begin points
	glVertex2i(x,y);
	glEnd();
	while (x<x_end){            // For initializing points

		x=x+1;
		if(p0<0){
			p0=p0+Xin;
		}
		else{
			y=y+1;
			p0=p0+Yin;
		}
		glBegin(GL_POINTS); //begin the points
		glVertex2i(x,y);
		glEnd();//end the points
	}
	glFlush(); //clear the buffer
}
void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);  // Switches to the Projection matrix
	glLoadIdentity();        //replaces current matrix with identity matrix
	gluOrtho2D(-100,100,-100,100);  // for 2D projection matrix
}
int main(int argc, char** argv) {
	printf("Enter the value of x1,y1,x2,y2 : ");
	scanf("%f",&x1);
	scanf("%f",&y1);
	scanf("%f",&x2);
	scanf("%f",&y2);  //getting points from user
	glutInit(&argc, argv);  // initialize the toolkit
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  // set the display mode
	glutInitWindowSize (500, 500);   //set window size
	glutInitWindowPosition (100,100);  //set window position on screen
	glutCreateWindow ("DDA Line Algo");  //create window with title
	init();	
	glutDisplayFunc(display);   //sets display call-back for current window
	glutMainLoop();
	return 0;
}
