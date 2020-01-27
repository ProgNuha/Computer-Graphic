#include "general.h"

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


/*=============================================================================================*/
/*=--------------------------------------- Praktikum 4 ---------------------------------------=*/
/*=============================================================================================*/
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
		printf("Region 1 \n");
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
		printf("Region 2 \n");
		ellipsePlotPoints(xCenter, yCenter, x, y);
	}
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
	
	delay(10);
	putpixel(xCenter + x, yCenter + y, Color);
	printf("(%d,%d)\n", xCenter + x, yCenter + y);
	
	delay(10);
	putpixel(xCenter - x, yCenter + y, Color);
	printf("(%d,%d)\n", xCenter - x, yCenter + y);
	
	Color = 5;
	
	delay(10);
	putpixel(xCenter + x, yCenter - y, Color);
	printf("(%d,%d)\n", xCenter + x, yCenter - y);
	
	delay(10);
	putpixel(xCenter - x, yCenter - y, Color);
	printf("(%d,%d)\n\n", xCenter - x, yCenter - y);
}

Point translation(int dX, int dY, int x, int y){
	Point p;
	p.x = x + dX;
	p.y = y + dY;
	return p;
}

/*=============================================================================================*/
/*=--------------------------------------- Praktikum 5 ---------------------------------------=*/
/*=============================================================================================*/
void ownTriangle(int x, int y, int pivot_x, 
				int pivot_y, double angle){
	double radian=angle*(-0.01745);
	int rotated_point_x=abs(pivot_x +((x-pivot_x)*
		cos(radian)-(y-pivot_y)*sin(radian)));
	int rotated_point_y=abs(pivot_y +((x-pivot_x)*
		sin(radian)+(y-pivot_y)*cos(radian)));

	setcolor(3);
	line(pivot_x,pivot_y,rotated_point_x,
					rotated_point_x);
	line(rotated_point_x,rotated_point_x,
					x,y);
}

Point ownRotate1(int x, int y, int pivot_x, 
				int pivot_y, double angle){
	Point p1;
	double radian=angle*(-0.01745);
	p1.x=abs(pivot_x +((x-pivot_x)*
		cos(radian)-(y-pivot_y)*sin(radian)));
	p1.y=abs(pivot_y +((x-pivot_x)*
		sin(radian)+(y-pivot_y)*cos(radian)));
	
	return p1;
}

void eightRotate(Point center, Point r){
	Point temp;
	int angle;
	
	for(int i=0;i<8;i++){
		angle = 0;
		temp = ownRotate1(center.x,center.y,r.x,r.y,angle);
		angle += 45;
	}
}

void eightEllipseMidpoint(int xCenter, int yCenter, int Rx, int Ry){
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
//	Point center,r;
//	center.x = xCenter;
//	center.y = yCenter;
//	r.x = x;
//	r.y = y;
//	eightRotate(center,r);
	ellipse8PlotPoints(xCenter, yCenter, x, y);
	
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
		
//		center.x = xCenter;
//		center.y = yCenter;
//		r.x = x;
//		r.y = y;
//		eightRotate(center,r);
		ellipse8PlotPoints(xCenter, yCenter, x, y);
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
			
//		center.x = xCenter;
//		center.y = yCenter;
//		r.x = x;
//		r.y = y;
//		eightRotate(center,r);
		ellipse8PlotPoints(xCenter, yCenter, x, y);
	}
}

void ellipse8PlotPoints(int xCenter, int yCenter, int x, int y){
	Point center,r;
	center.x = xCenter;
	center.y = yCenter;
	r.x = x;
	r.y = y;
	
	Point temp,counter;
	counter.x = xCenter + x;
	counter.y = yCenter + y;
	int angle;
	int Color = 3;
	
	angle = 0;
	for(int i=0;i<8;i++){
		temp = ownRotate1(center.x,center.y,counter.x,counter.y,angle);
		printf("(%d,%d)\n", temp.x, temp.y);
		putpixel(temp.x, temp.y, Color);
		angle += 45;
	}
	
//	for(int i=0;i<8;i++){
//		angle = 0;
//		temp = ownRotate1(center.x,center.y,xCenter - x, yCenter + y,angle);
//		putpixel(temp.x, temp.y, Color);
//		angle += 45;
//	}
//	
//	Color = 5;
//	for(int i=0;i<8;i++){
//		angle = 0;
//		temp = ownRotate1(center.x,center.y,xCenter + x, yCenter - y,angle);
//		putpixel(temp.x, temp.y, Color);
//		angle += 45;
//	}
//	
//	for(int i=0;i<8;i++){
//		angle = 0;
//		temp = ownRotate1(center.x,center.y,xCenter - x, yCenter - y,angle);
//		putpixel(temp.x, temp.y, Color);
//		angle += 45;
//	}
	
//	int Color = 3;
//	putpixel(xCenter + x, yCenter + y, Color);
//	putpixel(xCenter - x, yCenter + y, Color);
//	
//	Color = 5;
//	putpixel(xCenter + x, yCenter - y, Color);
//	putpixel(xCenter - x, yCenter - y, Color);
}

void poligon(int n, Point pivot, Point p){
	/* Define Point */
	Point temp,temp1;
	int angle = 360/n,c_angle,color = 5;
	
	temp = pivot;
	temp1 = p;
	
	for(int i=0;i<n;i++){
		c_angle = (i+1)*angle;
		temp = ownRotate1(p.x, p.y, pivot.x, pivot.y, c_angle);
		delay(50);
		line_bresenham(temp1.x, temp1.y, temp.x, temp.y,color);
		temp1 = temp;
		
	}
}


	
