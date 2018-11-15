/******************************************************************************
 PROJECT NAME : CRICKET EMPIRE
 201812022 : ZEEL MODI
 201812051 : PARITA DUDHANI
 201812064 : JAINAM SHAH
 201812091 : SHIVANI DESAI
 201812093 : MOHIT SHAH
 *******************************************************************************/
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include <ctype.h>
#include<string.h>
FILE *fp, *fp1;
static int count1 = 0, first_inning_total_run = 0, second_inning_total_run = 0,total_wicket = 0, total_over = 0, total_ball = 0;
char copy;
char *first_team_player;
char *second_team_player;
int first_team_motm, second_team_motm;
char *first_team_players_name[11] = { "Virat Kohli(c)", "Shikhar Dhawan",
		"Hardik Pandya", "Suresh Raina", "Ravindra Jadeja", "MS Dhoni   ",
		"Kedar Jadhav", "K Khaleel Ahmed", "Bhuvneshwar Kumar",
		"Jasprit Bumrah", "Yuzvendra Chahal" };
char *team1_batsmen[8] = { "Virat Kohli(c)", "Shikhar Dhawan", "Hardik Pandya",
		"Suresh Raina", "Ravindra Jadeja", "MS Dhoni   ", "Kedar Jadhav",
		"K Khaleel Ahmed" };
char *team1_bowler[3] = { "Bhuvneshwar Kumar", "Jasprit Bumrah",
		"Yuzvendra Chahal" };

char *second_team_players_name[11] = { "Azhaar Ali(c)", "Beelaal Asif",
		"Faakhar Zamaan", "Armaam Haaq  ", "Baabar Aazam  ", "Aala Hafeez",
		"Fahem Ashraf", "Hasan Ali  ", "Mohammad Abbas", "Sarfraz Ahmed",
		"Haris Sohail" };

char *team2_batsmen[8] = { "Azhaar Ali(c)", "Beelaal Asif", "Faakhar Zamaan",
		"Armaam Haaq", "Baabar Aazam", "Aala Hafeez", "Fahem Ashraf",
		"Hasan Ali" };

char *team2_bowler[3] = { "Mohammad Abbas", "Sarfraz Ahmed", "Haris Sohail" };

char *third_team_players_name[11] = { "Tim Paine(c)", "Aaron Finch",
		"Ashton Agar", "Aleaxn Carey", "Travis Head", "Nathan Lyon",
		"Glenn Maxwell", "Shaun Marsh", "Jhye Richardson", "Kane Richardson",
		"Andrew Tye" };

char *team3_batsmen[8] = { "Tim Paine(c)", "Aaron Finch", "Ashton Agar",
		"Aleaxn Carey", "Travis Head", "Nathan Lyon", "Glenn Maxwell",
		"Shaun Marsh" };
char *team3_bowler[3] = { "Jhye Richardson", "Kane Richardson", "Andrew Tye" };
int tmp_first_team_select_option_no;
int my_team_no, opposite_team_no; // 1 for INDIA  ,   2 for PAKISTAN  ,   3 for SOUTH AFRICA
char *batting_team_name, *bowling_team_name;
void home_page();
void play_game();
void first_number_team();
void second_number_team();
void third_number_team();
void toss(int, int, int);
void batting(int, int);
void opp_batting(int, int);
void call_batting(char *, int, int, int);
void call_opp_batting(char *, int, int, int);
void remaining_batting(int,int,int);
int gmode = DETECT, gdriver;
int xx, yy;
int midx, midy;
int score = 0, ball = 0;
void border() {
	setcolor(1);
	line(0, 0, 0, yy);
	line(0, 0, xx, 0);
	line(xx, 0, xx, yy);
	line(0, yy, xx, yy);

	setcolor(4);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy(35, 5, "Welcome to Cricket Empire");

	char *strBall, *strScore;
	setcolor(2);
	settextstyle(10, HORIZ_DIR, 1);
	outtextxy(50, 50, "Ball: ");
	outtextxy(150, 50, itoa(ball, strBall, 10));
	setcolor(13);
	outtextxy(200, 50, "Run: ");
	outtextxy(300, 50, itoa(score, strScore, 10));
}
void initial() {
	border();
	setcolor(WHITE);
	line(0, midy + 100, xx, midy + 100);
	rectangle(560, 215, 570, 250);
	rectangle(550, 325, 580, 250);
}
void rotateRect(int left, int top, int right, int bottom) {
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
void batRotation() {
	border();
	setcolor(WHITE);
	line(0, midy + 100, xx, midy + 100);
	rotateRect(560, 215, 570, 250);
	rotateRect(550, 325, 580, 250);
}
void throwBall() {
	float x = 1, y = 0.00000, j = .5, count = .1;
	float r = 10;
	sleep(1);
	for (int k = 0; k <= 1; k++) {
		for (float i = 90; i < 270; i += 10) {
			y = cos(((i * 22 / 7) / 180)) / j;
			if (y > 0)
				y = -y;
			x += 15;
			setcolor(14);
			setfillstyle(1, 14);
			circle(x, y * 100 + midx, r);
			floodfill(x, y * 100 + midx, 14);
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
void wicketCode() {
	for (int w = 30; w <= 530; w += 30) {
		initial();
		settextstyle(10, HORIZ_DIR, 3);
		outtextxy(450, 50, "WICKET");
		setcolor(14);
		setfillstyle(1, 14);
		circle(w, 300, 10);
		floodfill(w, 300, 14);
		delay(100);
		cleardevice();
	}
	getch();
}
void run4() {
	int mm = 5;
	for (int m = midy - 50; m >= 30; m -= 30) {
		batRotation();
		setcolor(5);
		settextstyle(10, HORIZ_DIR, 3);
		outtextxy(450, 50, "FOUR");
		setcolor(WHITE);
		setfillstyle(1, 14);
		circle(550 - mm, m, 10);
		floodfill(550 - mm, m, 15);
		mm += 5;
		if (m >= 30 && m <= 50) {
			continue;
		} else {
			delay(100);
			cleardevice();
		}
	}
	getch();
}
void run6() {
	int mm = 50;
	for (int m = midy - 50; m >= 30; m -= 30) {
		batRotation();
		settextstyle(10, HORIZ_DIR, 3);
		outtextxy(450, 50, "SIX");
		setcolor(WHITE);
		setfillstyle(1, 14);
		circle(550 - mm, m, 10);
		floodfill(550 - mm, m, 15);
		mm += 50;
		if (m >= 30 && m <= 50) {
			continue;
		} else {
			delay(100);
			cleardevice();
		}
	}
	getch();
}
void run1235() {
	batRotation();
	setcolor(14);
	setfillstyle(1, 14);
	circle(350, 350, 10);
	floodfill(350, 350, 14);

	delay(500);
	cleardevice();

	initial();
	setcolor(14);
	setfillstyle(1, 14);
	circle(250, 400, 10);
	floodfill(250, 400, 14);

	delay(500);
	cleardevice();

	initial();
	setcolor(14);
	setfillstyle(1, 14);
	circle(250, 400, 10);
	floodfill(250, 400, 14);
	getch();
}

void cricketGame() {
	xx = getmaxx();
	yy = getmaxy();
	midx = getmaxx() / 2;
	midy = getmaxy() / 2;

	setcolor(4);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy(35, 5, "Welcome to Cricket Empire");

	int over, target;
	printf("\n\n \n \n\n\n\n");
	printf("\n Enter how many overs you want to play?:");
	scanf("%d", &over);
	printf("\n Enter your target score:");
	scanf("%d", &target);

	//ball
	cleardevice();
	int flag = 1;
	int randNo;
	int totalBall = 6 * over;
	while (flag) {
		initial();
		throwBall();
		srand(time(NULL));
		randNo = rand() % 7;
		cleardevice();
		switch (randNo) {
		case 0:
			run1235();
			score += 1;
			break;
		case 1:
			wicketCode();
			score += 0;
			flag = 0;
			break;
		case 2:
			run1235();
			score += 2;
			break;
		case 3:
			run1235();
			score += 3;
			break;
		case 4:
			run4();
			score += 4;
			break;
		case 5:
			run1235();
			score += 5;
			break;
		case 6:
			run6();
			score += 6;
			break;
		}
		ball++;
		if (randNo == 1 || ball == totalBall || score >= target) {
			flag = 0;
		}
		cleardevice();
	}
	//border
	setcolor(1);
	line(0, 0, 0, yy);
	line(0, 0, xx, 0);
	line(xx, 0, xx, yy);
	line(0, yy, xx, yy);

	setcolor(4);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy(35, 5, "Welcome to Cricket Empire");
	if (score >= target) {

		setcolor(2);
		settextstyle(10, HORIZ_DIR, 2);
		outtextxy(35, 100, "Congratulations! You WON!!");
	} else {
		setcolor(15);
		settextstyle(10, HORIZ_DIR, 3);
		outtextxy(35, 100, "OOPS! You lose..");
	}
	setcolor(5);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy(35, 150, "Score is :");

	char *cricScore;
	setcolor(5);
	settextstyle(10, HORIZ_DIR, 3);
	outtextxy(220, 150, itoa(score, cricScore, 10));

}

void call_batting(char *ptr_bat1, int runs1, int four1, int six1) {
	fp = fopen("batting.txt", "a");
	fputs("\n", fp);
	fputs(ptr_bat1, fp);
	fputs("\t\t", fp);
	fprintf(fp, "%d", runs1);
	fputs("\t", fp);
	fprintf(fp, "%d", four1);
	fputs("\t", fp);
	fprintf(fp, "%d", six1);
	fclose(fp);
}
void call_opp_batting(char *ptr_bat, int runs, int four, int six) {

	fp1 = fopen("sbatting.txt", "a");
	fputs("\n", fp1);
	fputs(ptr_bat, fp1);
	fputs("\t\t", fp1);
	fprintf(fp1, "%d", runs);
	fputs("\t", fp1);
	fprintf(fp1, "%d", four);
	fputs("\t", fp1);
	fprintf(fp1, "%d", six);
	fclose(fp1);
}
void remaining_batting(int count1,int team_no,int inning_no)
{
		FILE *fp1;
		if(inning_no==1)
			 fp1 = fopen("remaining_batting.txt", "a");
		else
			fp1 = fopen("rbatting.txt", "a");

		for (int ii = count1; ii < 11; ii++) {
			fputs("\n", fp1);
			if(team_no==1)
				fputs(first_team_players_name[ii], fp1);
			else if(team_no==2)
				fputs(second_team_players_name[ii], fp1);
			else
				fputs(third_team_players_name[ii], fp1);
			fputs("\t\t", fp1);
			fprintf(fp1, "%d", 0);
			fputs("\t", fp1);
			fprintf(fp1, "%d", 0);
			fputs("\t", fp1);
			fprintf(fp1, "%d", 0);
		}
		fclose(fp1);
}
void bowler(char *ptr_bowl1,int tot_runs11,int wkt1)
{
					fp = fopen("bowler.txt", "a");
					fputs("\n", fp);
					fputs(ptr_bowl1, fp);
					fputs("\t\t", fp);
					fprintf(fp, "%d", tot_runs11);
					fputs("\t", fp);
					fprintf(fp, "%d", wkt1);
					fclose(fp);
}
void second_bowler(char *ptr_bowl,int tot_runs,int wkt)
{
			fp1 = fopen("sbowler.txt", "a");
			fputs("\n", fp1);
			fputs(ptr_bowl, fp1);
		    fputs("\t\t", fp1);
			fprintf(fp1, "%d", tot_runs);
			fputs("\t", fp1);
			fprintf(fp1, "%d", wkt);
			fclose(fp1);
}
void tossChoice(int my_team_no, int opposite_team_no)
{
	int choice;
	printf("\n\n0. Head\n1. Tail\nEnter your choice: ");
	scanf("%d", &choice);
	getch();
	toss(my_team_no, opposite_team_no, choice);
}
void print_total_run(int total_run,int total_wicket,int inning_no){
								if(inning_no==1)
									fp = fopen("batting.txt", "a");
								else
									fp = fopen("sbatting.txt", "a");
								fputs("\n\nTOTAL SCORE : ", fp);
								fprintf(fp, "%d", total_run);
								fputs(" \\ ", fp);
								fprintf(fp, "%d", total_wicket);
								fclose(fp);
}
void cpoy_bowler_to_batting(int inning_no)
{
		FILE *source, *target;
		if(inning_no==1)
		{
			source = fopen("remaining_batting.txt", "r");
			target = fopen("batting.txt", "a");
		}
		else if(inning_no==2)
		{
			source = fopen("bowler.txt", "r");
			target = fopen("batting.txt", "a");
			fputs("\n\n \t\tBOWLER\n", target);
		}
		else if(inning_no==3)
		{
			source = fopen("rbatting.txt", "r");
			target = fopen("sbatting.txt", "a");
		}
		else if(inning_no==4)
		{
			source = fopen("sbowler.txt", "r");
			target = fopen("sbatting.txt", "a");
			fputs("\n\n \t\tBOWLER\n", target);
		}
		while ((copy = fgetc(source)) != EOF) {
				fputc(copy, target);
		}
		fclose(source);
		fclose(target);
}
void final_copy_from_sbatting_to_batting(int old_team,int new_team)
{
	FILE *source, *target;
	source = fopen("sbatting.txt", "r");
	target = fopen("batting.txt", "a");
	fputs("\n\n==================================================================\n\n",target);
	while ((copy = fgetc(source)) != EOF) {
		fputc(copy, target);
	}
	if (first_inning_total_run > second_inning_total_run) {
		if (old_team == 1) {
			fputs("\n\nTEAM INDIA WON THE MATCH", target);
			fputs("\n\nMAN OF THE MATCH : ", target);
			fputs(first_team_player, target);
			printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
			printf("\nTEAM INDIA WON THE MATCH\n\nMAN OF THE MATCH :%s",first_team_player);
			printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		} else if (old_team == 2) {
			fputs("\n\nTEAM PAKISTAN WON THE MATCH", target);
			fputs("\n\nMAN OF THE MATCH : ", target);
			fputs(first_team_player, target);
			printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
			printf("\nTEAM PAKISTAN WON THE MATCH\n\nMAN OF THE MATCH :%s",first_team_player);
			printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		} else {
			fputs("\n\nTEAM SOUTH AFRICA WON THE MATCH", target);
			fputs("\n\nMAN OF THE MATCH : ", target);
			fputs(first_team_player, target);
			printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
			printf("\nTEAM SOUTH AFRICA WON THE MATCH\n\nMAN OF THE MATCH :%s",first_team_player);
			printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		}
	} else if (second_inning_total_run > first_inning_total_run) {
		if (new_team == 1) {
			fputs("\n\nTEAM INDIA WON THE MATCH", target);
			fputs("\n\nMAN OF THE MATCH : ", target);
			fputs(second_team_player, target);
			printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
			printf("\nTEAM INDIA WON THE MATCH\n\nMAN OF THE MATCH :%s",second_team_player);
			printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		} else if (new_team == 2) {
			fputs("\n\nTEAM PAKISTAN WON THE MATCH", target);
			fputs("\n\nMAN OF THE MATCH : ", target);
			fputs(second_team_player, target);
			printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
			printf("\nTEAM PAKISTAN WON THE MATCH\n\nMAN OF THE MATCH :%s",second_team_player);
			printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		} else {
			fputs("\n\nTEAM SOUTH AFRICA WON THE MATCH", target);
			fputs("\n\nMAN OF THE MATCH : ", target);
			fputs(second_team_player, target);
			printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
			printf("\nTEAM SOUTH AFRICA WON THE MATCH\n\nMAN OF THE MATCH :%s",second_team_player);
			printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		}
	} else {
		fputs("\n\nMATCH TIE......", target);
		printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		printf("\nMATCH TIE......");
		if (first_team_motm > second_team_motm) {
			fputs("\n\nMAN OF THE MATCH : ", target);
			fputs(first_team_player, target);
			printf("\nMATCH TIE......\n\nMAN OF THE MATCH :%s", first_team_player);
		} else {
			fputs("\n\nMAN OF THE MATCH : ", target);
			fputs(second_team_player, target);
			printf("\nMATCH TIE......\n\nMAN OF THE MATCH :%s", second_team_player);
		}
		printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	}
	fclose(source);
	fclose(target);
}
void print_team_name(int team_no,int inning_no)
{
	if(inning_no==1)
		fp = fopen("batting.txt", "a");
	else
		fp = fopen("sbatting.txt", "a");
	
	if(team_no==1)
		fputs("\n\t\tINDIA\n\t\tBATTING\n", fp);
	else if(team_no==2)
		fputs("\n\t\tPAKISTAN\n\t\tBATTING\n", fp);
	else
		fputs("\n\t\tSOUTH AFRICA\n\t\tBATTING\n", fp);
	fclose(fp);
}
int main() {

clrscr();
initgraph(&gmode, &gdriver, "C:\\TurboC3\\BGI");
setcolor(4);
settextstyle(10, HORIZ_DIR, 3);
outtextxy(35, 5, "Welcome to Cricket Empire");
getch();
printf("");
//first_number_team();
cleardevice();
home_page();

return 0;
}
void home_page() {
int option;
printf("                 MENU                 \n\n");
printf("         1. PLAY THE GAME\n");
printf("         2. GENERATE SCORE CARD\n");
printf("         3. CREDITS\n");
printf("         4. EXIT\n");
printf("         SELECT AN OPTION ( 1- 4) : ");
scanf("%d", &option);
switch (option) {
case 1:
	initgraph(&gmode, &gdriver, "C:\\TurboC3\\BGI");
	//	rectangle(2,2,518,427); left,top,right,bottom
	cricketGame();
	getch();
	break;
case 2:
	play_game();
	break;
case 3:
	break;
case 4:
	exit(1);
default:
	printf("INVALID CHOICE...");
	home_page();
	break;
}
}
void play_game() {
int choose_first_team_number, choose_second_team_number;
char invalid_choice;
clrscr();
printf("\n\n\n\n              TEAM NAMES              \n\n");
printf("==================================================\n");
printf("              1. INDIA\n");
printf("              2. PAKISTAN\n");
printf("              3. SOUTH AFRICA\n");
printf("Choose Your Team ( 1-3 ) :");
scanf("%d", &choose_first_team_number);
tmp_first_team_select_option_no = choose_first_team_number;
clrscr();
int choice;
if (tmp_first_team_select_option_no == 1) {
	printf("\n\n\n\n              TEAM NAMES              \n\n");
	printf("==================================================\n");
	printf("              1. PAKISTAN\n");
	printf("              2. SOUTH AFRICA\n");
	printf("Choose Opposite Team ( 1-2 ) :");
	scanf("%d", &choose_second_team_number);
	clrscr();
	if (choose_second_team_number == 1) {
		clrscr();
		first_number_team();
		getch();
		clrscr();
		second_number_team();
		my_team_no = 1;
		opposite_team_no = 2;
		getch();
		tossChoice(my_team_no, opposite_team_no);
	} else {
		clrscr();
		first_number_team();
		getch();
		clrscr();
		third_number_team();
		my_team_no = 1;
		opposite_team_no = 3;
		getch();
		tossChoice(my_team_no, opposite_team_no);
	}
} else if (tmp_first_team_select_option_no == 2) {
	printf("\n\n\n\n              TEAM NAMES              \n\n");
	printf("==================================================\n");
	printf("              1. INDIA\n");
	printf("              2. SOUTH AFRICA\n");
	printf("Choose Opposite Team ( 1-2 ) :");
	scanf("%d", &choose_second_team_number);
	if (choose_second_team_number == 1) {
		clrscr();
		second_number_team();
		getch();
		clrscr();
		first_number_team();
		my_team_no = 2;
		opposite_team_no = 1;
		getch();
		tossChoice(my_team_no, opposite_team_no);
	} else {
		clrscr();
		second_number_team();
		getch();
		clrscr();
		third_number_team();
		my_team_no = 2;
		opposite_team_no = 3;
		getch();
		tossChoice(my_team_no, opposite_team_no);
	}
} else if (tmp_first_team_select_option_no == 3) {
	printf("\n\n\n\n              TEAM NAMES              \n\n");
	printf("==================================================\n");
	printf("              1. INDIA\n");
	printf("              2. PAKISTAN\n");
	printf("Choose Opposite Team ( 1-2 ) :");
	scanf("%d", &choose_second_team_number);
	if (choose_second_team_number == 1) {
		clrscr();
		third_number_team();
		getch();
		clrscr();
		first_number_team();
		my_team_no = 3;
		opposite_team_no = 1;
		getch();
		tossChoice(my_team_no, opposite_team_no);
	} else {
		clrscr();
		third_number_team();
		getch();
		clrscr();
		second_number_team();
		my_team_no = 3;
		opposite_team_no = 2;
		getch();
		tossChoice(my_team_no, opposite_team_no);
	}
} else {
	clrscr();
	printf("\n\n\nINVALID CHOICE\n\n\n");
	play_game();
}
}
void first_number_team() {
int print_player_index;
char *(*print_player_name)[11] = &first_team_players_name;

printf("");
printf("\n\n\t\t\tINDIA TEAM PLAYERS LIST : \n\n");
for (print_player_index = 0; print_player_index < 11; print_player_index++) {
	printf("\t\t\t%d : %s\n", print_player_index + 1,(*print_player_name)[print_player_index]);
}
}
void second_number_team() {
int print_player_index;
char *(*print_player_name)[11] = &second_team_players_name;

printf("");
printf("\n\n\t\t\tPAKISTAN TEAM PLAYERS LIST : \n\n");

for (print_player_index = 0; print_player_index < 11; print_player_index++) {
	printf("\t\t\t%d : %s\n", print_player_index + 1,(*print_player_name)[print_player_index]);
}
}
void third_number_team() {
int print_player_index;
char *(*print_player_name)[11] = &third_team_players_name;

printf("");
printf("\n\n\t\t\tSOUTH AFRICA TEAM PLAYERS LIST : \n\n");
for (print_player_index = 0; print_player_index < 11; print_player_index++) {
	printf("\t\t\t%d : %s\n", print_player_index + 1,(*print_player_name)[print_player_index]);
}
}
void toss(int my_team, int opposite_team, int choice) {
int toss_random;
int toss_option_select;
clrscr();
srand(time(NULL));
toss_random = rand() % 2;
if (toss_random == 0)
	printf("\nIt's a head\n");
else
	printf("\nIt's a tail\n");
if (toss_random == choice) // IF PART : YOUR TEAM WON THE TOSS    ,     ELSE PART : OPPOSITE TEAM WON THE TOSS
		{
	if (my_team == 1 && opposite_team == 2) {
		printf("YOU : TEAM INDIA WON THE TOSSS...\n");
		printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		scanf("%d", &toss_option_select);
		if (toss_option_select == 1) {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM INDIA\n");
			printf("Bowling : TEAM PAKISTAN\n");
			batting_team_name = "INDIA";
			bowling_team_name = "PAKISTAN";
			batting(1, 2);
			getch();
		} else {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM PAKISTAN\n");
			printf("Bowling : TEAM INDIA\n");
			batting_team_name = "PAKISTAN";
			bowling_team_name = "INDIA";
			batting(2, 1);
			getch();
		}
	} else if (my_team == 1 && opposite_team == 3) {
		printf("YOU : TEAM INDIA WON THE TOSSS...\n");
		printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		scanf("%d", &toss_option_select);
		if (toss_option_select == 1) {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM INDIA\n");
			printf("Bowling : TEAM SOUTH AFRICA\n");
			batting_team_name = "INDIA";
			bowling_team_name = "SOUTH AFRICA";
			batting(1, 3);
			getch();
		} else {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM SOUTH AFRICA\n");
			printf("Bowling : TEAM INDIA\n");
			batting_team_name = "SOUTH AFRICA";
			bowling_team_name = "INDIA";
			batting(3, 1);
			getch();
		}
	} else if (my_team == 2 && opposite_team == 1) {
		printf("YOU : TEAM PAKISTAN WON THE TOSSS...\n");
		printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		scanf("%d", &toss_option_select);
		if (toss_option_select == 1) {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM PAKISTAN\n");
			printf("Bowling : TEAM INDIA\n");
			batting_team_name = "PAKISTAN";
			bowling_team_name = "INDIA";
			batting(2, 1);
			getch();
		} else {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM INDIA\n");
			printf("Bowling : TEAM PAKISTAN\n");
			batting_team_name = "INDIA";
			bowling_team_name = "PAKISTAN";
			batting(1, 2);
			getch();
		}
	} else if (my_team == 2 && opposite_team == 3) {
		printf("YOU : TEAM PAKISTAN WON THE TOSSS...\n");
		printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		scanf("%d", &toss_option_select);
		if (toss_option_select == 1) {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM PAKISTAN\n");
			printf("Bowling : TEAM SOUTH AFRICA\n");
			batting_team_name = "PAKISTAN";
			bowling_team_name = "SOUTH AFRICA";
			batting(2, 3);
			getch();
		} else {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM SOUTH AFRICA\n");
			printf("Bowling : TEAM PAKISTAN\n");
			batting_team_name = "SOUTH AFRICA";
			bowling_team_name = "PAKISTAN";
			batting(3, 2);
			getch();
		}
	} else if (my_team == 3 && opposite_team == 1) {
		printf("YOU : TEAM SOUTH AFRICA WON THE TOSSS...\n");
		printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		scanf("%d", &toss_option_select);
		if (toss_option_select == 1) {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM SOUTH AFRICA\n");
			printf("Bowling : TEAM INDIA\n");
			batting_team_name = "SOUTH AFRICA";
			bowling_team_name = "INDIA";
			batting(3, 1);
			getch();
		} else {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM INDIA\n");
			printf("Bowling : TEAM SOUTH AFRICA\n");
			batting_team_name = "INDIA";
			bowling_team_name = "SOUTH AFRICA";
			batting(1, 3);
			getch();
		}
	} else if (my_team == 3 && opposite_team == 2) {
		printf("YOU : TEAM SOUTH AFRICA WON THE TOSSS...\n");
		printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		scanf("%d", &toss_option_select);

		if (toss_option_select == 1) {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM SOUTH AFRICA\n");
			printf("Bowling : TEAM PAKISTAN\n");
			batting_team_name = "SOUTH AFRICA";
			bowling_team_name = "PAKISTAN";
			batting(3, 2);
			getch();
		} else {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM PAKISTAN\n");
			printf("Bowling : TEAM SOUTH AFRICA\n");
			batting_team_name = "PAKISTAN";
			bowling_team_name = "SOUTH AFRICA";
			batting(2, 3);
			getch();
		}
	}
}
else {
	if (my_team == 1 && opposite_team == 2) {

		printf("OPPOSITE : TEAM PAKISTAN WON THE TOSSS...\n");
		printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		scanf("%d", &toss_option_select);

		if (toss_option_select == 1) {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM PAKISTAN\n");
			printf("Bowling : TEAM INDIA\n");
			batting_team_name = "PAKISTAN";
			bowling_team_name = "INDIA";
			batting(2, 1);
			getch();
		} else {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM INDIA\n");
			printf("Bowling : TEAM PAKISTAN\n");
			batting_team_name = "INDIA";
			bowling_team_name = "PAKISTAN";
			batting(1, 2);
			getch();
		}
	} else if (my_team == 1 && opposite_team == 3) {
		printf("OPPOSITE : TEAM SOUTH AFRICA WON THE TOSSS...\n");
		printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		scanf("%d", &toss_option_select);
		if (toss_option_select == 1) {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM SOUTH AFRICA\n");
			printf("Bowling : TEAM INDIA\n");
			batting_team_name = "SOUTH AFRICA";
			bowling_team_name = "INDIA";
			batting(3, 1);
			getch();
		} else {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM INDIA\n");
			printf("Bowling : TEAM SOUTH AFRICA\n");
			batting_team_name = "INDIA";
			bowling_team_name = "SOUTH AFRICA";
			batting(1, 3);
			getch();
		}
	} else if (my_team == 2 && opposite_team == 1) {

		printf("OPPOSITE : TEAM INDIA WON THE TOSSS...\n");
		printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		scanf("%d", &toss_option_select);
		if (toss_option_select == 1) {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM INDIA\n");
			printf("Bowling : TEAM PAKISTAN\n");
			batting_team_name = "INDIA";
			bowling_team_name = "PAKISTAN";
			batting(1, 2);
			getch();
		} else {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM PAKISTAN\n");
			printf("Bowling : TEAM INDIA\n");
			batting_team_name = "PAKISTAN";
			bowling_team_name = "INDIA";
			batting(2, 1);
			getch();
		}
	} else if (my_team == 2 && opposite_team == 3) {
		printf("OPPOSITE : TEAM SOUTH AFRICA WON THE TOSSS...\n");
		printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		scanf("%d", &toss_option_select);
		if (toss_option_select == 1) {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM SOUTH AFRICA\n");
			printf("Bowling : TEAM PAKISTAN\n");
			batting_team_name = "SOUTH AFRICA";
			bowling_team_name = "PAKISTAN";
			batting(3, 2);
			getch();
		} else {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM PAKISTAN\n");
			printf("Bowling : TEAM SOUTH AFRICA\n");
			batting_team_name = "PAKISTAN";
			bowling_team_name = "SOUTH AFRICA";
			batting(2, 3);
			getch();
		}
	} else if (my_team == 3 && opposite_team == 1) {
		printf("OPPOSITE : TEAM INDIA WON THE TOSSS...\n");
		printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		scanf("%d", &toss_option_select);
		if (toss_option_select == 1) {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM INDIA\n");
			printf("Bowling : TEAM SOUTH AFRICA\n");
			batting_team_name = "INDIA";
			bowling_team_name = "SOUTH AFRICA";
			batting(1, 3);
			getch();
		} else {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM SOUTH AFRICA\n");
			printf("Bowling : TEAM INDIA\n");
			batting_team_name = "SOUTH AFRICA";
			bowling_team_name = "INDIA";
			batting(3, 1);
			getch();
		}
	} else if (my_team == 3 && opposite_team == 2) {
		printf("OPPOSITE : TEAM PAKISTAN WON THE TOSSS...\n");
		printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		scanf("%d", &toss_option_select);
		if (toss_option_select == 1) {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM PAKISTAN\n");
			printf("Bowling : TEAM SOUTH AFRICA\n");
			batting_team_name = "PAKISTAN";
			bowling_team_name = "SOUTH AFRICA";
			batting(2, 3);
			getch();
		} else {
			printf("\n\nTOSS RESULT\n");
			printf("Batting : TEAM SOUTH AFRICA\n");
			printf("Bowling : TEAM PAKISTAN\n");
			batting_team_name = "SOUTH AFRICA";
			bowling_team_name = "PAKISTAN";
			batting(3, 2);
			getch();
		}
	}
}
}

char *ptr_bat1[2], *ptr_bowl1;
int over1[3][6], runs1[2] = { 0, 0 }, wkt1 = 0;
static four1[2] = { 0, 0 }, six1[2] = { 0, 0 };
int temp_runs11;
static int temp_stk1 = 2;
static int temp_bowl1 = 0;
int strike1 = 0, non_Strike1 = 1, tot_runs11[3] = { 0, 0, 0 };
static int tot_wkts11 = 0;

void instructions() {
clrscr();
printf("\n1. For 1 run");
printf("\n2. For 2 runs");
printf("\n3. For 3 runs");
printf("\n4. For 4 runs");
printf("\n6. For 6 runs");
printf("\n-1. For out");
getch();
clrscr();
printf("Name\t\t\t\t\t\truns\t4's\t6's\n(S): ");

}
void battingInd_cal(int i) {
runs1[strike1] += temp_runs11;
tot_runs11[i] += temp_runs11;
printf("Name\t\t\t\t\t\truns1\t4's\t6's\n(S): ");
printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat1[strike1], runs1[strike1],four1[strike1], six1[strike1]);
printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat1[non_Strike1], runs1[non_Strike1],four1[non_Strike1], six1[non_Strike1]);
printf("Bowler details:\n");
printf("Name\t\t\t\t\t\truns1\twickets\n");
printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i], wkt1);
}

void battingSA_cal(int i) {
runs1[strike1] += temp_runs11;
tot_runs11[i] += temp_runs11;
printf("Name\t\t\t\t\t\truns1\t4's\t6's\n(S): ");
printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat1[strike1], runs1[strike1],four1[strike1], six1[strike1]);
printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat1[non_Strike1], runs1[non_Strike1],four1[non_Strike1], six1[non_Strike1]);
if (!strcmp(ptr_bowl1, "Jasprit Bumrah")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns1\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i], wkt1);
} else if (!strcmp(ptr_bowl1, "Mohammad Abbas")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns1\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i], wkt1);
} else if (!strcmp(ptr_bowl1, "Sarfraz Ahmed")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns1\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i], wkt1);
} else if (!strcmp(ptr_bowl1, "Haris Sohail")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns1\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i], wkt1);
} else {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns1\twicket\n");
	printf("%s\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i], wkt1);
}
}
void battingPak_cal(int i) {
runs1[strike1] += temp_runs11;
tot_runs11[i] += temp_runs11;
printf("Name\t\t\t\t\t\truns1\t4's\t6's\n(S): ");
printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat1[strike1], runs1[strike1],four1[strike1], six1[strike1]);
printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat1[non_Strike1], runs1[non_Strike1],four1[non_Strike1], six1[non_Strike1]);
if (!strcmp(ptr_bowl1, "Jasprit Bumrah")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns1\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i], wkt1);
} else if (!strcmp(ptr_bowl1, "Jhye Richardson")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns1\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i], wkt1);
} else if (!strcmp(ptr_bowl1, "Kane Richardson")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns1\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i], wkt1);
} else if (!strcmp(ptr_bowl1, "Andrew Tye")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns1\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i], wkt1);
} else {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns1\twicket\n");
	printf("%s\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i], wkt1);
}
}
void batting(int batting_team, int bowling_team) {
instructions();
print_team_name(batting_team,1);
if (batting_team == 1) {
	ptr_bat1[strike1] = team1_batsmen[0];
	ptr_bat1[non_Strike1] = team1_batsmen[1];
	printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat1[strike1], runs1[strike1],four1[strike1], six1[non_Strike1]);
	printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat1[non_Strike1],runs1[non_Strike1], four1[strike1], six1[non_Strike1]);
	printf("Keep entering runs1 for 3 over1s: \n");
	for (int i = 0; i < 3; i++) {
		tot_runs11[i] = 0;
		tot_wkts11 += wkt1;
		wkt1 = 0;
		if (bowling_team == 2) {
			ptr_bowl1 = team2_bowler[i];
		} else if (bowling_team == 3) {
			ptr_bowl1 = team3_bowler[i];
		}
		for (int j = 0; j < 6; j++) {
			if ((j + 1) == 6) {
				total_ball = 0;
			} else {
				total_ball = j + 1;
			}
			if (tot_wkts11 == 10) {
				printf("\n-----Batting over1-----\n");
				getch();
				opp_batting(batting_team, bowling_team);
			}
			scanf("%d", &temp_runs11);
			if (temp_runs11 == 0 || temp_runs11 == 1 || temp_runs11 == 2|| temp_runs11 == 3 || temp_runs11 == 4|| temp_runs11 == 6) {
				first_inning_total_run += temp_runs11;
			}
			if (temp_runs11 == 1 || temp_runs11 == 3) {
				clrscr();
				battingInd_cal(i);
				if (strike1 == 0) {
					strike1 = 1;
					non_Strike1 = 0;
				} else {
					strike1 = 0;
					non_Strike1 = 1;
				}
			} else if (temp_runs11 == 4) {
				clrscr();
				four1[strike1]++;
				battingInd_cal(i);
			} else if (temp_runs11 == 6) {
				clrscr();
				six1[strike1]++;
				battingInd_cal(i);
			}
			else if (temp_runs11 == 2) {
				clrscr();
				battingInd_cal(i);
			} else if (temp_runs11 == -1) {
				clrscr();
				if (runs1[strike1] > first_team_motm) {
					first_team_motm = runs1[strike1];
					first_team_player = ptr_bat1[strike1];
				}
				total_wicket++;
				count1++;
				call_batting(ptr_bat1[strike1], runs1[strike1], four1[strike1],six1[strike1]);
				wkt1++;
				printf("Name\t\t\t\t\t\truns1\t4's\t6's\n(S): ");
				printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat1[strike1],runs1[strike1], four1[strike1], six1[strike1]);
				printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat1[non_Strike1],runs1[non_Strike1], four1[non_Strike1],six1[non_Strike1]);
				printf("Bowler details: \n");
				printf("Name\t\t\t\t\t\truns1\twicket\n");
				printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i], wkt1);
				runs1[strike1] = four1[strike1] = six1[strike1] = 0;
				if (temp_stk1 <= 7) {
					ptr_bat1[strike1] = team1_batsmen[temp_stk1];
				} else {
					ptr_bat1[strike1] = team1_bowler[temp_bowl1];
					temp_bowl1++;
				}
				printf("New player is: %s\n", ptr_bat1[strike1]);
				printf("Other player is: %s\n", ptr_bat1[non_Strike1]);
				runs1[strike1] = 0;
				four1[strike1] = 0;
				six1[strike1] = 0;
				temp_stk1++;
				if (count1 == 10) {
					call_batting(ptr_bat1[non_Strike1], runs1[non_Strike1],four1[non_Strike1], six1[non_Strike1]);

					if (runs1[strike1] > first_team_motm) {
						first_team_motm = runs1[strike1];
						first_team_player = ptr_bat1[strike1];
					}
					cpoy_bowler_to_batting(2);

					getch();
					clrscr();
					printf("\n++++++++++++++++++++++++++");
					printf("\n\nTotal Score=%d / %d", first_inning_total_run,total_wicket);
					printf("\n\n++++++++++++++++++++++++++");
					getch();
					print_total_run(first_inning_total_run,total_wicket,1);
					opp_batting(batting_team, bowling_team);
					getch();
				}

			} else if (temp_runs11 == 0) {
				clrscr();
				battingInd_cal(i);
			} else
				printf("Enter valid runs1\n");
		}
		bowler(ptr_bowl1,tot_runs11[i], wkt1);

		wkt1 = 0;
	}
	count1++;
	call_batting(ptr_bat1[strike1], runs1[strike1], four1[strike1],six1[strike1]);

	if (runs1[strike1] > first_team_motm) {
		first_team_motm = runs1[strike1];
		first_team_player = ptr_bat1[strike1];
	}
	count1++;
	call_batting(ptr_bat1[non_Strike1], runs1[non_Strike1], four1[non_Strike1],six1[non_Strike1]);

	if (runs1[non_Strike1] > first_team_motm) {
		first_team_motm = runs1[non_Strike1];
		first_team_player = ptr_bat1[non_Strike1];
	}
	remaining_batting(count1,1,1);
	cpoy_bowler_to_batting(1);
	cpoy_bowler_to_batting(2);
	getch();
	clrscr();
	printf("\n++++++++++++++++++++++++++");
	printf("\n\nTotal Score=%d / %d", first_inning_total_run, total_wicket);
	printf("\n\n++++++++++++++++++++++++++");
	getch();
	print_total_run(first_inning_total_run,total_wicket,1);
} else if (batting_team == 2) {
	ptr_bat1[strike1] = team2_batsmen[0];
	ptr_bat1[non_Strike1] = team2_batsmen[1];
	printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat1[strike1], runs1[strike1],four1[strike1], six1[non_Strike1]);
	printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat1[non_Strike1],runs1[non_Strike1], four1[strike1], six1[non_Strike1]);
	printf("Keep entering runs1 for 3 over1s: \n");

	for (int i = 0; i < 3; i++) {
		tot_wkts11 += wkt1;
		wkt1 = 0;
		if (bowling_team == 1) {
			ptr_bowl1 = team1_bowler[i];
		} else if (bowling_team == 3) {
			ptr_bowl1 = team3_bowler[i];
		}
		for (int j = 0; j < 6; j++) {
			if ((j + 1) == 6) {
				total_ball = 0;
			} else {
				total_ball = j + 1;
			}

			if (tot_wkts11 == 10) {
				printf("\n-----Batting over1-----\n");
				getch();
				opp_batting(batting_team, bowling_team);
			}
			scanf("%d", &temp_runs11);
			if (temp_runs11 == 0 || temp_runs11 == 1 || temp_runs11 == 2|| temp_runs11 == 3 || temp_runs11 == 4|| temp_runs11 == 6) {
				first_inning_total_run += temp_runs11;
			}
			if (temp_runs11 == 1 || temp_runs11 == 3) {
				clrscr();
				battingPak_cal(i);
				if (strike1 == 0) {
					strike1 = 1;
					non_Strike1 = 0;
				} else {
					strike1 = 0;
					non_Strike1 = 1;
				}
			} else if (temp_runs11 == 4) {
				clrscr();
				four1[strike1]++;
				battingPak_cal(i);
			} else if (temp_runs11 == 6) {
				clrscr();
				six1[strike1]++;
				battingPak_cal(i);
			}
			else if (temp_runs11 == 2) {
				clrscr();
				battingPak_cal(i);
			} else if (temp_runs11 == -1) {
				clrscr();
				if (runs1[strike1] > first_team_motm) {
					first_team_motm = runs1[strike1];
					first_team_player = ptr_bat1[strike1];
				}
				total_wicket++;
				count1++;
				call_batting(ptr_bat1[strike1], runs1[strike1], four1[strike1],	six1[strike1]);
				wkt1++;
				printf("Name\t\t\t\t\t\truns1\t4's\t6's\n(S): ");
				printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat1[strike1],runs1[strike1], four1[strike1], six1[strike1]);
				printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat1[non_Strike1],runs1[non_Strike1], four1[non_Strike1],six1[non_Strike1]);
				if (!strcmp(ptr_bowl1, "Jasprit Bumrah")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns1\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i],wkt1);
				} else if (!strcmp(ptr_bowl1, "Jhye Richardson")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns1\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i],wkt1);
				} else if (!strcmp(ptr_bowl1, "Kane Richardson")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns1\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i],wkt1);
				} else if (!strcmp(ptr_bowl1, "Andrew Tye")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns1\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i],wkt1);
				} else {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns1\twicket\n");
					printf("%s\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i],wkt1);
				}
				runs1[strike1] = four1[strike1] = six1[strike1] = 0;

				if (temp_stk1 <= 7) {
					ptr_bat1[strike1] = team2_batsmen[temp_stk1];
				} else {
					ptr_bat1[strike1] = team2_bowler[temp_bowl1];
					temp_bowl1++;
				}
				printf("New player is: %s\n", ptr_bat1[strike1]);
				printf("Other player is: %s\n", ptr_bat1[non_Strike1]);
				runs1[strike1] = 0;
				four1[strike1] = 0;
				six1[strike1] = 0;
				temp_stk1++;
				if (count1 == 10) {
					call_batting(ptr_bat1[non_Strike1], runs1[non_Strike1],four1[non_Strike1], six1[non_Strike1]);
					if (runs1[strike1] > first_team_motm) {
						first_team_motm = runs1[strike1];
						first_team_player = ptr_bat1[strike1];
					}
					cpoy_bowler_to_batting(2);
					getch();
					clrscr();
					printf("\n++++++++++++++++++++++++++");
					printf("\n\nTotal Score=%d / %d", first_inning_total_run,total_wicket);
					printf("\n\n++++++++++++++++++++++++++");
					getch();
					print_total_run(first_inning_total_run,total_wicket,1);
					opp_batting(batting_team, bowling_team);
					getch();
				}
			} else if (temp_runs11 == 0) {
				clrscr();
				battingPak_cal(i);
			} else
				printf("Enter valid runs1\n");
		}
		bowler(ptr_bowl1,tot_runs11[i], wkt1);
		wkt1 = 0;
	}
	count1++;
	call_batting(ptr_bat1[strike1], runs1[strike1], four1[strike1],six1[strike1]);
	if (runs1[strike1] > first_team_motm) {
		first_team_motm = runs1[strike1];
		first_team_player = ptr_bat1[strike1];
	}
	count1++;
	call_batting(ptr_bat1[non_Strike1], runs1[non_Strike1], four1[non_Strike1],six1[non_Strike1]);
	if (runs1[non_Strike1] > first_team_motm) {

		first_team_motm = runs1[non_Strike1];
		first_team_player = ptr_bat1[non_Strike1];
	}
	remaining_batting(count1,2,1);
	cpoy_bowler_to_batting(1);
	cpoy_bowler_to_batting(2);
	getch();
	clrscr();
	printf("\n++++++++++++++++++++++++++");
	printf("\n\nTotal Score=%d / %d", first_inning_total_run, total_wicket);
	printf("\n\n++++++++++++++++++++++++++");
	getch();
	print_total_run(first_inning_total_run,total_wicket,1);
} else {
	ptr_bat1[strike1] = team3_batsmen[0];
	ptr_bat1[non_Strike1] = team3_batsmen[1];
	printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat1[strike1], runs1[strike1],four1[strike1], six1[non_Strike1]);
	printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat1[non_Strike1],	runs1[non_Strike1], four1[strike1], six1[non_Strike1]);
	printf("Keep entering runs1 for 3 over1s: \n");

	for (int i = 0; i < 3; i++) {
		tot_wkts11 += wkt1;
		wkt1 = 0;
		if (bowling_team == 1) {
			ptr_bowl1 = team1_bowler[i];
		} else if (bowling_team == 2) {
			ptr_bowl1 = team2_bowler[i];
		}
		for (int j = 0; j < 6; j++) {

			if ((j + 1) == 6) {
				total_ball = 0;
			} else {
				total_ball = j + 1;
			}
			if (tot_wkts11 == 10) {
				printf("\n-----Batting over1-----\n");
				getch();
				opp_batting(batting_team, bowling_team);

			}
			scanf("%d", &temp_runs11);
			if (temp_runs11 == 0 || temp_runs11 == 1 || temp_runs11 == 2|| temp_runs11 == 3 || temp_runs11 == 4|| temp_runs11 == 6) {
				first_inning_total_run += temp_runs11;
			}
			if (temp_runs11 == 1 || temp_runs11 == 3) {
				clrscr();
				battingSA_cal(i);
				if (strike1 == 0) {
					strike1 = 1;
					non_Strike1 = 0;
				} else {
					strike1 = 0;
					non_Strike1 = 1;
				}
			} else if (temp_runs11 == 4) {
				clrscr();
				four1[strike1]++;
				battingSA_cal(i);
			} else if (temp_runs11 == 6) {
				clrscr();
				six1[strike1]++;
				battingSA_cal(i);
			}
			else if (temp_runs11 == 2) {
				clrscr();
				battingSA_cal(i);
			} else if (temp_runs11 == -1) {
				clrscr();
				if (runs1[strike1] > first_team_motm) {
					first_team_motm = runs1[strike1];
					first_team_player = ptr_bat1[strike1];
				}
				total_wicket++;
				count1++;
				call_batting(ptr_bat1[strike1], runs1[strike1], four1[strike1],six1[strike1]);
				wkt1++;
				printf("Name\t\t\t\t\t\truns1\t4's\t6's\n(S): ");
				printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat1[strike1],runs1[strike1], four1[strike1], six1[strike1]);
				printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat1[non_Strike1],runs1[non_Strike1], four1[non_Strike1],six1[non_Strike1]);
				if (!strcmp(ptr_bowl1, "Jasprit Bumrah")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns1\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i],wkt1);
				} else if (!strcmp(ptr_bowl1, "Mohammad Abbas")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns1\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i],wkt1);
				} else if (!strcmp(ptr_bowl1, "Sarfraz Ahmed")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns1\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i],wkt1);
				} else if (!strcmp(ptr_bowl1, "Haris Sohail")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns1\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i],wkt1);
				} else {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns1\twicket\n");
					printf("%s\t\t\t\t%d\t%d\n", ptr_bowl1, tot_runs11[i],wkt1);
				}
				runs1[strike1] = four1[strike1] = six1[strike1] = 0;
				if (temp_stk1 <= 7) {
					ptr_bat1[strike1] = team3_batsmen[temp_stk1];
				} else {
					ptr_bat1[strike1] = team3_bowler[temp_bowl1];
					temp_bowl1++;
				}
				printf("New player is: %s\n", ptr_bat1[strike1]);
				printf("Other player is: %s\n", ptr_bat1[non_Strike1]);
				runs1[strike1] = 0;
				four1[strike1] = 0;
				six1[strike1] = 0;
				temp_stk1++;
				if (count1 == 10) {
					call_batting(ptr_bat1[non_Strike1], runs1[non_Strike1],four1[non_Strike1], six1[non_Strike1]);
					if (runs1[strike1] > first_team_motm) {
						first_team_motm = runs1[strike1];
						first_team_player = ptr_bat1[strike1];
					}
					cpoy_bowler_to_batting(2);
					getch();
					clrscr();
					printf("\n++++++++++++++++++++++++++");
					printf("\n\nTotal Score=%d / %d", first_inning_total_run,total_wicket);
					printf("\n\n++++++++++++++++++++++++++");
					getch();
					print_total_run(first_inning_total_run,total_wicket,1);
					opp_batting(batting_team, bowling_team);
					getch();
				}
			} else if (temp_runs11 == 0) {
				clrscr();
				battingSA_cal(i);
			} else
				printf("Enter valid runs1\n");
		}
		bowler(ptr_bowl1,tot_runs11[i], wkt1);
		wkt1 = 0;
	}
	count1++;
	call_batting(ptr_bat1[strike1], runs1[strike1], four1[strike1],six1[strike1]);
	if (runs1[strike1] > first_team_motm) {
		first_team_motm = runs1[strike1];
		first_team_player = ptr_bat1[strike1];
	}
	count1++;
	call_batting(ptr_bat1[non_Strike1], runs1[non_Strike1], four1[non_Strike1],six1[non_Strike1]);
	if (runs1[non_Strike1] > first_team_motm) {
		first_team_motm = runs1[non_Strike1];
		first_team_player = ptr_bat1[non_Strike1];
	}
	remaining_batting(count1,3,1);
	cpoy_bowler_to_batting(1);
	cpoy_bowler_to_batting(2);
	getch();
	clrscr();
	printf("\n++++++++++++++++++++++++++");
	printf("\n\nTotal Score=%d / %d", first_inning_total_run, total_wicket);
	printf("\n\n++++++++++++++++++++++++++");
	getch();
	print_total_run(first_inning_total_run,total_wicket,1);
}
opp_batting(batting_team, bowling_team);
getch();
}
char *ptr_bat[2], *ptr_bowl;
int over[3][6], runs[2] = { 0, 0 }, wkt = 0;
static four[2] = { 0, 0 }, six[2] = { 0, 0 };
int temp_runs;
static int temp_stk = 2;
static int temp_bowl = 0, tot_wkts = 0;
int strike = 0, non_strike = 1, tot_runs[3] = { 0, 0, 0 };
void oppInd_cal(int i) {
runs[strike] += temp_runs;
tot_runs[i] += temp_runs;
printf("Name\t\t\t\t\t\truns\t4's\t6's\n(S): ");
printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat[strike], runs[strike], four[strike],six[strike]);
printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat[non_strike], runs[non_strike],four[non_strike], six[non_strike]);
printf("Bowler details:\n");
printf("Name\t\t\t\t\t\truns\twicket\n");
printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
}
void oppPak_cal(int i) {
runs[strike] += temp_runs;
tot_runs[i] += temp_runs;
printf("Name\t\t\t\t\t\truns\t4's\t6's\n(S): ");
printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat[strike], runs[strike], four[strike],six[strike]);
printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat[non_strike], runs[non_strike],four[non_strike], six[non_strike]);
if (!strcmp(ptr_bowl, "Jasprit Bumrah")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
} else if (!strcmp(ptr_bowl, "Jhye Richardson")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
} else if (!strcmp(ptr_bowl, "Kane Richardson")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
} else if (!strcmp(ptr_bowl, "Andrew Tye")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
} else {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns\twicket\n");
	printf("%s\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
}
}
void oppSA_cal(int i) {
runs[strike] += temp_runs;
tot_runs[i] += temp_runs;
printf("Name\t\t\t\t\t\truns\t4's\t6's\n(S): ");
printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat[strike], runs[strike], four[strike],six[strike]);
printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat[non_strike], runs[non_strike],four[non_strike], six[non_strike]);
if (!strcmp(ptr_bowl, "Jasprit Bumrah")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\truns\twicket\n");
	printf("%s\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
} else if (!strcmp(ptr_bowl, "Mohammad Abbas")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
} else if (!strcmp(ptr_bowl, "Sarfraz Ahmed")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
} else if (!strcmp(ptr_bowl, "Haris Sohail")) {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\t\truns\twicket\n");
	printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
} else {
	printf("Bowler details:\n");
	printf("Name\t\t\t\t\truns\twicket\n");
	printf("%s\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
}
}
void opp_batting(int old_team, int new_team) {
total_wicket = count1 = 0;
instructions();
print_team_name(new_team,2);
if (new_team == 1) {
	ptr_bat[strike] = team1_batsmen[0];
	ptr_bat[non_strike] = team1_batsmen[1];
	printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat[strike], runs[strike],four[strike], six[non_strike]);
	printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat[non_strike], runs[non_strike],four[strike], six[non_strike]);
	printf("Keep entering runs for 3 overs:\n ");
	for (int i = 0; i < 3; i++) {
		tot_wkts += wkt;
		wkt = 0;
		if (old_team == 2) {
			ptr_bowl = team2_bowler[i];
		} else if (old_team == 3) {
			ptr_bowl = team3_bowler[i];
		}
		for (int j = 0; j < 6; j++) {
			if ((j + 1) == 6) {
				total_ball = 0;
			} else {
				total_ball = j + 1;
			}
			if (tot_wkts == 10) {
				printf("\n-----Game over-----\n");
				getch();
				exit(0);
			}
			scanf("%d", &temp_runs);
			if (temp_runs == 0 || temp_runs == 1 || temp_runs == 2|| temp_runs == 3 || temp_runs == 4 || temp_runs == 6) {
				second_inning_total_run += temp_runs;
			}
			if (second_inning_total_run > first_inning_total_run) {
				second_bowler(ptr_bowl,tot_runs[i],wkt);
				wkt = 0;
				count1++;
				call_opp_batting(ptr_bat[strike], runs[strike], four[strike],six[strike]);
				if (runs[strike] > second_team_motm) {
					second_team_motm = runs[strike];
					second_team_player = ptr_bat[strike];
				}
				count1++;
				call_opp_batting(ptr_bat[non_strike], runs[non_strike],four[non_strike], six[non_strike]);
				if (runs[strike] > second_team_motm) {
					second_team_motm = runs[strike];
					second_team_player = ptr_bat[strike];
				}
				remaining_batting(count1,1,2);
				cpoy_bowler_to_batting(3);
				cpoy_bowler_to_batting(4);
				getch();
				clrscr();
				printf("\n++++++++++++++++++++++++++");
				printf("\n\nTotal Score=%d / %d", second_inning_total_run,total_wicket);
				printf("\n\n++++++++++++++++++++++++++");
				getch();
				print_total_run(second_inning_total_run,total_wicket,2);
				getch();
				clrscr();
				final_copy_from_sbatting_to_batting(old_team,new_team);
				getch();
				clrscr();
				exit(0);
			}
			if (temp_runs == 1 || temp_runs == 3) {
				clrscr();
				oppInd_cal(i);
				if (strike == 0) {
					strike = 1;
					non_strike = 0;
				} else {
					strike = 0;
					non_strike = 1;
				}
			} else if (temp_runs == 4) {
				clrscr();
				four[strike]++;
				oppInd_cal(i);
			} else if (temp_runs == 6) {
				clrscr();
				six[strike]++;
				oppInd_cal(i);
			}
			else if (temp_runs == 2) {
				clrscr();
				oppInd_cal(i);
			} else if (temp_runs == -1) {
				clrscr();
				if (runs[strike] > second_team_motm) {
					second_team_motm = runs[strike];
					second_team_player = ptr_bat[strike];
				}
				total_wicket++;
				count1++;
				call_opp_batting(ptr_bat[strike], runs[strike], four[strike],six[strike]);
				wkt++;
				printf("Name\t\t\t\t\t\truns\t4's\t6's\n(S): ");
				printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat[strike], runs[strike],four[strike], six[strike]);
				printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat[non_strike],runs[non_strike], four[non_strike], six[non_strike]);
				printf("Bowler details:\n");
				printf("Name\t\t\t\t\t\truns\twicket\n");
				printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				if (temp_stk <= 7) {
					ptr_bat[strike] = team1_batsmen[temp_stk];
				} else {
					ptr_bat[strike] = team1_bowler[temp_bowl];
					temp_bowl++;
				}
				printf("New player is: %s\n", ptr_bat[strike]);
				printf("Other player is: %s\n", ptr_bat[non_strike]);
				runs[strike] = 0;
				four[strike] = 0;
				six[strike] = 0;
				temp_stk++;
			} else if (temp_runs == 0) {
				clrscr();
				oppInd_cal(i);
			} else
				printf("Enter valid runs\n");
		}
		fp1 = fopen("sbowler.txt", "a");
		fputs("\n", fp1);
		fputs(ptr_bowl, fp1);
		fputs("\t", fp1);
		fprintf(fp1, "%d", tot_runs[i]);
		fputs("\t", fp1);
		fprintf(fp1, "%d", wkt);
		fclose(fp1);
		wkt = 0;
	}
	count1++;
	call_opp_batting(ptr_bat[strike], runs[strike], four[strike], six[strike]);
	if (runs[strike] > second_team_motm) {

		second_team_motm = runs[strike];
		second_team_player = ptr_bat[strike];
	}
	count1++;
	call_opp_batting(ptr_bat[non_strike], runs[non_strike], four[non_strike],six[non_strike]);
	if (runs[non_strike] > second_team_motm) {
		second_team_motm = runs[non_strike];
		second_team_player = ptr_bat[non_strike];
	}
	remaining_batting(count1,1,2);
	cpoy_bowler_to_batting(3);
	cpoy_bowler_to_batting(4);
	getch();
	clrscr();
	printf("\n++++++++++++++++++++++++++");
	printf("\n\nTotal Score=%d / %d", second_inning_total_run, total_wicket);
	printf("\n\n++++++++++++++++++++++++++");
	getch();
	print_total_run(second_inning_total_run,total_wicket,2);
} else if (new_team == 2) {
	ptr_bat[strike] = team2_batsmen[0];
	ptr_bat[non_strike] = team2_batsmen[1];
	printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat[strike], runs[strike],four[strike], six[non_strike]);
	printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat[non_strike], runs[non_strike],four[strike], six[non_strike]);
	printf("Keep entering runs for 3 overs: \n");
	for (int i = 0; i < 3; i++) {
		tot_wkts += wkt;
		wkt = 0;
		if (old_team == 1) {
			ptr_bowl = team1_bowler[i];
		} else if (old_team == 3) {
			ptr_bowl = team3_bowler[i];
		}
		for (int j = 0; j < 6; j++) {
			if ((j + 1) == 6) {
				total_ball = 0;
			} else {
				total_ball = j + 1;
			}
			if (tot_wkts == 10) {
				printf("\n-----Game over-----\n");
				getch();
			}
			scanf("%d", &temp_runs);
			if (temp_runs == 0 || temp_runs == 1 || temp_runs == 2|| temp_runs == 3 || temp_runs == 4 || temp_runs == 6) {
				second_inning_total_run += temp_runs;
			}
			if (second_inning_total_run > first_inning_total_run) {
				fp1 = fopen("sbowler.txt", "a");
				fputs("\n", fp1);
				fputs(ptr_bowl, fp1);
				fputs("\t", fp1);
				fprintf(fp1, "%d", tot_runs[i]);
				fputs("\t", fp1);
				fprintf(fp1, "%d", wkt);
				fclose(fp1);
				wkt = 0;
				count1++;
				call_opp_batting(ptr_bat[strike], runs[strike], four[strike],six[strike]);
				if (runs[strike] > second_team_motm) {
					second_team_motm = runs[strike];
					second_team_player = ptr_bat[strike];
				}
				count1++;
				call_opp_batting(ptr_bat[non_strike], runs[non_strike],four[non_strike], six[non_strike]);
				if (runs[strike] > second_team_motm) {
					second_team_motm = runs[strike];
					second_team_player = ptr_bat[strike];
				}
				remaining_batting(count1,2,2);
				cpoy_bowler_to_batting(3);
				cpoy_bowler_to_batting(4);
				getch();
				clrscr();
				printf("\n++++++++++++++++++++++++++");
				printf("\n\nTotal Score=%d / %d", second_inning_total_run,total_wicket);
				printf("\n\n++++++++++++++++++++++++++");
				getch();
				print_total_run(second_inning_total_run,total_wicket,2);
				getch();
				clrscr();
				final_copy_from_sbatting_to_batting(old_team,new_team);
				getch();
				clrscr();
				exit(0);
			}
			if (temp_runs == 1 || temp_runs == 3) {
				clrscr();
				oppPak_cal(i);
				if (strike == 0) {
					strike = 1;
					non_strike = 0;
				} else {
					strike = 0;
					non_strike = 1;
				}
			} else if (temp_runs == 4) {
				clrscr();
				four[strike]++;
				oppPak_cal(i);
			} else if (temp_runs == 6) {
				clrscr();
				six[strike]++;
				oppPak_cal(i);
			}
			else if (temp_runs == 2) {
				clrscr();
				oppPak_cal(i);
			} else if (temp_runs == -1) {
				clrscr();
				if (runs[strike] > second_team_motm) {
					second_team_motm = runs[strike];
					second_team_player = ptr_bat[strike];
				}
				total_wicket++;
				count1++;
				call_opp_batting(ptr_bat[strike], runs[strike], four[strike],six[strike]);
				wkt++;
				printf("Name\t\t\t\t\t\truns\t4's\t6's\n(S): ");
				printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat[strike], runs[strike],four[strike], six[strike]);
				printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat[non_strike],runs[non_strike], four[non_strike], six[non_strike]);
				if (!strcmp(ptr_bowl, "Jasprit Bumrah")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Jhye Richardson")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Kane Richardson")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Andrew Tye")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				}
				if (temp_stk <= 7) {
					ptr_bat[strike] = team2_batsmen[temp_stk];
				} else {
					ptr_bat[strike] = team2_bowler[temp_bowl];
					temp_bowl++;
				}
				printf("New player is: %s\n", ptr_bat[strike]);
				printf("Other player is: %s\n", ptr_bat[non_strike]);
				runs[strike] = 0;
				four[strike] = 0;
				six[strike] = 0;
				temp_stk++;
			} else if (temp_runs == 0) {
				clrscr();
				oppPak_cal(i);
			} else
				printf("Enter valid runs\n");
		}
		fp1 = fopen("sbowler.txt", "a");
		fputs("\n", fp1);
		fputs(ptr_bowl, fp1);
		fputs("\t", fp1);
		fprintf(fp1, "%d", tot_runs[i]);
		fputs("\t", fp1);
		fprintf(fp1, "%d", wkt);
		fclose(fp1);
		wkt = 0;
	}
	count1++;
	call_opp_batting(ptr_bat[strike], runs[strike], four[strike], six[strike]);
	if (runs[strike] > second_team_motm) {
		second_team_motm = runs[strike];
		second_team_player = ptr_bat[strike];
	}
	count1++;
	call_opp_batting(ptr_bat[non_strike], runs[non_strike], four[non_strike],six[non_strike]);
	if (runs[non_strike] > second_team_motm) {
		second_team_motm = runs[non_strike];
		second_team_player = ptr_bat[non_strike];
	}
	remaining_batting(count1,2,2);
	cpoy_bowler_to_batting(3);
	cpoy_bowler_to_batting(4);
	getch();
	clrscr();
	printf("\n++++++++++++++++++++++++++");
	printf("\n\nTotal Score=%d / %d", second_inning_total_run, total_wicket);
	printf("\n\n++++++++++++++++++++++++++");
	getch();
	print_total_run(second_inning_total_run,total_wicket,2);
} else {
	ptr_bat[strike] = team3_batsmen[0];
	ptr_bat[non_strike] = team3_batsmen[1];
	printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat[strike], runs[strike],four[strike], six[non_strike]);
	printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat[non_strike], runs[non_strike],four[strike], six[non_strike]);
	printf("Keep entering runs for 3 overs: \n");

	for (int i = 0; i < 3; i++) {
		tot_wkts += wkt;
		wkt = 0;
		if (old_team == 1) {
			ptr_bowl = team1_bowler[i];
		} else if (old_team == 2) {
			ptr_bowl = team2_bowler[i];
		}
		for (int j = 0; j < 6; j++) {
			if ((j + 1) == 6) {
				total_ball = 0;
			} else {
				total_ball = j + 1;
			}
			if (tot_wkts == 10) {
				printf("\n-----Game over-----\n");
				getch();
			}
			scanf("%d", &temp_runs);
			if (temp_runs == 0 || temp_runs == 1 || temp_runs == 2|| temp_runs == 3 || temp_runs == 4 || temp_runs == 6) {
				second_inning_total_run += temp_runs;
			}
			if (second_inning_total_run > first_inning_total_run) {
				fp1 = fopen("sbowler.txt", "a");
				fputs("\n", fp1);
				fputs(ptr_bowl, fp1);
				fputs("\t", fp1);
				fprintf(fp1, "%d", tot_runs[i]);
				fputs("\t", fp1);
				fprintf(fp1, "%d", wkt);
				fclose(fp1);
				wkt = 0;
				count1++;
				call_opp_batting(ptr_bat[strike], runs[strike], four[strike],six[strike]);
				if (runs[strike] > second_team_motm) {
					second_team_motm = runs[strike];
					second_team_player = ptr_bat[strike];
				}
				count1++;
				call_opp_batting(ptr_bat[non_strike], runs[non_strike],four[non_strike], six[non_strike]);
				if (runs[strike] > second_team_motm) {
					second_team_motm = runs[strike];
					second_team_player = ptr_bat[strike];
				}
				remaining_batting(count1,3,2);
				cpoy_bowler_to_batting(3);
				cpoy_bowler_to_batting(4);
				getch();
				clrscr();
				printf("\n++++++++++++++++++++++++++");
				printf("\n\nTotal Score=%d / %d", second_inning_total_run,total_wicket);
				printf("\n\n++++++++++++++++++++++++++");
				getch();
				print_total_run(second_inning_total_run,total_wicket,2);
				getch();
				clrscr();
				final_copy_from_sbatting_to_batting(old_team,new_team);
				getch();
				clrscr();
				exit(0);
			}
			if (temp_runs == 1 || temp_runs == 3) {
				clrscr();
				oppSA_cal(i);
				if (strike == 0) {
					strike = 1;
					non_strike = 0;
				} else {
					strike = 0;
					non_strike = 1;
				}
			} else if (temp_runs == 4) {
				clrscr();
				four[strike]++;
				runs[strike] += temp_runs;
				tot_runs[i] += temp_runs;
				printf("Name\t\t\t\t\t\truns\t4's\t6's\n(S): ");
				printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat[strike], runs[strike],four[strike], six[strike]);
				printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat[non_strike],runs[non_strike], four[non_strike], six[non_strike]);
				if (!strcmp(ptr_bowl, "Jasprit Bumrah")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Mohammad Abbas")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Sarfraz Ahmed")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Haris Sohail")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				}
			} else if (temp_runs == 6) {
				clrscr();
				six[strike]++;
				runs[strike] += temp_runs;
				tot_runs[i] += temp_runs;
				printf("Name\t\t\t\t\t\truns\t4's\t6's\n(S): ");
				printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat[strike], runs[strike],four[strike], six[strike]);
				printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat[non_strike],runs[non_strike], four[non_strike], six[non_strike]);
				if (!strcmp(ptr_bowl, "Jasprit Bumrah")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Mohammad Abbas")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Sarfraz Ahmed")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Haris Sohail")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				}
			}
			else if (temp_runs == 2) {
				clrscr();
				runs[strike] += temp_runs;
				tot_runs[i] += temp_runs;
				printf("Name\t\t\t\t\t\truns\t4's\t6's\n(S): ");
				printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat[strike], runs[strike],four[strike], six[strike]);
				printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat[non_strike],runs[non_strike], four[non_strike], six[non_strike]);
				if (!strcmp(ptr_bowl, "Jasprit Bumrah")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Mohammad Abbas")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Sarfraz Ahmed")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Haris Sohail")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				}
			} else if (temp_runs == -1) {
				clrscr();
				if (runs[strike] > second_team_motm) {
					second_team_motm = runs[strike];
					second_team_player = ptr_bat[strike];
				}
				total_wicket++;
				count1++;
				call_opp_batting(ptr_bat[strike], runs[strike], four[strike],six[strike]);
				wkt++;
				printf("Name\t\t\t\t\t\truns\t4's\t6's\n(S): ");
				printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat[strike], runs[strike],four[strike], six[strike]);
				printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat[non_strike],runs[non_strike], four[non_strike], six[non_strike]);
				if (!strcmp(ptr_bowl, "Jasprit Bumrah")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Mohammad Abbas")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Sarfraz Ahmed")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Haris Sohail")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				}
				if (temp_stk <= 7) {
					ptr_bat[strike] = team3_batsmen[temp_stk];
				} else {
					ptr_bat[strike] = team3_bowler[temp_bowl];
					temp_bowl++;
				}
				printf("New player is: %s\n", ptr_bat[strike]);
				printf("Other player is: %s\n", ptr_bat[non_strike]);
				runs[strike] = 0;
				four[strike] = 0;
				six[strike] = 0;
				temp_stk++;
			} else if (temp_runs == 0) {
				clrscr();
				runs[strike] += temp_runs;
				tot_runs[i] += temp_runs;
				printf("Name\t\t\t\t\t\truns\t4's\t6's\n(S): ");
				printf("%s\t\t\t\t%d\t%d\t%d\n", ptr_bat[strike], runs[strike],four[strike], six[strike]);
				printf("%s\t\t\t\t\t%d\t%d\t%d\n", ptr_bat[non_strike],runs[non_strike], four[non_strike], six[non_strike]);
				if (!strcmp(ptr_bowl, "Jasprit Bumrah")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Mohammad Abbas")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Sarfraz Ahmed")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else if (!strcmp(ptr_bowl, "Haris Sohail")) {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				} else {
					printf("Bowler details:\n");
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("%s\t\t\t%d\t%d\n", ptr_bowl, tot_runs[i], wkt);
				}
			} else
				printf("Enter valid runs\n");
		}
		fp1 = fopen("sbowler.txt", "a");
		fputs("\n", fp1);
		fputs(ptr_bowl, fp1);
		fputs("\t", fp1);
		fprintf(fp1, "%d", tot_runs[i]);
		fputs("\t", fp1);
		fprintf(fp1, "%d", wkt);
		fclose(fp1);
		wkt = 0;
	}
	count1++;
	call_opp_batting(ptr_bat[strike], runs[strike], four[strike], six[strike]);
	if (runs[strike] > second_team_motm) {
		second_team_motm = runs[strike];
		second_team_player = ptr_bat[strike];
	}
	count1++;
	if (runs[non_strike] > second_team_motm) {
		second_team_motm = runs[non_strike];
		second_team_player = ptr_bat[non_strike];
	}
	remaining_batting(count1,3,2);
	cpoy_bowler_to_batting(3);
	cpoy_bowler_to_batting(4);
	getch();
	clrscr();
	printf("\n++++++++++++++++++++++++++");
	printf("\n\nTotal Score=%d / %d", second_inning_total_run, total_wicket);
	printf("\n\n++++++++++++++++++++++++++");
	getch();
	print_total_run(second_inning_total_run,total_wicket,2);
}
getch();
clrscr();
final_copy_from_sbatting_to_batting(old_team,new_team);
getch();
clrscr();
exit(0);
}
