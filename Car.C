/* A Simple Car Game Program By "Bareet Singh".
   You can control the Car by following Keys;
   Enter U for Up
	D for Down
	L for Left
	R for Right
	*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
void car(int,int);
void sides();

void treeleft1(int x1,int y1,int x2,int y2);
void treeleft2(int x1,int y1,int x2,int y2);
void treeleft3(int x1,int y1,int x2,int y2);
void treeright1(int x1,int y1,int x2,int y2);
void treeright2(int x1,int y1,int x2,int y2);
void treeright3(int x1,int y1,int x2,int y2);

int x[20],y[20],h[10],k[10];
int midx1,midy1,stangle1,endangle1,xradius1,yradius1;
int midx2,midy2,stangle2,endangle2,xradius2,yradius2;
int midx3,midy3,stangle3,endangle3,xradius3,yradius3;
int a=0,b=0,c=0,d=0;
int x1,x2,y1,y2;
void main()
{
 int i,gd,gm,m=0,n=0;
 char ch;
 clrscr();

 midx1=280, midy1=350, stangle1=0, endangle1=180,xradius1=30, yradius1=30; //top
 midx2=280, midy2=390, stangle2=200, endangle2=340,xradius2=32, yradius2=32; //bottom
 midx3=280, midy3=334, stangle3=215, endangle3=325,xradius3=36, yradius3=25; //middle
 x[1]=250,y[1]=350,x[2]=250,y[2]=400,x[3]=310,y[3]=350,x[4]=310,y[4]=400;
 x[5]=270,y[5]=330,x[6]=290,y[6]=330,x[7]=270,y[7]=320,x[8]=290,y[8]=320;
 x[9]=280,y[9]=390,x[10]=280,y[10]=422;
 x[11]=260,y[11]=370,x[12]=260,y[12]=375,x[13]=270,y[13]=375,x[14]=270,y[14]=370;
 x[15]=290,y[15]=370,x[16]=290,y[16]=375,x[17]=300,y[17]=375,x[18]=300,y[18]=370;
 h[1]=265,k[1]=372,h[2]=295,k[2]=372;
 h[3]=274,k[3]=326,h[4]=278,k[4]=326,h[5]=282,k[5]=326,h[6]=286,k[6]=326;

 detectgraph(&gd,&gm);
 initgraph(&gd,&gm,"");

 do
 {
  setcolor(10);
  sides();
  setcolor(13);
  car(m,n);
  setcolor(2);

  ch=getch();
  switch(ch)
  {
   case 'l':
    if(x[1]>153)
     m=-3,n=0;
    else
     m=0,n=0;
   break;

   case 'r':
    if(x[3]<425)
     m=3,n=0;
    else
     m=0,n=0;
   break;

   case 'u':
    if(y[7]>0)
     m=0,n=-3;
    else
     m=0,n=0;
   break;

   case 'd':
    if(y[10]<479)
     m=0,n=3;
    else
     m=0,n=0;
   break;

   default:
   exit(0);
  }
  delay(0);
  cleardevice();
 }while(1);
// getch();
}

void car(int m,int n)
{
 line(x[1]+=m,y[1]+=n,x[2]+=m,y[2]+=n);       //ske l  1-2
 line(x[3]+=m,y[3]+=n,x[4]+=m,y[4]+=n);     //ske r    3-4
 line(x[1],y[1],(x[5]+=m),(y[5]+=n));     //top left  1-5
 line(x[5],y[5],x[6]+=m,y[6]+=n);       //top middle 5-6
 line(x[3],y[3],x[6],y[6]);     //top right    3-6
 line(x[5],y[5],x[7]+=m,y[7]+=n);      //top straight left 5-7
 line(x[6],y[6],x[8]+=m,y[8]+=n);      //top straight right 6-8
 line(x[2],y[2],x[9]+=m,y[9]+=n);    //bottom left    2-9
 line(x[9],y[9],x[4],y[4]);    //bottom right 9-4
 line(x[9],y[9],x[10]+=m,y[10]+=n);  //bottom straight 9-10

// circle
 ellipse(midx1+=m,midy1+=n,stangle1,endangle1,xradius1,yradius1);  //TOP
 ellipse(midx2+=m,midy2+=n,stangle2,endangle2,xradius2,yradius2); // BOTTOM
 ellipse(midx3+=m,midy3+=n,stangle3,endangle3,xradius3,yradius3); // MIDDLE

 //left seat
 line(x[11]+=m,y[11]+=n,x[12]+=m,y[12]+=n);       //  left
 line(x[12],y[12],x[13]+=m,y[13]+=n);     //     bottom
 line(x[13],y[13],x[14]+=m,y[14]+=n);      //    right

 //right seat
 line(x[15]+=m,y[15]+=n,x[16]+=m,y[16]+=n);      //left
 line(x[16],y[16],x[17]+=m,y[17]+=n);    //bottom
 line(x[17],y[17],x[18]+=m,y[18]+=n);    //right

 //PEOPLE
  circle(h[1]+=m,k[1]+=n,1);// LEFT
  circle(h[2]+=m,k[2]+=n,1);   //RIGHT

 //audi
  circle(h[3]+=m,k[3]+=n,1);
  circle(h[4]+=m,k[4]+=n,1);
  circle(h[5]+=m,k[5]+=n,1);
  circle(h[6]+=m,k[6]+=n,1);


 if(y[1]<=30)
 {

	a=0,b=3,c=0,d=3;
 }
 else if(y[1]>=400)
 {
   a=0,b=-3,c=0,d=-3;
 }
 else
 {
	a=0,b=0,c=0,d=0;
 }
 treeleft1(a,b,c,d);
 treeleft2(a,b,c,d);
 treeleft3(a,b,c,d);
 treeright1(a,b,c,d);
 treeright2(a,b,c,d);
 treeright3(a,b,c,d);

}

void sides()
{
 line(150,0,150,479);     //left 1
 line(153,0,153,479);    //left 2
 line(426,0,426,479);    //right 3
 line(429,0,429,479);    //right 4
 line(153,0,426,0);    //up
 line(153,479,426,479);    //bottom
}

void treeleft1(int a,int b,int c,int d)
{
 y1+=b;
 y2+=d;
 if(y1>=360 || y2<=-120)
 {
 y1=0;
 y2=0;
 }

 line(50+a,120+y1,50+c,150+y2);
 line(50,120+y1,35,100+y2);
 line(50,120+y1,65,100+y2);
 circle(50,105+y1,15);
}

void treeleft2(int a,int b,int c,int d)
{
 if(y1>=240 )
 {
 y1=0;
 y2=0;
 }
 line(50+a,240+y1,50+c,270+y2);
 line(50,240+y1,35,220+y2);
 line(50,240+y1,65,220+y2);
 circle(50,225+y1,15);
}

void treeleft3(int a,int b,int c,int d)
{
 if(y1>=120 )
 {
 y1=0;
 y2=0;
 }
 line(50+a,360+y1,50+c,390+y2);
 line(50,360+y1,35,340+y2);
 line(50,360+y1,65,340+y2);
 circle(50,345+y1,15);
}

void treeright1(int a,int b,int c,int d)
{
 line(500+a,120+y1,500+c,150+y2);
 line(500,120+y1,485,100+y2);
 line(500,120+y1,515,100+y2);
 circle(500,105+y1,15);
}

void treeright2(int a,int b,int c,int d)
{
 line(500+a,240+y1,500+c,270+y2);
 line(500,240+y1,485,220+y2);
 line(500,240+y1,515,220+y2);
 circle(500,225+y1,15);
}

void treeright3(int a,int b,int c,int d)
{
 line(500+a,360+y1,500+c,390+y2);
 line(500,360+y1,485,340+y2);
 line(500,360+y1,515,340+y2);
 circle(500,345+y1,15);
}

