
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#define med(x,y) ((x+y)/2)
float L;
float getrandom(){
float r,t;
r=rand()%150;
r/=100;
if(r==0)
return r;
else{
	t=rand()%2;
	if(t==1)
		return (sin(r));
	 else
		return (-(sin(r)));
}
}
int fractal (float x1, float y1,float x2,float y2,float wf,int it){
float xm,ym,dx,dy,G;
if(it==0)
	return 0;
xm=med(x1,x2);
ym=med(y1,y2);
G=getrandom();
dx=L*G*wf;
xm+=dx;
G=getrandom();
dy=L*G*wf;
ym+=dy;
setcolor(8);
line(x1,y1,x2,y2);
setcolor(WHITE);
line(x1,y1,xm,ym);
line(xm,ym,x2,y2);
//getch();
fractal(x1,y1,xm,ym,wf,it-1);
fractal(xm,ym,x2,y2,wf,it-1);
return 0;
}
 void main()
 {
 float x1,y1,x2,y2,wf;
 int gd=DETECT,gm;
  initgraph(&gd,&gm,"..\\bgi");
  //     setbkcolor(WHITE);
 printf("enter the co-ordinatws :");
 scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
// printf("%f  %f",med(x1,x2),med(y1,y2));
 scanf("%f",&wf);
 setcolor(8);
 line(x1,y1,x2,y2);

getch();
setbkcolor(8);
L=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
fractal(x1,y1,x2,y2,wf,6);
printf("Final Output:");
getch();
  closegraph();

 }

