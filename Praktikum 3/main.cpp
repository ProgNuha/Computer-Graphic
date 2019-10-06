#include "general.h"
#include "praktikum-3.h"

main(int argc, char *argv[])
{
	/* next version canvas dijadikan function, input point dijadikan function, tiap nomer dijadikan function*/
	/* Input size of canvas */
	int height, width;
	printf("Height = ");
	scanf("%d", &height);
	printf("Width = ");
	scanf("%d", &width);
	initwindow(width,height, "PRAKTIKUM KOMPUTER GRAFIK - 1711050");	// init window graphics
	
//	/* Input point */
//	Point p1,p2;
//	printf("Point 1\n");
//	printf("x : ");
//	scanf("%d", &p1.x);
//	printf("y : ");
//	scanf("%d", &p1.y);
//	printf("Point 2\n");
//	printf("x : ");
//	scanf("%d", &p2.x);
//	printf("y : ");
//	scanf("%d", &p2.y);
//	
//	line_bresenham(p1.x,p1.y,p2.x,p2.y);
//
//	/* Input point for line break*/
//	Point q1,q2;
//	int break_;
//	printf("Point 1\n");
//	printf("x : ");
//	scanf("%d", &q1.x);
//	printf("y : ");
//	scanf("%d", &q1.y);
//	printf("Point 2\n");
//	printf("x : ");
//	scanf("%d", &q2.x);
//	printf("y : ");
//	scanf("%d", &q2.y);
//	printf("Break :");		//break
//	scanf("%d", &break_);
//	
//	breakline1_bresenham(q1.x,q1.y,q2.x,q2.y,break_);
//	breakline_bresenham(q1.x,q1.y,q2.x,q2.y,break_);
//
//	/* Input point for line with custom thick*/
//	Point r1,r2;
//	int thickness;
//	printf("Point 1\n");
//	printf("x : ");
//	scanf("%d", &r1.x);
//	printf("y : ");
//	scanf("%d", &r1.y);
//	printf("Point 2\n");
//	printf("x : ");
//	scanf("%d", &r2.x);
//	printf("y : ");
//	scanf("%d", &r2.y);
//	printf("Thickness :");
//	scanf("%d", &thickness);
//	
//	thickness_line_bresenham(r1.x,r1.y,r2.x,r2.y,thickness);
//
//	/* Input point for circle with 
//	custom center point and radius*/
//	Point c1;
//	int radius;
//	printf("Center Point\n");
//	printf("x : ");
//	scanf("%d", &c1.x);
//	printf("y : ");
//	scanf("%d", &c1.y);
//	printf("Radius :");
//	scanf("%d", &radius);
//	
//	
//	circle_bresenham(c1.x,c1.y,radius);

	/* Input point for circle with 
	custom center point and radius*/
	Point c1;
	int radius;
//	printf("Center Point\n");
//	printf("x : ");
//	scanf("%d", &c1.x);
//	printf("y : ");
//	scanf("%d", &c1.y);
//	printf("Radius :");
//	scanf("%d", &radius);
	
	
	/* Create emoji smiley */
	
	circle_bresenham(250,250,200);
	circle_bresenham(320,150,50);
	circle_bresenham(180,150,50);
	quarter_circle_bresenham(250,250,150);
	

	getch();
	closegraph();	
	return 0;

}



