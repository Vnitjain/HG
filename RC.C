#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#define speed 20

int a[20][2],au[20][2],al[20][2];
int gd=DETECT,gm=0;
int check1=0,check2=0;


void plot_lower();
void plot_upper();
void rotatenfill();
void drawTriangle();

void plot_lower()
{
	static int y=299,xl=101,xr=299;

	detectgraph(&gd,&gm);
	setcolor(7);

	if(y>=201)
    {
		if(getpixel(xl,y)==15)
		{
			xl++;
		}
		if(getpixel(xr,y)==15)
		{
			xr--;
		}
		line(xl,y,xr,y);
		y--;
	}
	else
		  check1=1;

}

void plot_upper()
{
	static int y=101,xl=101,xr=299;

	detectgraph(&gd,&gm);
	setcolor(0);

    if(y<=199)
    {
		if(getpixel(xl,y)==15)
		{
			xl++;
		}
		if(getpixel(xr,y)==15)
		{
			xr--;
		}
		line(xl,y,xr,y);
		y++;
	 }

	else
		check2=1;

}

void plot_ini()
{
	static int y,xl=101,xr=299;

	detectgraph(&gd,&gm);
	setcolor(7);

    for(y=101;y<=199;y++)
    {
		if(getpixel(xl,y)==15)
		{
			xl++;
		}
		if(getpixel(xr,y)==15)
		{
			xr--;
		}
		line(xl,y,xr,y);
	}

}

void grav_eff()
{
	int x=200,y=201;

	while(y<300)
	{
		putpixel(x-1,y,7);
		putpixel(x,y,7);
		putpixel(x+1,y,7);
		y++;
		delay(speed);
	}
}

/*V*/
void rotatenfill(int a[][],int o)
{
	float t,centre[2],t1[10];
	t=(3.14/180)*o;

	centre[0]=a[2][0];
	centre[1]=a[2][1];

	//translate centre to origin
	t1[0]=a[0][0]-centre[0];
	t1[1]=a[0][1]-centre[1];

	t1[2]=a[1][0]-centre[0];
	t1[3]=a[1][1]-centre[1];

	t1[4]=a[2][0]-centre[0];
	t1[5]=a[2][1]-centre[1];

	t1[6]=a[3][0]-centre[0];
	t1[7]=a[3][1]-centre[1];

	t1[8]=a[4][0]-centre[0];
	t1[9]=a[4][1]-centre[1];

	//rotate
	t1[0]=

	//translate back
}

void drawTriangle(int a[])
{

}
/*V*/
int main()
{
	int flag=0,i;
	int point[]={200,200,100,300,300,300};

	a[0][0]=100;//a
	a[0][1]=100;//a
	a[1][0]=300;//b
	a[1][1]=100;//b
	a[2][0]=200;//c
	a[2][1]=200;//c
	a[3][0]=100;//d
	a[3][1]=300;//d
	a[4][0]=300;//e
	a[4][1]=300;//e


	//inner coordinated for upper part
	au[0][0]=101;
	au[0][1]=101;
	au[1][0]=299;
	au[1][1]=101;
	au[2][0]=199;
	au[2][1]=200;

	//inner coordinates for lower part
	al[0][0]=200;
	al[0][1]=201;
	al[1][0]=101;
	al[1][1]=299;
	al[2][0]=299;
	al[2][1]=299;

	initgraph(&gd,&gm,"C:\\TC\\BGI");

	/*animation part*/
	line(a[0][0],a[0][1],a[1][0],a[1][1]);
	line(a[1][0],a[1][1],a[2][0],a[2][1]);
	line(a[0][0],a[0][1],a[2][0],a[2][1]);
	line(a[2][0],a[2][1],a[3][0],a[3][1]);
	line(a[3][0],a[3][1],a[4][0],a[4][1]);
	line(a[2][0],a[2][1],a[4][0],a[4][1]);


	plot_ini();
	delay(50*speed);

	grav_eff();

	while(check1==0 && check2==0)
	{
		if(flag==0)
		{
			plot_lower();
			flag=1;
			delay(2*speed);
		}
		else
		{
			plot_upper();
			flag=0;
		}
	}
	/*end animation part*/


	/*rotation part*/
	line(a[0][0],a[0][1],a[1][0],a[1][1]);
	line(a[1][0],a[1][1],a[2][0],a[2][1]);
	line(a[0][0],a[0][1],a[2][0],a[2][1]);
	line(a[2][0],a[2][1],a[3][0],a[3][1]);
	line(a[3][0],a[3][1],a[4][0],a[4][1]);
	line(a[2][0],a[2][1],a[4][0],a[4][1]);
	getch();
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	fillpoly(3,point);

	for(i=0;i<181;i++)
	{
		rotatenfill(a,i);
	}
	/* end rotation part*/


	getch();
	closegraph();
	return 0;
}

