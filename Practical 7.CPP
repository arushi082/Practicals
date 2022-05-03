#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void drawcube(int x1[],int y1[])
{	int i;
	for(i=0;i<4;i++)
	{	if(i<3)
			line(x1[i],y1[i],x1[i+1],y1[i+1]);
		line(x1[0],y1[0],x1[3],y1[3]);
	}
	for(i=4;i<8;i++)
	{	if(i<7)
			line(x1[i],y1[i],x1[i+1],y1[i+1]);
		line(x1[4],y1[4],x1[7],y1[7]);
	}
	for(i=0;i<4;i++)
		line(x1[i],y1[i],x1[i+4],y1[i+4]);
}
void main()
{	clrscr();
	int gd=DETECT,gm,x,y,z,size,i,x1[8],y1[8],x2[8],y2[8],z1[8],x3[8],y3[8],z3[8],x4[8],y4[8],ang,c,ch,tx,ty,tz,sx,sy,sz,xf,yf,zf;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	cout<<"\n Enter The General X , Y , Z Coordinates For The Cube : ";
	cin>>x>>y>>z;
	cout<<"\n Enter The Size Of The Edge : ";
	cin>>size;
	x1[0]=x1[3]=x1[4]=x1[7]=x;
	x1[1]=x1[2]=x1[5]=x1[6]=x+size;
	y1[0]=y1[1]=y1[4]=y1[5]=y;
	y1[2]=y1[3]=y1[6]=y1[7]=y+size;
	z1[0]=z1[1]=z1[2]=z1[3]=z;
	z1[4]=z1[5]=z1[6]=z1[7]=z-size;
	for(i=0;i<8;i++)
	{	x2[i]=x1[i]+z1[i]/2;
		y2[i]=y1[i]+z1[i]/2;
	}
	drawcube(x2,y2);
	getch();
	closegraph();
	cout<<"\n TRANSFORMATION MENU ";
	cout<<"\n 1. Translation ";
	cout<<"\n 2. Rotation ";
	cout<<"\n 3. Scaling ";
	cout<<"\n 4. Reflection ";
	cout<<"\n 5. Perspective Projection ";
		cout<<"\n Enter Choice : ";
	cin>>ch;
	switch(ch)
	{	case 1:{	cout<<"\n Enter Translation vectors For X , Y And Z : ";
				cin>>tx>>ty>>tz;
				for(i=0;i<8;i++)
				{	x3[i]=x1[i]+tx;
					y3[i]=y1[i]+ty;
					z3[i]=z1[i]+tz;
				}
				for(i=0;i<8;i++)
				{	x4[i]=x3[i]+z3[i]/2;
					y4[i]=y3[i]+z3[i]/2;
				}
				initgraph(&gd,&gm,"C:\\turboc3\\bgi");
				drawcube(x2,y2);
				drawcube(x4,y4);
				getch();
				closegraph();
		       }
		       break;
		case 2:{	cout<<"\n Enter The Angle For Rotation : ";
				cin>>ang;
				ang=(ang*3.14)/180;
				cout<<"\n Enter 1 For Rotation Along X Axis , 2 For Rotation Along Y Axis And 3 For Rotation Along Z Axis : ";
				cin>>c;
				if(c==1)
				{	for(i=0;i<8;i++)
					{	x3[i]=x1[i];
						y3[i]=y1[i]*cos(ang)-z1[i]*sin(ang);
						z3[i]=y1[i]*sin(ang)+z1[i]*cos(ang);
					}
				}
				else
				if(c==2)
				{	for(i=0;i<8;i++)
					{	y3[i]=y1[i];
						x3[i]=z1[i]*cos(ang)-x1[i]*sin(ang);
						x3[i]=z1[i]*sin(ang)+x1[i]*cos(ang);
					}
				}
				else
				if(c==3)
				{	for(i=0;i<8;i++)
					{	z3[i]=z1[i];
						x3[i]=x1[i]*cos(ang)-y1[i]*sin(ang);
						y3[i]=x1[i]*sin(ang)+y1[i]*cos(ang);
					}
				}
				for(i=0;i<8;i++)
				{	x4[i]=x3[i]+z3[i]/2;
					y4[i]=y3[i]+z3[i]/2;
				}
				initgraph(&gd,&gm,"C:\\turboc3\\bgi");
				drawcube(x2,y2);
				drawcube(x4,y4);
				getch();
				closegraph();
			}
			break;
		case 3:{	cout<<"\n Enter The Scaling Factors For X,Y And Z : ";
				cin>>sx>>sy>>sz;
				cout<<"\n Enter The Reference Point : ";
				cin>>xf>>yf>>zf;
				for(i=0;i<8;i++)
				{	x3[i]=xf+(x1[i]*sx)+xf*(1-sx);
					y3[i]=yf+(y1[i]*sy)+yf*(1-sy);
					z3[i]=zf+(z1[i]*sz)+zf*(1-sz);
				}
				for(i=0;i<8;i++)
				{	x4[i]=x3[i]+z3[i]/2;
					y4[i]=y3[i]+z3[i]/2;
				}
				initgraph(&gd,&gm,"C:\\turboc3\\bgi");
				drawcube(x2,y2);
				drawcube(x4,y4);
				getch();
				closegraph();
			}
		case 4:{	cout<<"\n Enter 1 For Reflection Along X Axis , 2 For Rotation Along Y Axis And 3 For Rotation Along Z Axis : ";
					cin>>ch;
					switch(ch)
					{	case 1:{	for(i=0;i<8;i++)
									{	x1[i]=x1[i];
										y1[i]=-y1[i]+500;
										z1[i]=-z1[i]+500;
									}
									initgraph(&gd,&gm,"C:\\turboc3\\bgi");
									drawcube(y1,z1);
									getch();
									closegraph();
								}
								break;
						case 2:{	for(i=0;i<8;i++)
									{	x1[i]=-x1[i]+500;
										y1[i]=y1[i];
										z1[i]=-z1[i]+500;
									}
									initgraph(&gd,&gm,"C:\\turboc3\\bgi");
									drawcube(x1,z1);
									getch();
									closegraph();
								}
								break;
						case 3:{	for(i=0;i<8;i++)
									{	x1[i]=-x1[i]+500;	
										y1[i]=-y1[i]+500;
										z1[i]=z1[i];
									}
									initgraph(&gd,&gm,"C:\\turboc3\\bgi");
									drawcube(x1,y1);
									getch();
									closegraph();
								}
								break;
					}
				}
				break;
		case 5:{	double p,q,r;
					cout<<"\n Enter 1 For Perspective Projection Along X Axis , 2 For Rotation Along Y Axis And 3 For Rotation Along Z Axis : ";
					cin>>ch;
					switch(ch)
					{	case 1:{	cout<<"\n Enter P : ";
									cin>>p;
									for(i=0;i<8;i++)
									{	x1[i]=x1[i]/(p*x1[i]+1);
										y1[i]=y1[i]/(p*x1[i]+1);
										z1[i]=z1[i]/(p*x1[i]+1);
									}
									initgraph(&gd,&gm,"C:\\turboc3\\bgi");
									drawcube(y1,z1);
									getch();
									closegraph();
								}
								break;
						case 2:{	cout<<"\n Enter Q : ";
									cin>>q;
									for(i=0;i<8;i++)
									{	y1[i]=y1[i]/(y1[i]*q+1);
										x1[i]=x1[i]/(y1[i]*q+1);
										z1[i]=z1[i]/(y1[i]*q+1);
									}
									initgraph(&gd,&gm,"C:\\turboc3\\bgi");
									drawcube(x1,z1);
									getch();
									closegraph();
								}
								break;
						case 3:{	cout<<"\n Enter R : ";
									cin>>r;
									for(i=0;i<8;i++)
									{	z1[i]=z1[i]/(z1[i]*r+1);
										x1[i]=x1[i]/(z1[i]*r+1);
										y1[i]=y1[i]/(z1[i]*r+1);
									}
									initgraph(&gd,&gm,"C:\\turboc3\\bgi");
									drawcube(x1,y1);
									getch();
									closegraph();
								}
								break;
						}
				}
	}
	getch();
}
