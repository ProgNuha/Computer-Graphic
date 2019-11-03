#include "library.h"
#include <math.h>

/*=============================================================================================*/
/*=---------------------------------------- Windows ------------------------------------------=*/
/*=============================================================================================*/

void init_windows_glut(int argc, char** argv, int width, int height,const char title[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(title);
	
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, width, 0, height);
}

void process_next_screen(unsigned char key, int x, int y){
    switch (key) {   
       case 32 : glutLeaveMainLoop();  break;
    }
}

/*=============================================================================================*/
/*=----------------------------------------- Draw --------------------------------------------=*/
/*=============================================================================================*/

void draw_pixel(int x, int y){
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}

void draw_line_bresenham(int x1, int y1, int x2, int y2){
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
		draw_pixel(x, y);
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
			draw_pixel(x, y);
		}
	} else {
		draw_pixel(x, y);
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
			draw_pixel(x, y);
		}
	}
}

void draw_line_DDA(Point p1, Point p2){
	int dx = p2.x - p1.x, dy = p2.y - p1.y, steps;
	float xIncrement, yIncrement, x = p1.x, y = p1.y;
	
	if(abs(dx) > abs(dy)){
		steps = abs(dx);
	} else {
		steps = abs(dy);
	}
	xIncrement = dx / (float) steps; 
	yIncrement = dy / (float) steps; 

	for(int i=0;i<steps;i++){
		draw_pixel(abs(x), abs(y));
		x += xIncrement;
		y += yIncrement;
	}
}

void draw_octet_points(int xc, int yc, int x, int y) 
{ 
    draw_pixel(xc+x, yc+y); 
    draw_pixel(xc-x, yc+y); 
    draw_pixel(xc+x, yc-y); 
    draw_pixel(xc-x, yc-y); 
    draw_pixel(xc+y, yc+x); 
    draw_pixel(xc-y, yc+x); 
    draw_pixel(xc+y, yc-x); 
    draw_pixel(xc-y, yc-x); 
} 

void draw_circle(int xc, int yc, int r){ 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    draw_octet_points(xc, yc, x, y); 
    while (y >= x){  
        x++; 
        if (d > 0){ 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
            
        draw_octet_points(xc, yc, x, y);
    } 
} 

void draw_ellipse(int xCenter, int yCenter, int Rx, int Ry){
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
	draw_ellips_points(xCenter, yCenter, x, y);
	
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
		draw_ellips_points(xCenter, yCenter, x, y);
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
		draw_ellips_points(xCenter, yCenter, x, y);
	}
}

void draw_ellips_points(int xCenter, int yCenter, 
						int x, int y){
	draw_pixel(xCenter + x, yCenter + y);
	draw_pixel(xCenter - x, yCenter + y);
	draw_pixel(xCenter + x, yCenter - y);
	draw_pixel(xCenter - x, yCenter - y);
}


/*=============================================================================================*/
/*=---------------------------------------- Display ------------------------------------------=*/
/*=============================================================================================*/

void displayPoint(){
	draw_pixel(point1.x, point1.y);
	glFlush();
}

void displayBresenham(){
	draw_line_bresenham(point1.x, point1.y, 
						point2.x, point2.y);
	glFlush();
}

void displayDDA(){
	draw_line_DDA(point1, point2);
	glFlush();
}

void displayCircle(){
	draw_circle(circle.xCenter, 
				circle.yCenter, circle.radius);
	glFlush();
}

void displayEllips(){
	draw_ellipse(ellips.xCenter, ellips.yCenter, 
				ellips.radiusX, ellips.radiusY);
	glFlush();
}

/*=============================================================================================*/
/*=----------------------------------------- View --------------------------------------------=*/
/*=============================================================================================*/

void viewEllips(int argc, char** argv){
	printf( "Enter midpoint of elips \n");
	printf( "X : ");
	scanf("%d", &ellips.xCenter);
	printf( "Y : ");
	scanf("%d", &ellips.yCenter);
	printf( "Enter radius of elips\n");
	printf( "radius X : ");
	scanf("%d", &ellips.radiusX);
	printf( "radius Y : ");
	scanf("%d", &ellips.radiusY);

	init_windows_glut(argc, argv, 500,500,"Ellips");
	glutKeyboardFunc(process_next_screen);
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, 
					GLUT_ACTION_CONTINUE_EXECUTION ); 
	glutDisplayFunc(displayEllips);
	glutMainLoop();
}

void viewCircle(int argc, char** argv){
	printf( "Enter midpoint of circle\n");
	printf( "X : ");
	scanf("%d", &circle.xCenter);
	printf( "Y : ");
	scanf("%d", &circle.yCenter);
	printf( "Enter radius  of circle\n");
	printf( "Radius : ");
	scanf("%d", &circle.radius);

	init_windows_glut(argc, argv, 500,500,"Circle");
	glutKeyboardFunc(process_next_screen);
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, 
					GLUT_ACTION_CONTINUE_EXECUTION ); 
	glutDisplayFunc(displayCircle);
	glutMainLoop();
}

void viewLineBresenham(int argc, char** argv){
	printf( "Enter First Point Coordinate\n");
	printf( "X : ");
	scanf("%d", &point1.x);
	printf( "Y : ");
	scanf("%d", &point1.y);
	
	printf( "Enter Second Point Coordinate\n");
	printf( "X : ");
	scanf("%d", &point2.x);
	printf( "Y : ");
	scanf("%d", &point2.y);

	init_windows_glut(argc, argv, 500,500,"Line Bresenham");
	glutKeyboardFunc(process_next_screen);
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, 
					GLUT_ACTION_CONTINUE_EXECUTION ); 
	glutDisplayFunc(displayBresenham);
	glutMainLoop();
}

void viewLineDDA(int argc, char** argv){
	printf( "Enter First Point  Coordinate\n");
	printf( "X : ");
	scanf("%d", &point1.x);
	printf( "Y : ");
	scanf("%d", &point1.y);
	
	printf( "Enter Second Point Coordinate\n");
	printf( "X : ");
	scanf("%d", &point2.x);
	printf( "Y : ");
	scanf("%d", &point2.y);

	init_windows_glut(argc, argv, 500,500,"Line DDA");
	glutKeyboardFunc(process_next_screen);
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, 
					GLUT_ACTION_CONTINUE_EXECUTION ); 
	glutDisplayFunc(displayDDA);
	glutMainLoop();
}

void viewPoint(int argc, char** argv){
	printf( "Enter Point Coordinate\n");
	printf( "X : ");
	scanf("%d", &point1.x);
	printf( "Y : ");
	scanf("%d", &point1.y);

	init_windows_glut(argc, argv, 500,500,"Point");
	glutKeyboardFunc(process_next_screen);
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, 
					GLUT_ACTION_CONTINUE_EXECUTION ); 
	glutDisplayFunc(displayPoint);
	glutMainLoop();
}


/*=============================================================================================*/
/*=------------------------------------ Transformation ---------------------------------------=*/
/*=============================================================================================*/

// Translasi
Point translation(Point point,
					int xTr,int yTr){
	point.x += xTr;
	point.y += yTr;
	
	return point;
}

// Rotation Point about to origin counter clock wise
Point rotation_point_ccw(double angle,Point pointRotation){
	Point pointResult;
	double radian=angle*(-0.01745);
	
	pointResult.x=(int)(pointRotation.x*cos(radian)-(pointRotation.y*sin(radian)));
	pointResult.y=(int)(pointRotation.x*sin(radian)+(pointRotation.y*cos(radian)));
	
    return pointResult;
}

// Rotation Point about to origin clock wise
Point rotation_point_cw(double angle,Point pointRotation){
	Point pointResult;
	double radian=angle*(-0.01745);
	
	pointResult.x=(int)(pointRotation.x*cos(radian)+(pointRotation.y*sin(radian)));
	pointResult.y=(int)(pointRotation.x*-(sin(radian))+(pointRotation.y*cos(radian)));
	
    return pointResult;
}

//// Rotation Point about to origin clock wise
//Point rotation_point_ccw(double angle,Point pointRotation){
//	Point pointResult;
//	angle = -angle;
//
//	double radian=angle*0.01745;
//	
//	pointResult.x=(int)(pivotX +((pointRotation.x-pivotX)*cos(radian)+(pointRotation.y-pivotY)*sin(radian)));
//	pointResult.y=(int)(pivotY +((pointRotation.x-pivotX)*sin(radian)+(pointRotation.y-pivotY)*cos(radian)));
//	
//    return pointResult;
//}


// Rotation Line counter clock wise
Line rotation_line_ccw(double angle,Line lineRotation){
	Line lineResult;
	angle = -angle;
	
    int pivotX = lineRotation.p1.x;
    int pivotY = lineRotation.p1.y;
	double radian=angle*0.01745;
	
	lineResult.p1.x = pivotX;
	lineResult.p1.y = pivotY;
	
	lineResult.p2.x=(int)(pivotX +((lineRotation.p2.x-pivotX)
					*cos(radian)+(lineRotation.p2.y-pivotY)*sin(radian)));
	lineResult.p2.y=(int)(pivotY +((lineRotation.p2.x-pivotX)
							*-(sin(radian))+(lineRotation.p2.y-pivotY)*cos(radian)));
	
    return lineResult;
}

// Rotation Line clock wise
Line rotation_line_cw(double angle,Line lineRotation){
	Line lineResult;
	angle = -angle;
	
    int pivotX = lineRotation.p1.x;
    int pivotY = lineRotation.p1.y;
	double radian=angle*0.01745;
	
	lineResult.p1.x = pivotX;
	lineResult.p1.y = pivotY;
	
	lineResult.p2.x=(int)(pivotX +((lineRotation.p2.x-pivotX)
					*cos(radian)-(lineRotation.p2.y-pivotY)*sin(radian)));
	lineResult.p2.y=(int)(pivotY +((lineRotation.p2.x-pivotX)
					*sin(radian)+(lineRotation.p2.y-pivotY)*cos(radian)));
	
    return lineResult;
}

// Reflection Line about to x=0 or y-axis
Line reflection_line_x(int x,Line lineReflection){
	Line lineResult;
	
    int pivotX = lineReflection.p1.x;
    int pivotY = lineReflection.p1.y;
	
	lineResult.p1.x = pivotX;
	lineResult.p1.y = pivotY;
	
	//Reflect to pivot point y-axis or x=0
	lineResult.p2.x=(int)(pivotX +((lineReflection.p2.x-pivotX)
					*(-1)-(lineReflection.p2.y-pivotY)*(0)));
	lineResult.p2.y=(int)(pivotY +((lineReflection.p2.x-pivotX)
					*(0)+(lineReflection.p2.y-pivotY)*(1)));
	
	//Translation p2				
	lineResult.p2 = translation(lineResult.p2,2*x,0);
	
    return lineResult;
}

// Reflection Line about to y=0 or x-axis
Line reflection_line_y(int y,Line lineReflection){
	Line lineResult;
	
    int pivotX = lineReflection.p1.x;
    int pivotY = lineReflection.p1.y;
	
	lineResult.p1.x = pivotX;
	lineResult.p1.y = pivotY;
	
	//Reflect to pivot point x-axis or y=0
	lineResult.p2.x=(int)(pivotX +((lineReflection.p2.x-pivotX)
					*(1)-(lineReflection.p2.y-pivotY)*(0)));
	lineResult.p2.y=(int)(pivotY +((lineReflection.p2.x-pivotX)
					*(0)+(lineReflection.p2.y-pivotY)*(-1)));
	
	//Translation p2
	lineResult.p2 = translation(lineResult.p2,0,2*y);
	
    return lineResult;
}

// Reflection Line about to x=y
Line reflection_line_xy(Line lineReflection){
	Line lineResult;
	
    int pivotX = lineReflection.p1.x;
    int pivotY = lineReflection.p1.y;
	
	lineResult.p1.x = pivotX;
	lineResult.p1.y = pivotY;
	
	//Reflect to pivot point y=x
	lineResult.p2.x=(int)(pivotX +((lineReflection.p2.x-pivotX)
					*(0)-(lineReflection.p2.y-pivotY)*(1)));
	lineResult.p2.y=(int)(pivotY +((lineReflection.p2.x-pivotX)
					*(1)+(lineReflection.p2.y-pivotY)*(0)));
	
    return lineResult;
}

// Reflection Line about to origin
Line reflection_line_origin(int y,Line lineReflection){
	Line lineResult;
	
    int pivotX = lineReflection.p1.x;
    int pivotY = lineReflection.p1.y;
	
	lineResult.p1.x = pivotX;
	lineResult.p1.y = pivotY;
	
	//Reflect to pivot point origin (0,0)
	lineResult.p2.x=(int)(pivotX +((lineReflection.p2.x-pivotX)
					*(-1)-(lineReflection.p2.y-pivotY)*(0)));
	lineResult.p2.y=(int)(pivotY +((lineReflection.p2.x-pivotX)
					*(0)+(lineReflection.p2.y-pivotY)*(-1)));
	
    return lineResult;
}

// Scaling
Point scaling(Point point,
			int xSc,int ySc){
	point.x *= xSc;
	point.y *= ySc;
	
	return point;
}
