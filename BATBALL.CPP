#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>

int gmode=DETECT,gdriver;
int xx,yy;
int midx,midy;
void main()
{
	clrscr();
	initgraph(&gmode,&gdriver,"C:\\TC\\BGI");
	clearviewport();
	cleardevice();

//	rectangle(2,2,518,427); left,top,right,bottom
	xx=getmaxx();
	yy=getmaxy();
	midx=getmaxx()/2;
	midy=getmaxy()/2;
	printf(" %d %d",xx,yy);
	//setcolor(14);
	line(0,midy+100,xx,midy+100);

	float x = 1, y = 0.00000, j = .5, count = .1;
	float r = 10;

	//line(0, 215, 650, 215);
	//sleep(1);
	for (int k = 0; k <= 7; k++)
	{
		for (float i = 90; i < 270; i += 10)
		{
			y = cos(((i * 22 / 7) / 180)) / j;
			if (y > 0)
				y = -y;
			x += 4;
			setcolor(14);
			//setfillstyle(1, 14);
			circle(x, y * 100 + midx, r);
			//floodfill(x, y * 100 + 200, 14);
			delay(100);
			setcolor(0);
			setfillstyle(1, 0);
			circle(x, y * 100 + midx, r);
			//floodfill(x, y * 100 + 200, 0);

		}
		j += count;
		count += .1;
	}

	getch();
}