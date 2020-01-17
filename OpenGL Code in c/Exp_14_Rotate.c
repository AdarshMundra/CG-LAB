#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<stdio.h>
float r;
void Rotation() //Rotation function
{
	glClearColor(0,0,0,0.0); /*specifies red,green,blue and alpha (opacity) values used by glclear to clear the color buffers*/
	glClear(GL_COLOR_BUFFER_BIT);/*performs clear operation on one or more buffers at the same time*/
	glColor3f(1.0,1.0,0.0); // indicates the color for red, green and blue
	glBegin(GL_POLYGON); //Begin the polygon
	glVertex2f(-0.5,-0.5);
	glColor3f(1.0,0.0,0.0); //red color
	glVertex2f(-0.5,0.5);
	glColor3f(0.0,0.0,1.0); //blue color
	glVertex2f(0.5,0.5);//represents triangle
	glEnd();  //End the polygon
	glRotatef(r,0.1f, 0.1f, 0.1f); //Rotate the object
	glFlush();  // empties all the buffers
}

int main (int argc, char** argv)
{
	printf("Enter angle of rotaion"); //taking angle of rotation
	scanf("%f",&r);

	glutInit(&argc,argv); /*initialize the toolkit*/
	glutInitDisplayMode(GLUT_SINGLE);/*set the display mode*/
	glutInitWindowSize(700,500);//set the window size
	glutInitWindowPosition(300,300);//set the window position on the screen
	glutCreateWindow("Hut using point"); //open window with a title
	glutDisplayFunc(Rotation);  //sets display calback for current window
	glutMainLoop(); // Enter the infinite event-processing loop
}
