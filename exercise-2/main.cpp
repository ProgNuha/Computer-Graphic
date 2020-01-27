#include "general.h"

main(int argc, char *argv[])
{
	/* Input size of canvas */
	int height, width;
	printf("Height = ");
	scanf("%d", &height);
	printf("Width = ");
	scanf("%d", &width);
	initwindow(width,height, 
		"PRAKTIKUM KOMPUTER GRAFIK - 1711050");	// init window graphics
	
	/*=================================================================================*/
	/* Input amount of pixel */
	int number_of_points;
	printf("Points = ");
	scanf("%d", &number_of_points);

	/* pixel */
	Point points;
	for(int increment = 0;increment<number_of_points;increment++){	
		points.x = rand()%getmaxx();			// random the value of x
		points.y = rand()%getmaxy();			// random the value of y
		putpixel(points.x,points.y,rand()%15+1);	// show pixel, with random the color
	}
 	/*=================================================================================*/
 	
 	
 	/*=================================================================================*/
	/* Input amount of line */
	int number_of_lines;
	printf("Line = ");
	scanf("%d", &number_of_lines);
	
	/* line */
	Point point1,point2;
	for(int i = 0;i<number_of_lines;i++){
		point1.x = rand()%getmaxx();	// random the value of x
		point1.y = rand()%getmaxy();	// random the value of y
		point2.x = rand()%getmaxx();	// random the value of x
		point2.y = rand()%getmaxy();	// random the value of y
		draw_line_bresenham(point2.x,point2.y,point1.x,point1.y,rand()%15+1);
	}
 	/*=================================================================================*/


	/* clear canvas */
	cleardevice();



	/*=================================================================================*/
	/* Input margin */
	int counter_line,margin,color;
	printf("Margin = ");
	scanf("%d", &margin);

	/* create square with 2 line using function and the other using putpixel */
	counter_line = margin;
	color = rand()%15+1;		// random color
	
	/* create square */
	/* 2 line using function */
	draw_line_bresenham(margin,margin,getmaxx()-margin,margin,color);
	draw_line_bresenham(margin,getmaxx()-margin,getmaxx()-margin,getmaxx()-margin,color);
	/* 2 line using putpixel */
	for(counter_line;counter_line-1<getmaxx()-margin;counter_line++){
		putpixel(margin,counter_line,color);
		putpixel(getmaxx()-margin,counter_line,color);
	}
	/*=================================================================================*/
	
	
	/*=================================================================================*/
	/* fine 4 corners of rectangle */
	Point corner;
	for(int increment_y = 0;increment_y<getmaxy();increment_y++){
		for(int increment_x = 0;increment_x<getmaxx();increment_x++){
			/* upper left corner */
			if(getpixel(increment_x,increment_y) == color && getpixel(increment_x+1,increment_y) == color && getpixel(increment_x,increment_y+1) == color){
				printf("Koordinat titik sudut kiri atas =  (%d,%d)\n", increment_y,increment_y);
			}
			/* upper right corner */
			if(getpixel(increment_x,increment_y) == color && getpixel(increment_x-1,increment_y) == color && getpixel(increment_x,increment_y+1) == color){
				printf("Koordinat titik sudut kanan atas =  (%d,%d)\n", increment_y,increment_y);
			}
			/* bottom left corner */
			if(getpixel(increment_x,increment_y) == color && getpixel(increment_x+1,increment_y) == color && getpixel(increment_x,increment_y-1) == color){
				printf("Koordinat titik sudut kiri bawah =  (%d,%d)\n", increment_y,increment_y);
			}
			/* bottom right corner */
			if(getpixel(increment_x,increment_y) == color && getpixel(increment_x-1,increment_y) == color && getpixel(increment_x,increment_y-1) == color){
				printf("Koordinat titik sudut kanan bawah = (%d,%d)\n", increment_y,increment_y);
				corner.x = increment_x;
				corner.y = increment_y;
			}
		}	
	}
	/*=================================================================================*/
		

	getch();
	closegraph();	
	return 0;

}
