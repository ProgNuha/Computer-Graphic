#include "general.h"

main(int argc, char *argv[])
{

	/* Define size of canvas */
	int height = 500, width = 500;
//	initwindow(height, width, "PRAKTIKUM KOMPUTER GRAFIK - 1711050");	// init window graphics
//	
//	/*=================Create Triangle=================*/
//	/* Define Point */
//	Point p1,p2;
//	/* Define point of line */
//	p1.x = 100;
//	p1.y = 100;
//	p2.x = 200;
//	p2.y = 100;
//	/* Draw a line */
//	line_DDA(p1,p2);
//	/* Define angle */
//	int angle = 60;
//	/* Draw a triangle */
// 	ownTriangle(p1.x, p1.y, p2.x, p2.y,angle);
//	/*=============End of Create Triangle==============*/
	
//	delay(1000);
//	closegraph();
	initwindow(height, width, "PRAKTIKUM KOMPUTER GRAFIK - 1711050");
	
	/*=================Create Flower Batik=================*/
	/* Define Point */
	Point p3;
	/* Define point of line */
	p3.x = 10;
	p3.y = 10;
	/* Define Rx and Ry */
	int Rx = 5, Ry = 10;
	/* Draw Flower Batik */
	flower_batik(p3,Rx,Ry);
	/*=============End of Create Flower Batik=============*/
 	
// 	delay(1000);
//	closegraph();
//	initwindow(height, width, "PRAKTIKUM KOMPUTER GRAFIK - 1711050");
 	
//	square_batik();


	getch();
	closegraph();	
	return 0;

}
