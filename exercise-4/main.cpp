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
	
	int color = 7;
	
	/* Translasi titik */
	/*=================================================================================*/
	Point origin_point,translation_point;
	printf("Translasi Titik /n");
	printf("Point 1\n");
	printf("x : ");
	scanf("%d", &origin_point.x);
	printf("y : ");
	scanf("%d", &origin_point.y);
	
	putpixel(translation_point_1.x, translation_point_1.y, color);
	
	printf("Ditranslasikan sejauh >> \n");
	printf("x : ");
	scanf("%d", &translation_point.x);
	printf("y : ");
	scanf("%d", &translation_point.y);
	
	Point dp = translation(translation_point.x, translation_point.y, origin_point.x, origin_point.x);
	putpixel(dp.x, dp.y, color+3);
	delay(1500);
	cleardevice();
	/*=================================================================================*/


	/* Create Ellips */
	/*=================================================================================*/
	Point center;
	int ry = 80;
	int rx = 30;
	center.x = 150;
	center.y = 120;

	ellipseMidpoint(center.x, center.y, rx, ry);
	delay(1500);
	cleardevice();
	/*=================================================================================*/
	
	
	/* Batik Persegi */
	/*=================================================================================*/
	square_batik();
	delay(1500);
	cleardevice();
	/*=================================================================================*/
	
	/* Batik Elips */
	/*=================================================================================*/
	Point start_point;
	start_point.x = 10;
	start_point.y = 10;
	int Rx = 5, Ry = 10;

	flower_batik(start_point,Rx,Ry);
	delay(1500);
	cleardevice();
	/*=================================================================================*/
	

	getch();
	closegraph();	
	return 0;

}
