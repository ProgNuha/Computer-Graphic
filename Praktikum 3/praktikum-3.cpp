#include "general.h"
#include "praktikum-3.h"

void line_bresenham(int xa, int ya, int xb, int yb) { 
	int dx = abs(xa-xb), dy = abs(ya-yb);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyDx = 2 * (dy - dx);
	int x,y,xEnd;
	
	/**/
	if(xa>xb){
		x = xb;
		y = yb;
		xEnd = xa;
	} else {
		x = xa;
		y = ya;
		xEnd = xb;
	}
	putpixel(x,y,3);
	delay(10);
	
	while(x<xEnd){
		x++;
		if(p<0){
			p += twoDy;
		} else {
			y++;
			p += twoDyDx;
		}
		putpixel(x,y,3);
		delay(10);
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
    
    line_bresenham(xc+x, yc+y,xc-x, yc+y);
	line_bresenham(250,180,250,320); 
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

// function for line generation 

void breakline1_bresenham(int xa, int ya, int xb, int yb,int break_) { 
	int dx = abs(xa-xb), dy = abs(ya-yb);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyDx = 2 * (dy - dx);
	int x,y,xEnd;
	
	/**/
	if(xa>xb){
		x = xb;
		y = yb;
		xEnd = xa;
	} else {
		x = xa;
		y = ya;
		xEnd = xb;
	}
	if(xa % break_!= 0){
			putpixel(x,y,5);
			delay(100);
		} else {
			xa += break_;
			ya += break_;
		}
	
	while(x<xEnd){
		x++;
		if(p<0){
			p += twoDy;
		} else {
			y++;
			p += twoDyDx;
		}
	if(xa % break_!= 0){
			putpixel(x,y,5);
			delay(100);
		} else {
			xa += break_;
			ya += break_;
		}
	
	}
} 

void breakline_bresenham(int x1, int y1, int x2, int y2, int break_) 
{ 
	int m_new = 2 * (y2 - y1); 
	int slope_error_new = m_new - (x2 - x1); 
	
	for (int x = x1, y = y1; x <= x2; x++) { 
		if(x % break_!= 0){
			putpixel(x,y,5);
			delay(100);
		} else {
			x += break_;
			y += break_;
		}
		
		// Add slope to increment angle formed 
		slope_error_new += m_new; 
		
		// Slope error reached limit, time to 
		// increment y and update slope error. 
		if (slope_error_new >= 0){ 
		 y++; 
		 slope_error_new  -= 2 * (x2 - x1); 
		} 
	} 
} 

// function for line generation 
void thickness_line_bresenham(int x1, int y1, int x2, int y2, int thickness) 
{ 
	int m_new = 2 * (y2 - y1); 
	int slope_error_new = m_new - (x2 - x1); 
	for (int x = x1, y = y1; x <= x2; x++) 
	{ 
		for(int xx=0;xx<thickness;xx++){
			putpixel(x,y+xx,7);
		}
		
		// Add slope to increment angle formed 
		slope_error_new += m_new; 
		
		// Slope error reached limit, time to 
		// increment y and update slope error. 
		if (slope_error_new >= 0) 
		{ 
		 y++; 
		 slope_error_new  -= 2 * (x2 - x1); 
		} 
	} 
} 
