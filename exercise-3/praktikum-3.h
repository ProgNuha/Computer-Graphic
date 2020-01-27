#include<graphics.h>
#include<conio.h>
#include<stdio.h> 
#include<stdlib.h> 
#include<dos.h>
#include<math.h>

typedef struct{
	int x,y;
}Point;

void line_bresenham(int x1, int y1, int x2, int y2, int color);

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
void breakline_bresenham(int x1, int y1, int x2, int y2, int color, int space);

// function for line generation 
void thickness_line_bresenham(int x1, int y1, int x2, int y2, int color, int thickness);



