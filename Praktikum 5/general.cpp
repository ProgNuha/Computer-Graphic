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

/*=============================================================================================*/
/*=--------------------------------------- Praktikum 3 ---------------------------------------=*/
/*=============================================================================================*/


void bresenham_line(int xa, int ya, int xb, int yb) {
    
    int dx = abs (xa - xb), dy = abs (ya - yb);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyDx = 2 * (dy - dx);
    int x, y, xEnd;
    
    /* Determine which point to use as start, which as end */
    if (xa > xb) {
        x = xb;
        y = yb;
        xEnd = xa;
    } else {
        x = xa;
        y = ya;
        xEnd = xb;
    }
    
    putpixel (x, y, 3);
//    delay(100);
    
    while (x < xEnd) {
        x++;
        if (p < 0) {
            p += twoDy;     
        }else {
            y++;
            p += twoDyDx;
        }
        putpixel (x, y, 3);
//        delay(100);    
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
    
    bresenham_line(xc+x, yc+y,xc-x, yc+y);
	bresenham_line(250,180,250,320); 
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

void square(Point t1, Point t2){
	int dX = t1.x;
	Point temp1,temp2,temp3;
	/*atas*/
	ownRectangle(t1,t2);
	printf("%d %d %d %d\n", t1.x,t1.y,t2.x,t2.y);
	
	temp1 = t1;
	temp2 = t2;
	/*kanan*/
	t1.x = temp1.y;
	t1.y = temp1.x;
	t2.x = temp2.y;
	t2.y = temp2.x;
	temp3 = t2;
	ownRectangle(t1,t2);
	printf("%d %d %d %d\n", t1.x,t1.y,t2.x,t2.y);
	
	
	/*kiri*/
	t1 = temp2;
	t2.x = t1.x + dX;
	t2.y = t1.y + dX;
	ownRectangle(t1,t2);
	printf("%d %d %d %d\n", t1.x,t1.y,t2.x,t2.y);


	/*bawah*/
	t1 = temp3;
	t2.x = t1.x + dX;
	t2.y = t1.y + dX;
	ownRectangle(t1,t2);
	printf("%d %d %d %d\n", t1.x,t1.y,t2.x,t2.y);
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
	int angle = 360/n,c_angle;
	
	temp = pivot;
	temp1 = p;
	
	for(int i=0;i<n;i++){
		c_angle = (i+1)*angle;
		temp = ownRotate1(p.x, p.y, pivot.x, pivot.y, c_angle);
		delay(50);
		line(temp1.x, temp1.y, temp.x, temp.y);
		temp1 = temp;
		
	}

	
}


	
