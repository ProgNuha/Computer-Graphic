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
	viewLineBresenham(argc, argv);
	
//	viewLineDDA(argc, argv);
//
//	viewCircle(argc, argv);
//	
//	viewEllips(argc, argv);
	
	return 0;
}
