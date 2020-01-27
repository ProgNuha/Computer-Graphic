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
