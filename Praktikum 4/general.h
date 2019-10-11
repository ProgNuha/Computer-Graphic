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

void ownLine(Point t1,Point t2);
void ownRectangle(Point t1,Point t2);

void bresenham_line(int xa, int ya, int xb, int yb);

/*=============================================================================================*/
/*=--------------------------------------- Praktikum 3 ---------------------------------------=*/
/*=============================================================================================*/

// Function to put pixels 
// at subsequence points 
void drawCircle(int xc, int yc, int x, int y);

void drawHalfCircle(int xc, int yc, int x, int y); 

void drawQuarterCircle(int xc, int yc, int x, int y);

// Function for circle-generation 
// using Bresenham's algorithm 
void quarter_circle_bresenham(int xc, int yc, int r);

// Function for circle-generation 
// using Bresenham's algorithm 
void half_circle_bresenham(int xc, int yc, int r);

// Function for circle-generation 
// using Bresenham's algorithm 
void circle_bresenham(int xc, int yc, int r);

// function for line generation 
void breakline1_bresenham(int xa, int ya, int xb, int yb,int break_);

void breakline_bresenham(int x1, int y1, int x2, int y2, int break_);

// function for line generation 
void thickness_line_bresenham(int x1, int y1, int x2, int y2, int thickness);

/*=============================================================================================*/
/*=--------------------------------------- Praktikum 4 ---------------------------------------=*/
/*=============================================================================================*/

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


