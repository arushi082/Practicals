#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#define SIN(x) sin(x*3.141592653589/180)
#define COS(x) cos(x*3.141592653589/180)
void main()
{	clrscr();
	int gdriver=DETECT,gmode,x0=0,y0=0,x1=0,y1=0,tx=0,ty=0,ch=0,sx=0,sy=0,a=0,b=0,c=0,d=0,x2=0,y2=0,r=0,ang=0,X0=0,Y0=0,X1=0,Y1=0;
	cout<<"\n Enter The Co-Ordinates For First Point : ";
	cin>>x0>>y0;
	cout<<"\n Enter The Co-Ordinates For Second Point : ";
	cin>>x1>>y1;
	clrscr();
	cout<<"\n TRANSFORMATION MENU ";
	cout<<"\n 1. Translation ";
	cout<<"\n 2. Scaling ";
	cout<<"\n 3. Reflection ";
	cout<<"\n 4. Rotation ";
	cout<<"\n 5. Shearing ";
	cout<<"\n Enter Choice : ";
	cin>>ch;
	switch(ch)
	{	case 1 :{	cout<<"\n Enter Translation Factors For X And Y : ";
				cin>>tx>>ty;
				initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
				line(x0,y0,x1,y1);
				line(x0+tx,y0+ty,x1+tx,y1+ty);
				getch();
				closegraph();
			}
			break;
		case 2 :{	cout<<"\n Enter Scaling Factors For X And Y : ";
				cin>>sx>>sy;
				initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
				line(x0,y0,x1,y1);
				line(x0*sx,y0*sy,x1*sx,y1*sy);
				getch();
				closegraph();
			}
			break;
		case 3 :{	cout<<"\n Enter The Co-Ordinates For Third Point : ";
				cin>>x2>>y2;
				cout<<"\n Enter 1 For Reflecting Along X Axis And 0 For Reflecting Against Y Axis : ";
				cin>>r;
				initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
				line(x0,y0,x1,y1);
				line(x1,y1,x2,y2);
				line(x0,y0,x2,y2);
				if(r==1)
				{	line(x0,-y0+500,x1,-y1+500);
					line(x1,-y1+500,x2,-y2+500);
					line(x0,-y0+500,x2,-y2+500);
				}	
				else
				{	line(-x0+500,y0,-x1+500,y1);
					line(-x1+500,y1,-x2+500,y2);
					line(-x0+500,y0,-x2+500,y2);
				}
				getch();
				closegraph();
			}
			break;
		case 4 :{	cout<<"\n Enter Angle In Degree By Which You Want To Rotate : ";
				cin>>ang;
				X0=x0*COS(ang)-y0*SIN(ang);
				X1=x1*COS(ang)-y1*SIN(ang);
				Y0=x0*SIN(ang)-y0*COS(ang);
				Y1=x1*SIN(ang)-y1*COS(ang);
				initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
				line(x0,y0,x1,y1);
				line(X0,Y0,X1,Y1);
				getch();
				closegraph();
			}
			break;
		case 5 :{	cout<<"\n Enter Shearing Factors For X And Y : ";
				cin>>a>>b>>c>>d;
				initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
				line(x0,y0,x1,y1);
				line(a*x0+c*y0,b*x0+d*y0,a*x1+c*y1,b*x1+d*y1);
				getch();
				closegraph();
			}
			break;
	}
	getch();
}