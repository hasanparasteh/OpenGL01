#include <GL/freeglut.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble size = 1;

void display(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    glTranslatef(0.0, 0.0, -4.5);
    // Red color used to draw.
    glColor3f(0.8, 0.2, 0.1);
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated, 1.0, 0.0, 0.0);
    // rotation about Y axis
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    // rotation about Z axis
    glRotatef(zRotated, 0.0, 0.0, 1.0);
    glScalef(1.0, 1.0, 1.0);
    glutSolidTeapot(size);
    // Flush buffers to screen
    glFlush();
}

void reshapeFunc(int x, int y)
{
    if (y == 0 || x == 0)
        return; //Nothing is visible then, so return
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0

    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
    glViewport(0, 0, x, y); //Use the whole window for rendering
}

void idleFunc(void)
{
    yRotated += 0.01;
    display();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    //double buffering used to avoid flickering problem in animation
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 350);
    
    glutCreateWindow("Teapot Rotating Animation");
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    xRotated = yRotated = zRotated = 30.0;
    xRotated = 33;
    yRotated = 40;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //Assign  the function used in events
    glutDisplayFunc(display);
    glutReshapeFunc(reshapeFunc);
    glutIdleFunc(idleFunc);
    
    glutMainLoop();
    return 0;
}