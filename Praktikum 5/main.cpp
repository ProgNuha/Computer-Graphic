#include "general.h"

main(int argc, char *argv[])
{
	/* Input size of canvas */
	int height, width;
	printf("Height = ");
	scanf("%d", &height);
	printf("Width = ");
	scanf("%d", &width);
	initwindow(height,width, "PRAKTIKUM KOMPUTER GRAFIK - 1711050");	// init window graphics
	
	
	/*=================Create Triangle=================*/
	/* Define Point */
	Point p1,p2;
	/* Define point of line */
	p1.x = 100;
	p1.y = 100;
	p2.x = 200;
	p2.y = 100;
	/* Draw a line */
	line_DDA(p1,p2);
	/* Define angle */
	int angle = 60;
	/* Draw a triangle */
 	ownTriangle(p1.x, p1.y, p2.x, p2.y,angle);
 	delay(1500);
	cleardevice();
	/*=============End of Create Triangle==============*/


	/*=================Create Poligon=================*/
	/* Define Point */
	Point p3,p4,temp,temp1;
	/* Define point of line */
	p3.x = 200;
	p3.y = 200;
	p4.x = 200;
	p4.y = 50;

	int n = 3;
	int angle = 360/n;
	
	for(int i=0;i<36;i++){
		poligon(n,p3,p4);
		n++;
		delay(500);
		cleardevice();
	}
	delay(1500);
	cleardevice();
	/*=============End of Create Poligon=============*/


	getch();
	closegraph();	
	return 0;

}
