#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include <ctype.h>

int gmode = DETECT, gdriver;
int xx, yy;
int midx, midy;

void initial()
{
	setcolor(WHITE);
	line(0, midy + 100, xx, midy + 100);

	rectangle(560,215,570,250);
	rectangle(550,325,580,250);
}

void rotateRect(int left,int top,int right,int bottom)
{
    float x1, y1, x2, y2, x3, y3, x4, y4;
    float rad = 1.5 * (3.14 / 180);

/*    line(left, bottom, right, bottom);
    line(left, bottom, left, top);
    line(right, bottom, right, top);
    line(left, top, right, top);*/

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

void batRotation()
{
	setcolor(WHITE);
	line(0, midy + 100, xx, midy + 100);
	rotateRect(560,215,570,250);
	rotateRect(550,325,580,250);
}

void throwBall()
{
	float x = 1, y = 0.00000, j = .5, count = .1;
	float r = 10;
	sleep(1);
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
	getch();
}

void wicketCode()
{
	for(int w=30;w<=530;w+=30)
	{
		initial();
		setcolor(14);
		setfillstyle(1,14);
		circle(w,300,14);
		floodfill(w, 300, 14);
		delay(100);
		cleardevice();
	}

	delay(30);
	getch();
}

void run4()
{
	int mm=5;
	for(int m=midy-50;m>=30;m-=30)
	{
		//cleardevice();
		initial();
		//delay(100);
		setcolor(WHITE);
		setfillstyle(1,14);
		circle(550-mm,m,15);
		floodfill(550-mm,m,15);
		mm+=5;
		if(m>=30 && m<=50)
		{
			continue;
		}
		else
		{
			delay(100);
			cleardevice();
		}
	}
	getch();
}

void run6()
{
	int mm=50;
	for(int m=midy-50;m>=30;m-=30)
	{
		//cleardevice();
		initial();
		//delay(100);
		setcolor(WHITE);
		setfillstyle(1,14);
		circle(550-mm,m,15);
		floodfill(550-mm,m,15);
		mm+=50;
		if(m>=30 && m<=50)
		{
			continue;
		}
		else
		{
			delay(100);
			cleardevice();
		}
	}
	getch();
}

void run1235()
{
	setcolor(WHITE);
	circle(400,350,14);
	int ty=25;
	for(int t=400;t<=200;t-=50)
	{
		//initial();
		setcolor(WHITE);
		circle(t,350-ty,14);
		ty+=25;
	}
	getch();

	/*setcolor(14);
	setfillstyle(1,14);
	circle(350,350,14);
	floodfill(350, 350, 14);

	delay(500);
	cleardevice();

	initial();
	setcolor(14);
	setfillstyle(1,14);
	circle(250,400,14);
	floodfill(250, 400, 14);

	delay(500);
	cleardevice();

	initial();
	setcolor(14);
	setfillstyle(1,14);
	circle(250,400,14);
	floodfill(250, 400, 14);*/
}

void main()
{
	clrscr();
	initgraph(&gmode, &gdriver, "C:\\TC\\BGI");

	//	rectangle(2,2,518,427); left,top,right,bottom
	xx = getmaxx();
	yy = getmaxy();
	midx = getmaxx() / 2;
	midy = getmaxy() / 2;

	int over,target;
	printf("\n Enter how many overs you want to play?:");
	scanf("%d",&over);
	printf("\n Enter your target score:");
	scanf("%d",&target);
	//printf(" %d %d %d %d", xx, yy,midx,midy);
	//setcolor(14);
	/*line(0, midy + 100, xx, midy + 100);

	rectangle(560,215,570,250);
	rectangle(550,325,580,250);
	//ball

	//ball with run 1,2,3
	cleardevice();   */


	//outtextxy(350,350,"(350,350)");
//	outtextxy(250,400,"(250,400)");
//	outtextxy(200,450,"(200,450)");*/
	clrscr();
	int score=0;

	int flag=1;
	int randNo;
	int ball=0,totalBall=6*over;
	while(flag)
	{
		initial();
		throwBall();
		randNo=rand()%7;
		printf("\nrandom : %d ball: %d",randNo,ball);
		delay(30);
		cleardevice();
		batRotation();
		switch(randNo)
		{
			case 0:
				wicketCode();
				score+=0;
				break;
			case 1:
				run1235();
				score+=1;
				break;
			case 2:
				run1235();
				score+=2;
				break;
			case 3:
				run1235();
				score+=3;
				break;
			case 4:
				run4();
				score+=4;
				break;
			case 5:
				run1235();
				score+=5;
				break;
			case 6:
				run6();
				score+=6;
				break;
		}
		ball++;
		if(randNo==0 || ball==totalBall)
		{
			flag=0;
		}
		//getch();
		cleardevice();
	}
	printf("\n Score is : %d",score);
	if(score>=target)
	{
		printf("\n Congratulations! You WON!!");
	}
	else
	{
		printf("\n OOPS! You lose..");
	}
	getch();

}