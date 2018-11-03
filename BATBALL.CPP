#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>

int gmode = DETECT, gdriver;
int xx, yy;
int midx, midy;

void rotateRect(int left,int top,int right,int bottom)
{
    float x1, y1, x2, y2, x3, y3, x4, y4;
    float rad = 1.5 * (3.14 / 180);

    line(left, bottom, right, bottom);
    line(left, bottom, left, top);
    line(right, bottom, right, top);
    line(left, top, right, top);

    x1 = left * cos(rad) - bottom * sin(rad);
    y1 = left * sin(rad) + bottom * cos(rad);
    x2 = right * cos(rad) - bottom * sin(rad);
    y2 = right * sin(rad) + bottom * cos(rad);
    x3 = left * cos(rad) - top * sin(rad);
    y3 = left * sin(rad) + top * cos(rad);
    x4 = right * cos(rad) - top * sin(rad);
    y4 = right * sin(rad) + top * cos(rad);

    line(fabs(x1), fabs(y1), fabs(x2), fabs(y2));
    line(fabs(x1), fabs(y1), fabs(x3), fabs(y3));
    line(fabs(x3), fabs(y3), fabs(x4), fabs(y4));
    line(fabs(x2), fabs(y2), fabs(x4), fabs(y4));
}

void main()
{
	clrscr();
	initgraph(&gmode, &gdriver, "C:\\TC\\BGI");
	clearviewport();
	cleardevice();

	//	rectangle(2,2,518,427); left,top,right,bottom
	xx = getmaxx();
	yy = getmaxy();
	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
	printf(" %d %d %d %d", xx, yy,midx,midy);
	//setcolor(14);
	line(0, midy + 100, xx, midy + 100);

	rectangle(560,215,570,250);
	rectangle(550,325,580,250);

	/*line(560,215,570,215);
	line(570,215,570,250);
	line(570,250,560,250);
	line(560,250,560,215);

	line(550,325,580,325);
	line(580,325,580,250);
	line(580,250,550,250);
	line(550,250,550,325);*/


	//rotate(560,215,570,215,570,250,560,215);
	//rotate
	//line(570,235,580,215);
	//line(580,215,560,250);
	//line(560,250,550,260);
	//line(550,260,570,225);

	/*line(550,325,580,325);
	line(580,325,580,250);
	line(580,250,550,250);
	line(550,250,550,325);*/

	//ball
	float x = 1, y = 0.00000, j = .5, count = .1;
	float r = 10;
	//sleep(1);
	for (int k = 0; k <= 1; k++)
	{
		for (float i = 90; i < 270; i += 10)
		{
			y = cos(((i * 22 / 7) / 180)) / j;
			if (y > 0)
				y = -y;
			x += 15;
			setcolor(14);
			setfillstyle(1, 14);
			circle(x, y * 100 + midx, r);
			floodfill(x, y * 100 +midx, 14);
			delay(100);
			setcolor(0);
			setfillstyle(1, 0);
			circle(x, y * 100 + midx, r);
			floodfill(x, y * 100 + midx, 0);
				//printf("%d %d",x,y);

		}
		j += count;
		count += .1;
	}


	//bat
	cleardevice();
	setcolor(0);
	rectangle(560,215,570,250);
	rectangle(550,325,580,250);
	delay(30);
	setcolor(WHITE);
	line(0, midy + 100, xx, midy + 100);
	rotateRect(560,215,570,250);
	rotateRect(550,325,580,250);

	setcolor(14);
	setfillstyle(1,14);
	circle(150,400,14);
	floodfill(150, 400, 14);

	/*int c,t=400;
	int pixy=0;
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	for (int z = 1; z <10 ; z++)
	{
		cleardevice();
		circle(z, pixy, 10);
		floodfill(z, pixy, RED);
		delay(100);
		if (pixy >= 400)
		{
			c = 0;
			t -= 20;
		}
		if (pixy <= (400 - t))
			c = 1;
		pixy = pixy + (c ? 15 : -15);
	} */

	getch();
}