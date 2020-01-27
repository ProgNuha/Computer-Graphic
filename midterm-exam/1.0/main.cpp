#include "general.h"

main(int argc, char *argv[])
{

	/* Define size of canvas */
	int height = 700, width = 700;
	initwindow(height, width, "ETS KOMPUTER GRAFIK - 1711050");	// init window graphics

	/*=================Create Poligon=================*/

	/* Define Variable */
	Point p, pivot, temp_pivot, temp_p, delta ,t;
	int edge = 6, radius = 150,edges = 13,delay=500;
	double rotate = 60;
	
	/* add value */
	pivot.x = 350;
	pivot.y = 350;
	p.x = 350;
	p.y = pivot.y - radius;

	t.x = -50;
	t.y = 0;
	
	for(int j=edge;j<=edges;j+=2){
		animated_scale_polygon(pivot,p,radius,j);
		
		for(int i=0;i<4;i++){
			t = tranlation_point(i);
			animated_translation_polygon(pivot, t, j, radius);
		}
		
		poligon_pattern_rotate(j,pivot,p,radius);
		poligon_pattern(j,pivot,p,radius);
		clear_screen(delay);
	}
	
	getch();
	closegraph();	
	return 0;

}
