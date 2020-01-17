//Aim: Performing 2D TRANSFORMATIONS on objects.
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<stdio.h>
float x,y,z;
void Scale() //Scaling function
{
	glClearColor(0,0,0,0.0); /*specifies red,green,blue and alpha (opacity) values used by glclear to clear the color buffers*/
	glClear(GL_COLOR_BUFFER_BIT);/*performs clear operation on one or more buffers at the same time*/
	glColor3f(1.0,1.0,0.0); // indicates the color for red, green and blue
	glBegin(GL_POLYGON); //Begin the polygon
	glVertex2f(-0.25,-0.25);
	glColor3f(1.0,0.0,0.0); //red color
	glVertex2f(-0.25,0.25);
	glColor3f(0.0,0.0,1.0); //blue color
	glVertex2f(0.25,0.25);//represents triangle
	glEnd();  //End the polygon
	glScalef(x,y,z); //Rotate the object
	glFlush();  // empties all the buffers
}

int main (int argc, char** argv)
{
	printf("Enter x axis"); //taking X axis
	scanf("%f",&x);
	printf("Enter y axis"); //taking Y axis
	scanf("%f",&y);
	printf("Ente z axis"); //taking Z axis
	scanf("%f",&z);

	glutInit(&argc,argv); /*initialize the toolkit*/
	glutInitDisplayMode(GLUT_SINGLE);/*set the display mode*/
	glutInitWindowSize(700,500);//set the window size
	glutInitWindowPosition(300,300);//set the window position on the screen
	glutCreateWindow("Scaling of triangle"); //open window with a title
	glutDisplayFunc(Scale);  //sets display calback for current window
	glutMainLoop(); // Enter the infinite event-processing loop

}
