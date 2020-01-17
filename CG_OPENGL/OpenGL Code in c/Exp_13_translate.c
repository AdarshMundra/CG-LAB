#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<stdio.h>
float x,y,z;
void Translate() // Translate function
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
	glTranslatef(x,y,0.1f); //Translate the object
	glFlush();  // empties all the buffers
}

int main (int argc, char** argv)
{
	printf("Enter x axis"); //taking X axis
	scanf("%f",&x);
	printf("Enter y axis"); //taking Y axis
	scanf("%f",&y);

	glutInit(&argc,argv); /*initialize the toolkit*/
	glutInitDisplayMode(GLUT_SINGLE);/*set the display mode*/
	glutInitWindowSize(700,500);//set the window size
	glutInitWindowPosition(300,300);//set the window position on the screen
	glutCreateWindow("Trasnlate"); //open window with a title
	glutDisplayFunc(Translate);  //sets display calback for current window
	glutMainLoop(); // Enter the infinite event-processing loop

}
