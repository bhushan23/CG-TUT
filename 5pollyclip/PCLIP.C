		//Bhushan Sonawane
		//CG TUT 5 SUTHERLAND-HODGEMAN POLYGON CLIPPING
		#include <stdio.h>
		#include <conio.h>
		#include <graphics.h>
		int k;
		float xmin,ymin,xmax,ymax,arr[20],m;

		void clipl(float x1,float y1,float x2,float y2)
		{
			if(x2!=x1)
			{	m=(y2-y1)/(x2-x1);

			if(x1>=xmin && x2>=xmin)
			{
				arr[k]=x2;
				arr[k+1]=y2;
				k+=2;
			}
			if(x1<xmin && x2>=xmin)
			{
				arr[k]=xmin;
				arr[k+1]=y1+m*(xmin-x1);
				arr[k+2]=x2;
				arr[k+3]=y2;
				k+=4;
			}
			if(x1>=xmin  && x2<xmin)
			{
				arr[k]=xmin;
				arr[k+1]=y1+m*(xmin-x1);
				k+=2;
			}
			}else{

			if(x1>=xmin && x2>=xmin)
			{
				arr[k]=x2;
				arr[k+1]=y2;
				k+=2;
			}

			}
		}

		void clipb(float x1,float y1,float x2,float y2)
		{
			if(y2-y1)
			{	m=(x2-x1)/(y2-y1);
			if(y1<=ymax && y2<=ymax)
			{
				arr[k]=x2;
				arr[k+1]=y2;
				k+=2;
			}
			if(y1>ymax && y2<=ymax)
			{
				arr[k]=x1+m*(ymax-y1);
				arr[k+1]=ymax;
				arr[k+2]=x2;
				arr[k+3]=y2;
				k+=4;
			}
			if(y1<=ymax  && y2>ymax)
			{
				arr[k]=x1+m*(ymax-y1);
				arr[k+1]=ymax;
				k+=2;
			}
			}else{
				if(y1<=ymax && y2<=ymax)
			{
				arr[k]=x2;
				arr[k+1]=y2;
				k+=2;
			}


			}
		}

		void clipr(float x1,float y1,float x2,float y2)
		{
			if(x2-x1)
			{	m=(y2-y1)/(x2-x1);
			if(x1<=xmax && x2<=xmax)
			{
				arr[k]=x2;
				arr[k+1]=y2;
				k+=2;
			}
			if(x1>xmax && x2<=xmax)
			{
				arr[k]=xmax;
				arr[k+1]=y1+m*(xmax-x1);
				arr[k+2]=x2;
				arr[k+3]=y2;
				k+=4;
			}
			if(x1<=xmax  && x2>xmax)
			{
				arr[k]=xmax;
				arr[k+1]=y1+m*(xmax-x1);
				k+=2;
			}
			}else{
				if(x1<=xmax && x2<=xmax)
			{
				arr[k]=x2;
				arr[k+1]=y2;
				k+=2;
			}


			}
		}

		void clipt(float x1,float y1,float x2,float y2)
		{
			if(y2-y1)
			{
			   m=(x2-x1)/(y2-y1);
			if(y1>=ymin && y2>=ymin)
			{
				arr[k]=x2;
				arr[k+1]=y2;
				k+=2;
			}
			if(y1<ymin && y2>=ymin)
			{
				arr[k]=x1+m*(ymin-y1);
				arr[k+1]=ymin;
				arr[k+2]=x2;
				arr[k+3]=y2;
				k+=4;
			}
			if(y1>=ymin  && y2<ymin)
			{
				arr[k]=x1+m*(ymin-y1);
				arr[k+1]=ymin;
				k+=2;
			}}
			else{
				if(y1>=ymin && y2>=ymin)
			{
				arr[k]=x2;
				arr[k+1]=y2;
				k+=2;
			}

			}
		}

		void main()
		{
			int gd=DETECT,gm,n,poly[20],i;
			clrscr();
			xmin=100;
			ymin=100;
			xmax=300;
			ymax=300;
			n=4;
			 poly[0]=50;poly[1]=200;
		       poly[2]=200;poly[3]=50;
		       poly[4]=350;poly[5]=200;
		       poly[6]=200;poly[7]=350;
		       poly[8]=50;poly[9]=200;
			initgraph(&gd,&gm,"..\\BGI");
			setcolor(RED);
			rectangle(xmin,ymax,xmax,ymin);
			setcolor(WHITE);
			fillpoly(n,poly);
			getch();
			k=0;
			for(i=0;i<2*n;i+=2)
				clipl(poly[i],poly[i+1],poly[i+2],poly[i+3]);
			n=k/2;
			for(i=0;i<k;i++)
				poly[i]=arr[i];
			poly[i]=poly[0];
			poly[i+1]=poly[1];
			k=0;
			for(i=0;i<2*n;i+=2)
				clipt(poly[i],poly[i+1],poly[i+2],poly[i+3]);
			n=k/2;
			for(i=0;i<k;i++)
				poly[i]=arr[i];
			poly[i]=poly[0];
			poly[i+1]=poly[1];
			k=0;
			for(i=0;i<2*n;i+=2)
				clipr(poly[i],poly[i+1],poly[i+2],poly[i+3]);
			n=k/2;
			for(i=0;i<k;i++)
				poly[i]=arr[i];
			poly[i]=poly[0];
			poly[i+1]=poly[1];
			k=0;
			for(i=0;i<2*n;i+=2)
				clipb(poly[i],poly[i+1],poly[i+2],poly[i+3]);
			for(i=0;i<k;i++)
				poly[i]=arr[i];
			if(k){
				setfillstyle(LINE_FILL,WHITE);
				fillpoly(k/2,poly);
				}
			setcolor(RED);
			rectangle(xmin,ymax,xmax,ymin);
			getch();
			closegraph();
		}
