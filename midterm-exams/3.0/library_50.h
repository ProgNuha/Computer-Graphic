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

typedef struct{
	Point pivot,angle;
}own_Polygon;

/*=============================================================================================*/
/*=------------------------------------------- Line ------------------------------------------=*/
/*=============================================================================================*/

void drawLineBresenham(int x1, int y1, int x2, int y2);

/*=============================================================================================*/
/*=----------------------------------------- Circle ---------------------------------------=*/
/*=============================================================================================*/

void circleBresenham(int xc, int yc, int r);
void drawCircle(int xc, int yc, int x, int y);
Point getPointPolygon(Point pivot,int radius);

/*=============================================================================================*/
/*=--------------------------------------- Transformation -------------------------------------=*/
/*=============================================================================================*/

Point pointTranslation(Point translation, Point origin);
Point pointScale(Point translation, Point origin,float scale);
Point pointRotationClockWise(Point origin, Point pivot, double degree);
Point pointRotationCounterClockWise(Point origin, Point pivot, double degree);

/*=============================================================================================*/
/*=----------------------------------------- Poligon -----------------------------------------=*/
/*=============================================================================================*/

int setColorPoligon(int edge);
void poligon(int edge, Point pivot, int radius);
void poligonAngle(int edge, Point pivot, Point angle, int radius);
void poligonAngleRadius(int edge, Point pivot, Point angle, int radius);
void poligonPattern(int edge, Point pivot, int radius);
void poligonPatternRotatation(int edge, Point pivot, int radius);
void poligonPatternRotatationAndScale(int edge, Point pivot, int radius);

/*=============================================================================================*/
/*=----------------------------------------- Animated ----------------------------------------=*/
/*=============================================================================================*/

void animatedScalePolygon(Point pivot, int radius, int edge, int count);
void animatedTranslationPolygon(Point pivot, int radius, int edge, int count);
void animatedRotatationPolygon(Point pivot, int radius, int edge, int count);

/*=============================================================================================*/
/*=---------------------------------------- Additional ---------------------------------------=*/
/*=============================================================================================*/

void clearScreen(int time_delay);
void myDelay(int time_delay);
Point choosePointTranslation(int direction);
Point choosePointTranslation9(int direction);
