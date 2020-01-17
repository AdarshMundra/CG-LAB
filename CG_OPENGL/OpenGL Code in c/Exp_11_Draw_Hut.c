#include <GL/glut.h>
#include<stdio.h>
void Object()
{
glClearColor(255,255,255,0.0); /*specifies red,green,blue and alpha (opacity) values used by glclear to clear the color buffers*/
glClear(GL_COLOR_BUFFER_BIT);/*performs clear operation on one or more buffers at the same time*/
//glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);/* indicates the clipping value for left, right , bottom, top, nearest and farthest value*/

glBegin(GL_POLYGON);
glColor3f(1.0,0.0,0.0);
glVertex2f(-0.45,0.4);
glVertex2f(-0.6,0.2);
glVertex2f(-0.3,0.2);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0,200,0);
glVertex2f(-0.6,0.2);
glVertex2f(-0.6,-0.2);
glVertex2f(-0.3,-0.2);
glVertex2f(-0.3,0.2);
glEnd();


glBegin(GL_POLYGON);
glColor4f(0,0,200,0);
glVertex2f(-0.3,0.2);
glVertex2f(-0.45,0.4);
glVertex2f(0.05,0.4);
glVertex2f(0.2,0.2);
glEnd();

glBegin(GL_POLYGON);
glColor3f(245,84,0);
glVertex2f(-0.3,-0.2);
glVertex2f(-0.3,0.2);
glVertex2f(0.2,0.2);
glVertex2f(0.2,-0.2);
glEnd();

glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2f(-0.45,0.4);
glVertex2f(-0.6,0.2);
glEnd();

glBegin(GL_LINES);
glVertex2f(-0.6,0.2);
glVertex2f(-0.3,0.2);
glEnd();

glBegin(GL_LINES);
glVertex2f(-0.45,0.4);
glVertex2f(-0.3,0.2);
glEnd();

glBegin(GL_LINES);
glVertex2f(0.05,0.4);
glVertex2f(0.2,0.2);
glEnd();

glBegin(GL_LINES);
glVertex2f(-0.45,0.4);
glVertex2f(0.05,0.4);
glEnd();

glBegin(GL_LINES);
glVertex2f(-0.3,0.2);
glVertex2f(0.2,0.2);
glEnd();

glBegin(GL_LINES);
glVertex2f(-0.6,0.2);
glVertex2f(-0.6,-0.2);
glEnd();

glBegin(GL_LINES);
glVertex2f(-0.6,-0.2);
glVertex2f(-0.3,-0.2);
glEnd();

glBegin(GL_LINES);
glVertex2f(-0.3,-0.2);
glVertex2f(-0.3,0.2);
glEnd();

glBegin(GL_LINES);
glVertex2f(-0.3,-0.2);
glVertex2f(0.2,-0.2);
glEnd();

glBegin(GL_LINES);
glVertex2f(0.2,0.2);
glVertex2f(0.2,-0.2);
glEnd();
glFlush();
}

int main (int argc, char** argv)
{
glutInit(&argc,argv); /*initialize the toolkit*/
glutInitDisplayMode(GLUT_SINGLE);/*set the display mode*/
glutInitWindowSize(700,500);//set the window size
glutInitWindowPosition(300,300);//set the window position on the screen
glutCreateWindow("Hut using lines"); //open window with a title
glutDisplayFunc (Object); // Calling Object function
glutMainLoop();
}
