#include <GL/glut.h>
void renderFunction()
{
glClearColor(0.0,0.0,0.0,0.0); //specifies red,green,blue and alpha (opacity) values used by glclear to clear the color buffers
glClear(GL_COLOR_BUFFER_BIT); //performs clear operation on one or more buffers at the same time
glColor3f(1.0,1.0,0.0); // indicates the color for red, green and blue
glBegin(GL_POLYGON); //Begin the polygon
glVertex2f(-0.5,-0.5); // origin of line with two vertices of float
glVertex2f(-0.5,0.5);	
glVertex2f(0.5,0.5);//represents triangle
glEnd(); //End the polygon.
glFlush();
}
int main (int argc, char** argv)
{
glutInit(&argc,argv); /*initialize the toolkit*/
glutInitDisplayMode(GLUT_SINGLE); /*set the display mode*/
glutInitWindowSize(500,500); //set the window size
glutInitWindowPosition(100,100); //set the window position on the screen
glutCreateWindow("triangle");//will create a window with title triangle
glutDisplayFunc(renderFunction); //Call display function
glutMainLoop(); // Enter the infinite event-processing loop
}
