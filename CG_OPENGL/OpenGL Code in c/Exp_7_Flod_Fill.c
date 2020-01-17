#include<Windows.h>    
#include<gl/GL.h>    
#include<gl/GLU.h>    
#include<gl/glut.h> 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int ww = 640, wh = 480;
float bgCol[3] = { 1.0, 0.0, 0.0 };   //set background color
float intCol[3] = { 0.0, 0.0, 0.0 };
float fillCol[3] = { 0.4, 0.0, 0.0 };
void setPixel(int pointx, int pointy, float f[3])//set pixel with user defined color
{
	glBegin(GL_POINTS);
	glColor3fv(f);
	glVertex2i(pointx, pointy);
	glEnd();
	glFlush();
}
void getPixel(int x, int y, float pixels[3])//returns color of pixel
{
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, pixels);//read block of pixels from frame buffer
}
void drawPolygon(int x1, int y1, int x2, int y2)//draws a closed polygon defined by arrays of x and y coordinates
	glColor3f(0.0, 0.0, 0.0);
glBegin(GL_POLYGON);
	glVertex2i(x1, y1);
	glVertex2i(x1, y2);
	glVertex2i(x2, y2);
	glVertex2i(x2, y1);
	glEnd();
	glFlush();
}
void display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
//If you modify following values, u should change condition in mouse() also
	drawPolygon(150, 250, 200, 300);
	glFlush();
}
void floodfill4(int x, int y, float oldcolor[3], float newcolor[3])//filling using floodfill
{
	float color[3];
	getPixel(x, y, color);
	if (color[0] == oldcolor[0] && (color[1]) == oldcolor[1] && (color[2]) == oldcolor[2])
	{
		setPixel(x, y, newcolor);
		floodfill4(x + 1, y, oldcolor, newcolor);
		floodfill4(x - 1, y, oldcolor, newcolor);
		floodfill4(x, y + 1, oldcolor, newcolor);
		floodfill4(x, y - 1, oldcolor, newcolor);
	}
}
void mouse(int btn, int state, int x, int y)
{         //This check is based on size of the polygon mentioned in display() function
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		int xi = x;
		int yi = (wh - y);
		floodfill4(xi, yi, intCol, fillCol);
	}
}
void myinit()//set state variables 
{
	glViewport(0, 0, ww, wh);//specify width and height of viewport
	glMatrixMode(GL_PROJECTION);//speicfy which matrix is current matrix
	glLoadIdentity();//replace current matrix with identity matrix
	gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)wh);//set up 2d orthographic viewing region
	glMatrixMode(GL_MODELVIEW);//specify which matrix stack is target for subsequent matrix operations
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  // set the display mode	glutInitWindowSize(ww, wh); // set window size
	glutCreateWindow("Flood-Fill-Recursive"); // Create window with title
	glutDisplayFunc(display);  //sets display call-back for current window
	myinit();
	glutMouseFunc(mouse);  // sets the mouse callback for the current window
	glutMainLoop();
	return 0;
}
glutInit(&argc, argv);  // initialize the toolkit
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  // set the display mode
	glutInitWindowSize (500, 500);   //set window size
	glutInitWindowPosition (100,100);  //set window position on screen
	glutCreateWindow ("Flood fill algo.");  //create window with title
	init();	
	glutDisplayFunc(display);   //sets display call-back for current window
	glutMainLoop();
	return 0;
}
