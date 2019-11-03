#include "library.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <gl/glut.h>

Point point1, point2;
Line line;
Circle circle;
Elips ellips;
Color color;

int main(int argc, char **argv) {
//	viewPoint(argc, argv);
//	viewLineBresenham(argc, argv);
//	
//	viewLineDDA(argc, argv);
//
//	viewCircle(argc, argv);
//	
//	viewEllips(argc, argv);


	line.p1.x = 100;
	line.p1.y = 100;
	line.p2.x = 200;
	line.p2.y = 100;
	
	
	point1.x = line.p1.x;
	point1.y = line.p1.y;
	point2.x = line.p2.x;
	point2.y = line.p2.y;
	
	init_windows_glut(argc, argv, 500,500,"Rotation");
	glutKeyboardFunc(process_next_screen);
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, 
					GLUT_ACTION_CONTINUE_EXECUTION ); 
	glutDisplayFunc(displayBresenham);
	glutMainLoop();
	
	printf("(%d,%d)\n", line.p2.x, line.p2.y);
	line = reflection_line_x(0,line);
	point1.x = line.p1.x;
	point1.y = line.p1.y;
	point2.x = line.p2.x;
	point2.y = line.p2.y;
	printf("(%d,%d)\n", line.p2.x, line.p2.y);


	init_windows_glut(argc, argv, 500,500,"Rotation");
	glutKeyboardFunc(process_next_screen);
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, 
					GLUT_ACTION_CONTINUE_EXECUTION ); 
	glutDisplayFunc(displayBresenham);
	glutMainLoop();
	
	
	
	return 0;
}
