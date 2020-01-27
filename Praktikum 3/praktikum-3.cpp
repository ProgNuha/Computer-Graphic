#include "praktikum-3.h"

void line_bresenham(int x1, int y1, int x2, int y2, int color) 
{ 
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

// Function to put pixels 
// at subsequence points 
void drawCircle(int xc, int yc, int x, int y) 
{ 
    putpixel(xc+x, yc+y, 1); 
    putpixel(xc-x, yc+y, 2); 
    putpixel(xc+x, yc-y, 3); 
    putpixel(xc-x, yc-y, 4); 
    putpixel(xc+y, yc+x, 5); 
    putpixel(xc-y, yc+x, 6); 
    putpixel(xc+y, yc-x, 7); 
    putpixel(xc-y, yc-x, 8); 
} 

void drawHalfCircle(int xc, int yc, int x, int y) 
{ 
    putpixel(xc-x, yc-y, 4); 
    putpixel(xc-y, yc-x, 8);
	putpixel(xc+y, yc-x, 7); 
	putpixel(xc+x, yc-y, 3); 
} 

void drawQuarterCircle(int xc, int yc, int x, int y) 
{ 
    putpixel(xc+x, yc+y, 1); 
    putpixel(xc-x, yc+y, 2);
} 


// Function for circle-generation 
// using Bresenham's algorithm 
void quarter_circle_bresenham(int xc, int yc, int r) 
{ 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawQuarterCircle(xc, yc, x, y); 
    while (y >= x) 
    { 
        // for each pixel we will 
        // draw all eight pixels 
          
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
        drawQuarterCircle(xc, yc, x, y); 
    } 
    
    line_bresenham(xc+x, yc+y,xc-x, yc+y,7);
	line_bresenham(250,180,250,320,7); 
} 

// Function for circle-generation 
// using Bresenham's algorithm 
void half_circle_bresenham(int xc, int yc, int r) 
{ 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawHalfCircle(xc, yc, x, y); 
    while (y >= x) 
    { 
        // for each pixel we will 
        // draw all eight pixels 
          
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
        drawHalfCircle(xc, yc, x, y); 
//        delay(50); 
    } 
} 

// Function for circle-generation 
// using Bresenham's algorithm 
void circle_bresenham(int xc, int yc, int r) 
{ 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(xc, yc, x, y); 
    while (y >= x) 
    { 
        // for each pixel we will 
        // draw all eight pixels 
          
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
        drawCircle(xc, yc, x, y); 
//        delay(50); 
    } 
} 

void breakline_bresenham(int x1, int y1, int x2, int y2, int color, int space) 
{ 
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
			
			if(x % space != 0){
				putpixel(x, y, color);
				delay(100);
			}
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
			if(y % space != 0){
				putpixel(x, y, color);
				delay(100);
			}
		}
	}
} 

// function for line generation 
void thickness_line_bresenham(int x1, int y1, int x2, int y2, int color, int thickness) 
{ 
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
		for(int increment=0;increment<thickness;increment++){
			putpixel(x,y+increment,color);
		}
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
			for(int increment=0;increment<thickness;increment++){
				putpixel(x,y+increment,color);
			}
		}
	} else {
		for(int increment=0;increment<thickness;increment++){
			putpixel(x+increment,y,color);
		}
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
			for(int increment=0;increment<thickness;increment++){
				putpixel(x+increment,y,color);
			}
		}
	}
} 



