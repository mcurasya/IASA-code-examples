#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

struct point{
    GLfloat x; 
    GLfloat y;
};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glFlush();
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("function graph");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}
