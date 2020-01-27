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
Point rotate_cw(Point p, Point t, double angle);
Point rotate_ccw(Point center, Point pivot, double angle);
Point scaling_matrix(Point t, Point p,float scale);

/*=============================================================================================*/
/*=----------------------------------------- Animated ----------------------------------------=*/
/*=============================================================================================*/

void poligon(int n, Point pivot, Point p);

void poligon_pattern(int edge, Point pivot, Point p, int radius);

void poligon_pattern_rotate(int edge, Point pivot, Point p, int radius);

void pattern();

void animated_translation_polygon(Point pivot, Point t, int edge, int radius);
void looping_translation_polygon(Point pivot,Point t, int radius);
Point tranlation_point(int i);

void animated_scale_polygon(Point pivot, Point p, int radius,int edge);
void loop_scale_poligon(Point pivot, Point p, int radius, int edge);

void animated_rotate_polygon(Point pivot, int radius, double angle,int edge);
void looping_rotate_polygon(Point pivot, int radius, double angle);

void clear_screen(int time_delay);


/*=============================================================================================*/
/*=----------------------------------------- - - - - ----------------------------------------=*/
/*=============================================================================================*/
void looping_rotate_and_scale_polygon(Point pivot, int radius,double angle);
void line_circuit(int edge, Point pivot, Point p, int radius,int stop);

Point return_line_bresenham(int x1, int y1, int x2, int y2,int stop);
bool return_point(int count, int stop);


void setcolor_poligon(int n);

