#include "general.h"

/*Create Line*/
void ownLine(Point t1, Point t2){
	int x1 = t1.x;
	int y1 = t1.y;
	int x2 = t2.x;
	int y2 = t2.y;
	
	line(x1, y1, x2, y2);
}

/*Create Rectangle*/
void ownRectangle(Point t1, Point t2)
{
	int x1 = t1.x;
	int y1 = t1.y;
	int x2 = t2.x;
	int y2 = t2.y;
	
	line(x1, y1, x2, y1);
	line(x1, y1, x1, y2);
	line(x1, y2, x2, y2);
	line(x2, y2, x2, y1);
}

// Function for line-generation 
// using Bresenham's algorithm 
// https://github.com/nowke/cg_lab/blob/master/1_bresenham_line/bresenham_line.cpp
void draw_line_bresenham(int x1, int y1, int x2, int y2, int color){
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	
	if (x2 < x1) incx = -1;
	incy = 1;
	
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	
	if (dx > dy) {
		putpixel(x, y, color);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			putpixel(x, y, color);
		}
	} else {
		putpixel(x, y, color);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			putpixel(x, y, color);
		}
	}
}

