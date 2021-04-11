#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
int windowWidth=1000, windowHeight=1000;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void triangle(void)
{
    glBegin(GL_TRIANGLES);


    glColor3f(1.0,1.0,1.0);
    glVertex2f(2.0,2.0);

    glColor3f(1.0,1.0,1.0);
    glVertex2f(2.0,0.0);

    glColor3f(1.0,1.0,1.0);
    glVertex2f(0.0,0.0);

    glEnd();

}

void rectangle(void)
{
    glBegin(GL_POLYGON);


    glColor3f(1.0,0.0,0.0);
    glVertex2f(0.0,0.0);

    glColor3f(1.0,0.0,0.0);
    glVertex2f(2.0,0.0);

    glColor3f(0.0,1.0,0.0);
    glVertex2f(2.0,1.0);

    glColor3f(0.0,1.0,0.0);
    glVertex2f(0.0,1.0);

    glEnd();
}
double Txval=0,Tyval=0;
void dsply(void)
{

}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glViewport(250,250,500,500);

    glPushMatrix();
    glTranslatef(-1.5,0,0);
    rectangle();
    glPopMatrix();


    /**
        glPushMatrix();
        glTranslatef(5,0,0);
        glRotatef(45,0,0,1);
        triangle();
        glPopMatrix();
    **/

    glFlush();
    glutSwapBuffers();
}
double rotation =0.05;
void display2(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glViewport(0, 0,500,500);

    glPushMatrix();
    glRotatef(rotation,0,0,1);
    triangle();
    glPopMatrix();


    glFlush();
    glutSwapBuffers();
}



void drawcube()
{
    glBegin(GL_QUADS);

    glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);


      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);


      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);


      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);


      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);


      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();

}


void reshape(GLsizei width, GLsizei height) {

   if (height == 0) height = 1;
   GLfloat aspect = (GLfloat)width / (GLfloat)height;


   glViewport(0, 0, width, height);


   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}





















void display3(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);


   glLoadIdentity();
   glRotatef(rotation,10,10,-10);
   glTranslatef(1.5f, 0.0f, -7.0f);

    glPushMatrix();
    drawcube();
    glPopMatrix();




    glFlush();
    glutSwapBuffers();
}


bool flagScale=false;
void animate()
{

    if (flagScale == true)
    {
        rotation+= 0.5;
        if(rotation > 359)
            rotation = 0.5;
    }
    glutPostRedisplay();

}

void myKeyboardFunc( unsigned char key, int x, int y )
{

    switch ( key )
    {
    case '1':
        glutDisplayFunc(display);
        break;
    case '2':
        glutDisplayFunc(display2);
        break;
    case '3':
        glutDisplayFunc(display3);
        break;
    case 'r':
        flagScale=true;
        break;
    case 'b':
        flagScale=false;
        break;
    case 27: // Escape key
        exit(1);
    }
    glutPostRedisplay();

}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Traingle-Demo");
    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glutDisplayFunc(dsply);
    glutKeyboardFunc(myKeyboardFunc);
    glutIdleFunc(animate);
    glutReshapeFunc(reshape);
    initGL();
    glutMainLoop();
    return 0;
}
