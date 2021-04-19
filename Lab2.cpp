#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>

double Txval=0,Tyval=0,Tzval=0;
double windowHeight=700, windowWidth=700;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
GLboolean bRotate = true, uRotate = false;
GLfloat angle = 0;
GLUquadricObj *qobj;

static GLfloat v_cube[8][3] =
{
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 2.0},
    {2.0, 0.0, 2.0},
    {2.0, 0.0, 0.0},
    {0,2,0},
    {0,2,2},
    {2,2,2},
    {2,2,0}

};

static GLubyte quadIndices[6][4] =
{
    {4,5,6,7},
    {1,2,6,5},
    {3,2,6,7},
    {0,3,7,4},
    {0,1,2,3},
    {0,1,5,4}
};


static GLfloat colors[7][3] =
{
    {0.0, 0.0, 1.0},
    {0.5, 0.0, 1.0},
    {0.0, 1.0, 0.0},
    {0.0, 1.0, 1.0},
    {0.8, 0.0, 0.0},
    {0.0, 1.0, 0.8},
    {0.8, 0.8, 0.0}
};



static void getNormal3p
(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}



void drawCube(float col_a,float col_b,float col_c)
{
    ///glColor4f(col_a,col_b,col_c,0);


    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        ///glColor3f(colors[i][0],colors[i][1],colors[i][2]);
        glColor3f(col_a - i*0.03, col_b - i*0.03, col_c - i*0.03);
        ///glColor3f(col_a,col_b,col_c);
        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);
    }
    glEnd();


}

void window()
{

    glPushMatrix();
    glTranslatef(-4.9,2.5,-1.5);
    glScalef(0.35,2,0.1);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.9,2.5,-4.2);
    glScalef(0.35,2,0.1);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.9,6.1,-4.2);
    glScalef(0.35,0.2,1.45);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.9,2.3,-4.2);
    glScalef(0.35,0.2,1.45);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.4,5.4,-4.2);
    glScalef(0.05,0.05,1.45);
    drawCube(.2,.2,.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.4,4.4,-4.2);
    glScalef(0.05,0.05,1.45);
    drawCube(.2,.2,.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.4,3.4,-4.2);
    glScalef(0.05,0.05,1.45);
    drawCube(.2,.2,.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.4,2.6,-2.9);
    glScalef(0.05,1.9,0.05);
    drawCube(.2,.2,.2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-4.9,2.5,-4);
    glScalef(0.25,2,1.3);
    drawCube(1,1,1);
    glPopMatrix();

}

void window2()
{

    glPushMatrix();
    glTranslatef(5,2,-4.9);
    glScalef(0.1,2,0.35);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7.5,2,-4.9);
    glScalef(0.1,2,0.35);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,6,-4.9);
    glScalef(1.35,0.1,0.35);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,2,-4.9);
    glScalef(1.35,0.1,0.35);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,3,-4.9);
    glScalef(1.35,0.05,0.3);
    drawCube(0.2,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,4,-4.9);
    glScalef(1.35,0.05,0.3);
    drawCube(0.2,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,5,-4.9);
    glScalef(1.35,0.05,0.3);
    drawCube(0.2,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.25,2,-4.9);
    glScalef(0.07,2,0.3);
    drawCube(0.2,0.2,0.2);
    glPopMatrix();




    glPushMatrix();
    glTranslatef(5,2,-4.9);
    glScalef(1.3,2,0.25);
    drawCube(1,1,1);
    glPopMatrix();
}

void fanparts()
{
    glPushMatrix();
    ///glRotatef(theta,0,1,0);
    ///glRectf(-1, -1, 1, 1);


    glTranslatef(2,6.5,0);
    glScalef(0.25,0.1,0.25);
    drawCube(0.1,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    ///glRotatef(theta,0,1,0);
    glTranslatef(2,6.55,0);
    glScalef(1,0.001,0.25);
    drawCube(0.1,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    ///glRotatef(theta,0,1,0);
    glTranslatef(2,6.55,0);
    glScalef(0.25,0.001,1);
    drawCube(0.1,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    ///glRotatef(theta,0,1,0);
    glTranslatef(1,6.55,0);
    glScalef(1,0.001,0.25);
    drawCube(0.1,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    ///glRotatef(theta,0,1,0);
    glTranslatef(2,6.55,-1);
    glScalef(0.25,0.001,1);
    drawCube(0.1,0.2,0.2);
    glPopMatrix();
}

/**
void ownTranslatef(GLfloat dx, GLfloat dy, GLfloat dz){

	GLfloat m[16];

	m[0] = 1;	m[4] = 0;  	 m[8] = 0;   	m[12] = dx;
	m[1] = 0; 	m[5] = 1; 	 m[9] = 0;   	m[13] = dy;
	m[2] = 0; 	m[6] = 0;	 m[10] = 1; 	m[14] = dz;
	m[3] = 0; 	m[7] = 0; 	 m[11] = 0; 	m[15] = 1;

	glMatrixMode(GL_MODELVIEW);
	glMultMatrixf(m);
}

**/
float eyeX =7,eyeY=5,eyeZ=7, lookX=3,lookY=3,lookZ=1;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    ///glFrustum(-5,5,-5,5, 4, 50);
    gluPerspective(60,1,5,100);
    ///glOrtho(-5,5,-5,5, 4, 50);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    ///gluLookAt(7,5,7, 3,3,1, 0,1,0);
    ///gluLookAt(7,5,7, 4,3,-4, 0,1,0);
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);




    glViewport(0, 0, windowHeight, windowWidth);
    glPushMatrix();
    glTranslatef(-10*0.5,0.0,-10*0.5);
    glScalef(0.25,4,7);
    drawCube(0.8,0.8,0.8);                         ///wall 04
    glPopMatrix();

    //glViewport(0, 0, windowHeight, windowWidth);
    glPushMatrix();
    glTranslatef(18*0.5,0.0,-10*0.5);
    glScalef(0.25,4,7);
    drawCube(0.8,0.8,0.8);                       ///wall 03
    glPopMatrix();

    //glViewport(0, 0, windowHeight, windowWidth);
    glPushMatrix();
    glTranslatef(18*0.5,0.0,-10*0.5);
    glRotatef(-90,0,1,0);               ///wall 02
    glScalef(0.25,4,7);
    drawCube(0.8,0.8,0.8);
    glPopMatrix();

    //glViewport(0, 0, windowHeight, windowWidth);
    glPushMatrix();
    glTranslatef(18*0.5,0.0,18*0.5);
    glRotatef(-90,0,1,0);
    glScalef(0.25,4,7);             ///wall 01
    drawCube(0.8,0.8,0.8);
    glPopMatrix();

    GLfloat reduce = -0.5;
    glPushMatrix();
    glTranslatef(2+reduce,0,-5);
    glScalef(2,0.3,4);          ///khat
    drawCube(0.5,0.0,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2+reduce,0.6,-3);
    glScalef(0.9,0.1,1);        /// balish 1
    drawCube(1,0.8,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.1+reduce,0.6,-3);
    glScalef(0.9,0.1,1);        /// balish 2
    drawCube(1,0.8,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2+reduce,0.6,0);
    glScalef(1.9,0.1,1.2);        /// bedsheet
    drawCube(2/5,1/5,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2+reduce,0.6,-4);
    glScalef(2,0.6,0.1);        /// bed head
    drawCube(0.5,0.0,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6,0.6,0);
    glScalef(0.6,0.0,1.3);        /// carpet
    drawCube(1,0.0,1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(6.5,0.0,-4);
    glScalef(0.8,0.8,0.8);        /// drawer 1
    drawCube(0.5,0.0,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,0.0,-4);
    glScalef(0.8,1.8,1);        /// drawer 2
    drawCube(0.5,0.0,0.1);
    glPopMatrix();


    GLfloat ex = 1.75;
    glPushMatrix();
    glTranslatef(-4,0.0,3-ex);
    glScalef(0.8,1.2,1.8);        /// drawer 3
    drawCube(0.5,0.0,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,12/5,3-ex);
    glScalef(0,1.5,1.5);        /// mirror
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,12/5 + 3,3-ex);  ///mirror
    glScalef(0.1,0.1,1.5);
    drawCube(1,1,153/255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,12/5 + 3,3-ex);   ///mirror
    glRotatef(90,1,0,0);
    glScalef(0.1,0.1,1.5);
    drawCube(1,1,153/255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,12/5 + 3,6-0.2-ex);
    glRotatef(90,1,0,0);                     ///mirror
    glScalef(0.1,0.1,1.5);
    drawCube(1,1,153/255);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-2,5,-3);
    glScalef(1.0,1,0.1);        /// picture
    drawCube(0.9,0.9,0.6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.25,6,-3);
    glScalef(0.2,0.2,0.12);        /// pic_head
    drawCube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.25,6-0.25,-3);
    glScalef(0.1,0.18,0.12);        /// pic_throat
    drawCube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.75,6-0.95,-3);
    glScalef(0.7,0.45,0.12);        /// pic_body
    drawCube(0,0.0,0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,5+0.5,-3);
    glScalef(0.5,0.5,0.1);        /// clock
    drawCube(0.95,0.95,0.95);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(1+0.5-0.1,6-0.25+0.2,-3+0.21);
    glScalef(0.08,0.08,0);        /// clock_dot
    drawCube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1+0.5-0.1,6-0.25+0.2,-3+0.21);
    glScalef(0.25,0.05,0);        /// clock_hand1
    drawCube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1+0.5-0.1,6-0.25+0.2,-3+0.21);
    glScalef(0.05,0.25,0);        /// clock_hand2
    drawCube(0,0,0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-5,8,-5);     /// ceiling
    glScalef(7,0,7);
    drawCube(0.8,0.8,0.8);
    glPopMatrix();









    window();
    window2();




















































    ///number 1 cube

    ///The floor
    for(int i=-10; i<18; i++)
    {
        for(int j=-10; j<18; j++)
        {
            glPushMatrix();
            glTranslatef(0.5*j,0,0.5*i);
            glScalef(0.25,0.02,0.25);
            if((i+j)%2 == 0)
            {
                drawCube(1,1,1);
            }
            else
            {
                drawCube(0,0,0);
            }
            glPopMatrix();

        }

    }

    glPushMatrix();
    glTranslatef(2,6.7,0);
    glScalef(0.05,0.3,0.05);
    drawCube(0.1,0.1,0.2);
    glPopMatrix();

    glPushMatrix();
    ///glRotatef(theta,0,1,0);
    ///glRectf(-1, -1, 1, 1);


    glTranslatef(2,6.5,0);
    glScalef(0.25,0.1,0.25);
    drawCube(0.1,0.2,0.2);
    glPopMatrix();
    glRotatef(angle,0,1,0);

    glPushMatrix();
    ///glRotatef(theta,0,1,0);
    glTranslatef(2,6.55,0);
    glScalef(1,0.001,0.25);
    drawCube(0.1,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    ///glRotatef(theta,0,1,0);
    glTranslatef(2,6.55,0);
    glScalef(0.25,0.001,1);
    drawCube(0.1,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    ///glRotatef(theta,0,1,0);
    glTranslatef(1,6.55,0);
    glScalef(1,0.001,0.25);
    drawCube(0.1,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    ///glRotatef(theta,0,1,0);
    glTranslatef(2,6.55,-1);
    glScalef(0.25,0.001,1);
    drawCube(0.1,0.2,0.2);
    glPopMatrix();

/**
    /// the walls
    glPushMatrix();
    glTranslatef(-5,0,-5);
    glScalef(0.25,4,7);
    drawCube(0.7,0.7,0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5,0,-5);
    glScalef(7,4,0.25);
    drawCube(0.5,0.5,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9,0,-5);
    glScalef(0.25,4,7);
    drawCube(0.7,0.7,0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5,0,9);
    glScalef(7,4,0.25);
    drawCube(0.5,0.5,0.5);
    glPopMatrix();

    ///ceiling
    glPushMatrix();
    glTranslatef(-5,7.5,-5);
    glScalef(7,0.5,7);
    drawCube(0.25,0.35,0.35);
    glPopMatrix();


    ///the box1
    glPushMatrix();
    glTranslatef(-4,0,-1);
    glScalef(0.5,1,1.75);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4,1.75,0);
    glScalef(0.1,1.5,0.75);
    drawCube(0.98,0.98,0.96);
    glPopMatrix();

    ///the box2
    glPushMatrix();
    glTranslatef(-3,0,-4);
    glScalef(1.5,1.5,0.25);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    ///pic frame 1
    glPushMatrix();
    glTranslatef(-1.25,3.25,-4.6);
    glScalef(0.5,0.5,0.1);
    drawCube(0.2,0.6,0.7);
    glPopMatrix();

    ///pic frame 2
    glPushMatrix();
    glTranslatef(2.5,5,-4.6);
    glScalef(0.5,0.5,0.1);
    drawCube(0.2,0.6,0.7);
    glPopMatrix();

    ///bed
    glPushMatrix();
    glTranslatef(1,0.25,-3.75);
    glScalef(1.76,0.15,3.01);       ///matress
    glRotatef(-4,0,1,0);
    drawCube(0.99,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,0,-3.75);
    glScalef(1.75,0.25,3);
    glRotatef(-4,0,1,0);              ///base
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,0,-3.75);
    glScalef(1.75,1,0.05);
    glRotatef(-4,0,1,0);           ///head support
    drawCube(0.52,0.37,0.26);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.1,0.54,-3);
    glScalef(0.7,0.06,0.6);
    glRotatef(-4,0,1,0);          ///balish1
    drawCube(1,0.5,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.8,0.53,-3);
    glScalef(0.7,0.06,0.6);
    glRotatef(-4,0,1,0);          ///balish2
    drawCube(1,0.5,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5,0.53,0);
    glScalef(1.2,0.03,0.6);
    glRotatef(-4,0,1,0);          ///katha
    drawCube(0,0,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.7,0.25,0);
    glScalef(0.4,0.01,1);
    glRotatef(-4,0,1,0);          ///paposh
    drawCube(0.4,0.8,0.3);
    glPopMatrix();

    ///the box3
    qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricDrawStyle(qobj, GLU_FILL);
    glPushMatrix();
    glTranslatef(5,0,-3);
    glScalef(0.75,0.75,1);
    drawCube(0.52,0.37,0.26);
    glPopMatrix();




    ///window 1
    window();

    ///window 2
    window2();

    ///fan

    glPushMatrix();
    glTranslatef(2,6.7,0);
    glScalef(0.05,0.3,0.05);
    drawCube(0.1,0.1,0.2);
    glPopMatrix();

    fanparts();








**/


    glFlush();
    glutSwapBuffers();
}

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 'w':
        eyeY += 0.1;
        break;
    case 's':
        eyeY -= 0.1;
        break;
    case 'a':
        eyeX += 0.1;
        break;
    case 'd':
        eyeX -= 0.1;
        break;
    case 'q':
        eyeZ += 0.1;
        break;
    case 'e':
        eyeZ -= 0.1;
        break;

    case 'i':
        lookY += 0.1;
        break;
    case 'k':
        lookY -= 0.1;
        break;
    case 'j':
        lookX += 0.1;
        break;
    case 'l':
        lookX -= 0.1;
        break;
    case 'u':
        lookZ += 0.1;
        break;
    case 'o':
        lookZ -= 0.1;
        break;






    case 27:	// Escape key
        exit(1);
    }
}


void animate()
{
    angle+=0.50;
    if(angle>360)angle-=360;
    glutPostRedisplay();

}



int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("Traingle-Demo");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}






