#include<stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
int min,sec;
void draw_oct(int xi,int yi,int x,int y,int r,int cc){

putpixel(xi+x,yi+y,cc);
putpixel(xi-x,yi+y,cc);
putpixel(xi+x,yi-y,cc);
putpixel(xi-x,yi-y,cc);
putpixel(xi+y,yi+x,cc);
putpixel(xi-y,yi+x,cc);
putpixel(xi+y,yi-x,cc);
putpixel(xi-y,yi-x,cc);
}
void draw_circle(int x,int y,int r,int col){
int s=3-2*r;
int yold=y;
int xold=x;
int xc,yc;
x=0;
y=r;
//printf("init s %d",s);

xc=x;
yc=y;
draw_oct(xold,yold,x,y,r,col);
while(x<y){
	if(s < 0){
			s+=4*x+6;
			x++;
		//	printf("%d s < 0\n",s);
	}else{
			s+=4*(x-y)+10;
		 //	printf("%d s > 0\n",s);
			x++;
			y--;
	}
	draw_oct(xold,yold,x,y,r,col);
}
}
void draw_second(int ts,int xs,int ys){
		char print[10];

int sr=ts;
		while(ts-->0){
		draw_circle(xs,ys,ts,8);
		delay(50);
		}

		while(ts++<sr){
		draw_circle(xs,ys,ts,15);
		delay(50);
		}
}
int main(){
	int gd,gm,i;
	int x,y,r,ts,xi,yi;
	int t;
	int col=1;
	int xs,ys,sr;
	clrscr();
	gd=DETECT;
	initgraph(&gd,&gm,"..\\bgi");
	setbkcolor(WHITE);
	min=0;
	sec=0;
	xi=getmaxx()/2;
	yi=getmaxy()/2;
	xs=xi+100;
	ys=yi;
	r=60;
	sr=10;
	t=r;
	while(t-->0){
	//draw second hand
	draw_second( sr,xs,ys);
	draw_circle(xi,yi,t,8);
	}

	while(t++<r){
	draw_second(sr,xs,ys);
	 draw_circle(xi,yi,t,15);
	}
	getch();
return 0;
}

