#include "general.h"

main(int argc, char *argv[])
{
	/* Input size of canvas */
	int height, width;
	printf("Height = ");
	scanf("%d", &height);
	printf("Width = ");
	scanf("%d", &width);
	initwindow(width,height, "PRAKTIKUM KOMPUTER GRAFIK - 1711050");	// init window graphics
	
	initwindow(500,500, "PRAKTIKUM KOMPUTER GRAFIK - 1711050");	// init window graphics
	
	/* Translasi titik */
	Point p1,p2;
	printf("Point 1\n");
	printf("x : ");
	scanf("%d", &p1.x);
	printf("y : ");
	scanf("%d", &p1.y);
	
	putpixel(p1.x, p1.y, 3);
	
	printf("Ditranslasikan sejauh >> \n");
	printf("x : ");
	scanf("%d", &p2.x);
	printf("y : ");
	scanf("%d", &p2.y);
	
	Point dp = translation(p2.x, p2.y, p1.x, p2.x);
	putpixel(dp.x, dp.y, 7);

	/* Batik Persegi */
	square_batik();

	Point center;
	int ry = 20;
	int rx = 10;
	center.x = 30;
	center.y = 20;
	
	/* Ellipse */
	ellipseMidpoint(xCenter,yCenter,rx,ry);
	ellipseMidpoint(80,120,ry,rx);
	
	
	getch();
	closegraph();	
	return 0;

}
