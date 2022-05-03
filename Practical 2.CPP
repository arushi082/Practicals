#include<iostream.h>
#include<graphics.h>
#include<conio.h>
void drawcircle(int x0,int y0,int radius)
{   int x=radius;
    int y=0;
    int err=0;
    while(x>=y)
    {	putpixel(x0+x,y0+y,7);
	putpixel(x0+y,y0+x,7);
	putpixel(x0-y,y0+x,7);
	putpixel(x0-x,y0+y,7);
	putpixel(x0-x,y0-y,7);
	putpixel(x0-y,y0-x,7);
	putpixel(x0+y,y0-x,7);
	putpixel(x0+x,y0-y,7);
	if(err<=0)
	{	y+=1;
		err+=2*y+1;
	}
	if(err>0)
	{	x-=1;
		err-=2*x+1;
	}
    }
}
void main()
{	int gdriver=DETECT,gmode,error,x,y,r;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	cout<<"\n Enter The Radius For The Circle : ";
	cin>>r;
	cout<<"\n Enter The Co-Ordinates For The Center(X And Y) : ";
	cin>>x>>y;
	drawcircle(x,y,r);
	getch();
}