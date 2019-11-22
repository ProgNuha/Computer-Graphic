#include "general.h"

// Function for line-generation 
// using Bresenham's algorithm 
void draw_line_bresenham(int x1, int y1, int x2, int y2){
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;
	int color = LIGHTMAGENTA;

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

// Function for circle-generation 
// using Bresenham's algorithm 
void circle_bresenham(int xc, int yc, int r){ 
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

void drawCircle(int xc, int yc, int x, int y){ 
    putpixel(xc+x, yc+y, 1); 
    putpixel(xc-x, yc+y, 2); 
    putpixel(xc+x, yc-y, 3); 
    putpixel(xc-x, yc-y, 4); 
    putpixel(xc+y, yc+x, 5); 
    putpixel(xc-y, yc+x, 6); 
    putpixel(xc+y, yc-x, 7); 
    putpixel(xc-y, yc-x, 8); 
} 

// get point for pivot in polygon
Point circlePoint(Point pivot,int r){
	Point p;
	
	int x = 0, y = r; 
	p.x = pivot.x + x;
	p.y = pivot.y + y;
	
	return p;
}


/*=============================================================================================*/
/*=--------------------------------------- ETS ---------------------------------------=*/
/*=============================================================================================*/
Point translation(Point d, Point p){
	
	Point pivot;
	pivot.x = p.x + d.x;
	pivot.y = p.y + d.y;
	return pivot;
}

Point translation_matrix(Point t, Point p){
//	int matrix [3][3] = {
//		{1,0,t.x},
//		{0,1,t.y},
//		{0,0,1}
//	}

	Point pivot;
	pivot.x = p.x + t.x;
	pivot.y = p.y + t.y;
	return pivot;
}

Point scaling_matrix(Point t, Point p,float scale){
//	int matrix [3][3] = {
//		{scale,0,t.x},
//		{0,scale,t.y},
//		{0,0,1}
//	}
	
	Point pivot;
	pivot.x = (int)(scale*p.x) + (int)(scale*(-1*t.x)) + t.x;
	pivot.y = (int)(scale*p.y) + (int)(scale*(-1*t.x)) + t.y;
	return pivot;
}

Point ownRotate1(int x, int y, int pivot_x, 
				int pivot_y, double angle){
	Point p1;
	double radian=angle*(-0.01745);
	p1.x=abs(pivot_x +((x-pivot_x)*cos(radian)-(y-pivot_y)*sin(radian)));
	p1.y=abs(pivot_y +((x-pivot_x)*sin(radian)+(y-pivot_y)*cos(radian)));
	
	return p1;
}

Point rotate_cw(Point center, Point pivot, double angle){
	Point p1;
	double radian=angle*(-0.01745);
	
	p1.x=abs(pivot.x +((center.x-pivot.x)*cos(radian)-(center.y-pivot.y)*sin(radian)));
	p1.y=abs(pivot.y +((center.x-pivot.x)*sin(radian)+(center.y-pivot.y)*cos(radian)));
	
	return p1;
}

Point rotate_ccw(Point center, Point pivot, double angle){
	Point p1;
	double radian=angle*(-0.01745);
	
	p1.x=abs(pivot.x +((center.x-pivot.x)*cos(radian)+(center.y-pivot.y)*sin(radian)));
	p1.y=abs(pivot.y +((center.x-pivot.x)*(-sin(radian))+(center.y-pivot.y)*cos(radian)));
	
	return p1;
}


void poligon(int n, Point pivot, Point p){
	/* Define Point */
	Point temp,temp1;
	int angle = 360/n,c_angle;
	
	temp = pivot;
	temp1 = p;
	
	for(int i=0;i<n;i++){
		c_angle = (i+1)*angle;
		temp = rotate_cw(p, pivot, c_angle);
		draw_line_bresenham(temp1.x, temp1.y, temp.x, temp.y);
		temp1 = temp;		
	}	
}

void poligon_pattern(int edge, Point pivot, Point p, int radius){
	/* Define Point */
	Point temp,temp1,temp2;
	int angle = 360/edge,c_angle;
	
	temp = pivot;
	temp1 = p;
	
	for(int i=0;i<8;i++){
		c_angle = (i+1)*angle;
		temp = ownRotate1(p.x, p.y, pivot.x, pivot.y, c_angle);
		temp2 = circlePoint(temp,radius);
		poligon(edge, temp, temp2);
		temp1 = temp;
	}	
}

void setcolor_poligon(int n){

	 switch(n)
	 {
	     case 0: setcolor(4); break;	
	     case 1: setcolor(4); break;
	     case 2: setcolor(1); break;
	     case 3: setcolor(1); break;
	     case 4: setcolor(9); break;
	     case 5: setcolor(9); break;
	     case 6: setcolor(14); break;
	     case 7: setcolor(14); break;
	     default:setcolor(4); break;
	}
}

void pattern(){
	/* Define Variable */
	Point center, pivot;
	int edge = 8, radius = 150;
	
	/* add value */
	center.x = 350;
	center.y = 350;
	pivot.x = 350;
	pivot.y = center.y - radius;
	
	while(radius >= 0){
		poligon_pattern(edge, center, pivot, radius);
		radius -= 45;
		pivot.y  = center.y - radius;
		
	}
	
}

//void translasi_poligon(){
//		delta.x = 0;
//	delta.y = 30;
//	
//	while(pivot.y<height-radius){
//		poligon_pattern(edge, pivot, p , radius);
//		pivot = translation(delta,pivot);
//		p = translation(delta,p);
//		delay(100);
//		cleardevice(); 
//	}
//	
//	delta.x = -30;
//	delta.y = 0;
//	
//	while(pivot.x>radius){
//		poligon_pattern(edge, pivot, p , radius);
//		pivot = translation(delta,pivot);
//		p = translation(delta,p);
//		delay(100);
//		cleardevice(); 
//	}
//	
//	delta.x = 0;
//	delta.y = -30;
//	
//	while(pivot.y>radius){
//		poligon_pattern(edge, pivot, p , radius);
//		pivot = translation(delta,pivot);
//		p = translation(delta,p);
//		delay(100);
//		cleardevice(); 
//	}
//}

void scaling_polygon(){
		Point p, pivot, temp_pivot, temp_p, delta ,t;
	int edge = 8, radius = 150;
	
		/* add value */
	pivot.x = 350;
	pivot.y = 350;
	p.x = 350;
	p.y = pivot.y - radius;

	t.x = -350;
	t.y = -350;
	poligon(8,pivot,p);
	t.x = 350;
	t.y = 350;
	
//	pivot = scaling_matrix(t,pivot,0.5);
	p = scaling_matrix(t,p,0.5);
	poligon(8,pivot,p); 
	
	pivot.x = 350;
	pivot.y = 350;
	p.x = 350;
	p.y = pivot.y - radius;
	
//	pivot = scaling_matrix(t,pivot,2);
	p = scaling_matrix(t,p,2);
	poligon(8,pivot,p); 
	
}

	
