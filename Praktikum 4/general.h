//#ifndef GENERAL_H_INCLUDED
//#define GENERAL_H_INCLUDED

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
/*=--------------------------------------- Praktikum 4 ---------------------------------------=*/
/*=============================================================================================*/

void line_bresenham(int x1, int y1, int x2, int y2, int color);

void line_DDA(Point p1, Point p2);

Point translation(int dX, int dY, int x, int y);

void line_DDA_translation(Point p1, Point p2);

void bresenham_line_translation(int xa, int ya, int xb, int yb);

void square(Point p1, Point p2, Point p3);

void v_square_translation(Point p1, Point p2, Point p3);

void h_square_translation(Point p1, Point p2, Point p3);

void square_translation(Point p1, Point p2, Point p3, Point p4, Point p5);

void looping_square(Point p1, Point p2, Point p3, Point p4, Point p5);

void square_batik();

void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry);

void ellipseMidpointTranlation(int xCenter, int yCenter, int Rx, int Ry, int dX, int dY);

void ellipsePlotPoints(int xCenter, int yCenter, int x, int y);

void ellipse(Point center, int rx, int ry);

void flower_batik(Point center,int rx, int ry);

void flower(Point center, int rx, int ry);

void batik();


