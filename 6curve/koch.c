#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#define med(x,y) ((x+y)/2)
#define PI 3.14
float L;
int koach (float x1, float y1,float x2,float y2,int it){
float xm[3],ym[3],d,a,h;
float dx,dy,part,xmin;
setcolor(WHITE);
line(x1,y1,x2,y2);
if(it==0)
	return 0;
    d = sqrt ((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1)) / 3;
    a = atan2 ((double) (y2-y1), (double) (x2-x1));      
    h = 2 * d * cos (30 * PI / 180);          
    xm[0] = x1 + (int) (d * cos (a));
    ym[0] = y1 + (int) (d * sin (a));
    xm[1] = x1 + (int) (h * cos ((a + 30 * PI / 180)));  
    ym[1] = y1 + (int) (h * sin ((a + 30 * PI / 180)));
    xm[2] = x1 + (int) (2 * d * cos (a));
    ym[2] = y1 + (int) (2 * d * sin (a));
setcolor(8);
line(xm[0],ym[0],xm[2],ym[2]);
setcolor(WHITE);
line(xm[0],ym[0],xm[1],ym[1]);
line(xm[1],ym[1],xm[2],ym[2]);
getch();
koach(xm[0],ym[0],xm[1],ym[1],it-1);
koach(xm[1],ym[1],xm[2],ym[2],it-1);
koach(x1,y1,xm[0],ym[0],it-1);
koach(xm[2],ym[2],x2,y2,it-1);
return 0;
}
 void main()
 {
 float x1,y1,x2,y2,wf;
 int gd=DETECT,gm;
  initgraph(&gd,&gm,"..\\bgi");
scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
 setcolor(8);
 line(x1,y1,x2,y2);
getch();
setbkcolor(8);
L=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
koach(x1,y1,x2,y2,3);
printf("Final Output:");
getch();
  closegraph();}

