/******************************************************************************

PROJECT NAME : CRICKET EMPIRE

201812022 : ZEEL MODI
201812051 : PARITA DUDHANI
201812064 : JAINAM SHAH
201812091 : SHIVANI DESAI
201812093 : MOHIT SHAH

*******************************************************************************/
#include<stdlib.h>
#include <stdio.h>
#include<conio.h>
FILE *fp;
static int count1=0,total_run=0,total_wicket=0,total_over=0,total_ball=0;
char copy;	
char *first_team_players_name[11] = {"Virat Kohli(c)","Shikhar Dhawan","Hardik Pandya",
					"Suresh Raina","Ravindra Jadeja",
					"MS Dhoni   ","Kedar Jadhav","K Khaleel Ahmed",
					"Bhuvneshwar Kumar","Jasprit Bumrah","Yuzvendra Chahal"};

char *team1_batsmen[8] = {"Virat Kohli(c)","Shikhar Dhawan","Hardik Pandya","Suresh Raina",
			"Ravindra Jadeja","MS Dhoni   ","Kedar Jadhav","K Khaleel Ahmed"};

char *team1_bowler[3] ={"Bhuvneshwar Kumar","Jasprit Bumrah","Yuzvendra Chahal"};

char *second_team_players_name[11] = {"Sarfraz Ahmed(c)","Azhar Ali  ","Fakhar Zaman",
					"Imam-ul-Haq  ","Babar Azam  ","Mohammad Hafeez",
					"Faheem Ashraf","Hasan Ali  ","Mohammad Abbas","Bilal Asif",
					"Haris Sohail"};

char *team2_batsmen[8] = {"Sarfraz Ahmed(c)","Azhar Ali","Fakhar Zaman",
					"Imam-ul-Haq","Babar Azam","Mohammad Hafeez",
					"Faheem Ashraf","Hasan Ali"};

char *team2_bowler[3]={"Mohammad Abbas","Bilal Asif","Haris Sohail"};

char *third_team_players_name[11] = {"Tim Paine(c)","Aaron Finch","Ashton Agar",
					"Alex Carey","Travis Head","Nathan Lyon",
					"Glenn Maxwell","Shaun Marsh","Jhye Richardson","Kane Richardson",
					"Andrew Tye"};

char *team3_batsmen[8]={"Tim Paine(c)","Aaron Finch","Ashton Agar",
					"Alex Carey","Travis Head","Nathan Lyon",
					"Glenn Maxwell","Shaun Marsh"};

char *team3_bowler[3]={"Jhye Richardson","Kane Richardson","Andrew Tye"};

int tmp_first_team_select_option_no;
int my_team_no,opposite_team_no;    // 1 for INDIA  ,   2 for PAKISTAN  ,   3 for SOUTH AFRICA
char *batting_team_name,*bowling_team_name;
void home_page();
void play_game();
void first_number_team();
void second_number_team();
void third_number_team();
void toss(int,int,int);
void batting(int,int);
void opp_batting(int,int);



int main()
{

	clrscr();
    printf("WELCOME TO GAME OF THE CRICKET !!!!\n");
    getch();
    printf("");
    //first_number_team();
    clrscr();
    home_page();


    return 0;
}
void home_page(){
    int option;

    printf("                 MENU                 \n\n");
    printf("         1. PLAY THE GAME\n");
    printf("         2. RULES\n");
    printf("         3. CREDITS\n");
    printf("         4. EXIT\n");

    printf("         SELECT AN OPTION ( 1- 4) : ");
    scanf("%d",&option);


   switch (option)
   {
       case 1: play_game();
	       break;
       case 2:
	       break;
       case 3:
	       break;
       case 4:
	       exit(1);
       default:printf("INVALID CHOICE...");
		home_page();
		break;
   }

}
void play_game(){

    int choose_first_team_number,choose_second_team_number;
    char invalid_choice;
    clrscr();
    printf("\n\n\n\n              TEAM NAMES              \n\n");
    printf("==================================================\n");
    printf("              1. INDIA\n");
    printf("              2. PAKISTAN\n");
    printf("              3. SOUTH AFRICA\n");
    printf("Choose Your Team ( 1-3 ) :");
    scanf("%d",&choose_first_team_number);


    tmp_first_team_select_option_no=choose_first_team_number;
    clrscr();
    int choice;
    if(tmp_first_team_select_option_no==1){

			    printf("\n\n\n\n              TEAM NAMES              \n\n");
		printf("==================================================\n");
	       // printf("              1. INDIA\n");
		printf("              1. PAKISTAN\n");
		printf("              2. SOUTH AFRICA\n");

		printf("Choose Opposite Team ( 1-2 ) :");
		scanf("%d",&choose_second_team_number);



		clrscr();
		if(choose_second_team_number==1){

		    clrscr();
		    first_number_team();
		    getch();
		    clrscr();
		    second_number_team();
		    my_team_no=1;
		    opposite_team_no=2;
		    getch();
		    printf("\n\n0. Head\n1. Tail\nEnter your choice: ");
		    scanf("%d",&choice);
		    getch();
		    toss(1,2,choice);

		}
		else{

		    clrscr();
		    first_number_team();
		    getch();
		    clrscr();
		    third_number_team();
		    my_team_no=1;
		    opposite_team_no=3;
		    getch();
		    printf("\n\n0. Head\n1. Tail\nEnter your choice: ");
		    scanf("%d",&choice);
		    getch();
		    toss(1,3,choice);


		}
    }
    else if(tmp_first_team_select_option_no==2){

				printf("\n\n\n\n              TEAM NAMES              \n\n");
		printf("==================================================\n");
		printf("              1. INDIA\n");
	       // printf("              1. PAKISTAN\n");
		printf("              2. SOUTH AFRICA\n");
		printf("Choose Opposite Team ( 1-2 ) :");
		scanf("%d",&choose_second_team_number);

		 if(choose_second_team_number==1){

		    clrscr();

		    second_number_team();
		    getch();
		    clrscr();
		    first_number_team();
		    my_team_no=2;
		    opposite_team_no=1;
		    getch();
		    printf("\n\n0. Head\n1. Tail\nEnter your choice: ");
		    scanf("%d",&choice);
		    getch();
		    toss(2,1,choice);

		}
		else{

		    clrscr();
		    second_number_team();
		    getch();
		    clrscr();
		    third_number_team();
		    my_team_no=2;
		    opposite_team_no=3;
		    getch();
		    printf("\n\n0. Head\n1. Tail\nEnter your choice: ");
		    scanf("%d",&choice);
		    getch();
		    toss(2,3,choice);


		}



    }
    else if(tmp_first_team_select_option_no==3)
    {

			     printf("\n\n\n\n              TEAM NAMES              \n\n");
		printf("==================================================\n");
		printf("              1. INDIA\n");
		printf("              2. PAKISTAN\n");
	       // printf("              2. SOUTH AFRICA\n");
		printf("Choose Opposite Team ( 1-2 ) :");
		scanf("%d",&choose_second_team_number);



		if(choose_second_team_number==1){

		    clrscr();

		    third_number_team();
		    getch();
		    clrscr();
		    first_number_team();
		    my_team_no=3;
		    opposite_team_no=1;
		    getch();
		    printf("\n\n0. Head\n1. Tail\nEnter your choice: ");
		    scanf("%d",&choice);
		    getch();
		    toss(3,1,choice);

		}
		else{

		    clrscr();
		    third_number_team();
		    getch();
		    clrscr();
		    second_number_team();
		    my_team_no=3;
		    opposite_team_no=2;
		    getch();
		    printf("\n\n0. Head\n1. Tail\nEnter your choice: ");
		    scanf("%d",&choice);
		    getch();
		    toss(3,2,choice);


		}

    }
    else{
	clrscr();
	printf("\n\n\nINVALID CHOICE\n\n\n");
	play_game();

    }




}

void first_number_team(){



    int print_player_index;

    char *(*print_player_name)[11] = &first_team_players_name;



    printf("");

    printf("\n\n\t\t\tINDIA TEAM PLAYERS LIST : \n\n");

    for(print_player_index=0;print_player_index<11;print_player_index++)
    {

	 printf("\t\t\t%d : %s\n",print_player_index+1,(*print_player_name)[print_player_index]);

    }




}
void second_number_team(){


    int print_player_index;

    char *(*print_player_name)[11] = &second_team_players_name;



    printf("");

    printf("\n\n\t\t\tPAKISTAN TEAM PLAYERS LIST : \n\n");

    for(print_player_index=0;print_player_index<11;print_player_index++)
    {

	 printf("\t\t\t%d : %s\n",print_player_index+1,(*print_player_name)[print_player_index]);

    }


}
void third_number_team(){


    int print_player_index;

    char *(*print_player_name)[11] = &third_team_players_name;



    printf("");

    printf("\n\n\t\t\tSOUTH AFRICA TEAM PLAYERS LIST : \n\n");
    for(print_player_index=0;print_player_index<11;print_player_index++)
    {

	 printf("\t\t\t%d : %s\n",print_player_index+1,(*print_player_name)[print_player_index]);

    }


}
void toss(int my_team,int opposite_team,int choice){

    int toss_random;
    int toss_option_select;
    clrscr();
    srand(time(NULL));
    toss_random=rand()%2;
    if(toss_random==0)
	printf("\nIt's a head\n");
    else
	printf("\nIt's a tail\n");

	    if(toss_random==choice)   // IF PART : YOUR TEAM WON THE TOSS    ,     ELSE PART : OPPOSITE TEAM WON THE TOSS
	    {
		if(my_team==1 && opposite_team==2){

		     printf("YOU : TEAM INDIA WON THE TOSSS...\n");
		     printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		     scanf("%d",&toss_option_select);

		     if(toss_option_select==1){

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM INDIA\n");
				printf("Bowling : TEAM PAKISTAN\n");
				batting_team_name="INDIA";
				bowling_team_name="PAKISTAN";
				batting(1,2);
				getch();
		     }
		     else{

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM PAKISTAN\n");
				printf("Bowling : TEAM INDIA\n");
				batting_team_name="PAKISTAN";
				bowling_team_name="INDIA";
				batting(2,1);
				getch();
		     }


		}
		else if(my_team==1 && opposite_team==3){

		      printf("YOU : TEAM INDIA WON THE TOSSS...\n");
		      printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		      scanf("%d",&toss_option_select);

		      if(toss_option_select==1){

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM INDIA\n");
				printf("Bowling : TEAM SOUTH AFRICA\n");
				batting_team_name="INDIA";
				bowling_team_name="SOUTH AFRICA";
				batting(1,3);
				getch();
		     }
		     else{

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM SOUTH AFRICA\n");
				printf("Bowling : TEAM INDIA\n");
				batting_team_name="SOUTH AFRICA";
				bowling_team_name="INDIA";
				batting(3,1);
				getch();
		     }

		}
		else if(my_team==2 && opposite_team==1){

		      printf("YOU : TEAM PAKISTAN WON THE TOSSS...\n");
		      printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		      scanf("%d",&toss_option_select);

		      if(toss_option_select==1){

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM PAKISTAN\n");
				printf("Bowling : TEAM INDIA\n");
				batting_team_name="PAKISTAN";
				bowling_team_name="INDIA";
				batting(2,1);
				getch();
		     }
		     else{

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM INDIA\n");
				printf("Bowling : TEAM PAKISTAN\n");
				batting_team_name="INDIA";
				bowling_team_name="PAKISTAN";
				batting(1,2);
				getch();
		     }

		}
		else if(my_team==2 && opposite_team==3){

		      printf("YOU : TEAM PAKISTAN WON THE TOSSS...\n");
		      printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		      scanf("%d",&toss_option_select);

		      if(toss_option_select==1){

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM PAKISTAN\n");
				printf("Bowling : TEAM SOUTH AFRICA\n");
				batting_team_name="PAKISTAN";
				bowling_team_name="SOUTH AFRICA";
				batting(2,3);
				getch();
		     }
		     else{

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM SOUTH AFRICA\n");
				printf("Bowling : TEAM PAKISTAN\n");
				batting_team_name="SOUTH AFRICA";
				bowling_team_name="PAKISTAN";
				batting(3,2);
				getch();
		     }

		}
		else if(my_team==3 && opposite_team==1){

		      printf("YOU : TEAM SOUTH AFRICA WON THE TOSSS...\n");
		      printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		      scanf("%d",&toss_option_select);

		      if(toss_option_select==1){

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM SOUTH AFRICA\n");
				printf("Bowling : TEAM INDIA\n");
				batting_team_name="SOUTH AFRICA";
				bowling_team_name="INDIA";
				batting(3,1);
				getch();
		     }
		     else{

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM INDIA\n");
				printf("Bowling : TEAM SOUTH AFRICA\n");
				batting_team_name="INDIA";
				bowling_team_name="SOUTH AFRICA";
				batting(1,3);
				getch();
		     }

		}
		else if(my_team==3 && opposite_team==2){

		      printf("YOU : TEAM SOUTH AFRICA WON THE TOSSS...\n");
		      printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		      scanf("%d",&toss_option_select);

		      if(toss_option_select==1){

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM SOUTH AFRICA\n");
				printf("Bowling : TEAM PAKISTAN\n");
				batting_team_name="SOUTH AFRICA";
				bowling_team_name="PAKISTAN";
				batting(3,2);
				getch();
		     }
		     else{

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM PAKISTAN\n");
				printf("Bowling : TEAM SOUTH AFRICA\n");
				batting_team_name="PAKISTAN";
				bowling_team_name="SOUTH AFRICA";
				batting(2,3);
				getch();
		     }

		}


	    }
	    //**********************************************************************************************
	    else
	    {


		if(my_team==1 && opposite_team==2){

		     printf("OPPOSITE : TEAM PAKISTAN WON THE TOSSS...\n");
		     printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		     scanf("%d",&toss_option_select);

		     if(toss_option_select==1){

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM PAKISTAN\n");
				printf("Bowling : TEAM INDIA\n");
				batting_team_name="PAKISTAN";
				bowling_team_name="INDIA";
				batting(2,1);
				getch();
		     }
		     else{

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM INDIA\n");
				printf("Bowling : TEAM PAKISTAN\n");
				batting_team_name="INDIA";
				bowling_team_name="PAKISTAN";
				batting(1,2);
				getch();
		     }


		}
		else if(my_team==1 && opposite_team==3){

		      printf("OPPOSITE : TEAM SOUTH AFRICA WON THE TOSSS...\n");
		      printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		      scanf("%d",&toss_option_select);

		      if(toss_option_select==1){

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM SOUTH AFRICA\n");
				printf("Bowling : TEAM INDIA\n");
				batting_team_name="SOUTH AFRICA";
				bowling_team_name="INDIA";
				batting(3,1);
				getch();
		     }
		     else{

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM INDIA\n");
				printf("Bowling : TEAM SOUTH AFRICA\n");
				batting_team_name="INDIA";
				bowling_team_name="SOUTH AFRICA";
				batting(1,3);
				getch();
		     }

		}
		else if(my_team==2 && opposite_team==1){

		      printf("OPPOSITE : TEAM INDIA WON THE TOSSS...\n");
		      printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		      scanf("%d",&toss_option_select);

		      if(toss_option_select==1){

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM INDIA\n");
				printf("Bowling : TEAM PAKISTAN\n");
				batting_team_name="INDIA";
				bowling_team_name="PAKISTAN";
				batting(1,2);
				getch();
		     }
		     else{

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM PAKISTAN\n");
				printf("Bowling : TEAM INDIA\n");
				batting_team_name="PAKISTAN";
				bowling_team_name="INDIA";
				batting(2,1);
				getch();
		     }

		}
		else if(my_team==2 && opposite_team==3){

		      printf("OPPOSITE : TEAM SOUTH AFRICA WON THE TOSSS...\n");
		      printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		      scanf("%d",&toss_option_select);

		      if(toss_option_select==1){

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM SOUTH AFRICA\n");
				printf("Bowling : TEAM PAKISTAN\n");
				batting_team_name="SOUTH AFRICA";
				bowling_team_name="PAKISTAN";
				batting(3,2);
				getch();
		     }
		     else{

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM PAKISTAN\n");
				printf("Bowling : TEAM SOUTH AFRICA\n");
				batting_team_name="PAKISTAN";
				bowling_team_name="SOUTH AFRICA";
				batting(2,3);
				getch();
		     }

		}
		else if(my_team==3 && opposite_team==1){

		      printf("OPPOSITE : TEAM INDIA WON THE TOSSS...\n");
		      printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		      scanf("%d",&toss_option_select);

		      if(toss_option_select==1){

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM INDIA\n");
				printf("Bowling : TEAM SOUTH AFRICA\n");
				batting_team_name="INDIA";
				bowling_team_name="SOUTH AFRICA";
				batting(1,3);
				getch();
		     }
		     else{

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM SOUTH AFRICA\n");
				printf("Bowling : TEAM INDIA\n");
				batting_team_name="SOUTH AFRICA";
				bowling_team_name="INDIA";
				batting(3,1);
				getch();
		     }

		}
		else if(my_team==3 && opposite_team==2){

		      printf("OPPOSITE : TEAM PAKISTAN WON THE TOSSS...\n");
		      printf("1. Batting     \n2. Bowling      \nChoose Your option ( Either 1 or 2 ) :");
		      scanf("%d",&toss_option_select);

		      if(toss_option_select==1){

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM PAKISTAN\n");
				printf("Bowling : TEAM SOUTH AFRICA\n");
				batting_team_name="PAKISTAN";
				bowling_team_name="SOUTH AFRICA";
				batting(2,3);
				getch();
		     }
		     else{

				printf("\n\nTOSS RESULT\n");
				printf("Batting : TEAM SOUTH AFRICA\n");
				printf("Bowling : TEAM PAKISTAN\n");
				batting_team_name="SOUTH AFRICA";
				bowling_team_name="PAKISTAN";
				batting(3,2);
				getch();
		     }
		}
	    }

}

void batting(int batting_team,int bowling_team)
{
	char *ptr_bat[2],*ptr_bowl;
	int over[3][6],runs[2]={0,0},wkt=0;
	static four[2]={0,0},six[2]={0,0};
	clrscr();
	printf("\n1. For 1 run");
	printf("\n2. For 2 runs");
	printf("\n3. For 3 runs");
	printf("\n4. For 4 runs");
	printf("\n6. For 6 runs");
	printf("\n-1. For out");
	getch();
	clrscr();
	int temp_runs;
//	int stk,nstk;
	static int temp_stk=2;
	static int temp_bowl=0;
	int strike=0,non_strike=1,tot_runs[3]={0,0,0};
	static int tot_wkts=0;
	printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
	
					 fp=fopen("batting.txt","a");
					 fputs("\n\t\tBATTING\n",fp);
					 fclose(fp);
	
	if(batting_team==1)
	{
		ptr_bat[strike]=team1_batsmen[0];
		ptr_bat[non_strike]=team1_batsmen[1];
		printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[non_strike]);
		printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[strike],six[non_strike]);
		printf("Keep entering runs for 3 overs: ");

		for(int i=0;i<3;i++)
		{
			tot_runs[i]=0;
			tot_wkts+=wkt;
			wkt=0;
			if(bowling_team==2)
			{
				ptr_bowl=team2_bowler[i];
			}
			else if(bowling_team==3)
			{
				ptr_bowl=team3_bowler[i];
			}
			for(int j=0;j<6;j++)
			{
				
				if((j+1)==6){
					
					total_ball=0;
				}
				else{
					
					total_ball=j+1;
					
				}
				
				
				if(tot_wkts==10)
				{
					printf("\n-----Batting over-----\n");
					getch();
					opp_batting(batting_team,bowling_team);

				}
				scanf("%d",&temp_runs);
				
				if(temp_runs == 0 || temp_runs == 1 || temp_runs == 2 || temp_runs == 3 || temp_runs == 4 || temp_runs == 6 ){
					
					total_run+=temp_runs;
				}
				
				
				if(temp_runs==1 || temp_runs==3)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
					if(strike==0)
					{	strike=1;
						non_strike=0;
					}
					else
					{
						strike=0;
						non_strike=1;
					}
				}
				else if(temp_runs==4)
				{
					clrscr();
					four[strike]++;
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else if(temp_runs==6)
				{
					clrscr();
					six[strike]++;
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}

				else if(temp_runs==2)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else if(temp_runs==-1)
				{
					clrscr();

					
					
					 total_wicket++;
					 count1++;
					 fp=fopen("batting.txt","a");
					 fputs("\n",fp);
					 fputs(ptr_bat[strike],fp);
					 fputs("\t",fp);
					 fprintf(fp,"%d",runs[strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",four[strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",six[strike]);
					 fclose(fp);
					
					
					wkt++;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
					
					
					runs[strike]=four[strike]=six[strike]=0;
					
					if(temp_stk<=7)
					{
						ptr_bat[strike]=team1_batsmen[temp_stk];
					}
					else
					{
						ptr_bat[strike]=team1_bowler[temp_bowl];
						temp_bowl++;
					}
					printf("New player is: %s\n",ptr_bat[strike]);
					printf("Other player is: %s\n",ptr_bat[non_strike]);
					runs[strike]=0;
					four[strike]=0;
					six[strike]=0;
					temp_stk++;
				}
				else if(temp_runs==0)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else
					printf("Enter valid runs\n");
					//--j;
			}
			//printf("Total runs after %d over= %d",i,tot_runs[i]);
				     fp=fopen("bowler.txt","a");
					 fputs("\n",fp);
					 fputs(ptr_bowl,fp);
					 fputs("\t",fp);
					 fprintf(fp,"%d",tot_runs[i]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",wkt);
					 fclose(fp);
					 wkt=0;
		}
		
		//printf("In batting team 1");
		//ptr points to INDIA
		
		             count1++;
					 fp=fopen("batting.txt","a");
					 fputs("\n",fp);
					 fputs(ptr_bat[strike],fp);
					 fputs("\t",fp);
					 fprintf(fp,"%d",runs[strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",four[strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",six[strike]);
					 fclose(fp);
					 
					 					 
					 count1++;
					 fp=fopen("batting.txt","a");
					 fputs("\n",fp);
					 fputs(ptr_bat[non_strike],fp);
					 fputs("\t",fp);
					 fprintf(fp,"%d",runs[non_strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",four[non_strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",six[non_strike]);
					 fclose(fp);
			
			
		
								FILE  *fp1=fopen("remaining_batting.txt","a");
								for(int ii=count1;ii<8;ii++)
								{


											 fputs("\n",fp1);
											 fputs(first_team_players_name[ii],fp1);
											 fputs("\t",fp1);
											 fprintf(fp1,"%d",0);
											 fputs("\t",fp1);
											 fprintf(fp1,"%d",0);
											 fputs("\t",fp1);
											 fprintf(fp1,"%d",0);


								   }
								    fclose(fp1);
									FILE *source, *target;
									source = fopen("remaining_batting.txt", "r");
									target = fopen("batting.txt", "a");
									while( ( copy = fgetc(source) ) != EOF )
									{
											fputc(copy, target);
									}
									fclose(source);
									fclose(target);
									
									
									
									
									
									
									
									
									source = fopen("bowler.txt", "r");
									target = fopen("batting.txt", "a");
									fputs("\n\n \t\tBOWLER\n",target);
									while( ( copy = fgetc(source) ) != EOF )
									{
											fputc(copy, target);
									}
									fclose(source);
									fclose(target);
									
									getch();
									clrscr();
									printf("\n++++++++++++++++++++++++++");
									//getch();
									//getch();
									printf("\n\nTotal Score=%d / %d", total_run, total_wicket );
									printf("\n\n++++++++++++++++++++++++++");
									getch();
									
									fp=fopen("batting.txt","a");
									fputs("\n\nTOTAL SCORE : ",fp);
									fprintf(fp,"%d",total_run);
									fputs(" \\ ",fp);
									fprintf(fp,"%d",total_wicket);
									fclose(fp);
	  }
	else if(batting_team==2)
	{
		ptr_bat[strike]=team2_batsmen[0];
		ptr_bat[non_strike]=team2_batsmen[1];

		printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[non_strike]);
		printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[strike],six[non_strike]);
		//printf("Name\t\t\truns\twicket\n");
		//printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs,wkt);
		printf("Keep entering runs for 3 overs: ");

		for(int i=0;i<3;i++)
		{
			tot_wkts+=wkt;
			wkt=0;
			if(bowling_team==1)
			{
				ptr_bowl=team1_bowler[i];
			}
			else if(bowling_team==3)
			{
				ptr_bowl=team3_bowler[i];
			}
			for(int j=0;j<6;j++)
			{
				
				
				if((j+1)==6){
					
					total_ball=0;
				}
				else{
					
					total_ball=j+1;
					
				}
				
				if(tot_wkts==10)
				{
					printf("\n-----Batting over-----\n");
					getch();
					opp_batting(batting_team,bowling_team);

				}
				scanf("%d",&temp_runs);
				if(temp_runs == 0 || temp_runs == 1 || temp_runs == 2 || temp_runs == 3 || temp_runs == 4 || temp_runs == 6 ){
					
					total_run+=temp_runs;
				}
				if(temp_runs==1 || temp_runs==3)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
					if(strike==0)
					{	strike=1;
						non_strike=0;
					}
					else
					{
						strike=0;
						non_strike=1;
					}
				}
				else if(temp_runs==4)
				{
					clrscr();
					four[strike]++;
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else if(temp_runs==6)
				{
					clrscr();
					six[strike]++;
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}

				else if(temp_runs==2)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else if(temp_runs==-1)
				{
					clrscr();

					
					 total_wicket++;
					 count1++;
					 fp=fopen("batting.txt","a");
					 fputs("\n",fp);
					 fputs(ptr_bat[strike],fp);
					 fputs("\t",fp);
					 fprintf(fp,"%d",runs[strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",four[strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",six[strike]);
					 fclose(fp);
					
					
					wkt++;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
					
					
					
					runs[strike]=four[strike]=six[strike]=0;
					
					
					if(temp_stk<=7)
					{
						ptr_bat[strike]=team2_batsmen[temp_stk];
					}
					else
					{
						ptr_bat[strike]=team2_bowler[temp_bowl];
						temp_bowl++;
					}
					printf("New player is: %s\n",ptr_bat[strike]);
					printf("Other player is: %s\n",ptr_bat[non_strike]);
					runs[strike]=0;
					four[strike]=0;
					six[strike]=0;
					temp_stk++;
				}
				else if(temp_runs==0)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else
					printf("Enter valid runs\n");
					//--j;
			}
			//printf("Total runs after %d over= %d",i,tot_runs[i]);
			         fp=fopen("bowler.txt","a");
					 fputs("\n",fp);
					 fputs(ptr_bowl,fp);
					 fputs("\t",fp);
					 fprintf(fp,"%d",tot_runs[i]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",wkt);
					 fclose(fp);
					 wkt=0;
		}
		//printf("batting team 2");
		//ptr points to Pakistan
					 count1++;
					 fp=fopen("batting.txt","a");
					 fputs("\n",fp);
					 fputs(ptr_bat[strike],fp);
					 fputs("\t",fp);
					 fprintf(fp,"%d",runs[strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",four[strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",six[strike]);
					 fclose(fp);
					 
					 					 
					 count1++;
					 fp=fopen("batting.txt","a");
					 fputs("\n",fp);
					 fputs(ptr_bat[non_strike],fp);
					 fputs("\t",fp);
					 fprintf(fp,"%d",runs[non_strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",four[non_strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",six[non_strike]);
					 fclose(fp);
			
			
		
								FILE  *fp1=fopen("remaining_batting.txt","a");
								for(int ii=count1;ii<8;ii++)
								{


											 fputs("\n",fp1);
											 fputs(second_team_players_name[ii],fp1);
											 fputs("\t",fp1);
											 fprintf(fp1,"%d",0);
											 fputs("\t",fp1);
											 fprintf(fp1,"%d",0);
											 fputs("\t",fp1);
											 fprintf(fp1,"%d",0);


								   }
								 fclose(fp1);
									FILE *source, *target;
									source = fopen("remaining_batting.txt", "r");
									target = fopen("batting.txt", "a");
									while( ( copy = fgetc(source) ) != EOF )
									{
											fputc(copy, target);
									}
									fclose(source);
									fclose(target);
									
									
									
									
									
									
									
									
									source = fopen("bowler.txt", "r");
									target = fopen("batting.txt", "a");
									fputs("\n\n \t\tBOWLER\n",target);
									while( ( copy = fgetc(source) ) != EOF )
									{
											fputc(copy, target);
									}
									fclose(source);
									fclose(target);
									
									getch();
									clrscr();
									printf("\n++++++++++++++++++++++++++");
									//getch();
									//getch();
									printf("\n\nTotal Score=%d / %d", total_run, total_wicket );
									printf("\n\n++++++++++++++++++++++++++");
									getch();
									
									fp=fopen("batting.txt","a");
									fputs("\n\nTOTAL SCORE : ",fp);
									fprintf(fp,"%d",total_run);
									fputs(" \\ ",fp);
									fprintf(fp,"%d",total_wicket);
									fclose(fp);
	}
	else
	{
		ptr_bat[strike]=team3_batsmen[0];
		ptr_bat[non_strike]=team3_batsmen[1];

		printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[non_strike]);
		printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[strike],six[non_strike]);
		//printf("Name\t\t\truns\twicket\n");
		//printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs,wkt);
		printf("Keep entering runs for 3 overs: ");

		for(int i=0;i<3;i++)
		{
			tot_wkts+=wkt;
			wkt=0;
			if(bowling_team==1)
			{
				ptr_bowl=team1_bowler[i];
			}
			else if(bowling_team==2)
			{
				ptr_bowl=team2_bowler[i];
			}
			for(int j=0;j<6;j++)
			{
				
				if((j+1)==6){
					
					total_ball=0;
				}
				else{
					
					total_ball=j+1;
					
				}
				if(tot_wkts==10)
				{
					printf("\n-----Batting over-----\n");
					getch();
					opp_batting(batting_team,bowling_team);

				}
				scanf("%d",&temp_runs);
				if(temp_runs == 0 || temp_runs == 1 || temp_runs == 2 || temp_runs == 3 || temp_runs == 4 || temp_runs == 6 ){
					
					total_run+=temp_runs;
				}
				if(temp_runs==1 || temp_runs==3)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
					if(strike==0)
					{	strike=1;
						non_strike=0;
					}
					else
					{
						strike=0;
						non_strike=1;
					}
				}
				else if(temp_runs==4)
				{
					clrscr();
					four[strike]++;
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else if(temp_runs==6)
				{
					clrscr();
					six[strike]++;
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}

				else if(temp_runs==2)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else if(temp_runs==-1)
				{
					clrscr();

					 total_wicket++;
					 count1++;
					 fp=fopen("batting.txt","a");
					 fputs("\n",fp);
					 fputs(ptr_bat[strike],fp);
					 fputs("\t",fp);
					 fprintf(fp,"%d",runs[strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",four[strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",six[strike]);
					 fclose(fp);
					
					
					wkt++;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
					
					runs[strike]=four[strike]=six[strike]=0;
					
					if(temp_stk<=7)
					{
						ptr_bat[strike]=team3_batsmen[temp_stk];
					}
					else
					{
						ptr_bat[strike]=team3_bowler[temp_bowl];
						temp_bowl++;
					}
					printf("New player is: %s\n",ptr_bat[strike]);
					printf("Other player is: %s\n",ptr_bat[non_strike]);
					runs[strike]=0;
					four[strike]=0;
					six[strike]=0;
					temp_stk++;
				}
				else if(temp_runs==0)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else
					printf("Enter valid runs\n");
					//--j;
			}
			//printf("Total runs after %d over= %d",i,tot_runs[i]);
			         fp=fopen("bowler.txt","a");
					 fputs("\n",fp);
					 fputs(ptr_bowl,fp);
					 fputs("\t",fp);
					 fprintf(fp,"%d",tot_runs[i]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",wkt);
					 fclose(fp);
					 wkt=0;
		}
		//printf("battong team 3");
		//ptr points to South Africa
					 count1++;
					 fp=fopen("batting.txt","a");
					 fputs("\n",fp);
					 fputs(ptr_bat[strike],fp);
					 fputs("\t",fp);
					 fprintf(fp,"%d",runs[strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",four[strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",six[strike]);
					 fclose(fp);
					 
					 					 
					 count1++;
					 fp=fopen("batting.txt","a");
					 fputs("\n",fp);
					 fputs(ptr_bat[non_strike],fp);
					 fputs("\t",fp);
					 fprintf(fp,"%d",runs[non_strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",four[non_strike]);
					 fputs("\t",fp);
					 fprintf(fp,"%d",six[non_strike]);
					 fclose(fp);
			
			
		
								FILE  *fp1=fopen("remaining_batting.txt","a");
								for(int ii=count1;ii<8;ii++)
								{


											 fputs("\n",fp1);
											 fputs(third_team_players_name[ii],fp1);
											 fputs("\t",fp1);
											 fprintf(fp1,"%d",0);
											 fputs("\t",fp1);
											 fprintf(fp1,"%d",0);
											 fputs("\t",fp1);
											 fprintf(fp1,"%d",0);


								   }
								 fclose(fp1);
									FILE *source, *target;
									source = fopen("remaining_batting.txt", "r");
									target = fopen("batting.txt", "a");
									while( ( copy = fgetc(source) ) != EOF )
									{
											fputc(copy, target);
									}
									fclose(source);
									fclose(target);
									
									
									
									
									
									
									
									
									source = fopen("bowler.txt", "r");
									target = fopen("batting.txt", "a");
									fputs("\n\n \t\tBOWLER\n",target);
									while( ( copy = fgetc(source) ) != EOF )
									{
											fputc(copy, target);
									}
									fclose(source);
									fclose(target);
									
									getch();
									clrscr();
									printf("\n++++++++++++++++++++++++++");
									//getch();
									//getch();
									printf("\n\nTotal Score=%d / %d", total_run, total_wicket );
									printf("\n\n++++++++++++++++++++++++++");
									getch();
									
									fp=fopen("batting.txt","a");
									fputs("\n\nTOTAL SCORE : ",fp);
									fprintf(fp,"%d",total_run);
									fputs(" \\ ",fp);
									fprintf(fp,"%d",total_wicket);
									fclose(fp);

	}
									/*
										getch();
										clrscr();
										printf("\n*****************************");
										//getch();
										getch();
										printf("\n\nTotal Score=%d / %d", total_run, total_wicket );
										printf("\n\n*****************************");
										getch();
									*/
	opp_batting(batting_team,bowling_team);
	getch();
}





void opp_batting(int old_team,int new_team)
{
	char *ptr_bat[2],*ptr_bowl;
	int over[3][6],runs[2]={0,0},wkt=0;
	static four[2]={0,0},six[2]={0,0};
	clrscr();
	printf("\n1. For 1 run");
	printf("\n2. For 2 runs");
	printf("\n3. For 3 runs");
	printf("\n4. For 4 runs");
	printf("\n6. For 6 runs");
	printf("\n-1. For out");
	getch();
	clrscr();
	int temp_runs;
//	int stk,nstk;
	static int temp_stk=2;
	static int temp_bowl=0,tot_wkts=0;
	int strike=0,non_strike=1,tot_runs[3]={0,0,0};
	printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
	if(new_team==1)
	{
		ptr_bat[strike]=team1_batsmen[0];
		ptr_bat[non_strike]=team1_batsmen[1];
		printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[non_strike]);
		printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[strike],six[non_strike]);
		//printf("Name\t\t\truns\twicket\n");
		//printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs,wkt);
		printf("Keep entering runs for 3 overs: ");

		for(int i=0;i<3;i++)
		{
			tot_wkts+=wkt;
			wkt=0;
			if(old_team==2)
			{
				ptr_bowl=team2_bowler[i];
			}
			else if(old_team==3)
			{
				ptr_bowl=team3_bowler[i];
			}
			for(int j=0;j<6;j++)
			{
				if(tot_wkts==10)
				{
					printf("\n-----Game over-----\n");
					getch();
					//opp_batting(my_team_no,opposite_team_no);
					exit(0);
				}
				scanf("%d",&temp_runs);
				if(temp_runs==1 || temp_runs==3)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
					if(strike==0)
					{	strike=1;
						non_strike=0;
					}
					else
					{
						strike=0;
						non_strike=1;
					}
				}
				else if(temp_runs==4)
				{
					clrscr();
					four[strike]++;
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else if(temp_runs==6)
				{
					clrscr();
					six[strike]++;
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}

				else if(temp_runs==2)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else if(temp_runs==-1)
				{
					clrscr();

					wkt++;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
					if(temp_stk<=7)
					{
						ptr_bat[strike]=team1_batsmen[temp_stk];
					}
					else
					{
						ptr_bat[strike]=team1_bowler[temp_bowl];
						temp_bowl++;
					}
					printf("New player is: %s\n",ptr_bat[strike]);
					printf("Other player is: %s\n",ptr_bat[non_strike]);
					runs[strike]=0;
					four[strike]=0;
					six[strike]=0;
					temp_stk++;
				}
				else if(temp_runs==0)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else
					printf("Enter valid runs\n");
					//--j;
			}
			//printf("Total runs after %d over= %d",i,tot_runs[i]);
		}
		//printf("In batting team 1");
		//ptr points to INDIA
	  }
	else if(new_team==2)
	{
		ptr_bat[strike]=team2_batsmen[0];
		ptr_bat[non_strike]=team2_batsmen[1];

		printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[non_strike]);
		printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[strike],six[non_strike]);
		//printf("Name\t\t\truns\twicket\n");
		//printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs,wkt);
		printf("Keep entering runs for 3 overs: ");

		for(int i=0;i<3;i++)
		{
			tot_wkts+=wkt;
			wkt=0;
			if(old_team==1)
			{
				ptr_bowl=team1_bowler[i];
			}
			else if(old_team==3)
			{
				ptr_bowl=team3_bowler[i];
			}
			for(int j=0;j<6;j++)
			{
				if(tot_wkts==10)
				{
					printf("\n-----Game over-----\n");
					getch();
				//	opp_batting(batting_team,bowling_team);

				}
				scanf("%d",&temp_runs);
				if(temp_runs==1 || temp_runs==3)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
					if(strike==0)
					{	strike=1;
						non_strike=0;
					}
					else
					{
						strike=0;
						non_strike=1;
					}
				}
				else if(temp_runs==4)
				{
					clrscr();
					four[strike]++;
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else if(temp_runs==6)
				{
					clrscr();
					six[strike]++;
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}

				else if(temp_runs==2)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else if(temp_runs==-1)
				{
					clrscr();

					wkt++;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
					if(temp_stk<=7)
					{
						ptr_bat[strike]=team2_batsmen[temp_stk];
					}
					else
					{
						ptr_bat[strike]=team2_bowler[temp_bowl];
						temp_bowl++;
					}
					printf("New player is: %s\n",ptr_bat[strike]);
					printf("Other player is: %s\n",ptr_bat[non_strike]);
					runs[strike]=0;
					four[strike]=0;
					six[strike]=0;
					temp_stk++;

				}
				else if(temp_runs==0)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else
					printf("Enter valid runs\n");
					//--j;
			}
			//printf("Total runs after %d over= %d",i,tot_runs[i]);
		}
		//printf("batting team 2");
		//ptr points to Pakistan
	}
	else
	{
		ptr_bat[strike]=team3_batsmen[0];
		ptr_bat[non_strike]=team3_batsmen[1];

		printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[non_strike]);
		printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[strike],six[non_strike]);
		//printf("Name\t\t\truns\twicket\n");
		//printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs,wkt);
		printf("Keep entering runs for 3 overs: ");

		for(int i=0;i<3;i++)
		{
			tot_wkts+=wkt;
			wkt=0;
			if(old_team==1)
			{
				ptr_bowl=team1_bowler[i];
			}
			else if(old_team==2)
			{
				ptr_bowl=team2_bowler[i];
			}
			for(int j=0;j<6;j++)
			{
				if(tot_wkts==10)
				{
					printf("\n-----Game over-----\n");
					getch();
				//	opp_batting(batting_team,bowling_team);

				}
				scanf("%d",&temp_runs);
				if(temp_runs==1 || temp_runs==3)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
					if(strike==0)
					{	strike=1;
						non_strike=0;
					}
					else
					{
						strike=0;
						non_strike=1;
					}
				}
				else if(temp_runs==4)
				{
					clrscr();
					four[strike]++;
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else if(temp_runs==6)
				{
					clrscr();
					six[strike]++;
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}

				else if(temp_runs==2)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else if(temp_runs==-1)
				{
					clrscr();

					wkt++;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
					if(temp_stk<=7)
					{
						ptr_bat[strike]=team3_batsmen[temp_stk];
					}
					else
					{
						ptr_bat[strike]=team3_bowler[temp_bowl];
						temp_bowl++;
					}
					printf("New player is: %s\n",ptr_bat[strike]);
					printf("Other player is: %s\n",ptr_bat[non_strike]);
					runs[strike]=0;
					four[strike]=0;
					six[strike]=0;
					temp_stk++;

				}
				else if(temp_runs==0)
				{
					clrscr();
					runs[strike]+=temp_runs;
					tot_runs[i]+=temp_runs;
					printf("Name\t\t\t\t\truns\t4's\t6's\n(S): ");
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[strike],runs[strike],four[strike],six[strike]);
					printf("%s\t\t\t%d\t%d\t%d\n",ptr_bat[non_strike],runs[non_strike],four[non_strike],six[non_strike]);
					printf("Name\t\t\t\t\truns\twicket\n");
					printf("Bowler: %s\t\t\t%d\t%d\n",ptr_bowl,tot_runs[i],wkt);
				}
				else
					printf("Enter valid runs\n");
					//--j;
			}
			//printf("Total runs after %d over= %d",i,tot_runs[i]);
		}
		//printf("battong team 3");
		//ptr points to South Africa
	}
	//opp_batting(my_team_no,opposite_team_no);
	getch();
}
