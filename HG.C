#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>

#define del 100

void drawRect(float a[],float b[],float c[],float d[])
{
	line(a[0], a[1], b[0], b[1]);
	line(b[0], b[1], c[0], c[1]);
	line(c[0], c[1], d[0], d[1]);
	line(d[0], d[1], a[0], a[1]);
}

void drawTri(float a[],float b[],float c[])
{
	line(a[0], a[1], b[0], b[1]);
	line(b[0], b[1], c[0], c[1]);
	line(c[0], c[1], a[0], a[1]);
}

void rotate_rect(float a[],float b[],float c[],float d[],float o,float centre[])
{
	float t,ta[2],tb[2],tc[2],td[2];
	t=(3.14/180)*o;

	//translate to origin
	ta[0]=a[0]-centre[0];
	ta[1]=a[1]-centre[1];

	tb[0]=b[0]-centre[0];
	tb[1]=b[1]-centre[1];

	tc[0]=c[0]-centre[0];
	tc[1]=c[1]-centre[1];

	td[0]=d[0]-centre[0];
	td[1]=d[1]-centre[1];

	//rotate about angle
	ta[0]=(ta[0]*cos(t))-(ta[1]*sin(t));
	ta[1]=(ta[0]*sin(t))+(ta[1]*cos(t));

	tb[0]=(tb[0]*cos(t))-(tb[1]*sin(t));
	tb[1]=(tb[0]*sin(t))+(tb[1]*cos(t));

	tc[0]=(tc[0]*cos(t))-(tc[1]*sin(t));
	tc[1]=(tc[0]*sin(t))+(tc[1]*cos(t));

	td[0]=(td[0]*cos(t))-(td[1]*sin(t));
	td[1]=(td[0]*sin(t))+(td[1]*cos(t));

	//translate back to original point
	ta[0]=ta[0]+centre[0];
	ta[1]=ta[1]+centre[1];

	tb[0]=tb[0]+centre[0];
	tb[1]=tb[1]+centre[1];

	tc[0]=tc[0]+centre[0];
	tc[1]=tc[1]+centre[1];

	td[0]=td[0]+centre[0];
	td[1]=td[1]+centre[1];

	drawRect(ta,tb,tc,td);
}

void rotate_tri(float a[],float b[],float c[],float o,float centre[])
{
	float t,ta[2],tb[2],tc[2],td[2];
	t=(3.14/180)*o;
	
	//translate to origin
	ta[0]=a[0]-centre[0];
	ta[1]=a[1]-centre[1];

	tb[0]=b[0]-centre[0];
	tb[1]=b[1]-centre[1];

	tc[0]=c[0]-centre[0];
	tc[1]=c[1]-centre[1];
	
	//rotate about angle
	ta[0]=(ta[0]*cos(t))-(ta[1]*sin(t));
	ta[1]=(ta[0]*sin(t))+(ta[1]*cos(t));

	tb[0]=(tb[0]*cos(t))-(tb[1]*sin(t));
	tb[1]=(tb[0]*sin(t))+(tb[1]*cos(t));

	tc[0]=(tc[0]*cos(t))-(tc[1]*sin(t));
	tc[1]=(tc[0]*sin(t))+(tc[1]*cos(t));
	
	//translate back to original point
	ta[0]=ta[0]+centre[0];
	ta[1]=ta[1]+centre[1];

	tb[0]=tb[0]+centre[0];
	tb[1]=tb[1]+centre[1];

	tc[0]=tc[0]+centre[0];
	tc[1]=tc[1]+centre[1];

	drawTri(ta,tb,tc);
}

void main()
{
	int gd=DETECT,gm,i;
	float
	a1[2]={120,70},b1[2]={400,70},c1[2]={400,120},d1[2]={120,120},	 //I
	a2[2]={120,370},b2[2]={400,370},c2[2]={400,420},d2[2]={120,420}, //II
	a3[2]={130,120},b3[2]={140,120},c3[2]={140,370},d3[2]={130,370},//III
	a4[2]={380,120},b4[2]={390,120},c4[2]={390,370},d4[2]={380,370},//IV
	a5[2]={160,120},b5[2]={360,120},c5[2]={260,245}, 	//V
	a6[2]={260,245},b6[2]={360,370},c6[2]={160,370},	//VI
	centre[2]={260,245};

	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	//draw diagram
	drawRect(a1,b1,c1,d1);
	drawRect(a2,b2,c2,d2);
	drawRect(a3,b3,c3,d3);
	drawRect(a4,b4,c4,d4);
	drawTri(a5,b5,c5);
	drawTri(a6,b6,c6);
	delay(del*10);

	for(i=1;i<180;i++)
	{
		cleardevice();
		rotate_rect(a1,b1,c1,d1,i,centre);
		rotate_rect(a2,b2,c2,d2,i,centre);
		rotate_rect(a3,b3,c3,d3,i,centre);
		rotate_rect(a4,b4,c4,d4,i,centre);

		rotate_tri(a5,b5,c5,i,centre);
		rotate_tri(a6,b6,c6,i,centre);
		
		delay(del);
	}

	getch();
	closegraph();
}