// OpenGL related includes
#include <GL\glut.h>

// IO includes
#include <iostream>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

int lastMousex = 0;
int lastMousey = 0;

GLfloat currentXRotation = 0.0;
GLfloat currentYRotation = 0.0;

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Set perspective camera information
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Angle of view: 40 degrees
    // Near clipping plane: 0.5
    // Far clipping plane: 20.0
    gluPerspective(20.0, (GLdouble)WIDTH / (GLdouble)HEIGHT, 0.5, 20.0);
    glViewport(0, 0, WIDTH, HEIGHT);
}

void drawScene()
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(0.8f, 0.2f, 0.1f);
    glTranslatef(0.0, 0.0, -4.5);
    glRotatef(currentYRotation, 1.0, 0.0, 0.0);
    glRotatef(currentXRotation, 0.0, 1.0, 0.0);
    glScalef(1.0, 1.0, 1.0);

    glutSolidTeapot(0.1);

    glFlush();
    glutSwapBuffers();
}

void idleCallback()
{

}

void mouseClickCallback(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        lastMousex = x;
        lastMousey = y;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        lastMousex = 0;
        lastMousey = 0;
    }
}

void moveCallback(int x, int y)
{
    int xdiff = x - lastMousex;
    int ydiff = y - lastMousey;

    currentXRotation += xdiff;
    currentXRotation = (int)currentXRotation % 360;
    currentYRotation += ydiff;
    currentYRotation = (int)currentYRotation % 360;

    cout << "rotation status\nx: " << currentXRotation << "\ny: " << currentYRotation << endl;

    lastMousex = x;
    lastMousey = y;

    drawScene();
}

void registerCallbacks()
{
    glutDisplayFunc(drawScene);
//     glutReshapeFunc(reshapeCallback);
    glutIdleFunc(idleCallback);
    glutMouseFunc(mouseClickCallback);
    glutMotionFunc(moveCallback);
}

int main(int argc, char** argv)
{
    // Initialize GLUT, all argmuments sent to program are needed
    glutInit(&argc, argv);
    // double buffering, avoids flickering (swapBuffers technique)
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    // Window size
    glutInitWindowSize(800, 600);
    // Create the window
    glutCreateWindow("Demo - Procedural Building Creation");
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    init();
    registerCallbacks();

    // Start main loop !
    glutMainLoop();
    return 0;
}