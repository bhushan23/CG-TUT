	
	/*BHUSHAN SONAWANE*/
	/*TE E 66 CG TUT 4 COHEN-SUTHERLAND LINE CLIPPING ALGORITHM */

	#include <stdio.h>
	#include <graphics.h>
	#include "line.h"
	typedef unsigned int outcode;
	enum { TOP=0x1, BOTTOM=0x2, RIGHT=0x4, LEFT=0x8 };
	int calcode (float x,float y,float xwmin,float ywmin,float xwmax,float ywmax){
	//calculates code as per the position of two points
	int code =0;
	if(y> ywmax)
		code |=BOTTOM;
	else if( y<ywmin)
		code |= TOP;
	else if(x > xwmax)
		code |= RIGHT;
	else if ( x< xwmin)
		code |= LEFT;
	return(code);
	}

	int lineclip(float x0,float y0,float x1,float y1,float xwmin,float ywmin,float xwmax,float ywmax ){
	int gd,gm;
	outcode code0,code1,codeout;
	int accept = 0, done=0;

	code0 = calcode(x0,y0,xwmin,ywmin,xwmax,ywmax);//calculate 1st point code
	code1 = calcode(x1,y1,xwmin,ywmin,xwmax,ywmax);//calculate 2nd point code
	do{
		if(!(code0 | code1)){ 
			accept =1 ; done =1; //both points are in window
		 }else if(code0 & code1)
			 done = 1;	//line does not passes through clipping windows
		else{
			float x,y;
			codeout = code0 ? code0 : code1; //assign code which is not zero
			if(codeout & BOTTOM){
			x = x0 + (x1-x0)*(ywmax-y0)/(y1-y0);
			y = ywmax;
			}
			else if( codeout & TOP){
			x = x0 + (x1-x0)*(ywmin-y0)/(y1-y0);
			y = ywmin;
			}
			else if ( codeout & RIGHT){
			y = y0+(y1-y0)*(xwmax-x0)/(x1-x0);
			x = xwmax;
			}
			else{
			y = y0 + (y1-y0)*(xwmin-x0)/(x1-x0);
			x = xwmin;
			}
			if( codeout == code0){
			x0 = x; y0 = y;
			code0=calcode(x0,y0,xwmin,ywmin,xwmax,ywmax);
			}
			else{
			x1 = x; y1 = y;
			code1 = calcode(x1,y1,xwmin,ywmin,xwmax,ywmax);
			}
		}
	} while( done == 0);
	if(accept) bresen_line(x0,y0,x1,y1,RED);//draw clipped line with RED color
	return 0;
	}
	int main()
	{
	float x2,y2,x1,y1,xwmin,ywmin,xwmax,ywmax;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	setbkcolor(WHITE);
	x1=y1=x2=y2=0;
	int i;
		
		setcolor(8);
		xwmin=100;ywmin=100;
		ywmax=250;xwmax=250;
		rectangle(xwmin,ywmin,xwmax,ywmax);
		for(i=1;i<6;i++){
			x1+=10;y1=10;
			x2+=100;y2=300;
			bresen_line(x1,y1,x2,y2,8);   //draw plane line without clipping with dark gray color
			getchar();
			lineclip(x1,y1,x2,y2,xwmin,ywmin,xwmax,ywmax );
			}
	getchar();
	closegraph();
	return 0;
	}
