#include<stdio.h>
#include <conio.h>
#include <graphics.h>
#define ROUND(x) (int)(x+0.5)

void dda_line(int x1,int y1,int x2,int y2){
int dx,dy;
int k;
float xin,yin, x,y,steps;
 dx=x2-x1;
 dy=y2-y1;
 putpixel(x1,y1,4);
 x=x1;
 y=y1;

 if(abs(dx) >= abs(dy)){
	steps=abs(dx);
 }else{
	steps=abs(dy);
 }
 xin=(float)dx/ steps;
 yin=(float)dy/ steps;

 putpixel(ROUND(x1),ROUND(y1),4);
 for(k=0;k<steps;k++){
	x+=xin;
	y+=yin;
	putpixel(ROUND(x),ROUND(y),4);
 }


}
int sign(float f){

 if(f < 0)
	return -1;
 else if (f == 0)
	return 0;
 else
	return 1;
}
void bresen_line(int xa,int ya,int xb,int yb){
	int exchange,i,temp;
	int dx=abs(xb-xa);
	int dy=abs(yb-ya);
	int g=2*dy-dx,incy;
	int x,y,xend;
	int s1,s2;
	s1=sign(xb-xa);
	s2=sign(yb-ya);
	exchange=0;

	if(dx==0){ //Its vertical line
		 if(ya <= yb)
			incy=1;
		 else if (ya == yb )
			return;
		 else
			incy=-1;
		 y=ya;
		 while(y != yb){
			 putpixel(xa,y,8);
			 y+=incy;
		 }
		 return;
	}
	if(dy > dx){
	temp=dx;
	 dx=dy;
	 dy=temp;
	 exchange=1;
	}
	i=1;
	x=xa;
	y=ya;
	while(i <= dx){
		putpixel(x,y,8);//darkgray
		while(g >= 0){
			if(exchange == 1){
				x=x+s1;
			}else{
				y=y+s2;
			}
			g=g-2*dx;
		}
		if(exchange == 1){
			y=y+s2;
		}
		else{
			x=x+s1;
		}
		g=g+2*dy;
		i++;
	}

}

int main(){
	int gd,gm,i;
	int x1,x2,x3,x4,y2,y3,y1,y4;
	clrscr();
	gd=DETECT;
	initgraph(&gd,&gm,"..\\bgi");

	setbkcolor(WHITE);
	//Upper triangle

	x1=getmaxx()/2;
	y1=100;
	x2=getmaxx()/2-100;
	x3=getmaxx()/2+100;
	y2=180;
	y3=180;
	dda_line(x1,y1,x2,y2);
	dda_line(x2,y2,x3,y3);
	dda_line(x1,y1,x3,y3);
	//flag
	bresen_line(x1,y1,x1,40);
	bresen_line(x1,40,x1+30,40);
       bresen_line(x1,70,x1+30,70);
	//slanted line of flag
	bresen_line(x1+10,55,x1+30,70);
	bresen_line(x1+30,40,x1+10,55);
	//flag ends...
	//Horizontal Lines
	dda_line(x2,y2+200,getmaxx()/2-40,y2+200);
	dda_line(getmaxx()/2+40,y2+200,x3,y2+200);
	 //vertical lines
	dda_line(x2,y2,x2,y2+200);
	dda_line(x3,y3,x3,y2+200);

	dda_line(getmaxx()/2-40,y2+200,getmaxx()/2-40,y2+100);
	dda_line(getmaxx()/2+40,y2+200,getmaxx()/2+40,y2+100);
	//horizontal on door
	dda_line(getmaxx()/2-40,y2+100,getmaxx()/2+40,y2+100);
	getch();
	closegraph();
return 0;
}