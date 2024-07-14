#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

GLfloat theta_sec=0;
GLfloat theta_min=0;
GLfloat theta_hr=0;
float theta_bob=-5;
float temper=0;
int flag=0;

void drawText(char *text,int length,int x,int y,int f)
{
  glMatrixMode(GL_PROJECTION);
  double *matrix=malloc(16*sizeof(double));
  glGetDoublev(GL_PROJECTION_MATRIX,matrix);
  glLoadIdentity();
  glOrtho(0,800,0,600,-5,5);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glLoadIdentity();
  glRasterPos2i(x,y);
  if(f==0)
  {
    for(int i=0;i<length;i++)
    {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(int)text[i]);
    //GLUT_BITMAP_9_BY_24
    }
  }
  else
  {
    for(int i=0;i<length;i++)
    {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)text[i]);
    //GLUT_BITMAP_9_BY_24
    }
  }
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixd(matrix);
  glMatrixMode(GL_MODELVIEW);
}

void star(GLfloat x,GLfloat y)
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.184314,0.309804,0.184314);
    glVertex2d(x,y);
    glVertex2d(x-0.010,y-0.025);
    glVertex2d(x+0.015,y-0.010);
    glVertex2d(x-0.015,y-0.010);
    glVertex2d(x+0.010,y-0.025);
    glVertex2d(x,y);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0); 
    glVertex2d(x,y);
    glVertex2d(x-0.010,y-0.025);
    glVertex2d(x+0.015,y-0.010);
    glVertex2d(x-0.015,y-0.010);
    glVertex2d(x+0.010,y-0.025);
    glVertex2d(x,y);
    glEnd();
}

void bobMotion()
{
      glColor3f(0.0,0.0,0.0);
      glPushMatrix();
      glTranslatef(0.5,0.58,0);
      glRotatef(theta_bob,0,0,1);
      glTranslatef(-0.5,-0.58,0);
      glBegin(GL_LINES);
      glVertex2d(0.5,0.58);
      glVertex2d(0.5,0.288);
      glEnd();
      glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.184314,0.309804,0.184314);
      for(int i =0; i <= 360; i++)
      {
      double angle = 2 * PI * i / 360;
      double x = 0.04*cos(angle);
      double y = 0.04*sin(angle);
      glVertex2d(x+0.5,y+0.25);
      }
      glEnd();
      glBegin(GL_LINE_LOOP);
      glColor3f(0.0,0.0,0.0);
      for(int i =0; i <= 360; i++)
      {
      double angle = 2 * PI * i / 360;
      double x = 0.04*cos(angle);
      double y = 0.04*sin(angle);
      glVertex2d(x+0.5,y+0.25);
      }
      glEnd();
      glPopMatrix();
      if(flag==0)
      {
        theta_bob+=0.5;
        if(theta_bob>=5)
        {
          flag=1;
        }
      }
      else
      {
        theta_bob-=0.5;
        if(theta_bob<=-5)
        {
          flag=0;
        }
      }
}

void timer()
{
  glutPostRedisplay();
  glutTimerFunc(50,timer,0);
}

void drawClock() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1.4);

    //Bottom part
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.184314,0.309804,0.184314);
    glVertex2d(0.425,0.594);
    glVertex2d(0.425,0.2);
    glVertex2d(0.5,0.15);
    glVertex2d(0.575,0.2);
    glVertex2d(0.575,0.594);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0,0.5,0.0);
    glVertex2d(0.445,0.594);
    glVertex2d(0.445,0.2);
    //glVertex2d(0.5,0.165);
    glVertex2d(0.555,0.2);
    glVertex2d(0.555,0.594);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glVertex2d(0.445,0.594);
    glVertex2d(0.445,0.2);
    //glVertex2d(0.5,0.165);
    glVertex2d(0.555,0.2);
    glVertex2d(0.555,0.594);
    glEnd();

    //Big circle
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.184314,0.309804,0.184314);
    for(int i =0; i <= 360; i++)
    {
    double angle = 2 * PI * i / 360;
    double x = 0.2*cos(angle);
    double y = 0.2*sin(angle);
    glVertex2d(x+0.5,y+0.78);
    }
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0);
    for(int i =0; i <= 360; i++)
    {
    double angle = 2 * PI * i / 360;
    double x = 0.2*cos(angle);
    double y = 0.2*sin(angle);
    glVertex2d(x+0.5,y+0.78);
    }
    glEnd();

    //Small circle
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0,0.5,0.0);
    for(int i =0; i <= 360; i++)
    {
    double angle = 2 * PI * i / 360;
    double x = 0.18*cos(angle);
    double y = 0.18*sin(angle);
    glVertex2d(x+0.5,y+0.78);
    }
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0);
    for(int i =0; i <= 360; i++)
    {
    double angle = 2 * PI * i / 360;
    double x = 0.18*cos(angle);
    double y = 0.18*sin(angle);
    glVertex2d(x+0.5,y+0.78);
    }
    glEnd();

    //Smallest circle
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.184314,0.309804,0.184314);
    for(int i =0; i <= 360; i++)
    {
    double angle = 2 * PI * i / 360;
    double x = 0.007*cos(angle);
    double y = 0.007*sin(angle);
    glVertex2d(x+0.5,y+0.78);
    }
    glEnd();

    //stars
    star(0.38,0.70);
    star(0.40,0.73);
    star(0.42,0.70);

    //numbers
    glColor3f(0.0,0.0,0.0);
    char temp[2];
    temp[0]='1';
    temp[1]='2';
    drawText(temp,2,390,560,0);
    temp[0]='1';
    drawText(temp,1,460,545,0);
    temp[0]='2';
    drawText(temp,1,510,510,0);
    temp[0]='3';
    drawText(temp,1,520,465,0);
    temp[0]='4';
    drawText(temp,1,505,415,0);
    temp[0]='5';
    drawText(temp,1,460,380,0);
    temp[0]='6';
    drawText(temp,1,395,370,0);
    temp[0]='7';
    drawText(temp,1,330,380,0);
    temp[0]='8';
    drawText(temp,1,280,415,0);
    temp[0]='9';
    drawText(temp,1,265,465,0);
    temp[0]='1';
    temp[1]='0';
    drawText(temp,2,280,510,0);
    temp[0]='1';
    temp[1]='1';
    drawText(temp,2,330,545,0);
    char name[6];
    name[0]='T'; name[1]='I'; name[2]='T'; name[3]='A'; name[4]='N';
    drawText(name,5,385,435,1);
    name[0]='Q'; name[1]='U'; name[2]='A'; name[3]='R'; name[4]='T'; name[5]='Z';
    drawText(name,6,378,500,1);

    //seconds needle
    glPushMatrix();
    glTranslatef(0.5,0.78,0);
    glRotatef(theta_sec,0,0,1);
    glTranslatef(-0.5,-0.78,0);
    glBegin(GL_LINES);
    glVertex2d(0.5,0.78);
    glVertex2d(0.5,0.915);
    glEnd();
    glPopMatrix();
    if(theta_bob == -5 || theta_bob == 5)
    {
    theta_sec-=6;
    }

    //minute needle
    glPushMatrix();
    glTranslatef(0.5,0.78,0);
    glRotatef(-theta_min,0,0,1);
    glTranslatef(-0.5,-0.78,0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(0.5,0.78);
    glVertex2d(0.5,0.885);
    glVertex2d(0.495,0.895);
    glVertex2d(0.5,0.91);
    glVertex2d(0.505,0.895);
    glVertex2d(0.5,0.885);
    glEnd();
    glPopMatrix();
    theta_min+=0.005;

    //hour needle
    glPushMatrix();
    glTranslatef(0.5,0.78,0);
    glRotatef(-theta_hr,0,0,1);
    glTranslatef(-0.5,-0.78,0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(0.5,0.78);
    glVertex2d(0.5,0.855);
    glVertex2d(0.495,0.865);
    glVertex2d(0.5,0.88);
    glVertex2d(0.505,0.865);
    glVertex2d(0.5,0.855);
    glEnd();
    glPopMatrix();
    theta_hr+=0.0005;
  
    bobMotion();

    glFlush();
}

void Initialize() 
{
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv)
{
  glutInit(&iArgc, cppArgv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
  glutInitWindowPosition(300,30);
  glutInitWindowSize(800,700);
  glutCreateWindow("2D Transformation in Clock");
  Initialize();
  glutDisplayFunc(drawClock);
  timer();
  glutMainLoop();
  return 0;
}

/*
  sec_x = 0.14*cos(theta_sec*3.14/180)+0.5;
  sec_y = 0.14*sin(theta_sec*3.14/180)+0.78;
    */
  //0.22,0.69,0.87
  //