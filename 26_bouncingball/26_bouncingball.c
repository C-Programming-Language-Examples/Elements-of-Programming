//----------------------------------------------------------------------
// 26_bouncingball.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <GL/glut.h>

#define RADIUS 0.05
#define DT 20000

static float rx = 0.480;
static float ry = 0.860;
static float vx = 0.015;
static float vy = 0.023;

// Initializes the OpenGL environment
static void initGL(void) {
    glClearColor(0.5, 0.5, 0.5, 1.0); // Gray background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

static void updatePosition(void) {
    if (fabs(rx + vx) + RADIUS > 1.0) vx = -vx;
    if (fabs(ry + vy) + RADIUS > 1.0) vy = -vy;
    rx += vx;
    ry += vy;
}

static void drawBall(const float x, const float y) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0); // Red ball
    glVertex2f(x, y);
    for (int i = 0; i <= 100; i++) {
        const float angle = 2 * M_PI * i / 100;
        glVertex2f(x + RADIUS * cos(angle), y + RADIUS * sin(angle));
    }
    glEnd();
}

static void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    updatePosition();
    drawBall(rx, ry);
    glutSwapBuffers();
    usleep(DT);
    glutPostRedisplay();
}

int main(void) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Bouncing Ball");
    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

// Compile and run:
// gcc -o 26_bouncingball 26_bouncingball.c -lGL -lGLU -lglut -lm
// ./26_bouncingball
