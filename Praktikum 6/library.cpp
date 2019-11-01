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

void draw_ellips_points(int xCenter, int yCenter, int x, int y){
	draw_pixel(xCenter + x, yCenter + y);
	draw_pixel(xCenter - x, yCenter + y);
	draw_pixel(xCenter + x, yCenter - y);
	draw_pixel(xCenter - x, yCenter - y);
}


/*=============================================================================================*/
/*=---------------------------------------- Display ------------------------------------------=*/
/*=============================================================================================*/

void displayBresenham(){
	draw_line_bresenham(point1.x, point1.y, point2.x, point2.y);
	glFlush();
}

void displayDDA(){
	draw_line_DDA(point1, point2);
	glFlush();
}

void displayCircle(){
	draw_circle(circle.xCenter, circle.yCenter, circle.radius);
	glFlush();
}

void displayEllips(){
	draw_ellipse(ellips.xCenter, ellips.yCenter, ellips.radiusX, ellips.radiusY);
	glFlush();
}

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
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION ); 
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
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION ); 
	glutDisplayFunc(displayCircle);
	glutMainLoop();
}

void viewLineBresenham(int argc, char** argv){
	printf( "Enter First Point\n");
	printf( "X : ");
	scanf("%d", &point1.x);
	printf( "Y : ");
	scanf("%d", &point1.y);
	
	printf( "Enter Second Point\n");
	printf( "X : ");
	scanf("%d", &point2.x);
	printf( "Y : ");
	scanf("%d", &point2.y);

	init_windows_glut(argc, argv, 500,500,"Bresenham");
	glutKeyboardFunc(process_next_screen);
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION ); 
	glutDisplayFunc(displayBresenham);
	glutMainLoop();
}

void viewLineDDA(int argc, char** argv){
	printf( "Enter First Point\n");
	printf( "X : ");
	scanf("%d", &point1.x);
	printf( "Y : ");
	scanf("%d", &point1.y);
	
	printf( "Enter Second Point\n");
	printf( "X : ");
	scanf("%d", &point2.x);
	printf( "Y : ");
	scanf("%d", &point2.y);

	init_windows_glut(argc, argv, 500,500,"DDA");
	glutKeyboardFunc(process_next_screen);
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION ); 
	glutDisplayFunc(displayDDA);
	glutMainLoop();
}


/*=============================================================================================*/
/*=------------------------------------ Transformation ---------------------------------------=*/
/*=============================================================================================*/

