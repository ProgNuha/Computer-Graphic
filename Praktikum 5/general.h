//#ifndef GENERAL_H_INCLUDED
//#define GENERAL_H_INCLUDED

// Using macros to convert degree to radian 
// and call sin() and cos() as these functions 
// take input in radians 
#define SIN(x) sin(x * 3.141592653589/180) 
#define COS(x) cos(x * 3.141592653589/180) 

#include<graphics.h>
#include<conio.h>
#include<stdio.h> 
#include<stdlib.h> 
#include<dos.h>
#include<math.h>



typedef struct{
	int x,y;
}Point;

void line_bresenham(int x1, int y1, int x2, int y2, int color) ;

Point translation(int dX, int dY, int x, int y);

void bresenham_line_translation(int xa, int ya, int xb, int yb);

void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry);

void ellipseMidpointTranlation(int xCenter, int yCenter, int Rx, int Ry, int dX, int dY);

void ellipsePlotPoints(int xCenter, int yCenter, int x, int y);

void ellipse(Point center, int rx, int ry);

void square(Point t1, Point t2);

void createFlower(Point center, Point r,Point r1);


/*=============================================================================================*/
/*=--------------------------------------- Praktikum 5 ---------------------------------------=*/
/*=============================================================================================*/

void eightEllipseMidpoint(int xCenter, int yCenter, int Rx, int Ry);

void ownTriangle(int x, int y, int pivot_x, int pivot_y, double angle);

Point ownRotate1(int x, int y, int pivot_x, int pivot_y, double angle);

void eightRotate(Point center, Point r);

void ellipse8PlotPoints(int xCenter, int yCenter, int x, int y);

void poligon(int n, Point pivot, Point p);


