#include "general.h"

own_Polygon obj[8];


main(int argc, char *argv[])
{

	/* Define size of canvas */
	int height = 700, width = 700;
	initwindow(width, height, "ETS KOMPUTER GRAFIK - 1711050");	// init window graphics

	/*=================Create Poligon=================*/

	/* Define Variable */
	Point pivot;
	int edge = 6, edges = 13, radius = 150, count= 19,delay = 1000;
	
	/* add value */
	pivot.x = 350;
	pivot.y = 350;
	
	
	for(int counter_edge=edge;counter_edge<=edges;counter_edge+=2){
		poligonPattern(counter_edge,pivot,radius);
	}
	
	animatedScalePolygon(pivot,radius,edge,count+2);
	animatedTranslationPolygon(pivot,radius,edge,count);
	animatedRotatationPolygon(pivot,radius,edge,count);
	
	poligonPatternRotatation(edge,pivot,radius);
	poligonPatternRotatationAndScale(edge,pivot,radius);
	
	
	getch();
	closegraph();	
	return 0;

}
