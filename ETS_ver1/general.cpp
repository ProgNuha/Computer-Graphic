#include "general.h"

// Function for line-generation 
// using Bresenham's algorithm 
void draw_line_bresenham(int x1, int y1, int x2, int y2){
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;
	int color = YELLOW;

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
	Point pivot;
	pivot.x = p.x + t.x;
	pivot.y = p.y + t.y;
	return pivot;
}

Point scaling_matrix(Point t, Point p,float scale){
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
	double rotate =30;
	
	temp = pivot;
	temp1 = p;
	
	for(int i=0;i<edge;i++){
		c_angle = (i+1)*angle;
		temp = ownRotate1(p.x, p.y, pivot.x, pivot.y, c_angle);
		temp2 = circlePoint(temp,radius);
		poligon(edge, temp, temp2);
//		animated_rotate_polygon(temp, radius, rotate, edge);
		temp1 = temp;
	}	
}

void poligon_pattern_rotate(int edge, Point pivot, Point p, int radius){
	/* Define Point */
	Point temp,temp1,temp2;
	int angle = 360/edge,c_angle;
	double rotate =30;
	
	temp = pivot;
	temp1 = p;
	
	for(int i=0;i<edge;i++){
		c_angle = (i+1)*angle;
		temp = ownRotate1(p.x, p.y, pivot.x, pivot.y, c_angle);
		temp2 = circlePoint(temp,radius);
		poligon(edge, temp, temp2);
		animated_rotate_polygon(temp, radius, rotate, edge);
		temp1 = temp;
	}	
}

void animated_scale_polygon(Point pivot, Point p, int radius, int edge){
//	Point p;
	float scale=0.0;
	int count = 8,delay = 200;
	
	if(edge>10){
		count = 9;
	}
//	printf("delay");

	for(int j=0;j<count;j++){
		p = scaling_matrix(pivot,p,scale+=0.25);
		poligon(edge,pivot,p); 
		clear_screen(delay);
	}
}

void loop_scale_poligon(Point pivot, Point p, int radius, int edge){
	int edges = 13;
//	Point p;

	for(int i=edge;i<=edges;i+=2){
		animated_scale_polygon(pivot,p,radius,i);	
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

void animated_rotate_polygon(Point pivot, int radius,double angle,int edge){
	int delay = 500;
	Point p,temp,temp_p;
	float scale;
	
	p.x = pivot.x;
	p.y = pivot.y - radius;
	temp_p = p;
	
	for(int j=0;j<5;j++){
		poligon(edge,pivot,temp_p); 
		temp_p = ownRotate1(temp_p.x, temp_p.y, pivot.x, pivot.y, angle);
		clear_screen(delay);	
	}
}

void looping_rotate_polygon(Point pivot, int radius,double angle){
	int delay = 500;
	int edges = 11, edge = 6;
	Point p,temp,temp_p;
	float scale;

	for(int i=edge;i<=edges;i+=2){
		animated_rotate_polygon(pivot,radius,angle,i);
	}	
}

void animated_translation_polygon(Point pivot, Point t, int edge, int radius){
	int delay = 500;
	Point p,temp,temp_p;
	
	p.x = pivot.x;
	p.y = pivot.y - radius;
	temp_p = p;
	
	for(int j=0;j<5;j++){
		poligon(edge,pivot,temp_p); 
		pivot = translation_matrix(t,pivot);
		temp_p = translation_matrix(t,temp_p);
		clear_screen(delay);	
	}
}

void looping_translation_polygon(Point pivot,Point t, int radius){
	int delay = 500;
	int edges = 11, edge = 6;
	Point p,temp,temp_p;
	float scale;

	for(int i=edge;i<=edges;i+=2){
		animated_translation_polygon(pivot,t,i,radius);
	}	
}

void clear_screen(int time_delay){
	delay(time_delay);
	cleardevice(); 
}



//=========================================================================================

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


//void looping_rotate_and_scale_polygon(Point pivot, int radius,double angle){
//	int delay = 500;
//	int edges = 11, edge = 6;
//	Point p,temp,temp_p;
//	float scale;
//
//	for(int i=edge;i<=edges;i+=2){
//		animated_scale_polygon(pivot,radius,i);	
//		animated_rotate_polygon(pivot,radius,angle,i);
//	}	
//}


void line_circuit(int edge, Point pivot, Point p, int radius,int stop){
	/* Define Point */
	Point temp,temp1,temp2,pivot_[edge],p_[edge];
	Point temp_pivot,temp_p;
	
	int angle = 360/edge,c_angle;
	int delay = 500;
	
	temp = pivot;
	temp1 = p;
	
	for(int i=0;i<edge;i++){
		c_angle = (i+1)*angle;
		temp = ownRotate1(p.x, p.y, pivot.x, pivot.y, c_angle);
		temp1 = return_line_bresenham(pivot.x,pivot.y,temp.x,temp.y,stop);
//		poligon(edge,pivot,p);
//		clear_screen(delay); 
		temp2 = circlePoint(temp1,radius);
//		p_[i] = temp2;
		
//		draw_line_bresenham(pivot.x,pivot.y,temp1.x,temp1.y);
		
//	poligon(edge,pivot,p);
//	clear_screen(delay);
	pivot_[i] = temp1;
	p_[i]=temp2;
//	poligon(edge,temp_pivot,temp_p);
	
		temp1 = temp;
	}
	
	for(int j=0;j<edge;j++){
		poligon(edge,pivot,p);
	}
		clear_screen(delay);
	poligon(edge,pivot_[0],p_[0]);
	poligon(edge,pivot_[1],p_[1]);
	poligon(edge,pivot_[2],p_[2]);
	poligon(edge,pivot_[3],p_[3]);
	poligon(edge,pivot_[4],p_[4]);
	poligon(edge,pivot_[5],p_[5]);
	
	
//	p.x = 350;
//	p.y = pivot.y - radius;
	
//	for(int j=0;j<5;j++){
//		animated_translation_polygon(pivot,translation[j],edge,stop);
//	}	
}



// return 20th point
Point return_line_bresenham(int x1, int y1, int x2, int y2, int stop){
	int dx, dy, i, e, count = 0;
	int incx, incy, inc1, inc2;
	int x,y;
	int color = YELLOW;
	Point p;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	
	if (x2 < x1) incx = -1;
	incy = 1;
	
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	
	
	if (dx > dy){
		// start
		count++;
		if(count>stop){
			p.x = x;
			p.y = y;
			return p;
		}
		// end
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
			// start
			count++;
			if(count>stop){
				p.x = x;
				p.y = y;
				return p;
			}
			// end
		}
	} else {
		// start
		count++;
		if(count>stop){
			p.x = x;
			p.y = y;
			return p;
		}
		// end
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
			// start
			count++;
			if(count>stop){
				p.x = x;
				p.y = y;
				return p;
			}
			// end
		}
	}
}

bool return_point(int count, int stop){
	Point p;
	
	if(count>stop){
		return true;
	}
}

Point tranlation_point(int i){
	Point t;
	switch(i){
		case 0:		
		t.x = 0;
		t.y = 50;
		break;
		
		case 1:		
		t.x = -50;
		t.y = 0;
		break;
		
		case 2:		
		t.x = 0;
		t.y = -50;
		break;
		
		case 3:		
		t.x = 50;
		t.y = 0;
		break;
	}
	return t;
}



	
