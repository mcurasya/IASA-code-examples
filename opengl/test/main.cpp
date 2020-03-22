#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //I
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.1);
    glVertex2f(-0.7, 0.1);
    glVertex2f(-0.7, 0.3);
    glVertex2f(-0.3, 0.3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.7);
    glVertex2f(-0.7, 0.7);
    glVertex2f(-0.7, 0.9);
    glVertex2f(-0.3, 0.9);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, 0.3);
    glVertex2f(-0.6, 0.3);
    glVertex2f(-0.6, 0.7);
    glVertex2f(-0.4, 0.7);
    glEnd();
    //top A
    glBegin(GL_POLYGON);
    glVertex2f(.1, .1);
    glVertex2f(.8, .1);
    glVertex2f(.5, .9);
    glVertex2f(.4, .9);
    glEnd();
    glColor3f(.0, .0, .0);
    glBegin(GL_POLYGON);
    glVertex2f(.3, .1);
    glVertex2f(.4, .4);
    glVertex2f(.5, .4);
    glVertex2f(.6, .1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(.4, .5);
    glVertex2f(.5, .5);
    glVertex2f(.45, .7);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    //bottom A
    glBegin(GL_POLYGON);
    glVertex2f(.1, -.1);
    glVertex2f(.8, -.1);
    glVertex2f(.5, -.9);
    glVertex2f(.4, -.9);
    glEnd();
    glColor3f(.0, .0, .0);
    glBegin(GL_POLYGON);
    glVertex2f(.3, -.1);
    glVertex2f(.4, -.4);
    glVertex2f(.5, -.4);
    glVertex2f(.6, -.1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(.4, -.5);
    glVertex2f(.5, -.5);
    glVertex2f(.45, -.7);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    //S
    glRectf(-.1, -.1, -.9, -.9);
    glColor3f(.0, .0, .0);
    glRectf(-.1, -.3, -.7, -.4);
    glRectf(-.3, -.6, -.9, -.7);
    glColor3f(1.0, 1.0, 1.0);
    glFlush();
}
 
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(display);
    #ifdef __APPLE__
    glutReshapeWindow(400, 300);
    #endif
    glutMainLoop();
    return 0;
}   
