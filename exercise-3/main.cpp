#include "praktikum-3.h"


main(int argc, char *argv[])
{
	/* Input size of canvas */
	int height, width;
	printf("Height = ");
	scanf("%d", &height);
	printf("Width = ");
	scanf("%d", &width);
	initwindow(height,width, "PRAKTIKUM KOMPUTER GRAFIK - 1711050");	// init window graphics
	
	int color = 7;
	
	/* Input point for line */
	/*=================================================================================*/
	Point point_line_1,point_line_2;

	printf("Point 1\n");
	printf("x : ");
	scanf("%d", &point_line_1.x);
	printf("y : ");
	scanf("%d", &point_line_1.y);
	printf("Point 2\n");
	printf("x : ");
	scanf("%d", &point_line_2.x);
	printf("y : ");
	scanf("%d", &point_line_2.y);
	
	line_bresenham(point_line_1.x,point_line_1.y,point_line_2.x,point_line_2.y,color);
	delay(1500);
	cleardevice();
	/*=================================================================================*/
	

	/* Input point for dotted line */
	/*=================================================================================*/
	Point point_dotted_line_1,point_dotted_line_2;
	int space;
	printf("Dotted Line (garis putus-putus)\n");
	printf("Point 1\n");
	printf("x : ");
	scanf("%d", &point_dotted_line_1.x);
	printf("y : ");
	scanf("%d", &point_dotted_line_1.y);
	printf("Point 2\n");
	printf("x : ");
	scanf("%d", &point_dotted_line_2.x);
	printf("y : ");
	scanf("%d", &point_dotted_line_2.y);
	printf("Space :");				//space dotted line
	scanf("%d", &space);
	
	breakline_bresenham(point_dotted_line_1.x,point_dotted_line_1.y,
						point_dotted_line_2.x,point_dotted_line_2.y,color,space);
	delay(1500);
	cleardevice();
	/*=================================================================================*/

	/* Input point for thick line*/
	/*=================================================================================*/
	Point point_thick_line_1,point_thick_line_2;
	int thickness;
	printf("Thick Line (garis tebal)\n");
	printf("Point 1\n");
	printf("x : ");
	scanf("%d", &point_thick_line_1.x);
	printf("y : ");
	scanf("%d", &point_thick_line_1.y);
	printf("Point 2\n");
	printf("x : ");
	scanf("%d", &point_thick_line_2.x);
	printf("y : ");
	scanf("%d", &point_thick_line_2.y);
	printf("Thickness :");
	scanf("%d", &thickness);
	
	thickness_line_bresenham(point_thick_line_1.x,point_thick_line_1.y,
							 point_thick_line_2.x,point_thick_line_2.y,color,thickness);
	delay(1500);
	cleardevice();
	/*=================================================================================*/

	/* Input point for circle with 
	custom center point and radius*/
	/*=================================================================================*/
	Point center_point;
	int radius;
	printf("Circle (lingkaran)\n");
	printf("Center Point\n");
	printf("x : ");
	scanf("%d", &center_point.x);
	printf("y : ");
	scanf("%d", &center_point.y);
	printf("Radius :");
	scanf("%d", &radius);
	
	circle_bresenham(center_point.x,center_point.y,radius);
	delay(1500);
	cleardevice();
	/*=================================================================================*/

	
	/* Emoji */
	/*=================================================================================*/
	circle_bresenham(250,250,200);
	circle_bresenham(320,150,50);
	circle_bresenham(180,150,50);
	quarter_circle_bresenham(250,250,150);
	/*=================================================================================*/
	

	getch();
	closegraph();	
	return 0;

}



