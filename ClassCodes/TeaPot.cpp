#include <GL/freeglut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
    glutWireTeapot(2.0);
    glFlush();
}
void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3ub(0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Orthographic Projection");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}