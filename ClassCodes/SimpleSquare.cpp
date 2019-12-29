#include <GL/freeglut.h>

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex2f(-.5, -.5);
        glVertex2f(-.5, .5);
        glVertex2f(.5, .5);
        glVertex2f(.5, -.5);
    glEnd();

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutCreateWindow("Simple Square");
    glutDisplayFunc(display);
    glutMainLoop();
}