
int sign(float f){

 if(f < 0)
	return -1;
 else if (f == 0)
	return 0;
 else
	return 1;
}

void bresen_line(int xa,int ya,int xb,int yb,int color){
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
			 putpixel(xa,y,color);
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
		putpixel(x,y,color);
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
