#include <stdlib.h>
#include <GL/glut.h>
#include "BmpLoader.h"

using namespace std;

char title[] = "Praktikum 15";
int refreshMills = 15;
unsigned int ID;
float _angle = 0.0;
GLuint _textureGateway, _textureBricksGateway, _textureBrick, _textureRedBrick, _textureDoor, _textureGrass, _textureRoof, _textureWindow, _textureSky;


void Init();
void KeyboardHandler(unsigned char key, int x, int y);
void Reshape(GLsizei width, GLsizei height);
void Display();
void Timer(int value);
GLuint loadTexture(const char* filename);

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow(title);
	glEnable(GL_DEPTH_TEST);
	
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(KeyboardHandler);
	Init();
//	glutTimerFunc(0, Timer, 0); 
	glutMainLoop();
	return 0;
}

void Display()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// Sky
    glPushMatrix();
    	glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureSky);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glBegin(GL_QUADS); 
            glTexCoord3f(0.0,1.0,1.0);  glVertex3f(-50,8,-10);
            glTexCoord3f(1.0,1.0,1.0);  glVertex3f(50,8,-10);
            glTexCoord3f(1.0,0.0,1.0);  glVertex3f(50,-1.5,-10);
            glTexCoord3f(0.0,0.0,1.0);  glVertex3f(-50,-1.5,-10);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    // Grass
    glPushMatrix();
    	glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureGrass);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);
            glTexCoord3f(0.0,70.0,1);  glVertex3f(-50,-1.5,50);
            glTexCoord3f(0.0,0.0,-1);  glVertex3f(-50,-1.5,-50);
            glTexCoord3f(70.0,0.0,-1);  glVertex3f(50,-1.5,-50);
            glTexCoord3f(70.0,70.0,1);  glVertex3f(50,-1.5,50);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
   /*=================================GAPURA ATAS=======================================*/
   /*Bagian Depan*/
    glPushMatrix();
	    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureBricksGateway);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	    glTranslatef(0,0,-6);
	    glRotatef(_angle, 0.0, 1.0, 0.0);
	    glBegin(GL_QUADS);  // Wall
	        glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-2.1,1.75,1.25);
	        glTexCoord3f(2.0,2.0,0.1);  glVertex3f(2.1,1.75,1.25);
	        glTexCoord3f(2.0,0.0,0.1);  glVertex3f(2.1,1,1.25);
	        glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-2.1,1,1.25);
	    glEnd();
	    
	    glBegin(GL_TRIANGLES); //Depan
	    	glTexCoord3f(0.0,1.0,0); glVertex3f(-2.1,1,1.25);
	    	glTexCoord3f(1.0,0.0,0); glVertex3f(-2.1,1.75,1.25);
	    	glTexCoord3f(-1.0,0.0,-1); glVertex3f(-2.7,1,1.25);
	    glEnd();
		glBegin(GL_QUADS);  // 
	        glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-2.1,1.75,0.5);
	        glTexCoord3f(2.0,2.0,0.1);  glVertex3f(-2.1,1.75,1.25);
	        glTexCoord3f(2.0,0.0,0.1);  glVertex3f(-2.7,1,1.25);
	        glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-2.7,1,0.5);
	    glEnd();
	    
	    
	    glBegin(GL_TRIANGLES); //Depan
	    	glTexCoord3f(0.0,1.0,0); glVertex3f(2.1,1,1.25);
	    	glTexCoord3f(1.0,0.0,0); glVertex3f(2.1,1.75,1.25);
	    	glTexCoord3f(-1.0,0.0,-1); glVertex3f(2.7,1,1.25);
	    glEnd();
		glBegin(GL_QUADS);  // 
	        glTexCoord3f(0.0,2.0,0.1);  glVertex3f(2.1,1.75,0.5);
	        glTexCoord3f(2.0,2.0,0.1);  glVertex3f(2.7,1,0.5);
	        glTexCoord3f(2.0,0.0,0.1);  glVertex3f(2.7,1,1.25);
	        glTexCoord3f(0.0,0.0,0.1);  glVertex3f(2.1,1.75,1.25);
	    glEnd();
	    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    /*Bagian Belakang*/
    glPushMatrix();
	    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureGateway);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	    glTranslatef(0,0,-6);
	    glRotatef(_angle, 0.0, 1.0, 0.0);
	    glBegin(GL_QUADS); 
	        glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-2.1,1.75,0.5);
	        glTexCoord3f(2.0,2.0,0.1);  glVertex3f(2.1,1.75,0.5);
	        glTexCoord3f(2.0,0.0,0.1);  glVertex3f(2.1,1,0.5);
	        glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-2.1,1,0.5);
	    glEnd();
	    
	    glBegin(GL_TRIANGLES); // Kiri
	    	glTexCoord3f(0.0,1.0,0); glVertex3f(-2.1,1,0.5);
	    	glTexCoord3f(1.0,0.0,0); glVertex3f(-2.1,1.75,0.5);
	    	glTexCoord3f(-1.0,0.0,-1); glVertex3f(-2.7,1,0.5);
	    glEnd();
	    
	    glBegin(GL_TRIANGLES); //Belakang
	    	glTexCoord3f(0.0,1.0,0); glVertex3f(2.1,1,0.5);
	    	glTexCoord3f(1.0,0.0,0); glVertex3f(2.1,1.75,0.5);
	    	glTexCoord3f(-1.0,0.0,-1); glVertex3f(2.7,1,0.5);
	    glEnd();
	    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    /*Bagian Bawah*/
    glPushMatrix();
	    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureBricksGateway);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	    glTranslatef(0,0,-6);
	    glRotatef(_angle, 0.0, 1.0, 0.0);
	    glBegin(GL_QUADS);  // Wall
	        glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-2.1,1,1.25);
	        glTexCoord3f(2.0,2.0,0.1);  glVertex3f(-2.1,1,0.5);
	        glTexCoord3f(2.0,0.0,0.1);  glVertex3f(2.7,1,0.5);
	        glTexCoord3f(0.0,0.0,0.1);  glVertex3f(2.7,1,1.25);
	    glEnd();
	    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
   
   
   
   
   /*=================================GAPURA KIRI=======================================*/
    /*Bagian Depan*/
    glPushMatrix();
	    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureGateway);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-2.7,1,1.25);
            glTexCoord3f(2.0,2.0,0.1);  glVertex3f(-2.1,1,1.25);
            glTexCoord3f(2.0,0.0,0.1);  glVertex3f(-2.1,-1.5,1.25);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-2.7,-1.5,1.25);
        glEnd();
        glBegin(GL_QUADS);  // Wall
	        glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-2.1,1.75,1.25);
	        glTexCoord3f(2.0,2.0,0.1);  glVertex3f(2.1,1.75,1.25);
	        glTexCoord3f(2.0,0.0,0.1);  glVertex3f(2.1,1,1.25);
	        glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-2.1,1,1.25);
	    glEnd();
	    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    /*Bagian Belakang*/
    glPushMatrix();
	    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureGateway);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-2.7,1,0.5);
            glTexCoord3f(2.0,2.0,0.1);  glVertex3f(-2.1,1,0.5);
            glTexCoord3f(2.0,0.0,0.1);  glVertex3f(-2.1,-1.5,0.5);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-2.7,-1.5,0.5);
        glEnd();
	    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    /*Bagian Kanan*/
    glPushMatrix();
    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureGateway);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,1); glVertex3f(-2.1,1.75,1.25);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(-2.1,1.75,0.5);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(-2.1,-1.5,0.5);
            glTexCoord3f(0.0,0.0,1); glVertex3f(-2.1,-1.5,1.25);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
	/*Bagian Kiri*/
    glPushMatrix();
    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureGateway);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,1); glVertex3f(-2.7,1,1.25);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(-2.7,1,0.5);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(-2.7,-1.5,0.5);
            glTexCoord3f(0.0,0.0,1); glVertex3f(-2.7,-1.5,1.25);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    
   /*=================================GAPURA KANAN=======================================*/
    /*Bagian Depan*/
    glPushMatrix();
	    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureGateway);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(2.7,1,1.25);
            glTexCoord3f(2.0,2.0,0.1);  glVertex3f(2.1,1,1.25);
            glTexCoord3f(2.0,0.0,0.1);  glVertex3f(2.1,-1.5,1.25);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(2.7,-1.5,1.25);
        glEnd();
	    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    /*Bagian Belakang*/
    glPushMatrix();
	    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureGateway);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(2.7,1,0.5);
            glTexCoord3f(2.0,2.0,0.1);  glVertex3f(2.1,1,0.5);
            glTexCoord3f(2.0,0.0,0.1);  glVertex3f(2.1,-1.5,0.5);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(2.7,-1.5,0.5);
        glEnd();
	    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    /*Bagian Kanan*/
    glPushMatrix();
    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureGateway);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,1); glVertex3f(2.7,1,1.25);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(2.7,1,0.5);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(2.7,-1.5,0.5);
            glTexCoord3f(0.0,0.0,1); glVertex3f(2.7,-1.5,1.25);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    /*Bagian Kiri*/
    glPushMatrix();
    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureGateway);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,1); glVertex3f(2.1,1.75,1.25);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(2.1,1.75,0.5);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(2.1,-1.5,0.5);
            glTexCoord3f(0.0,0.0,1); glVertex3f(2.1,-1.5,1.25);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    
       /*=================================PEMBATAS RUMAH=======================================*/
    	/* Kiri*/
    glPushMatrix();
    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureRedBrick);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,1); glVertex3f(-2.7,0,0.5);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(-2.7,0,-3);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(-2.7,-1.5,-3);
            glTexCoord3f(0.0,0.0,1); glVertex3f(-2.7,-1.5,0.5);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
        	/* Kanan */
    glPushMatrix();
    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureRedBrick);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,1); glVertex3f(2.7,0,0.5);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(2.7,0,-3);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(2.7,-1.5,-3);
            glTexCoord3f(0.0,0.0,1); glVertex3f(2.7,-1.5,0.5);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    
       /*=================================RUMAH=======================================*/
	
	// Bagian Depan
    glPushMatrix();
	    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureBrick);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-2,0,0);
            glTexCoord3f(4.0,2.0,0.1);  glVertex3f(2,0,0);
            glTexCoord3f(4.0,0.0,0.1);  glVertex3f(2,-1.5,0);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-2,-1.5,0);
        glEnd();
        glBindTexture(GL_TEXTURE_2D,_textureRoof);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS); //Atap Depan
	    	glTexCoord3f(0.0,2.0,0); glVertex3f(-2.2,0.5,-1);
	    	glTexCoord3f(4.0,2.0,0); glVertex3f(2.2,0.5,-1);
	    	glTexCoord3f(4.0,0.0,1.25); glVertex3f(2.2,-0.1,0.25);
	    	glTexCoord3f(0.0,0.0,1.25); glVertex3f(-2.2,-0.1,0.25);
	    glEnd();
	    glBindTexture(GL_TEXTURE_2D, _textureDoor);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Door
            glTexCoord3f(0.0,1.0,1.0001);  glVertex3f(-0.3,-0.4,0.0001);
            glTexCoord3f(1.0,1.0,1.0001);  glVertex3f(0.3,-0.4,0.0001);
            glTexCoord3f(1.0,0.0,1.0001);  glVertex3f(0.3,-1.5,0.0001);
            glTexCoord3f(0.0,0.0,1.0001);  glVertex3f(-0.3,-1.5,0.0001);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, _textureWindow);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Window
            glTexCoord3f(0.0,1.0,1.0001);  glVertex3f(1.0,-0.2,0.0001);
            glTexCoord3f(1.0,1.0,1.0001);  glVertex3f(1.6,-0.2,0.0001);
            glTexCoord3f(1.0,0.0,1.0001);  glVertex3f(1.6,-0.8,0.0001);
            glTexCoord3f(0.0,0.0,1.0001);  glVertex3f(1.0,-0.8,0.0001);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, _textureWindow);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Window
            glTexCoord3f(0.0,1.0,1.0001);  glVertex3f(-1.0,-0.2,0.0001);
            glTexCoord3f(1.0,1.0,1.0001);  glVertex3f(-1.6,-0.2,0.0001);
            glTexCoord3f(1.0,0.0,1.0001);  glVertex3f(-1.6,-0.8,0.0001);
            glTexCoord3f(0.0,0.0,1.0001);  glVertex3f(-1.0,-0.8,0.0001);
        glEnd();
	    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    // Bagian Belakang
    glPushMatrix();
    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureBrick);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,-1);  glVertex3f(-2,0,-2);
            glTexCoord3f(4.0,2.0,-1);  glVertex3f(2,0,-2);
            glTexCoord3f(4.0,0.0,-1);  glVertex3f(2,-1.5,-2);
            glTexCoord3f(0.0,0.0,-1);  glVertex3f(-2,-1.5,-2);
        glEnd();
        glBindTexture(GL_TEXTURE_2D,_textureRoof);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS); //Atap Belakang
	    	glTexCoord3f(0.0,2.0,0); glVertex3f(-2.2,0.5,-1);
	    	glTexCoord3f(4.0,2.0,0); glVertex3f(2.2,0.5,-1);
	    	glTexCoord3f(4.0,0.0,1.25); glVertex3f(2.2,-0.1,-2.25);
	    	glTexCoord3f(0.0,0.0,1.25); glVertex3f(-2.2,-0.1,-2.25);
	    glEnd();
	    glBindTexture(GL_TEXTURE_2D, _textureWindow);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Window
            glTexCoord3f(0.0,1.0,1.0001);  glVertex3f(1.0,-0.2,-2.0001);
            glTexCoord3f(1.0,1.0,1.0001);  glVertex3f(1.6,-0.2,-2.0001);
            glTexCoord3f(1.0,0.0,1.0001);  glVertex3f(1.6,-0.8,-2.0001);
            glTexCoord3f(0.0,0.0,1.0001);  glVertex3f(1.0,-0.8,-2.0001);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, _textureWindow);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Window
            glTexCoord3f(0.0,1.0,1.0001);  glVertex3f(-1.0,-0.2,-2.0001);
            glTexCoord3f(1.0,1.0,1.0001);  glVertex3f(-1.6,-0.2,-2.0001);
            glTexCoord3f(1.0,0.0,1.0001);  glVertex3f(-1.6,-0.8,-2.0001);
            glTexCoord3f(0.0,0.0,1.0001);  glVertex3f(-1.0,-0.8,-2.0001);
        glEnd();
		glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    // Kanan
    glPushMatrix();
    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureBrick);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,1); glVertex3f(2,0,0);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(2,0,-2);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(2,-1.5,-2);
            glTexCoord3f(0.0,0.0,1); glVertex3f(2,-1.5,0);
        glEnd();
        glBegin(GL_TRIANGLES); //Atap Kanan
	    	glTexCoord3f(0.0,1.0,0); glVertex3f(2,0.5,-1);
	    	glTexCoord3f(1.0,0.0,0); glVertex3f(2,0,0);
	    	glTexCoord3f(-1.0,0.0,-1); glVertex3f(2,0,-2);
	    glEnd();
	    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    // Kiri
    glPushMatrix();
    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureBrick);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-2,0,0);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-2,0,-2);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-2,-1.5,-2);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-2,-1.5,0);
        glEnd();
		glBegin(GL_TRIANGLES); //Atap Kanan
	    	glTexCoord3f(0.0,1.0,0); glVertex3f(-2,0.5,-1);
	    	glTexCoord3f(1.0,0.0,1); glVertex3f(-2,0,0);
	    	glTexCoord3f(-1.0,0.0,-1); glVertex3f(-2,0,-2);
	    glEnd();
	    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    

    
    

	glutSwapBuffers();
}

void Timer(int value) {
   glutPostRedisplay();
   glutTimerFunc(refreshMills, Timer, 0);
}

void Init(){
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	
	_textureRoof = loadTexture("roof.bmp");
	_textureBrick = loadTexture("bricks.bmp");
	_textureGrass = loadTexture("grass.bmp");
	_textureDoor = loadTexture("door.bmp");
	_textureWindow = loadTexture("window.bmp");
	_textureSky = loadTexture("sky.bmp");
	_textureGateway = loadTexture("gateway.bmp");
	_textureBricksGateway = loadTexture("bricks_gateway.bmp");
	_textureRedBrick = loadTexture("red_bricks.bmp");
}

void Reshape(GLsizei width, GLsizei height) {
	const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void KeyboardHandler(unsigned char key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_RIGHT:  
		_angle += 1;
		if (_angle > 360) _angle = 0.0;
		break;
	case GLUT_KEY_LEFT:
        _angle -= 1;
        if (_angle > 360) _angle = 0.0;
	    break;
	case 'q':
		exit(0);
		break;
	default: 
		break;
	}
	glutPostRedisplay();
}

GLuint loadTexture(const char* filename) {
	BmpLoader bl(filename);	
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGB,
				 bl.iWidth, bl.iHeight,
				 0,
				 GL_RGB,
				 GL_UNSIGNED_BYTE,
				 bl.textureData);
	return textureId;
}
