//----------------------------------------------------------------------
// bouncingball.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <math.h>
#include <GL/glut.h>

#define RADIUS 0.05
#define DT 20000

// Global variables for ball position and velocity
float rx = 0.480;
float ry = 0.860;
float vx = 0.015;
float vy = 0.023;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5); // Gray background

    // Update position
    if (fabs(rx + vx) + RADIUS > 1.0) {
        vx = -vx;
    }
    if (fabs(ry + vy) + RADIUS > 1.0) {
        vy = -vy;
    }
    rx += vx;
    ry += vy;

    // Draw the ball
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0); // Red ball
    glVertex2f(rx, ry);
    for (int i = 0; i <= 100; i++) {
        float angle = 2 * M_PI * i / 100;
        glVertex2f(rx + RADIUS * cos(angle), ry + RADIUS * sin(angle));
    }
    glEnd();

    glutSwapBuffers();
    usleep(DT);
    glutPostRedisplay();
}

void init() {
    glClearColor(0.5, 0.5, 0.5, 1.0); // Gray background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Bouncing Ball");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

// Compile and run:
// gcc -o 26_bouncingball 26_bouncingball.c -lGL -lGLU -lglut -lm
// ./26_bouncingball
