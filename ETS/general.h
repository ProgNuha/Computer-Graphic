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

/*=============================================================================================*/
/*=------------------------------------------- Line ------------------------------------------=*/
/*=============================================================================================*/

void draw_line_bresenham(int x1, int y1, int x2, int y2);

/*=============================================================================================*/
/*=----------------------------------------- Circle ---------------------------------------=*/
/*=============================================================================================*/

void circle_bresenham(int xc, int yc, int r);
void drawCircle(int xc, int yc, int x, int y);
Point circlePoint(Point pivot,int r);

/*=============================================================================================*/
/*=--------------------------------------- Transformation -------------------------------------=*/
/*=============================================================================================*/

Point translation(Point d, Point p);
Point translation_matrix(Point t, Point p);
Point ownRotate1(int x, int y, int pivot_x, int pivot_y, double angle);
//Point rotate_cw(Point center, Point pivot, double angle);
Point rotate_cw(Point p, Point t, double angle);
Point rotate_ccw(Point center, Point pivot, double angle);
Point scaling_matrix(Point t, Point p,float scale);

/*=============================================================================================*/
/*=----------------------------------------- Poligon -----------------------------------------=*/
/*=============================================================================================*/

void setcolor_poligon(int n);
void poligon(int n, Point pivot, Point p);
void poligon_pattern(int edge, Point pivot, Point p, int radius);
void pattern();
void scaling_polygon();


