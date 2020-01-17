//EXPERIMENT 16
//Aim: Open Ended Programs in Opengl 
#include <GL/glut.h> /* Initialize OpenGL Graphics */
GLfloat angle= 0.0;
void spin (void)
{
    angle+= 1.0;
    glutPostRedisplay();//marks the current window as needing to be redisplayed.
}

void display(void)//Dispaly function
{
    glClear (GL_COLOR_BUFFER_BIT);// Clear the color buffer with current clearing color
    glLoadIdentity (); // replace the current matrix with the identity matrix
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//define a viewing transformation
    glRotatef(angle, 1, 0, 0); //Rotate around X axis
    glRotatef(angle, 0, 1, 0);//Rotate around Y axis
    glRotatef(angle, 0, 0, 1);//Rotate around Z axis
    glutWireCube(2.0);//render a solid or wireframe cube respectively.
    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei)w, (GLsizei)h);//set the viewport
    glMatrixMode (GL_PROJECTION);// Switches to the Projection matrix
    glLoadIdentity ();//replaces current matrix with identity matrix
    gluPerspective (60, (GLfloat) w / (GLfloat) h, 1.0, 100.0);//set up a perspective projection matrix
    glMatrixMode (GL_MODELVIEW);// Switches to the Projection matrix
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);// Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // added line pg35
    glutInitWindowSize (500, 500);// Set the window's initial width & height
    glutInitWindowPosition (100, 100);// Position the window's initial top-left corner
    glutCreateWindow ("Roataion of cube smooth cube");// Create window with the given title
    glutDisplayFunc(display);// Register callback handler for window re-paint event
    glutReshapeFunc(reshape);//Reshapes the screen Window
    glutIdleFunc(spin);//sets the global idle callback.
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
