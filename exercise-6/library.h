//#ifndef LIBRARY
//#define LIBRARY

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <gl/glut.h>
#include <gl/freeglut.h>

/*=============================================================================================*/
/*=------------------------------------- Global Variabel -------------------------------------=*/
/*=============================================================================================*/

typedef struct{
   int x,y;
}Point;

typedef struct{
	Point p1, p2;
}Line;

typedef struct{
	int xCenter,yCenter,radius;
}Circle;

typedef struct{
	int xCenter,yCenter,radiusX,radiusY;
}Elips;

typedef struct{
	int R,G,B;
}Color;

/*=============================================================================================*/
/*=----------------------------------------- Extern ------------------------------------------=*/
/*=============================================================================================*/

extern Point point1, point2;
extern Line line;
extern Circle circle;
extern Elips ellips;
extern Color color;

/*=============================================================================================*/
/*=---------------------------------------- Windows ------------------------------------------=*/
/*=============================================================================================*/

void init_windows_glut(int argc, char** argv, int width, int height,const char title[]);

void process_next_screen(unsigned char key, int x, int y);

/*=============================================================================================*/
/*=----------------------------------------- Draw --------------------------------------------=*/
/*=============================================================================================*/

void draw_line_bresenham(int x1, int y1, int x2, int y2);

void draw_line_DDA(Point p1, Point p2);

void draw_circle(int xc, int yc, int r);

void draw_pixel(int x, int y);

void draw_octet_points(int xc, int yc, int x, int y);

void draw_ellips_points(int xCenter, int yCenter, int x, int y);

void draw_ellipse(int xCenter, int yCenter, int Rx, int Ry);

/*=============================================================================================*/
/*=---------------------------------------- Display ------------------------------------------=*/
/*=============================================================================================*/

void displayPoint();

void displayBresenham();

void displayDDA();

void displayCircle();

void displayEllips();

/*=============================================================================================*/
/*=----------------------------------------- View --------------------------------------------=*/
/*=============================================================================================*/

void viewEllips(int argc, char** argv);

void viewCircle(int argc, char** argv);

void viewLineBresenham(int argc, char** argv);

void viewLineDDA(int argc, char** argv);

void viewPoint(int argc, char** argv);

/*=============================================================================================*/
/*=------------------------------------ Transformation ---------------------------------------=*/
/*=============================================================================================*/

Point translation(Point point,int xTr,int yTr);

Point rotation_point_ccw(double angle,Point pointRotation);

Point rotation_point_cw(double angle,Point pointRotation);

Line rotation_line_ccw(double angle,Line lineRotation);

Line rotation_line_cw(double angle,Line lineRotation);

Line reflection_line_x(int x,Line lineReflection);

Line reflection_line_y(int y,Line lineReflection);

Point scaling(Point point,int xSc,int ySc);
