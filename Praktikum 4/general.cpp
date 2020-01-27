#include "general.h"

/*=============================================================================================*/
/*=--------------------------------------- Praktikum 4 ---------------------------------------=*/
/*=============================================================================================*/

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

void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry){
	int Rx2 = Rx * Rx;
	int Ry2 = Ry * Ry;
	int twoRx2 = 2 * Rx2;
	int twoRy2 = 2 * Ry2;
	int p;
	int x = 0;
	int y = Ry;
	int px = 0;
	int py = twoRx2 * y;
	
	/* Plot the first set of points */
	ellipsePlotPoints(xCenter, yCenter, x, y);
	
	/* Region 1*/
	p = abs(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
	while(px<py){
		x++;
		px += twoRy2;
		if(p<0){
			p += Ry2 + px;
		} else {
			y--;
			py -= twoRx2;
			p += Ry2 + px - py;
		}
		ellipsePlotPoints(xCenter, yCenter, x, y);
	}
	
	/* Region 2*/
	p = abs(Ry2*(x+0.5)*(x+0.5) + Rx2 * (y-1)*(y-1) - Rx2 * Ry2);
	while(y>0){
		y--;
		py -= twoRx2;
		if(p>0){
			p+=Rx2-py;
		} else {
			x++;
			px += twoRy2;
			p += Rx2 - py + px;
		}
		ellipsePlotPoints(xCenter, yCenter, x, y);
	}
}

void line_DDA(Point p1, Point p2){
	int dx = p2.x - p1.x, dy = p2.y - p1.y, steps;
	float xIncrement, yIncrement, x = p1.x, y = p1.y;
	
	if(abs(dx) > abs(dy)){
		steps = abs(dx);
	} else {
		steps = abs(dy);
	}
	xIncrement = abs(dx/steps);
	yIncrement = abs(dy/steps);
	
	putpixel(abs(x), abs(y), 3);
	for(int i=0;i<steps;i++){
		x += xIncrement;
		y += yIncrement;
		putpixel(abs(x), abs(y), 3);
	}
}

void line_DDA_translation(Point p1, Point p2){
	Point temp3;
	int dx = p2.x - p1.x, dy = p2.y - p1.y, steps;
	float xIncrement, yIncrement, x = p1.x, y = p1.y;
	
	if(abs(dx) > abs(dy)){
		steps = abs(dx);
	} else {
		steps = abs(dy);
	}
	xIncrement = abs(dx/steps);
	yIncrement = abs(dy/steps);
	
	putpixel(abs(x), abs(y), 3);
	for(int i=0;i<steps;i++){
		x += xIncrement;
		y += yIncrement;
		putpixel(abs(x), abs(y), 3);
		
		if(abs(dx) > abs(dy)){
			temp3 = translation(0, dx, x, y);
		} else {
			temp3 = translation(dy, 0, x, y);
		}
		putpixel(temp3.x, temp3.y, 4);
	}
	
}

void square(Point p1, Point p2, Point p3){
	line_DDA_translation(p1,p2);
	line_DDA_translation(p1,p3);
}

void v_square_translation(Point p1, Point p2, Point p3){
	int dx = 2*(p2.x - p1.x);
	Point t1,t2,t3;
	
	t1 = translation(dx,0,p1.x,p1.y);
	t2 = translation(dx,0,p2.x,p2.y);
	t3 = translation(dx,0,p3.x,p3.y);
	
	square(p1,p2,p3);
	square(t1,t2,t3);
}

void h_square_translation(Point p1, Point p2, Point p3){
	int dy = 2*(p3.y - p1.y);
	Point t1,t2,t3;
	
	t1 = translation(0,dy,p1.x,p1.y);
	t2 = translation(0,dy,p2.x,p2.y);
	t3 = translation(0,dy,p3.x,p3.y);
	
	square(p1,p2,p3);
	square(t1,t2,t3);
}

void square_translation(Point p1, Point p2, Point p3, Point p4, Point p5){
	v_square_translation(p1,p2,p3);
	h_square_translation(p4,p5,p2);
}

void looping_square(Point p1, Point p2, Point p3, Point p4, Point p5){
	Point t1=p1,t2=p2,t3=p3,t4=p4,t5=p5;
	int dx = 3*(p2.x - p1.x), dy = 3*(p3.y - p1.y);
		printf("%d %d \n", dx,dy);
		
	for(int i=0;i<getmaxy();i+=dy){
		p1=t1,p2=t2,p3=t3,p4=t4,p5=t5;
		for(int j=0;j<getmaxx();j+=dx){
			square_translation(p1,p2,p3,p4,p5);
			p1 = translation(dx,0,p1.x,p1.y);
			p2 = translation(dx,0,p2.x,p2.y);
			p3 = translation(dx,0,p3.x,p3.y);
			p4 = translation(dx,0,p4.x,p4.y);
			p5 = translation(dx,0,p5.x,p5.y);
		}
		t1 = translation(0,dy,t1.x,t1.y);
		t2 = translation(0,dy,t2.x,t2.y);
		t3 = translation(0,dy,t3.x,t3.y);
		t4 = translation(0,dy,t4.x,t4.y);
		t5 = translation(0,dy,t5.x,t5.y);
		square_translation(t1,t2,t3,t4,t5);
	}
}

void square_batik(){
	Point p1,p2,p3,p4,p5;

	p1.x = 0;
	p1.y = 0;
	p2.x = 20;
	int d = p2.x - p1.x;
	p2.y = p1.y; 
	p3.x = p1.x; 
	p3.y = p1.y + d; 
	p4.x = p2.x; 
	p4.y = p2.y - d; 
	p5.x = p4.x + d; 
	p5.y = p4.y;
	
	looping_square(p1,p2,p3,p4,p5);
}


void ellipseMidpointTranlation(int xCenter, int yCenter, int Rx, int Ry, int dX, int dY){
	int Rx2 = Rx * Rx;
	int Ry2 = Ry * Ry;
	int twoRx2 = 2 * Rx2;
	int twoRy2 = 2 * Ry2;
	int p;
	int x = 0;
	int y = Ry;
	int px = 0;
	int py = twoRx2 * y;
	Point temp = translation(dX,dY,xCenter,yCenter);
	
	ellipseMidpoint(xCenter, yCenter, Rx, Ry);
	ellipseMidpoint(temp.x, temp.y, Rx, Ry);
	printf("%d %d \n", temp.x,temp.y);
	
}

void ellipsePlotPoints(int xCenter, int yCenter, int x, int y){
	int Color = 3;
	putpixel(xCenter + x, yCenter + y, Color);
	putpixel(xCenter - x, yCenter + y, Color);
	Color = 5;
	putpixel(xCenter + x, yCenter - y, Color);
	putpixel(xCenter - x, yCenter - y, Color);
}

Point translation(int dX, int dY, int x, int y){
	Point p;
	p.x = x + dX;
	p.y = y + dY;
	return p;
}

void flower(Point center, int rx, int ry){
	ellipseMidpointTranlation(center.x,center.y,rx,ry,0,2*ry);
	ellipseMidpointTranlation(center.x-ry,center.y+ry,ry,rx,2*ry,0);
}

void flower_batik(Point center,int rx, int ry){
	Point temp;
	int gapX = 35, gapY= 38;

	flower(center,rx,ry);
	for(int y=center.y;y<getmaxy();y+=gapY){
		temp.y = y;
		for(int x=center.x;x<getmaxx();x+=gapX){
			temp.x = x;
			flower(temp,rx,ry);
		}
	}
}



	
