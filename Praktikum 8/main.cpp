
#include <GL/glut.h>

int Width, Height;
GLfloat Widthfactor;
GLfloat Heightfactor;
GLfloat Zoom = 0.5;
GLint spin_x = 10;
GLint spin_y = 0;
GLfloat New_x;
GLfloat New_y;
GLfloat train_try = 0;
GLfloat train_trx = 0;
float angle = 0.0, x=-4;

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

void background()
{
	glColor3f(0.6,0.6,1);glRecti(-3,-2,3,0); //green grass
	glColor3f(0.6,0.6,1);glRecti(-3,0,3,2); //sky
	
	glPushMatrix();
		glTranslated(1.7,0.6,0);glScalef(0.3,0.3,0.1);	
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(1.5,0.8,0);glScalef(0.3,0.3,0.1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(-1.6,0.4,0);glScalef(0.23,0.23,0.1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(-1.4,0.6,0);glScalef(0.23,0.23,0.1);
	glPopMatrix();

}

void DrawScene() {
   glPushMatrix(); //Right Wheel Far
	   glColor3f(1,1,1); 
	   glTranslated(0.75,-0.5, -0.5);
	   glRotated(angle,0,0,1); 
	   glutWireTorus (0.1,0.2,10,10);
   glPopMatrix();

   glPushMatrix(); //Left Wheel Far
	   glColor3f(1,1,1); 
	   glTranslated(-0.75,-0.5, -0.5);
	   glRotated(angle,0,0,1); 
	   glutWireTorus (0.1,0.2,10,10);
   glPopMatrix();

   glPushMatrix(); //Train BOX
	   glColor3f(0,0,0); 
	   glScalef(2,1,1); 
	   glutSolidCube(1);
	   glColor3f(0,0,0); 
	   glutWireCube(1);
   glPopMatrix();

   glPushMatrix(); //Train Connection Boxes
	   glColor3f(0,0,0); 
	   glTranslated(1,-0.35,0);
	   glScaled(1,0.09,0.09); 
	   glutSolidCube(1);
   glPopMatrix();

   glPushMatrix(); //Right Wheel Far
	   glColor3f(1,1,1); 
	   glTranslated(0.75,-0.5, 0.5);
	   glRotated(angle,0,0,1); 
	   glutWireTorus (0.1,0.2,10,10);
   glPopMatrix();

   glPushMatrix(); //Left Wheel Far
	   glColor3f(1,1,1); 
	   glTranslated(-0.75,-0.5, 0.5);
	   glRotated(angle,0,0,1); 
	   glutWireTorus (0.1,0.2,10,10);
   glPopMatrix();

   angle-=0.2;
  

}

void MyDisplay() {
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode (GL_PROJECTION); glLoadIdentity();
   glOrtho (-3,3,-2,2,-4,4);    background();
   glRotatef(spin_x,1.0,1.0,0.0);
   
   glTranslatef(train_trx,train_try,0); // to move train
   glScaled(Zoom,Zoom,Zoom);
 
   glPushMatrix();
   	glTranslated (-2.4,0,0); DrawScene();
   glPopMatrix();
   glPushMatrix();
   	glTranslated (0,0,0); DrawScene();
   glPopMatrix();
   glPushMatrix();
   	glTranslated (2.4,0,0); DrawScene();
   glPopMatrix();
   
   glutSwapBuffers();
}

void MyReshape(int NewWidth, int NewHeight) {
	Widthfactor = (GLfloat)NewWidth / (GLfloat)500;
	Heightfactor = (GLfloat)NewHeight / (GLfloat)500;

}


void MySpecial(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
	{
		spin_y += 1;
		spin_y = spin_y % 360;
		DrawScene();
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_DOWN:
	{
		spin_y -= 1;
		spin_y = spin_y % 360;
		DrawScene();
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_LEFT:
	{
		spin_x += 1;
		spin_x = spin_x % 360;
		DrawScene();
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		spin_x -= 1;
		spin_x = spin_x % 360;
		DrawScene();
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_HOME:
		{
			train_trx -= 0.1;
			DrawScene();
			glutPostRedisplay();;
			break;
		}
	case GLUT_KEY_END:
		{
			train_trx += 0.1;
			DrawScene();
			glutPostRedisplay();
			break;
		}
	case GLUT_KEY_PAGE_UP:
	{
		Zoom = Zoom + 0.01;
		DrawScene();
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_PAGE_DOWN:
	{
		if (Zoom >= 0) {
			Zoom = Zoom - 0.01;
			DrawScene();
		}
		glutPostRedisplay();
		break;
	}
	}
}

void MyMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		New_x = x;
		New_y = y;
	}
}
void MyMotion(int x, int y)
{
	spin_x = x - New_x;
	spin_y = y - New_y;
	DrawScene();
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	Width = 500;
	Height = 500;
	     glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Kereta Api");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutSpecialFunc(MySpecial);
	glutMouseFunc(MyMouse);
	glutMotionFunc(MyMotion);
	glutMainLoop();
	return 0;
}
