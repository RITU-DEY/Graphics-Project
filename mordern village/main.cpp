#include<windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#include<iostream>
#include<math.h>
#include<cstdio>
#include <string.h>

#define PI 3.14159265358979323846

//global variable
float boatPosition1 =0.0f;
float speed1 =0.05f;

float boatPosition2 =0.0f;
float speed2 =0.05f;

float sunX =0.0f;
float sunSpeed =0.01f;

float planePos =14.0f;
float speed =0.05f;

float carposition1=0.01f;
float carspeed1=0.07f;

float carposition2=0.01f;
float carspeed2=0.08f;

bool isDay = true;


 void keyboard(unsigned char key, int x, int y)
{
    if(key == 'd' || key == 'D')
    {
        isDay = !isDay;
        glutPostRedisplay();
    }
}


void mouse(int button,int state,int x,int y)//boat animation
{

        if(button == GLUT_LEFT_BUTTON)
        {
            speed1 += 0.01f;
            speed2 += 0.01f;
        }
        else if(button == GLUT_RIGHT_BUTTON)
        {
            speed1 -= 0.01f;
            speed2 -= 0.01f;

       if(speed1<0) speed1 = 0;
            if(speed2<0) speed2 = 0;
        }

        glutPostRedisplay();

}

void specialKeys(int key, int x, int y)//car animation
{
    switch(key)
    {
        case GLUT_KEY_UP:
            carspeed1 += 0.01f;
            carspeed2 += 0.01f;
            break;

        case GLUT_KEY_DOWN:
            carspeed1 -= 0.01f;
            carspeed2 -= 0.01f;

            if(carspeed1 < 0)
                carspeed1 = 0;
            if(carspeed2 < 0)
            carspeed2 = 0;
            break;

        case GLUT_KEY_LEFT:
            carspeed1 = -carspeed1;
            carspeed2 = -carspeed2;
            break;

        case GLUT_KEY_RIGHT:
            if(carspeed1 < 0)
          carspeed1 = -carspeed1;

         if(carspeed2 < 0)
         carspeed2 = -carspeed2;
            break;
    }

    glutPostRedisplay();
}
void update(int value) {

    boatPosition1 += speed1;
     boatPosition2 += speed2;

    if(boatPosition1 > 14) boatPosition1 = -14;
    if(boatPosition2 > 14) boatPosition2 = -14;



    sunX += sunSpeed;

    if(sunX > 14.0f)
        sunX = -14.0f;

    planePos -= speed;
    if(planePos < -25.0f)
    planePos = 14.0f;

    carposition1 += carspeed1;
    if(carposition1 > 14) carposition1 = -14;

    carposition2 += carspeed2;
    if(carposition2 > 14) carposition2 = -14;

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

// Function declarations
void scenario3();
void myInit();
void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for(int i = 0; i <= 100; i++)
    {
        float angle = 2 * 3.1416 * i / 100;
        float x = r * cos(angle);
        float y = r * sin(angle);

        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}
//doted road
void drawRoad()
{
    // Road
    glColor3ub(26, 26, 26);
    glBegin(GL_QUADS);
        glVertex2f(-14,-2);
        glVertex2f(14,-2);
        glVertex2f(14,2);
        glVertex2f(-14,2);
    glEnd();

    // Dotted
    glColor3ub(255, 255, 255);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 0x00FF);
    glLineWidth(4);

    glBegin(GL_LINES);
    glVertex2f(-14,0);
    glVertex2f(14,0);
    glEnd();

    glDisable(GL_LINE_STIPPLE);
}

void drawAirplane() {
    glPushMatrix();

// pichoner pakhna
   glColor3ub(255, 191, 204);
   glBegin(GL_QUADS);
   glVertex2f(8.01,8.22);
   glVertex2f(9.48,7.57);
   glVertex2f(9.38,7.96);
   glVertex2f(8.63,8.22);
   glEnd();

// samner pakhna
  glColor3ub(255, 191, 204);
  glBegin(GL_QUADS);
  glVertex2f(8,8.98);
  glVertex2f(9.29,9.63);
 glVertex2f(9.82,9.56);
 glVertex2f(8.79,8.98);
 glEnd();

//  body
 glColor3ub(173, 216, 230);

 glBegin(GL_QUADS);
 glVertex2f(7.39,8.98);
 glVertex2f(7.39,8.21);
 glVertex2f(10.37,8.21);
 glVertex2f(10.37,8.98);
 glEnd();

// last part
   glBegin(GL_POLYGON);
   glVertex2f(10.32,8.98);
   glVertex2f(10.37,8.22);
   glVertex2f(10.82,9.59);
   glVertex2f(10.42,9.41);
   glEnd();

// samner mukh
   glBegin(GL_TRIANGLES);
   glVertex2f(6.98,8.62);
   glVertex2f(7.39,8.98);
   glVertex2f(7.39,8.21);
   glEnd();

    glColor3ub(0,0,0);
// Window 1
      glBegin(GL_QUADS);
    glVertex2f(8.23,8.76);
    glVertex2f(8.23,8.58);
    glVertex2f(8.42,8.56);
    glVertex2f(8.42,8.76);
    glEnd();

// Window 2
    glBegin(GL_QUADS);
    glVertex2f(8.57,8.76);
    glVertex2f(8.57,8.57);
    glVertex2f(8.7,8.57);
    glVertex2f(8.7,8.76);
    glEnd();

// Window 3
    glBegin(GL_QUADS);
    glVertex2f(8.77,8.75);
    glVertex2f(8.77,8.58);
    glVertex2f(8.88,8.58);
    glVertex2f(8.88,8.75);
    glEnd();

// Window 4
    glBegin(GL_QUADS);
    glVertex2f(8.95,8.74);
    glVertex2f(8.95,8.59);
    glVertex2f(9.09,8.59);
    glVertex2f(9.09,8.74);
    glEnd();

// Window 5
    glBegin(GL_QUADS);
    glVertex2f(9.2,8.74);
    glVertex2f(9.2,8.6);
    glVertex2f(9.31,8.6);
    glVertex2f(9.31,8.74);
    glEnd();



    glPopMatrix();
}

// Display function
void village()
{
    scenario3();
}

// Scenario 3
void scenario3()
{
    glClear(GL_COLOR_BUFFER_BIT);

// Ground///////////////////////////
    glColor3ub(62, 143, 80);
    glBegin(GL_QUADS);
    glVertex2f(-14,-8);
    glVertex2f(-14,-2);
    glVertex2f(14,-2);
    glVertex2f(14,-8);
    glEnd();
 //Sky//////////////////////////

   glBegin(GL_QUADS);

   if(isDay)
   {
    glColor3ub(255, 153, 102);
    glVertex2f(-14,4);
    glVertex2f(14,4);

    glColor3ub(57, 213, 255);
    glVertex2f(14,10);
    glVertex2f(-14,10);
   }
  else
   {

    glColor3ub(20, 20, 60);
    glVertex2f(-14,4);
    glVertex2f(14,4);

    glColor3ub(0, 0, 20);
    glVertex2f(14,10);
    glVertex2f(-14,10);
}

glEnd();

//2nd house//////////////////////////////////
    glColor3ub(210, 105, 30);
    glBegin(GL_QUADS);
    glVertex2f(-8.82,-2.13);
    glVertex2f(-6.82,-2.13);
    glVertex2f(-6.08,-2.59);
    glVertex2f(-8.44,-2.57);
    glEnd();

    glColor3ub(244, 164, 96);
    glBegin(GL_POLYGON);
    glVertex2f(-8.44,-2.57);
    glVertex2f(-6.63,-2.58);
    glVertex2f(-6.6,-3.61);
    glVertex2f(-8,-3.57);
    glVertex2f(-8,-3);
    glEnd();

    glLineWidth(8.0);
    glColor3ub(160,82,45);
    glBegin(GL_LINES);
    glVertex2f(-6.6,-3.61);
    glVertex2f(-8,-3.57);
    glEnd();

// 1st House////////////////////////////

   glColor3ub(160, 82, 45);
   glBegin(GL_QUADS);
   glVertex2f(-11,-2);
   glVertex2f(-9,-2);
   glVertex2f(-8,-3);
   glVertex2f(-10,-3);
   glEnd();

   glLineWidth(10.0);
   glBegin(GL_LINES);
   glVertex2f(-12,-3);
   glVertex2f(-11,-2);
   glEnd();


    glColor3ub(255, 222, 173);
    glBegin(GL_POLYGON);
    glVertex2f(-11,-2);
    glVertex2f(-12,-3);
    glVertex2f(-12,-4);
    glVertex2f(-10,-4);
    glVertex2f(-10,-3);
    glEnd();

    glLineWidth(3.0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-10,-3);
    glVertex2f(-10,-4);
    glEnd();


     glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2f(-10,-3);
    glVertex2f(-8,-3);
    glVertex2f(-8,-4);
     glVertex2f(-10,-4);

    glEnd();

    glLineWidth(8.0);
    glColor3ub(160,82,45);
    glBegin(GL_LINES);
    glVertex2f(-10,-4);
    glVertex2f(-8,-4);
    glEnd();

    glLineWidth(8.0);
    glColor3ub(160,82,45);
    glBegin(GL_LINES);
    glVertex2f(-10,-4);
    glVertex2f(-12,-4);
    glEnd();

//1st door

    glColor3ub(160, 85, 45);
    glBegin(GL_QUADS);
    glVertex2f(-9.4,-4);
    glVertex2f(-9.4,-3.53);
    glVertex2f(-8.82,-3.53);
    glVertex2f(-8.82,-4);
    glEnd();

//SUN//////////////////////////////////////

    glPushMatrix();
    glTranslatef(sunX, 8.0f, 0.0f);

    if(isDay)
   {
    glColor3f(1.0, 0.84, 0.0);
    drawCircle(0,0,1.0);
   }
   else
   {
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(0,0,0.8);
   }

glPopMatrix();

////// River//////////////////////////////////////
    glColor3ub(50, 130, 246);
    glBegin(GL_QUADS);
    glVertex2f(-14,4);
    glVertex2f(14,4);
    glColor3ub(0,191,255);
    glVertex2f(14,2);
    glVertex2f(-14,2);
    glEnd();

//road////////////////////////////////////////
     drawRoad();



//hill1////////////////////////////////

    glColor3ub(0, 100, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-14,4);
    glVertex2f(-11.88,5.69);
    glVertex2f(-10,4);
    glEnd();

//hill2//////////////////////////////
    glColor3ub(34, 139, 34);
    glBegin(GL_POLYGON);
    glVertex2f(-11.1,5);
    glVertex2f(-9.86,6.73);
    glVertex2f(-7.01,4);
    glVertex2f(-10,4);
    glEnd();

//hill3//////////////////////////////
    glColor3ub(120, 200, 120);
    glBegin(GL_POLYGON);
    glVertex2f(-6,6);
    glVertex2f(-7.53,4.5);
    glVertex2f(-7.01,4);
    glVertex2f(-4,4);
    glEnd();

//hill4///////////////////////////////
    glColor3ub(0, 100, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0,4);
    glVertex2f(2,6);
    glVertex2f(4,4);
    glEnd();

//hill5///////////////////////////
     glColor3ub(34, 139, 34);
    glBegin(GL_POLYGON);
    glVertex2f(4,4);
    glVertex2f(3.68,4.32);
    glVertex2f(5.46,6.93);
    glVertex2f(10.75,4);
    glEnd();

//hill tree////////////////////////
//tree2
   glColor3ub(139, 69, 19);

   glBegin(GL_QUADS);
   glVertex2f(-2.89,4);
   glVertex2f(-2.89,4.86);
   glVertex2f(-2.6,4.86);
   glVertex2f(-2.6,4);
   glEnd();


    glColor3ub(34, 139, 34);

    glBegin(GL_TRIANGLES);
    glVertex2f(-3.7,4.86);
    glVertex2f(-2.8,5.84);
    glVertex2f(-1.55,4.86);
    glEnd();

//tree3//////////////////////////
    glColor3ub(139, 69, 19);

    glBegin(GL_QUADS);
    glVertex2f(-0.93,4);
    glVertex2f(-0.93,5);
    glVertex2f(-0.46,5);
    glVertex2f(-0.46,4);
    glEnd();


    glColor3ub(34, 139, 34);

    glBegin(GL_TRIANGLES);
    glVertex2f(-2,5);
    glVertex2f(-0.72,5.73);
    glVertex2f(0.5,5);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(0, 255, 0);
    glVertex2f(-1.54,5.4);
    glColor3ub(0, 255, 0);

    glVertex2f(0.23,5.4);
    glColor3ub(255, 255, 0);
    glVertex2f(-0.69,6.44);
    glEnd();
//tree4////////////////////////
    glColor3ub(139, 69, 19);

   glBegin(GL_QUADS);

   glVertex2f(11.97,4);
   glVertex2f(12.69,4);
   glVertex2f(12.69,5.65);
   glVertex2f(11.97,5.65);

   glEnd();

    glColor3ub(34, 139, 34);

    glBegin(GL_TRIANGLES);
    glVertex2f(10.65,5.65);
    glVertex2f(13.65,5.65);
    glVertex2f(12.12,7.27);
    glEnd();

// Boat////////////////////////////////

     glPushMatrix();
     glTranslatef(boatPosition1 , 0.0f, 0.0f);

     glColor3ub(0, 0, 0);
     glBegin(GL_QUADS);
     glVertex2f(5.97,3.25);
     glVertex2f(10.01,3.22);
     glVertex2f(9.35,2.81);
     glVertex2f(6.73,2.84);

     glEnd();


    glColor3ub(205, 133, 63);
    glBegin(GL_QUADS);
    glVertex2f(7.25,3.24);
    glVertex2f(7.25,3.77);
    glVertex2f(8.56,3.78);
    glVertex2f(8.56,3.23);
    glEnd();

    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex2f(7.73,4);
    glVertex2f(7.73,3.77);
    glVertex2f(7.91,3.78);
    glVertex2f(7.91,4);
    glEnd();

   glColor3ub(127, 23, 156);
   glBegin(GL_QUADS);
   glVertex2f(7.5,4);
   glVertex2f(8.17,4);
   glVertex2f(8.17,4.41);
   glVertex2f(7.5,4.41);

   glEnd();
   glPopMatrix();

//boat2/////////////////////////////////
   glPushMatrix();
  glTranslatef(boatPosition2, 0, 0);
  glColor3ub(0, 0, 0);

  glBegin(GL_POLYGON);
  glVertex2f(-7,3);
  glVertex2f(-5,3);
  glVertex2f(-5.44,2.73);
  glVertex2f(-6.65,2.75);

  glEnd();

   glColor3ub(101, 67, 33);
   glBegin(GL_QUADS);
   glVertex2f(-6.6,3);
   glVertex2f(-6.6,3.51);
   glVertex2f(-5.51,3.53);
   glVertex2f(-5.49,3);
   glEnd();
   glPopMatrix();

//plane///////////////////////////////
     glPushMatrix();
     glTranslatef(planePos, 0.0f, 0.0f);
     drawAirplane();
     glPopMatrix();

//lamp9/////////////////////////////
  glColor3ub(139, 69, 19);

   glBegin(GL_QUADS);
   glVertex2f(-0.22,-2);
   glVertex2f(-0.22,-1);
   glVertex2f(0,-1);
   glVertex2f(0,-2);
   glEnd();

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(-0.12,-0.81,0.2);

//school////////////////////////////////////

    glColor3ub(244, 138, 68);
    glBegin(GL_QUADS);
    glVertex2f(-2,-7.53);
    glVertex2f(-2,-2);
    glVertex2f(4,-2);
    glVertex2f(4,-7.53);
    glEnd();

    glLineWidth(10.0);
    glColor3ub(139, 69, 19);
    glBegin(GL_LINES);
    glVertex2f(4,-7.53);
    glVertex2f(-2,-7.53);
    glEnd();

    glLineWidth(7.0);
    glColor3ub(139, 69, 19);
    glBegin(GL_LINES);
    glVertex2f(-2,-2);
    glVertex2f(4,-2);
    glEnd();

    glColor3ub(176, 105, 52);
    glBegin(GL_QUADS);
    glVertex2f(-2,-2);
    glVertex2f(-2,-7.51);
    glVertex2f(-2.61,-6.89);
    glVertex2f(-2.64,-2.47);
    glEnd();

    glLineWidth(10.0);
    glColor3ub(139, 69, 19);
    glBegin(GL_LINES);
    glVertex2f(-2.61,-6.89);
    glVertex2f(-2,-7.51);

    glEnd();

    glLineWidth(5.0);
   glColor3ub(255, 200, 100);
    glBegin(GL_LINE_LOOP);

   glVertex2f(-2,-2.2);
   glVertex2f(2.38,-2.2);
   glVertex2f(2.38,-4.01);
   glVertex2f(2.38,-6.01);
   glVertex2f(2.38,-7.45);
   glVertex2f(-2,-7.45);
   glVertex2f(-2,-6.01);
   glVertex2f(-2,-4.01);
   glEnd();

    glLineWidth(5.0);
    glColor3ub(255, 200, 100);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.59,-2.2);
    glVertex2f(-0.59,-7.45);
    glVertex2f(1.28,-7.45);
    glVertex2f(1.28,-2.2);

    glEnd();

    glLineWidth(5.0);
    glColor3ub(255, 200, 100);
    glBegin(GL_LINE_LOOP);

    glVertex2f(-2,-6.01);
    glVertex2f(-2,-4.01);
    glVertex2f(2.38,-4.01);
    glVertex2f(2.38,-6.01);

    glEnd();

// School Main Gate
    glColor3ub(50, 50, 59);
    glBegin(GL_QUADS);
    glVertex2f(18,-400);
    glVertex2f(48,-400);
    glVertex2f(48,-340);
    glVertex2f(18,-340);
    glEnd();


// School Main Gate
    glColor3ub(101, 67, 33);
    glBegin(GL_QUADS);
    glVertex2f(-1.47,-6.51);
    glVertex2f(-1.47,-7.51);
    glVertex2f(-1.04,-7.51);
    glVertex2f(-1.07,-6.51);
    glEnd();

//door2
      glColor3ub(101, 67, 33);
    glBegin(GL_QUADS);
    glVertex2f(0,-6);
    glVertex2f(0,-4.96);
    glVertex2f(0.67,-4.96);
    glVertex2f(0.69,-6);
    glEnd();

//door3
      glColor3ub(101, 67, 33);
    glBegin(GL_QUADS);
    glVertex2f(-1.61,-4.01);
    glVertex2f(-1.61,-2.71);
    glVertex2f(-1.07,-2.71);
    glVertex2f(-1.04,-4.01);
    glEnd();

//door4
      glColor3ub(101, 67, 33);
    glBegin(GL_QUADS);
    glVertex2f(0,-2.83);
    glVertex2f(0,-4);
    glVertex2f(0.69,-4);
    glVertex2f(0.67,-2.83);
    glEnd();

//window1
     glColor3ub(101, 67, 33);
    glBegin(GL_QUADS);
    glVertex2f(1.5,-4.5);
    glVertex2f(1.5,-5);
    glVertex2f(2,-5);
    glVertex2f(2,-4.5);
    glEnd();

//window2
    glColor3ub(101, 67, 33);
    glBegin(GL_QUADS);
    glVertex2f(1.5,-6.5);
    glVertex2f(1.5,-7);
    glVertex2f(2,-7);
    glVertex2f(2,-6.5);
    glEnd();
// School Text
    glColor3ub(255, 255, 255);
    glRasterPos2f(-0.3,-2);
    for (int i = 0; i < 6; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, "SCHOOL"[i]);
    }

// School Flag Stand///////////
    glBegin(GL_QUADS);
    glColor3ub(205, 133, 63);
    glVertex2f(4.7,-7.96);
    glVertex2f(4.8,-7.96);
    glVertex2f(4.8,-0.81);
    glVertex2f(4.7,-0.81);


    glEnd();

// School Flag/////////////////////////
    glBegin(GL_QUADS);
    glColor3ub(0, 100, 0);
    glVertex2f(4.8,-0.75);
    glVertex2f(8,-0.75);
    glVertex2f(8, -2);
    glVertex2f(4.8, -2);
    glEnd();

//  Flag Circle
    glColor3ub(255, 27, 27);
    drawCircle(6.39,-1.31,0.40);


//playground///////////////////////////

     glLineWidth(3.0);
     glColor3ub(255, 255, 255);
     glBegin(GL_LINE_LOOP);

     glVertex2f(7.01,-7.59);
     glVertex2f(12.97,-7.59);
     glVertex2f(12.66,-4.99);
     glVertex2f(7.33,-4.99);
     glEnd();

     glColor3ub(255, 255, 255);
     glBegin(GL_LINE_LOOP);

     glVertex2f(10,-4.99);
     glVertex2f(10,-7.58);

     glEnd();

    glColor3ub(255, 255,255);
    drawCircle(10.01,-6.35,0.40);

//school bus//////////////////////////

    glBegin(GL_QUADS);
    glColor3ub(255, 216, 0);
    glVertex2f(9.5,-1.5);
    glVertex2f(9.5,-3.5);
    glVertex2f(13.76,-3.5);
    glVertex2f(13.76,-1.5);
    glEnd();


// Windows
   glBegin(GL_QUADS);
   glColor3ub(135, 206, 235);

// First window
  glVertex2f(10.8,-1.6);
  glVertex2f(10.8,-1.8);
  glVertex2f(11.4,-1.8);
  glVertex2f(11.4,-1.6);


// Second window
  glVertex2f(11.6,-1.6);
  glVertex2f(11.6,-1.8);
  glVertex2f(12.2,-1.8);
  glVertex2f(12.2,-1.6);



// Third window
  glVertex2f(12.4,-1.6);
  glVertex2f(12.4,-1.8);
  glVertex2f(13,-1.8);
  glVertex2f(13,-1.6);


// Fourth window
  glVertex2f(13.2,-1.6);
  glVertex2f(13.2,-1.8);
  glVertex2f(13.75,-1.8);
  glVertex2f(13.75,-1.6);
  glEnd();

 // Door
  glBegin(GL_QUADS);
  glColor3ub(200, 200, 200);
  glVertex2f(10,-3.5);
  glVertex2f(10,-2);
  glVertex2f(10.5,-2);
  glVertex2f(10.5,-3.5);
  glEnd();

// bus Wheels

  glColor3ub(0, 0, 0);
  drawCircle(10.99,-3.25,0.3);
  drawCircle(12.99,-3.25,0.3);

  // School Bus Text
    glColor3ub(63, 72, 204);
    glRasterPos2f(11,-2.5);
    for (int i = 0; i < 10; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, "SCHOOL BUS"[i]);
    }

    //tree river
   glColor3ub(139, 69, 19);

   glBegin(GL_QUADS);
   glVertex2f(-9.86,2);
   glVertex2f(-9.86,2.52);
   glVertex2f(-9.76,2.52);
   glVertex2f(-9.76,2);
   glEnd();
   glColor3ub(0, 100, 0);
   drawCircle(-10.01,2.5,0.1);

   glColor3ub(34, 139, 34);
   drawCircle(-9.88,2.66,0.15);

   glColor3ub(0, 128, 0);
   drawCircle(-9.67,2.66,0.1);

   glColor3ub(0, 100, 0);
   drawCircle(-9.64,2.47,0.15);
   glColor3ub(34, 139, 34);
   drawCircle(-9.73,2.86,0.15);

  //lamp2//////////////////////////
   glColor3ub(139, 69, 19);

   glBegin(GL_QUADS);
   glVertex2f(-9,2);
   glVertex2f(-8.91,2);
   glVertex2f(-8.91,3);
   glVertex2f(-9,3);
   glEnd();

   glColor3ub(0,0,0);
   glBegin(GL_LINES);
   glVertex2f(-9,3);
   glVertex2f(-9.14,2.95);
   glEnd();

   glColor3ub(0,0,0);
   glBegin(GL_LINES);
   glVertex2f(-9,3);
   glVertex2f(-9.07,3.12);
   glEnd();

   glColor3ub(0,0,0);
   glBegin(GL_LINES);
   glVertex2f(-8.92,3);
   glVertex2f(-8.84,3.19);
   glEnd();

   glColor3ub(0,0,0);
   glBegin(GL_LINES);
   glVertex2f(-8.92,3);
   glVertex2f(-8.74,3);
   glEnd();

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);

   drawCircle(-9.2,2.93,0.1);

  if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(-9.11,3.17,0.1);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(-8.84,3.19,0.1);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(-8.63,2.99,0.1);

  //LAMP1/////////////////////////////
   glColor3ub(139, 69, 19);

   glBegin(GL_QUADS);
   glVertex2f(-13.69,2);
   glVertex2f(-13.5,2);
   glVertex2f(-13.5,3.58);
   glVertex2f(-13.69,3.59);
   glEnd();

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(-13.6,3.77,0.2);

  //lamp4///////////////////////////
   glColor3ub(139, 69, 19);

   glBegin(GL_QUADS);
   glVertex2f(-3.72,3.04);
   glVertex2f(-3.72,2);
   glVertex2f(-3.5,2);
   glVertex2f(-3.48,3.04);
   glEnd();

   glColor3ub(0,0,0);
   glBegin(GL_LINES);
   glVertex2f(-3.72,3.04);
   glVertex2f(-4.18,2.9);
   glEnd();

   glColor3ub(0,0,0);
   glBegin(GL_LINES);
   glVertex2f(-3.72,3.04);
   glVertex2f(-3.93,3.43);
   glEnd();

   glColor3ub(0,0,0);
   glBegin(GL_LINES);
   glVertex2f(-3.48,3.04);
   glVertex2f(-3.5,3.5);
   glEnd();

   glColor3ub(0,0,0);
   glBegin(GL_LINES);
   glVertex2f(-3.48,3.04);
   glVertex2f(-3.15,2.95);
   glEnd();
   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
  drawCircle(-4.18,2.9,0.15);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(-3.93,3.43,0.15);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(-3.5,3.5,0.15);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);;
   drawCircle(-3.15,2.95,0.15);

  //lamp5///////////////////////////
   glColor3ub(139, 69, 19);

   glBegin(GL_QUADS);
   glVertex2f(2.09,2);
   glVertex2f(2.1,2.83);
   glVertex2f(2.26,2.82);

   glVertex2f(2.26,2);
   glEnd();

   glColor3ub(0,0,0);
   glBegin(GL_LINES);
   glVertex2f(2.1,2.83);
   glVertex2f(1.98,3.3);
   glEnd();

   glColor3ub(0,0,0);
   glBegin(GL_LINES);
   glVertex2f(2.1,2.83);
   glVertex2f(1.82,2.74);
   glEnd();

   glColor3ub(0,0,0);
   glBegin(GL_LINES);
   glVertex2f(2.26,2.82);
   glVertex2f(2.41,3.28);
   glEnd();

   glColor3ub(0,0,0);
   glBegin(GL_LINES);
   glVertex2f(2.26,2.82);
   glVertex2f(2.6,2.76);
   glEnd();

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(1.82,2.74,0.15);
   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(1.98,3.3,0.15);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(2.41,3.28,0.15);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(2.6,2.76,0.15);

  //lamp6////////////////////////////////
   glColor3ub(139, 69, 19);

   glBegin(GL_QUADS);
   glVertex2f(12,2);
   glVertex2f(12,3);
   glVertex2f(12.14,3);
   glVertex2f(12.14,2);
   glEnd();

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(12.05,3.2,0.2);

   //CAR1//////////////////////////////////

   glPushMatrix();
   glTranslatef(carposition1,0.0f, 0.0f);
   glColor3ub(220, 20, 60);
   glBegin(GL_QUADS);
   glVertex2f(2.02,0.69);
   glVertex2f(2.02,0);
   glVertex2f(5,0);
   glVertex2f(4.99,0.69);
   glEnd();

   glColor3ub(255, 215, 0);
   glBegin(GL_POLYGON);
   glVertex2f(3,1.4);
   glVertex2f(2.67,0.7);
   glVertex2f(4.34,0.7);
   glVertex2f(4.03,1.4);
   glEnd();

   glColor3ub(0,0,0);
   drawCircle(2.62,-0.06,0.3);

   glColor3ub(255,255,255);
   drawCircle(2.62,-0.06,0.2);

   glColor3ub(0,0,0);
   drawCircle(4,0.02,0.3);

   glColor3ub(255,255,255);
   drawCircle(4,0.002,0.2);
   glPopMatrix();

  //daraz car///////////////////////////
   glPushMatrix();
   glTranslatef(carposition2,0.0f, 0.0f);
   glColor3ub(255, 165, 0);
   glBegin(GL_QUADS);
   glVertex2f(-5.5,1);
   glVertex2f(-5.5,0);
   glVertex2f(-3,0);
   glVertex2f(-3,1);
   glEnd();

   glColor3ub(0,0,0);
   drawCircle(-5,0,0.3);

   glColor3ub(255,255,255);
   drawCircle(-5,0,0.2);

   glColor3ub(0,0,0);
   drawCircle(-3.5,0,0.3);

   glColor3ub(255,255,255);
   drawCircle(-3.5,0,0.2);

   glColor3ub(255, 255, 255);
    glRasterPos2f(-4.72,0.51);
    for (int i = 0; i < 6; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, "DARAZ"[i]);
    }
   glPopMatrix();

  //tree barir piche//////////////////////
   glColor3ub(139, 69, 19);

   glBegin(GL_QUADS);
   glVertex2f(-9.76,-2);
   glVertex2f(-9.36,-2);
   glVertex2f(-9.36,-1);
   glVertex2f(-9.76,-1);
   glEnd();

   //dark green
    glColor3ub(34, 139, 34);

    glBegin(GL_TRIANGLES);
    glVertex2f(-10.6,-1);
    glVertex2f(-8.24,-1);
    glVertex2f(-9.44,1.45);
    glEnd();

    glColor3ub(144, 238, 144);

    glBegin(GL_TRIANGLES);
    glVertex2f(-11,-0.5);
    glVertex2f(-8,-0.5);
    glVertex2f(-9.44,1.45);
    glEnd();


    //lamp7//////////////////////////////
   glColor3ub(139, 69, 19);

   glBegin(GL_QUADS);
   glVertex2f(-13.21,-2);
   glVertex2f(-13.21,0);
   glVertex2f(-12.87,0);
   glVertex2f(-12.87,-2);
   glEnd();

   glColor3ub(128, 128, 128);
   glBegin(GL_LINES);
   glVertex2f(-13.21,0);
   glVertex2f(-13.57,-0.4);
   glEnd();

   glColor3ub(128, 128, 128);
   glBegin(GL_LINES);
   glVertex2f(-13.21,0);
   glVertex2f(-13.47,0.68);
   glEnd();

   glColor3ub(128, 128, 128);
   glBegin(GL_LINES);
   glVertex2f(-12.87,0);
   glVertex2f(-12.62,0.63);
   glEnd();

   glColor3ub(128, 128, 128);
   glBegin(GL_LINES);
   glVertex2f(-12.87,0);
   glVertex2f(-12.36,-0.4);
   glEnd();

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);

   drawCircle(-13.57,-0.4,0.18);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(-13.47,0.68,0.18);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(-12.62,0.63,0.18);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(-12.36,-0.4,0.18);

   //lamp8/////////////////////////////
   glColor3ub(139, 69, 19);

   glBegin(GL_QUADS);
   glVertex2f(-5,-1.98);
   glVertex2f(-5,-1);
   glVertex2f(-4.77,-1);
   glVertex2f(-4.77,-1.98);
   glEnd();

   glColor3ub(128, 128, 128);
   glBegin(GL_LINES);
   glVertex2f(-5,-1);
   glVertex2f(-5.29,-1.31);
   glEnd();

   glColor3ub(128, 128, 128);
   glBegin(GL_LINES);
   glVertex2f(-5,-1);
   glVertex2f(-5.23,-0.63);
   glEnd();

   glColor3ub(128, 128, 128);
   glBegin(GL_LINES);
   glVertex2f(-4.77,-1);
   glVertex2f(-4.55,-0.62);
   glEnd();

   glColor3ub(128, 128, 128);
   glBegin(GL_LINES);
   glVertex2f(-4.77,-1);
   glVertex2f(-4.54,-1.13);
   glEnd();

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);

   drawCircle(-5.29,-1.31,0.18);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(-5.23,-0.63,0.18);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(-4.55,-0.62,0.18);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
  drawCircle(-4.54,-1.13,0.18);

   //lamp10///////////////////////////

   glColor3ub(139, 69, 19);

   glBegin(GL_QUADS);
   glVertex2f(8.61,-2);
   glVertex2f(8.59,-0.31);
   glVertex2f(8.88,-0.31);
   glVertex2f(8.88,-2);
   glEnd();

   glColor3ub(128, 128, 128);
   glBegin(GL_LINES);
   glVertex2f(8.59,-0.31);
   glVertex2f(8.39,-0.77);
   glEnd();

   glColor3ub(128, 128, 128);
   glBegin(GL_LINES);
   glVertex2f(8.59,-0.31);
   glVertex2f(8.38,0.25);
   glEnd();

   glColor3ub(128, 128, 128);
   glBegin(GL_LINES);
   glVertex2f(8.88,-0.31);
   glVertex2f(8.95,0.28);
   glEnd();

   glColor3ub(128, 128, 128);
   glBegin(GL_LINES);
   glVertex2f(8.88,-0.31);
   glVertex2f(9.16,-0.64);
   glEnd();

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);

  drawCircle(8.39,-0.77,0.18);

  if(isDay)
  glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(8.38,0.25,0.18);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(8.95,0.28,0.18);

   if(isDay)
   glColor3ub(255,255,255);
   else
   glColor3ub(255, 255, 100);
   drawCircle(9.16,-0.64,0.18);

    //building1///////////////////////////

   glColor3ub(255, 105, 180);
   glBegin(GL_QUADS);
   glVertex2f(-13,3);
   glVertex2f(-13,2);
   glVertex2f(-12,2);
   glVertex2f(-12,3);

   glEnd();

   glColor3ub(255, 192, 203);
   glBegin(GL_QUADS);

  glVertex2f(-12.8,2.6);
  glVertex2f(-12.6,2.6);
  glVertex2f(-12.6,2.8);
  glVertex2f(-12.8,2.8);

  glEnd();


   glColor3ub(255, 192, 203);
   glBegin(GL_QUADS);

   glVertex2f(-12.4,2.6);
   glVertex2f(-12.2,2.6);
   glVertex2f(-12.2,2.8);
   glVertex2f(-12.4,2.8);

   glEnd();

//building 2///////////////////////////

  glColor3ub(200, 200, 200);
  glBegin(GL_QUADS);

  glVertex2f(-11.5,3.0);
  glVertex2f(-10.5,3.0);
  glVertex2f(-10.5,3.5);
  glVertex2f(-11.5,3.5);

  glEnd();

  glColor3ub(100, 249, 255);
  glBegin(GL_QUADS);

  glVertex2f(-11.5,2.5);
  glVertex2f(-10.5,2.5);
  glVertex2f(-10.5,3.0);
  glVertex2f(-11.5,3.0);

  glEnd();


  glColor3ub(120, 120, 120);

glBegin(GL_QUADS);

glVertex2f(-11.5,2.0);
glVertex2f(-10.5,2.0);
glVertex2f(-10.5,2.5);
glVertex2f(-11.5,2.5);

glEnd();

//building3////////////////////////

  glColor3ub(240, 200, 80);
  glBegin(GL_QUADS);

  glVertex2f(-2.37,2);
  glVertex2f(-2.37,3);
  glVertex2f(-1,3);
  glVertex2f(-1,2);

  glEnd();

  glColor3ub(255, 87, 34);
  glBegin(GL_QUADS);

  glVertex2f(-2.1,2.46);
  glVertex2f(-2.11,2.79);
  glVertex2f(-1.68,2.79);
  glVertex2f(-1.7,2.46);

  glEnd();


  glColor3ub(255, 87, 34);

glBegin(GL_QUADS);

glVertex2f(-1.51,2.43);
glVertex2f(-1.51,2.79);
glVertex2f(-1.17, 2.79);
glVertex2f(-1.17, 2.43);

glEnd();
//dustbin//////////////////////
glColor3ub(0, 255, 255);

glBegin(GL_POLYGON);
glVertex2f(-8.5,2);
glVertex2f(-8.58,2.52);
glVertex2f(-7.73,2.52);
glVertex2f(-7.83,2);
glEnd();


// BIN text
glColor3ub(0,0,0);
glRasterPos2f(-8.3,2.2);

for (int i = 0; i < 3; i++)
{
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, "BIN"[i]);
}

//solar/////////////////////////////

  glColor3ub(181, 101, 29);

glBegin(GL_POLYGON);
glVertex2f(-6,-3);
glVertex2f(-6,-0.5);
glVertex2f(-5.94,-0.5);
glVertex2f(-5.94,-3);
glEnd();


 glColor3ub(178, 178, 178);

glBegin(GL_POLYGON);
glVertex2f(-6.2,-0.5);
glVertex2f(-6.1,-0.24);
glVertex2f(-5.66,-0.24);
glVertex2f(-5.75,-0.5);
glEnd();

 glColor3ub(255,255,255);
 glBegin(GL_LINES);
 glVertex2f(-6.14,-0.36);
 glVertex2f(-5.7,-0.36);
 glEnd();

 //tubewell/////////////////////////////

  glColor3ub(173, 216, 245);

glBegin(GL_POLYGON);
glVertex2f(-10.10,-6.6);
glVertex2f(-10.10,-4.7);
glVertex2f(-9.22,-4.7);
glVertex2f(-9.22,-6.6);
glEnd();

glColor3ub(173, 216, 245);

glBegin(GL_POLYGON);
glVertex2f(-9.33,-5.34);
glVertex2f(-8.56,-5.33);
glVertex2f(-8.56,-5.72);
glVertex2f(-9.33,-5.71);
glEnd();

glColor3ub(173, 216, 245);

glBegin(GL_POLYGON);
glVertex2f(-9.33,-5.34);
glVertex2f(-8.82,-5.34);
glVertex2f(-8.56,-6.03);
glVertex2f(-8.8,-6.03);
glEnd();

glColor3ub(139, 69, 19);

glBegin(GL_POLYGON);
glVertex2f(-9.99,-4.75);
glVertex2f(-10.01,-4.4);
glVertex2f(-9.66,-4.4);
glVertex2f(-9.65,-4.75);
glEnd();

glColor3ub(139, 69, 19);

glBegin(GL_POLYGON);
glVertex2f(-10,-4.4);
glVertex2f(-11.2,-5.98);
glVertex2f(-11.12,-6);
glVertex2f(-10,-4.54);
glEnd();

glColor3ub(139, 69, 19);

glBegin(GL_POLYGON);
glVertex2f(-9.93,-6.59);
glVertex2f(-9.95,-7.67);
glVertex2f(-9.57,-7.67);
glVertex2f(-9.57,-6.59);
glEnd();

//grass////////////////////

glColor3ub(34, 139, 34);

glBegin(GL_POLYGON);
glVertex2f(3,2);
glVertex2f(3.51,2.35);
glVertex2f(4,2);
glEnd();

glColor3ub(34, 139, 34);

glBegin(GL_POLYGON);
glVertex2f(4,2);
glVertex2f(4.47,2.37);
glVertex2f(5,2);
glEnd();

glColor3ub(34, 139, 34);

glBegin(GL_POLYGON);
glVertex2f(5,2);
glVertex2f(5.2,2.49);
glVertex2f(5.82,2);
glEnd();

glColor3ub(34, 139, 34);

glBegin(GL_POLYGON);
glVertex2f(5.82,2);
glVertex2f(6.07,2.54);
glVertex2f(6.73,2);
glEnd();

glColor3ub(34, 139, 34);

glBegin(GL_POLYGON);
glVertex2f(6.72,2);
glVertex2f(7.11,2.38);
glVertex2f(7.69,2);
glEnd();


glColor3ub(34, 139, 34);

glBegin(GL_POLYGON);
glVertex2f(7.69,2);
glVertex2f(7.98,2.45);
glVertex2f(8.55,2);
glEnd();

glColor3ub(34, 139, 34);

glBegin(GL_POLYGON);
glVertex2f(8.55,2);
glVertex2f(8.88,2.48);
glVertex2f(9.41,2);
glEnd();

glColor3ub(34, 139, 34);

glBegin(GL_POLYGON);
glVertex2f(9.41,2);
glVertex2f(9.76,2.36);
glVertex2f(10.38,2);
glEnd();

glColor3ub(34, 139, 34);

glBegin(GL_POLYGON);
glVertex2f(10.38,2);
glVertex2f(10.77,2.44);
glVertex2f(11.26,2);
glEnd();

glColor3ub(34, 139, 34);

glBegin(GL_POLYGON);
glVertex2f(11.26,2);
glVertex2f(11.46,2.53);
glVertex2f(12,2);
glEnd();

//dhaner gola///////////////////////

glColor3ub(218, 165, 32);

glBegin(GL_QUADS);
glVertex2f(-13.55,-2.6);
glVertex2f(-13.55,-3.37);
glVertex2f(-12.27,-3.37);
glVertex2f(-12.27,-2.6);
glEnd();

glColor3ub(101, 67, 33);

glBegin(GL_TRIANGLES);
glVertex2f(-12.99,-2.2);
glVertex2f(-13.55,-2.6);
glVertex2f(-12.27,-2.6);
glEnd();

glColor3ub(101, 67, 33);
glBegin(GL_LINES);
glVertex2f(-13.55,-3.37);
glVertex2f(-12.27,-3.37);
glEnd();

//sports club///////////////////////
glColor3ub(128, 0, 128);

glBegin(GL_TRIANGLES);
glVertex2f(-6,-4.22);
glVertex2f(-4.45,-3.26);
glVertex2f(-3.05,-4.22);
glEnd();

//body
glColor3ub(230, 190, 255);

glBegin(GL_QUADS);
glVertex2f(-5.5,-4.2);
glVertex2f(-3.60,-4.22);
glVertex2f(-3.60,-6);
glVertex2f(-5.5,-6);
glEnd();

glColor3ub(128, 0, 128);
glBegin(GL_LINES);
glVertex2f(-3.60,-6);
glVertex2f(-5.5,-6);
glEnd();
//door
glColor3ub(128, 0, 128);

glBegin(GL_QUADS);
glVertex2f(-4.7,-6);
glVertex2f(-4.7,-5.3);
glVertex2f(-4.1,-5.3);
glVertex2f(-4.1,-6);
glEnd();


glColor3ub(128, 0, 128);

glBegin(GL_QUADS);
glVertex2f(-5.47,-4.87);
glVertex2f(-5,-4.86);
glVertex2f(-5,-5.5);
glVertex2f(-5.47,-5.5);
glEnd();

// club text
glColor3ub(255,255,255);
glRasterPos2f(-4.83,-3.82);

for (int i = 0; i < 4; i++)
{
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, "CLUB"[i]);
}

//tree///////////////////////
glColor3ub(139, 69, 19);

glBegin(GL_QUADS);
glVertex2f(-12.2,-3.82);
glVertex2f(-12.21,-2.1);
glVertex2f(-12.09,-2.1);
glVertex2f(-12.09,-3.82);
glEnd();

glColor3ub(0, 100, 0);
drawCircle(-12.33,-2.14,0.2);

glColor3ub(34, 139, 34);
drawCircle(-12.2,-1.87,0.2);

glColor3ub(0, 100, 0);
drawCircle(-11.92,-1.9,0.2);


glColor3ub(50, 205, 50);
drawCircle(-12,-2.2,0.2);

glColor3ub(0, 100, 0);
drawCircle(-12.52,-1.80,0.2);

glColor3ub(0, 128, 0);
drawCircle(-12.08,-1.58,0.2);

glColor3ub(34, 139, 34);
drawCircle(-12.65,-2.13,0.2);

glColor3ub(50, 205, 50);
drawCircle(-11.61,-2,0.2);

//garden/////////////////////

glColor3ub(0, 128, 0);

glBegin(GL_TRIANGLES);
glVertex2f(-14,-8);
glVertex2f(-13.83,-6.3);
glVertex2f(-13.46,-7.99);
glEnd();

glColor3ub(0, 128, 0);

glBegin(GL_TRIANGLES);
glVertex2f(-13.46,-7.99);
glVertex2f(-13.21,-6.31);
glVertex2f(-13,-8);
glEnd();

glColor3ub(124, 252, 0);

glBegin(GL_TRIANGLES);
glVertex2f(-13.46,-7.99);
glVertex2f(-12.69,-6.70);
glVertex2f(-13,-8);
glEnd();

glColor3ub(0, 128, 0);

glBegin(GL_TRIANGLES);
glVertex2f(-13,-8);
glVertex2f(-11.77,-6.89);
glVertex2f(-12.55,-8.01);
glEnd();

glColor3ub(50, 205, 50);

glBegin(GL_TRIANGLES);
glVertex2f(-12.55,-8.01);
glVertex2f(-11.14,-7.55);
glVertex2f(-12,-8);
glEnd();

glColor3ub(0, 128, 0);

glBegin(GL_TRIANGLES);
glVertex2f(-12.55,-8.01);
glVertex2f(-12.32,-6.90);
glVertex2f(-12,-8);
glEnd();


//flower/////////////////////////////
glColor3ub(0, 100, 0);

glBegin(GL_LINES);
glVertex2f(-13,-8);
glVertex2f(-12.22,-6.4);
glEnd();


glColor3ub(255, 0, 0);
drawCircle(-12.14,-6.25,0.075);
drawCircle(-12.24,-6.39,0.075);
drawCircle(-12.14,-6.53,0.075);
drawCircle(-12.04,-6.39,0.075);

glColor3ub(255,215,0);
drawCircle(-12.14,-6.39,0.075);

    glFlush();
}

// Initialization
void myInit()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-14, 14, -8, 10);
}

// MAIN FUNCTION
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 400);
    glutInitWindowPosition(50, 50);

    glutCreateWindow("Village View");

    myInit();

    glutDisplayFunc(village);
    glutTimerFunc(100, update, 0);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutSpecialFunc(specialKeys);
    glutMainLoop();

    return 0;
}
