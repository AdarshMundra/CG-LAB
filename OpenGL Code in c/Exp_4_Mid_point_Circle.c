#include<stdio.h>  
#include<GL/glut.h>  
GLint xc,yc,r,sizes=1000;
void myInit(void) // used to set the OpenGL state variables dealing with viewing and attributes
{
    glClearColor(0.0,1.0,1.0,0.0);
    glColor3f(1.0f,0.0f,0.0f);
glPointSize(3.0); // specfies the rasterized diameter of points
    glMatrixMode(GL_PROJECTION);  /// Switches to the Projection matrix
    glLoadIdentity();  //replaces the current matrix with the identity matrix
    gluOrtho2D(0.0,640.0,0.0,480.0);  // Rendering steps in 2D
    glOrtho(-sizes/2,sizes/2,-sizes/2,sizes/2,-1,1);//left,right,bootom,top,near,far
}
void readInput(){         // Function to read input
    printf("Enter xc, yc, radius(resp): ");
    scanf("%i %i %i",&xc,&yc,&r);
}
void setPixel(GLint xcoordinate, GLint ycoordinate)   //For setting pixel
{
    glBegin(GL_POINTS);  //delimit the vertices of a primitive or a group of like primitives
    glVertex2i(xcoordinate,ycoordinate);    //for setting x and y coordinate
    glEnd();
    glFlush();    // For empties all the commands in buffer
}
void draw_in_each_oct(GLint xk,GLint yk, GLint xc,GLint yc){     // For setting pixels in each octant
    setPixel(xc+xk,yc+yk);
    setPixel(xc+yk,yc+xk);
    setPixel(xc-yk,yc+xk);
    setPixel(xc-xk,yc+yk);
    setPixel(xc-xk,yc-yk);
    setPixel(xc-yk,yc-xk);
    setPixel(xc+yk,yc-xk);
    setPixel(xc+xk,yc-yk);
}
void midPtCircle(GLint xc,GLint yc,GLint r)    // For plotting points in circle
{
    GLint pk,xk,yk;
    pk=1-r;
    xk=0;
    yk=r;
    draw_in_each_oct(xk,yk,xc,yc);
    while(xk<=yk)
    {
        if(pk<0)
        {
            xk=xk+1;
            pk=pk+(2*xk)+1;
        }
        else
        {
            xk=xk+1;
            yk=yk-1;
            pk=pk+(2*xk)+1-(2*yk);
        }
        draw_in_each_oct(xk,yk,xc,yc);
    }
}
void Display(void)     // to print the output
{
    glClear(GL_COLOR_BUFFER_BIT);// clear buffer to present value
    midPtCircle(xc,yc,r);
}
int main(int argc,char *argv[])
{
     readInput();// to read the values inserted
glutInit(&argc,argv); // initialize the toolkit
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// specifies whether to use an RGBA or colorindex color model
    glutInitWindowSize(600,600);// in pixels
    glutInitWindowPosition(50,50);// from top-left corner of display
    glutCreateWindow("Mid Point Circle");// create window
    glutDisplayFunc(Display);// sets the display callback for the current window
    myInit();// set the OpenGL state variables dealing with viewing and attributes
    glutMainLoop();// enters the GLUT event processing loop
    return 0;
}
