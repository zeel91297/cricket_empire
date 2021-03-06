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
int score=0,ball=0;

void border()
{
	setcolor(1);
	line(0,0,0,yy);
	line(0,0,xx,0);
	line(xx,0,xx,yy);
	line(0,yy,xx,yy);

	setcolor(4);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(35,5,"Welcome to Cricket Empire");

	char *strBall,*strScore;
	setcolor(2);
	settextstyle(10,HORIZ_DIR,1);
	outtextxy(50,50,"Ball: ");
	outtextxy(150,50,itoa(ball,strBall,10));
	setcolor(13);
	outtextxy(200,50,"Run: ");
	outtextxy(300,50,itoa(score,strScore,10));
}

void initial()
{
	border();
	setcolor(WHITE);
	line(0, midy + 100, xx, midy + 100);
	rectangle(560,215,570,250);
	rectangle(550,325,580,250);
}

void rotateRect(int left,int top,int right,int bottom)
{
    float x1, y1, x2, y2, x3, y3, x4, y4;
    float rad = 1.5 * (3.14 / 180);

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
	border();
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
		}
		j += count;
		count += .1;
	}
}

void wicketCode()
{
	for(int w=30;w<=530;w+=30)
	{
		initial();
		settextstyle(10,HORIZ_DIR,3);
		outtextxy(450,50,"WICKET");
		setcolor(14);
		setfillstyle(1,14);
		circle(w,300,10);
		floodfill(w, 300, 14);
		delay(100);
		cleardevice();
	}
	getch();
}

void run4()
{
	int mm=5;
	for(int m=midy-50;m>=30;m-=30)
	{
		batRotation();
		setcolor(5);
		settextstyle(10,HORIZ_DIR,3);
		outtextxy(450,50,"FOUR");
		setcolor(WHITE);
		setfillstyle(1,14);
		circle(550-mm,m,10);
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
		batRotation();
		settextstyle(10,HORIZ_DIR,3);
		outtextxy(450,50,"SIX");
		setcolor(WHITE);
		setfillstyle(1,14);
		circle(550-mm,m,10);
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
	batRotation();
	setcolor(14);
	setfillstyle(1,14);
	circle(350,350,10);
	floodfill(350, 350, 14);

	delay(500);
	cleardevice();

	initial();
	setcolor(14);
	setfillstyle(1,14);
	circle(250,400,10);
	floodfill(250, 400, 14);

	delay(500);
	cleardevice();

	initial();
	setcolor(14);
	setfillstyle(1,14);
	circle(250,400,10);
	floodfill(250, 400, 14);
	getch();
}

void cricketGame()
{
	xx = getmaxx();
	yy = getmaxy();
	midx = getmaxx() / 2;
	midy = getmaxy() / 2;

	setcolor(4);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(35,5,"Welcome to Cricket Empire");

	int over,target;
	printf("\n\n \n \n\n\n\n");
	printf("\n Enter how many overs you want to play?:");
	scanf("%d",&over);
	printf("\n Enter your target score:");
	scanf("%d",&target);

	//ball
	cleardevice();
	int flag=1;
	int randNo;
	int totalBall=6*over;
	while(flag)
	{
		initial();
		throwBall();
		srand(time(NULL));
		randNo=rand()%7;
		cleardevice();
		switch(randNo)
		{
			case 0:
				run1235();
				score+=1;
				break;
			case 1:
				wicketCode();
				score+=0;
				flag=0;
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
		if(randNo==1 || ball==totalBall || score>=target)
		{
			flag=0;
		}
		cleardevice();
	}
	//border
	setcolor(1);
	line(0,0,0,yy);
	line(0,0,xx,0);
	line(xx,0,xx,yy);
	line(0,yy,xx,yy);

	setcolor(4);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(35,5,"Welcome to Cricket Empire");
	if(score>=target)
	{

		setcolor(2);
		settextstyle(10,HORIZ_DIR,2);
		outtextxy(35,100,"Congratulations! You WON!!");
	}
	else
	{
		setcolor(15);
		settextstyle(10,HORIZ_DIR,3);
		outtextxy(35,100,"OOPS! You lose..");
	}
	setcolor(5);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(35,150,"Score is :");

	char *cricScore;
	setcolor(5);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(220,150,itoa(score,cricScore,10));

}

void main()
{
	clrscr();
	initgraph(&gmode, &gdriver, "C:\\TC\\BGI");
	//	rectangle(2,2,518,427); left,top,right,bottom
	cricketGame();
	getch();
}