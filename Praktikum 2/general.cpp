#include "general.h"

/*Create Line*/
void ownLine(Point t1, Point t2){
	line(t1.x, t1.y, t2.x, t2.y);
}

/*Create Rectangle*/
void ownRectangle(Point t1, Point t2)
{
	line(t1.x, t1.y, t2.x, t1.y);
	line(t1.x, t1.y, t1.x, t2.y);
	line(t1.x, t2.y, t2.x, t2.y);
	line(t2.x, t2.y, t2.x, t1.y);
}
