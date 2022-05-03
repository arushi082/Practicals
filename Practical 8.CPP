#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
void hermite(int x[4],int y[4])
{	double t;
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	for(int i=0;i<4;i++)
		putpixel(x[i],y[i],YELLOW);
	delay(1000);
	for(t=0.0;t<=1.0;t+=0.0005)
	{	double xt=(2*pow(t,3)-3*pow(t,2)+1)*x[0]+(-2*pow(t,3)+3*pow(t,2))*x[1]+(pow(t,3)-2*pow(t,2)+t)*x[2]+(pow(t,3)-pow(t,2))*x[3];
		double yt=(2*pow(t,3)-3*pow(t,2)+1)*y[0]+(-2*pow(t,3)+3*pow(t,2))*y[1]+(pow(t,3)-2*pow(t,2)+t)*y[2]+(pow(t,3)-pow(t,2))*y[3];
		putpixel(xt,yt,WHITE);
	}
	getch();
	closegraph();
}
void bezier(int x[4],int y[4])
{	double t;
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	for(int i=0;i<4;i++)
		putpixel(x[i],y[i],YELLOW);
	delay(1000);
	for(t=0.0;t<=1.0;t+=0.0005)
	{	double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
		double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
		putpixel(xt,yt,WHITE);
	}
	getch();
	closegraph();
}
void main()
{	clrscr();
	int x[4],y[4],ch;
	cout<<"\n MAIN MENU ";
	cout<<"\n 1. Hermite Curve ";
	cout<<"\n 2. Bezier Curve ";
	cout<<"\n Enter Choice : ";
	cin>>ch;
	switch(ch)
	{	case 1 :{	cout<<"\n Enter X And Y Coordinates For P1 , P4 , R1 , R4 : ";
					for(int i=0;i<4;i++)
					{	cout<<"\n Enter For Point "<<i+1<<" : ";
						cin>>x[i]>>y[i];
					}
					clrscr();
					hermite(x,y);
				}
				break;
		case 2 :{	cout<<"\n Enter X And Y Coordinates : ";
					for(int i=0;i<4;i++)
					{	cout<<"\n Enter For Point "<<i+1<<" : ";
						cin>>x[i]>>y[i];
					}
					clrscr();
					bezier(x,y);
				}
				break;
		default:cout<<"\n Wrong Choice ";
	}
	getch();
}
