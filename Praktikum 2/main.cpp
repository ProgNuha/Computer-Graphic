#include "general.h"

main(int argc, char *argv[])
{
	/* Input size of canvas */
	int height, width;
	printf("Height = ");
	scanf("%d", &height);
	printf("Width = ");
	scanf("%d", &width);
	initwindow(width,height, "PRAKTIKUM KOMPUTER GRAFIK - 1711050");	// init window graphics
	
	/*=================================================================================*/
	/* Input amount of pixel */
	int p;
	printf("Pixel = ");
	scanf("%d", &p);

	/* pixel */
	Point p1;
	for(int i = 0;i<p;i++){	
		p1.x = rand()%getmaxx();			// random the value of x
		p1.y = rand()%getmaxy();			// random the value of y
		putpixel(p1.x,p1.y,rand()%15+1);	// show pixel, with random the color
	}
 	/*=================================================================================*/
 	
 	
 	/*=================================================================================*/
	/* Input amount of line */
	int l;
	printf("Line = ");
	scanf("%d", &l);
	
	/* line */
	Point l1,l2;
	for(int i = 0;i<l;i++){
		l1.x = rand()%getmaxx();	// random the value of x
		l1.y = rand()%getmaxy();	// random the value of y
		l2.x = rand()%getmaxx();	// random the value of x
		l2.y = rand()%getmaxy();	// random the value of y
		setcolor(rand()%15+1);		// set color, with parameter to get random color
	//	line(l1.x,l1.y,l2.x,l2.y);	// create line using default function at graphics.h
		ownLine(l1,l2);				// create line using custom function at general.h
	}
 	/*=================================================================================*/


	/*=================================================================================*/
	/* clear canvas */
	int clear;
	while(clear != 1){
		printf("Clear? ");
		scanf("%d", &clear);
	}
	cleardevice();
	/*=================================================================================*/


	/*=================================================================================*/
	/* Input margin */
	int loop,m,color;
	printf("Margin = ");
	scanf("%d", &m);

	/* create square with 2 line using function and the other using putpixel */
	loop = m;
	color = rand()%15+1;		// random color
	setcolor(color);			// setcolor
	
	/* create square */
	/* 2 line using function */
	line(m,m,getmaxx()-m,m);
	line(m,getmaxx()-m,getmaxx()-m,getmaxx()-m);
	/* 2 line using putpixel */
	for(loop;loop-1<getmaxx()-m;loop++){
		putpixel(m,loop,color);
		putpixel(getmaxx()-m,loop,color);
	}
	/*=================================================================================*/
	
	
	/*=================================================================================*/
	/* fine 4 corners of rectangle */
	Point c2;
	for(int yy = 0;yy<getmaxy();yy++){
		for(int xx = 0;xx<getmaxx();xx++){
			/* upper left corner */
			if(getpixel(xx,yy) == color && getpixel(xx+1,yy) == color && getpixel(xx,yy+1) == color){
				printf("Koordinat titik sudut kiri atas =  (%d,%d)\n", xx,yy);
			}
			/* upper right corner */
			if(getpixel(xx,yy) == color && getpixel(xx-1,yy) == color && getpixel(xx,yy+1) == color){
				printf("Koordinat titik sudut kanan atas =  (%d,%d)\n", xx,yy);
			}
			/* bottom left corner */
			if(getpixel(xx,yy) == color && getpixel(xx+1,yy) == color && getpixel(xx,yy-1) == color){
				printf("Koordinat titik sudut kiri bawah =  (%d,%d)\n", xx,yy);
			}
			/* bottom right corner */
			if(getpixel(xx,yy) == color && getpixel(xx-1,yy) == color && getpixel(xx,yy-1) == color){
				printf("Koordinat titik sudut kanan bawah = (%d,%d)\n", xx,yy);
				c2.x = xx;
				c2.y = yy;
			}
		}	
	}
	/*=================================================================================*/
		

	/*=================================================================================*/
	/* create cartesian */
	int counter = m;
	int center;
	center = ((c2.x-m)/2)+m;
	
	line(m,center,getmaxx()-m,center);
	line(center,m,center,c2.y);
	
	//	for(counter;counter-1<getmaxx()-m;counter++){
	//		putpixel(counter,center,color);
	//		putpixel(center,counter,color);
	//	}
	
	/*=================================================================================*/


	/*=================================================================================*/
	Point c0,c1,p,temp;
	int temp1,temp2,dilation=5;
	c0.x = center;
	c0.y = center;
	p = c0;
	
	/* y=x^2 */
	for(int i = 1;i<6;i++){
		/*find dilation*/
		temp.x = i*dilation;
		temp.y = (i * i)*dilation;
		/*pick coordinate dilation*/
		c1.x = center + temp.x;
		c1.y = center - temp.y;
		setcolor(10);				//setcolor
		line(p.x, p.y, c1.x, c1.y);	//draw line
		p = c1;						//set next point
	}
	
	/* y= */
	p = c0;
	for(int i = 2;i<10;i++){
		c1.x = center + i;
		temp1 = i*i*i;
		temp2 = 3*i;
		c1.y = center - (temp1-temp2-1);
		setcolor(7);
		line(p.x, p.y, c1.x, c1.y);
		p = c1;
	}
	
		/* y= */
	p = c0;
	for(int i = 2;i<10;i++){
		temp.x = i*dilation;
		c1.x = center + temp.x;
		temp1 = i*i*i;
		temp2 = 3*i;
		temp1 = temp1 - temp2 - 1;
		temp.y = temp1 * dilation;
		c1.y = center - temp.y;
		setcolor(1);
		line(p.x, p.y, c1.x, c1.y);
		p = c1;
	}
	
//	double degree = 0,x_rad;
//	/* y=cos(x) */
//	p = c0;
//	for(int i = 0;i<10;i++){
//		c1.x = center + i;
//		x_rad = degree*3.14159/180;
//		c1.y = abs(cos(x_rad));
//		setcolor(3);
//		putpixel(c1.x, c1.y, 3);
//		p = c1;
//		degree += 30;
//	}

//	double degree = 0,x_rad;
//	/* y=sin(x) */
//	p = c0;
//	for(int i = 0;i<10;i++){
//		c1.x = center + i;
//		x_rad = degree*3.14159/180;
//		c1.y = abs(sin(x_rad));
//		setcolor(3);
//		putpixel(c1.x, c1.y, 3);
//		p = c1;
//		degree += 30;
//	}
	/*=================================================================================*/
	
	

	

	getch();
	closegraph();	
	return 0;

}
