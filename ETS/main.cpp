#include "general.h"

main(int argc, char *argv[])
{

	/* Define size of canvas */
	int height = 700, width = 700;
	initwindow(height, width, "ETS KOMPUTER GRAFIK - 1711050");	// init window graphics

	/*=================Create Poligon=================*/

	/* Define Variable */
	Point p, pivot, temp_pivot, temp_p, delta ,t;
	int edge = 8, radius = 150;
	
	/* add value */
	pivot.x = 350;
	pivot.y = 350;
	p.x = 350;
	p.y = pivot.y - radius;

	t.x = -350;
	t.y = -350;
	
	scaling_polygon();
	

	

	

	getch();
	closegraph();	
	return 0;

}
