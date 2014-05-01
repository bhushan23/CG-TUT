#include <stdio.h>
#include <graphics.h>

int scan_fill(int p[100][2],int n){
int i,k,ymax,ymin,dx,dy,cnt,y,temp,inX[100];
float m[100];
ymax=-1;
ymin=999;
	for(i=0;i<n;i++){//calculates ymin ymax and slope of each edge
	 if(p[i][1] > ymax) ymax=p[i][1];
	 if(p[i][1] < ymin) ymin=p[i][1];

	 dx=p[(i+1)%n][0] - p[i][0];
	 dy=p[(i+1)%n][1] - p[i][1];
	 if(dx==0) m[i]=0;
	 if(dy==0) m[i]=1;

	 if(dx!=0 && dy !=0){
	  m[i]=(float) dx/dy;
	 }
	}
	 for(y=ymax;y>=ymin;y--){//starts filling polygon from ymax to ymin
		cnt=0;
		for(i=0;i<n;i++){
			if((p[i][1] > y && p[i+1][1] <=y) || (p[i][1] <=y && p[i+1][1] >y)){
				inX[cnt]=p[i][0]+(m[i]*(y-p[i][1]));
				cnt++;
			}
		}
		for(k=0;k<cnt;k++){
			for(i=0;i<cnt-1;i++){
				if(inX[i] > inX[i+1]){
					temp=inX[i];
					inX[i]=inX[i+1];
					inX[i+1]=temp;
				}
			}
		}
		for(i=0;i<cnt-1;i+=2){
		 line(inX[i],y,inX[i+1]+1,y);
		 delay(5);
		}
	 }
	
return 0;
}
int main(){
int gd,gm,i,pt[100][2];
int n;
gd=DETECT;
initgraph(&gd,&gm,NULL);
setbkcolor(WHITE);
setcolor(BLUE);
n=5;

pt[0][0]=30;
pt[0][1]=30;

pt[1][0]=30;
pt[1][1]=300;

pt[2][0]=400;
pt[2][1]=300;

pt[3][0]=400;
pt[3][1]=30;

pt[4][0]=215;
pt[4][1]=215;

scan_fill(pt,n);
getchar();
closegraph();

}
