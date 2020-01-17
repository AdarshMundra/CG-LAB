#include<gl/glut.h> 
#include <math.h>
#include <stdio.h>

float xc;
float yc;
float rx;
float ry;

void Init(void){
	glClearColor(1.0, 1.0, 1.0, 0.0); //Background Color
	glColor3f(0.0f, 0.0f, 0.0f); //Black Color
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0); //Coordinate System
}

void putpixel(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void axes(void){
	glBegin(GL_LINES);
	glVertex2i(-500, 0);
	glVertex2i(500, 0);
	glVertex2i(0, 500);
	glVertex2i(0, -500);
	glEnd();
}
void ellipse(){
	int x, y, p;
	x = 0;
	y = ry;
	p = (ry*ry) - (rx*rx*ry) + ((rx*rx) / 4);
	while ((2 * x*ry*ry)<(2 * y*rx*rx))
	{
		putpixel(xc + x, yc - y);
		putpixel(xc - x, yc + y);
		putpixel(xc + x, yc + y);
		putpixel(xc - x, yc - y);
		if (p<0)
		{
			x = x + 1;
			p = p + (2 * ry*ry*x) + (ry*ry);
		}
		else
		{
			x = x + 1;
			y = y - 1;
			p = p + (2 * ry*ry*x + ry*ry) - (2 * rx*rx*y);
		}
	}
	p = ((float)x + 0.5)*((float)x + 0.5)*ry*ry + (y - 1)*(y - 1)*rx*rx - rx*rx*ry*ry;
	while (y >= 0)
	{
		putpixel(xc + x, yc - y);
		putpixel(xc - x, yc + y);
		putpixel(xc + x, yc + y);
		putpixel(xc - x, yc - y);
		if (p>0)
		{
			y = y - 1;
			p = p - (2 * rx*rx*y) + (rx*rx);
		}
		else
		{
			y = y - 1;
			x = x + 1;
			p = p + (2 * ry*ry*x) - (2 * rx*rx*y) - (rx*rx);
		}
	}
}
void myDisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 1.0);
	glPointSize(1.0);
	ellipse();
	glFlush();
}
int main(int argc, char** argv){
	printf("Enter the coordinates of the centre of the ellipse: \n");
	scanf("%f%f", &xc, &yc);
	printf("Enter the radius of the x-axis and y-axis: \n");
	scanf("%f%f", &rx, &ry);
	glutInit(&argc, argv); // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
	glutInitWindowSize(640, 480); // Set window size
	glutInitWindowPosition(0, 0); //set window position on screeen
	glutCreateWindow("Ellipse"); // create window with title
	Init();//Call init function
	glutDisplayFunc(myDisplay); //sets display calback for current window
	glutMainLoop(); // Enter the infinite event-processing loop
	return 0;
}
