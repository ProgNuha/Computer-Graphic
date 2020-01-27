#include "library_50.h"

#define CONSTANT -0.01745
#define FULL_ROTATION 360
#define YELLOW_1 RGB(241,244,68)
#define LIGHT_BLUE_1 RGB(44,229,242)
#define LIGHT_RED_1 RGB(255,42,85)
#define DARK_BLUE_1 RGB(30,29,217)
#define ORANGE_1 RGB(255,170,0)
#define ORANGE_2 RGB(255,127,0)
#define ORANGE_3 RGB(255,127,42)
#define ORANGE_4 RGB(255,212,42)
#define ORANGE_5 RGB(255,85,0)
#define ORANGE_6 RGB(255,170,42)
#define GREEN_1 RGB(42,255,0)
#define GREEN_2 RGB(0,255,127)
#define LIGHT_BLUE_2 RGB(0,255,255)
#define LIGHT_BLUE_3 RGB(127,255,212)
#define PURPLE_1 RGB(170,127,255)
#define PURPLE_2 RGB(255,212,255)
#define LIGHT_GREEN_1 RGB(212,255,212)
#define LIGHT_GREEN_2 RGB(85,255,85)

// Function for line-generation 
// using Bresenham's algorithm 
// https://github.com/nowke/cg_lab/blob/master/1_bresenham_line/bresenham_line.cpp
void drawLineBresenham(int x1, int y1, int x2, int y2, int color){
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

// Function for circle-generation 
// using Bresenham's algorithm 
void circleBresenham(int xc, int yc, int r){ 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(xc, yc, x, y); 
    while (y >= x) { 
        // for each pixel we will 
        // draw all eight pixels 
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0){ 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
            
        drawCircle(xc, yc, x, y); 
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

Point getPointPolygon(Point pivot,int radius){
	Point polygon;
	
	polygon.x = pivot.x;
	polygon.y = pivot.y + radius;
	
	return polygon;
}

/*=============================================================================================*/
/*=--------------------------------------- Tranformation ---------------------------------------=*/
/*=============================================================================================*/
Point pointTranslation(Point translation, Point origin){
	Point point_translation;
	
	point_translation.x = origin.x + translation.x;
	point_translation.y = origin.y + translation.y;
	
	return point_translation;
}

Point pointScale(Point translation, Point origin,float scale){
	Point point_scale;
	
	point_scale.x = (int)(scale*origin.x) + (int)(scale*(-1*translation.x)) + translation.x;
	point_scale.y = (int)(scale*origin.y) + (int)(scale*(-1*translation.x)) + translation.y;
	
	return point_scale;
}


Point pointRotationClockWise(Point origin, Point pivot, double degree){
	Point point_rotation;
	double radian=degree*(CONSTANT);
	
	point_rotation.x=abs(pivot.x +((origin.x-pivot.x)*cos(radian)-(origin.y-pivot.y)*sin(radian)));
	point_rotation.y=abs(pivot.y +((origin.x-pivot.x)*sin(radian)+(origin.y-pivot.y)*cos(radian)));
	
	return point_rotation;
}

Point pointRotationCounterClockWise(Point origin, Point pivot, double degree){
	Point point_rotation;
	double radian=degree*(CONSTANT);
	
	point_rotation.x=abs(pivot.x +((origin.x-pivot.x)*cos(radian)+(origin.y-pivot.y)*sin(radian)));
	point_rotation.y=abs(pivot.y +((origin.x-pivot.x)*(-sin(radian))+(origin.y-pivot.y)*cos(radian)));
	
	return point_rotation;
}

void poligon(int edge, Point pivot, int radius){
	Point temp_pivot,temp_angle,angle;
	int degree = FULL_ROTATION/edge,counter_degree, color;
	
	angle.x = pivot.x;
	angle.y = pivot.y - radius;
	
	temp_pivot = pivot;
	temp_angle = angle;
	
	for(int increment=0;increment<edge;increment++){
		color = setColorPoligon(increment);
		counter_degree = (increment+1)*degree;
		temp_pivot = pointRotationClockWise(angle, pivot, counter_degree);
		drawLineBresenham(temp_angle.x, temp_angle.y, temp_pivot.x, temp_pivot.y, color);
		temp_angle = temp_pivot;		
	}	
}

void poligonAngle(int edge, Point pivot, Point angle, int radius){
	Point temp_pivot,temp_angle;
	int degree = FULL_ROTATION/edge,counter_degree, color;

	temp_pivot = pivot;
	temp_angle = angle;
	
	for(int increment=0;increment<edge;increment++){
		color = setColorPoligon(increment);
		counter_degree = (increment+1)*degree;
		temp_pivot = pointRotationClockWise(angle, pivot, counter_degree);
		drawLineBresenham(temp_angle.x, temp_angle.y, temp_pivot.x, temp_pivot.y, color);
		temp_angle = temp_pivot;		
	}	
}

void poligonAngleRadius(int edge, Point pivot, Point angle, int radius){
	Point temp_pivot,temp_angle;
	int degree = FULL_ROTATION/edge,counter_degree, color;

	
	temp_pivot = pivot;
	temp_angle = angle;
	
	angle.x = pivot.x;
	angle.y = pivot.y - radius;
	
	for(int increment=0;increment<edge;increment++){
		color = setColorPoligon(increment);
		counter_degree = (increment+1)*degree;
		temp_pivot = pointRotationClockWise(angle, pivot, counter_degree);
		drawLineBresenham(temp_angle.x, temp_angle.y, temp_pivot.x, temp_pivot.y, color);
		temp_angle = temp_pivot;		
	}	
}

int setColorPoligon(int edge){
	switch(edge){
		case 0: return ORANGE_1; break;	
		case 1: return ORANGE_2; break;
		case 2: return ORANGE_3; break;
		case 3: return ORANGE_4; break;
		case 4: return ORANGE_5; break;
		case 5: return ORANGE_6; break;
		case 6: return ORANGE_1; break;
		case 7: return ORANGE_2; break;
		default:return ORANGE_3; break;
	}
}

void poligonPattern(int edge, Point pivot, int radius){
	Point temp_pivot,temp_point,angle;
	int degree = FULL_ROTATION/edge,counter_degree,delay=1000;
	double rotate =30;
	
	angle.x = pivot.x;
	angle.y = pivot.y - radius;
	temp_pivot = pivot;
	
	for(int increment=0;increment<edge;increment++){
		counter_degree = (increment+1)*degree;
		temp_pivot = pointRotationClockWise(angle, pivot, counter_degree);
		poligon(edge, temp_pivot, radius);
	}
	
	clearScreen(delay);	
}

void poligonPatternRotatation(int edge, Point pivot, int radius){
	own_Polygon array_poligon[edge],array_poligon1[edge];
	Point temp_pivot,temp_angle,temp2,angle;
	int degree = FULL_ROTATION/edge,counter_degree,delay=70;
	double degree_rotation = 10;
	
	angle.x = pivot.x;
	angle.y = pivot.y - radius;
	temp_pivot = pivot;
	
	for(int increment=0;increment<edge;increment++){
		counter_degree = (increment+1)*degree;
		array_poligon[increment].pivot = pointRotationClockWise(angle, pivot, counter_degree);
		array_poligon[increment].angle = getPointPolygon(array_poligon[increment].pivot,radius);
	}
	
	for(int counter=0;counter<21;counter++){
		for(int increment=0;increment<edge;increment++){
			poligonAngle(edge, array_poligon[increment].pivot,array_poligon[increment].angle, radius);
			array_poligon[increment].angle = pointRotationClockWise(array_poligon[increment].angle, array_poligon[increment].pivot, degree_rotation);
		}
		clearScreen(delay);
	}		
}

void poligonPatternRotatationAndScale(int edge, Point pivot, int radius){
	own_Polygon array_poligon[edge],array_poligon1[edge];
	Point temp_pivot,temp_angle,temp2,angle;
	int degree = FULL_ROTATION/edge,counter_degree,delay=70,temp_radius=0;
	double degree_rotation = 10;
	
	angle.x = pivot.x;
	angle.y = pivot.y - radius;
	temp_angle = angle;
	temp_pivot = pivot;
	
	for(int increment=0;increment<edge;increment++){
		counter_degree = (increment+1)*degree;
		array_poligon[increment].pivot = pointRotationClockWise(temp_angle, temp_pivot, counter_degree);
		array_poligon[increment].angle = getPointPolygon(array_poligon[increment].pivot,radius);
		array_poligon1[increment].pivot = pointRotationClockWise(temp_angle, temp_pivot, counter_degree);
		array_poligon1[increment].angle = getPointPolygon(array_poligon1[increment].pivot,radius-30);
	}
	
	while(true){
		/* increase */
		if(temp_radius >= 120){
			temp_radius = 0;
		}	
		temp_radius = temp_radius + 10;

		for(int increment=0;increment<edge;increment++){
			poligonAngle(edge, array_poligon[increment].pivot,array_poligon[increment].angle, radius);
			poligon(edge, array_poligon1[increment].pivot, temp_radius);
			array_poligon[increment].angle = pointRotationCounterClockWise(array_poligon[increment].angle, array_poligon[increment].pivot, degree_rotation);
			array_poligon1[increment].angle = pointRotationClockWise(array_poligon1[increment].angle, array_poligon1[increment].pivot, degree_rotation);
		}
		clearScreen(delay);
	}		
}

void clearScreen(int time_delay){
	int page = 0;
	
	setactivepage(page);
	setvisualpage(1-page);
    page = 1 - page;
	delay(time_delay);
	cleardevice(); 
}

void myDelay(int time_delay){
	delay(time_delay);
	cleardevice(); 
}

void animatedScalePolygon(Point pivot, int radius, int edge, int count){
	float scale=0.0,temp_scale = 0.2;
	int delay = 150;
	
	Point angle;
	angle.x = pivot.x;
	angle.y = pivot.y - radius;

	for(int counter=0;counter<count;counter++){
		if(scale >= 2.2){
			scale = 0.0;
		}	
		scale = scale + temp_scale;
		
		angle = pointScale(pivot,angle,scale);
		poligonAngle(edge,pivot,angle,radius);  
		clearScreen(delay);
	}
}

void animatedTranslationPolygon(Point pivot, int radius, int edge, int count){
	int delay = 10;
	Point angle,temp_pivot,temp_angle,translation[8];
	own_Polygon array_poligon[8];
	
	angle.x = pivot.x;
	angle.y = pivot.y - radius;
	temp_angle = angle;
	temp_pivot = pivot;
	
	for(int increment=0;increment<8;increment++){
		array_poligon[increment].angle = temp_angle;
		array_poligon[increment].pivot = temp_pivot;
		poligon(edge,array_poligon[increment].pivot,radius);
	}
	
	for(int counter=0;counter<count;counter++){
		for(int increment=0;increment<8;increment++){
			translation[increment] = choosePointTranslation(increment);
			array_poligon[increment].pivot = pointTranslation(translation[increment],array_poligon[increment].pivot);
			array_poligon[increment].angle = pointTranslation(translation[increment],array_poligon[increment].angle);
			poligonAngle(edge,array_poligon[increment].pivot,array_poligon[increment].angle,radius);
		}
		clearScreen(delay);
	}
	
	myDelay(500);
	
	for(int counter=0;counter<count;counter++){
		for(int increment=0;increment<8;increment++){
			translation[increment] = choosePointTranslation(increment);
			translation[increment].x = translation[increment].x * (-1);
			translation[increment].y = translation[increment].y * (-1);
			array_poligon[increment].pivot = pointTranslation(translation[increment],array_poligon[increment].pivot);
			array_poligon[increment].angle = pointTranslation(translation[increment],array_poligon[increment].angle);
			poligonAngle(edge,array_poligon[increment].pivot,array_poligon[increment].angle,radius);
		}
		clearScreen(delay);
	}
	
	myDelay(500);
		
}

void animatedRotatationPolygon(Point pivot, int radius, int edge, int count){
	int delay = 200;
	double rotate = 60;
	Point angle,temp_pivot,temp_angle,translation[9];
	own_Polygon array_poligon[9];
	
	angle.x = pivot.x;
	angle.y = pivot.y - radius;
	temp_angle = angle;
	temp_pivot = pivot;
	
	for(int increment=0;increment<9;increment++){
		translation[increment] = choosePointTranslation9(increment);
		array_poligon[increment].pivot = pointTranslation(translation[increment],temp_pivot);
		array_poligon[increment].angle = pointTranslation(translation[increment],temp_angle);
	}
		
	poligon(edge,array_poligon[0].pivot,radius);
	myDelay(500);
	
	for(int counter=0;counter<7;counter++){
		if(counter%2==0){
			for(int rotation=0;rotation<7;rotation++){
				for(int increment=0;increment<9;increment+=2){
					array_poligon[increment].angle = pointRotationCounterClockWise(array_poligon[increment].angle,array_poligon[increment].pivot,rotate);
					poligonAngle(edge,array_poligon[increment].pivot,array_poligon[increment].angle,radius);
				}
				clearScreen(delay);
			}
		}
		else if(counter%2!=0) {
			for(int rotation=0;rotation<7;rotation++){
				for(int increment=1;increment<9;increment+=2){
					array_poligon[increment].angle = pointRotationCounterClockWise(array_poligon[increment].angle,array_poligon[increment].pivot,rotate);
					poligonAngle(edge,array_poligon[increment].pivot,array_poligon[increment].angle,radius);
				}
				clearScreen(delay);
			}
		}
	}
	
}

Point choosePointTranslation(int direction){
	Point translation;
	
	switch(direction){
		case 0:		
		translation.x = 0;
		translation.y = 10;
		break;
		
		case 1:		
		translation.x = 0;
		translation.y = -10;
		break;
		
		case 2:		
		translation.x = -10;
		translation.y = 0;
		break;
		
		case 3:		
		translation.x = 10;
		translation.y = 0;
		break;
		
		case 4:		
		translation.x = 10;
		translation.y = 10;
		break;
		
		case 5:		
		translation.x = -10;
		translation.y = 10;
		break;
		
		case 6:		
		translation.x = 10;
		translation.y = -10;
		break;
		
		case 7:		
		translation.x = -10;
		translation.y = -10;
		break;
		
		default:		
		translation.x = 0;
		translation.y = 10;
		break;
	}
	
	return translation;
}

Point choosePointTranslation9(int direction){
	Point translation;
	
	switch(direction){
		case 0:		
		translation.x = 0;
		translation.y = 0;
		break;
		
		case 1:			
		translation.x = 200;
		translation.y = -200;
		break;
		
		case 2:		
		translation.x = -200;
		translation.y = 0;
		break;
		
		case 3:
		translation.x = -200;
		translation.y = -200;
		break;
		
		case 4:		
		translation.x = 0;
		translation.y = -200;
		break;
		
		case 5:		
		translation.x = 200;
		translation.y = 200;
		break;
		
		case 6:	
		translation.x = 200;
		translation.y = 0;
		break;
		
		case 7:
		translation.x = -200;
		translation.y = 200;	

		break;
		
		case 8:	
		translation.x = 0;
		translation.y = 200;
		break;
		
		default:		
		translation.x = 0;
		translation.y = 0;
		break;
	}
	
	return translation;
}
