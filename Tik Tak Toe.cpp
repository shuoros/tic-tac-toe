//Tik Tak Toe.//
//Designed And Programmed By Soroush Shemshadi.//
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
char home[9]={'1','2','3','4','5','6','7','8','9'};
char temp1[9]={'1','2','3','4','5','6','7','8','9'};
char temp2[9]={'1','2','3','4','5','6','7','8','9'};
char temp3[9]={'1','2','3','4','5','6','7','8','9'};
char temp4[9]={'1','2','3','4','5','6','7','8','9'};
char temp5[9]={'1','2','3','4','5','6','7','8','9'};
int p1_score=0,p2_score=0,computer_score=0;
int round_winner=0;
int menu();
void intro_song()//This Function Play A Song For Us:).//
{
	Beep(300,500);
	sleep(0.05);
	Beep(300,500);
	sleep(0.05);
	Beep(300,500);
	sleep(0.05);
	
	Beep(250,500);
	sleep(0.05);		

	Beep(350,250);
	Beep(300,500);
	sleep(0.05);
	
	Beep(250,500);
	sleep(0.05);
	
	Beep(350,250);
	Beep(300,500);
	sleep(0.05);	
}
void start()//Here We Go. Start The Game Whit This Func And Say Hello To Our User.//
{
	cout<<endl<<" Hello!"<<endl;
	cout<<" Welcome To Tik Tak Toe :)"<<endl;
	intro_song();
	system("cls");
}
void round(string player1_name,string player2_name,int i)//This Function Show Us Witch Ruond We In It 
{                                                      //And Scores Of Players In Top Of Game Screen.//
	system("cls");
	cout<<"Round "<<i<<endl;
	if(i==5)
		cout<<"This Is The Last Round"<<endl;

	cout<<player1_name<<" : "<<p1_score<<" | ";
	if(player2_name=="AI")
		cout<<player2_name<<" : "<<computer_score<<endl;
	else
		cout<<player2_name<<" : "<<p2_score<<endl;			
}
void r_message(int i)//This Function Show Us Witch Round We In It
{     				//Befer That Round Start's And Freeze Program In
	system("cls"); //This Situation For 2 Seconds.//
	cout<<endl<<endl<<"     Round "<<i;
	sleep(2);
	system("cls");
}
void w_message(int i,string p1name,string p2name)//This Function Told Us The Round We Passed It
{												//Has Winner Or Not And Freeze Program In This
	system("cls");							   //Situation For 2 Seconds.// 		
	if(i>1)
	{
		if(round_winner==1)
		{
			cout<<endl<<endl<<"     Winner Of Round "<<i-1<<" Is"<<endl<<endl;
			cout<<"            "<<p1name;
		}
		else if(round_winner==2)
		{
			cout<<endl<<endl<<"     Winner Of Round "<<i-1<<" Is"<<endl<<endl;		
			cout<<"            "<<p2name;
		}
		else if(round_winner==0)
		{
			cout<<"        Game Is A Toe"<<endl<<endl;
			cout<<"     Round Has No Winner";
		}
		sleep(3);
	}
	system("cls");
}
const string currentdatetime()//This Function Returns The Date And Time.//
{
	time_t now=time(0);
	struct tm tstruct;
	char buf[80];
	tstruct=*localtime(&now);
	strftime(buf,sizeof(buf),"%Y-%m-%d.%X",&tstruct);
	return buf;
}
void mark(int player, int box)//This Function Give Two Int That The First One Wanna Tell The Function What Player Should be Mark
{                           //Him/Her And Second One Tell Witch Box Should Be mark On Game Board.//
	if (player==1)
	{
		home[box-1]='X';//'X' Allways For Player Num.1.//
	}
	else
		home[box-1]='O';//'O' Allways For Player Num.2.//	
}
void remark()//When A Round Or Game Finnished This Function Remark The Game board For A new Game.//
{
	home[0]='1';
	home[1]='2';
	home[2]='3';
	home[3]='4';
	home[4]='5';
	home[5]='6';
	home[6]='7';
	home[7]='8';
	home[8]='9';
}
int random(int min,int max)//This Function Produced A Random Int Number Between Two Numbers.//
{
	int randnum;
	srand(time(0));
	randnum=rand()%max+min;
	return randnum;
}
void game_board()//This Function Make Our Game Board For Us.//
{
	cout<<" ______________"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<home[0]<<" | "<<home[1]<<"  | "<<home[2]<<"  |"<<endl;
    cout<<"|____|____|____|"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<home[3]<<" | "<<home[4]<<"  | "<<home[5]<<"  |"<<endl;
    cout<<"|____|____|____|"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<home[6]<<" | "<<home[7]<<"  | "<<home[8]<<"  |"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<" --------------"<<endl;
}
void temp_mark(int i)//This Function Make A Temp For boards Of Each Round.//
{
	if(i==1)
	{
		for(int j=0; j<9 ;j++)
			temp1[j]=home[j];
	}
	if(i==2)
	{
		for(int j=0; j<9 ;j++)
			temp2[j]=home[j];
	}
	if(i==3)
	{
		for(int j=0; j<9 ;j++)
			temp3[j]=home[j];	
	}
	if(i==4)
	{
		for(int j=0; j<9 ;j++)
			temp4[j]=home[j];
	}
	if(i==5)
	{
		for(int j=0; j<9 ;j++)
			temp5[j]=home[j];
	}				
}
void temp_board()//This Function Shows The User/s Their Game Boardes After Finnishing The Game.//
{
	cout<<"Board Of First Round:"<<endl<<endl;
	cout<<" ______________"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp1[0]<<" | "<<temp1[1]<<"  | "<<temp1[2]<<"  |"<<endl;
    cout<<"|____|____|____|"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp1[3]<<" | "<<temp1[4]<<"  | "<<temp1[5]<<"  |"<<endl;
    cout<<"|____|____|____|"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp1[6]<<" | "<<temp1[7]<<"  | "<<temp1[8]<<"  |"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<" --------------"<<endl;
	cout<<endl<<"Board Of Second Round:"<<endl<<endl;
	cout<<" ______________"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp2[0]<<" | "<<temp2[1]<<"  | "<<temp2[2]<<"  |"<<endl;
    cout<<"|____|____|____|"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp2[3]<<" | "<<temp2[4]<<"  | "<<temp2[5]<<"  |"<<endl;
    cout<<"|____|____|____|"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp2[6]<<" | "<<temp2[7]<<"  | "<<temp2[8]<<"  |"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<" --------------"<<endl;
	cout<<endl<<"Board Of Third Round:"<<endl<<endl;
	cout<<" ______________"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp3[0]<<" | "<<temp3[1]<<"  | "<<temp3[2]<<"  |"<<endl;
    cout<<"|____|____|____|"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp3[3]<<" | "<<temp3[4]<<"  | "<<temp3[5]<<"  |"<<endl;
    cout<<"|____|____|____|"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp3[6]<<" | "<<temp3[7]<<"  | "<<temp3[8]<<"  |"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<" --------------"<<endl;	
	cout<<endl<<"Board Of 4TH Round:"<<endl<<endl;
	cout<<" ______________"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp4[0]<<" | "<<temp4[1]<<"  | "<<temp4[2]<<"  |"<<endl;
    cout<<"|____|____|____|"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp4[3]<<" | "<<temp4[4]<<"  | "<<temp4[5]<<"  |"<<endl;
    cout<<"|____|____|____|"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp4[6]<<" | "<<temp4[7]<<"  | "<<temp4[8]<<"  |"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<" --------------"<<endl;
	cout<<endl<<"Board Of 5TH Round:"<<endl<<endl;
	cout<<" ______________"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp5[0]<<" | "<<temp5[1]<<"  | "<<temp5[2]<<"  |"<<endl;
    cout<<"|____|____|____|"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp5[3]<<" | "<<temp5[4]<<"  | "<<temp5[5]<<"  |"<<endl;
    cout<<"|____|____|____|"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<"|  "<<temp5[6]<<" | "<<temp5[7]<<"  | "<<temp5[8]<<"  |"<<endl;
    cout<<"|    |    |    |"<<endl;
    cout<<" --------------"<<endl;					
}
int chek_box(int box)//This Function Check That Our User Don't Enter An Invaild Number For Mark Boxs Of Game Board.//
{
	switch(box)
	{
		case 1:{
			return 1;
			break;
		}
		case 2:{
			return 1;
			break;
		}
		case 3:{
			return 1;
			break;
		}
		case 4:{
			return 1;
			break;
		}
		case 5:{
			return 1;
			break;
		}
		case 6:{
			return 1;
			break;
		}
		case 7:{
			return 1;
			break;
		}
		case 8:{
			return 1;
			break;
		}
		case 9:{
			return 1;
			break;
		}
		default:{
			return 0;
			break;
		}
	}
}
int chek_winner()//This Function Find The Winner If He/She Exist Whit Check some Special Condition On Game Board.//
{
		//The Func Check That If Three Row Column Or Diagonal Row Exsit With Same Mark <<'X'/'O'>> Return The User Whit That Mark 
		//The Winner Of Game.//
		if (home[0]==home[1] && home[1]==home[2])
		{	if (home[0]=='X')			
			return 1;
			else
			return 2; 
		}		
		else if(home[3]==home[4] && home[4]==home[5])
			{
				if(home[3]=='X')			
				return 1;
				else
				return 2; 
			}
		else if(home[6]==home[7] && home[7]==home[8])
			{
				if(home[6]=='X')			
				return 1;
				else
				return 2; 
			}
		else if(home[0]==home[3] && home[3]==home[6])
			{
				if (home[0]=='X')			
				return 1;
				else
				return 2; 
			}
		else if(home[1]==home[4] && home[4]==home[7])
			{
				if(home[1]=='X')			
				return 1;
				else
				return 2; 
			}
		else if(home[2]==home[5] && home[5]==home[8])
			{
				if(home[2]=='X')			
				return 1;
				else
				return 2; 
			}
		else if(home[0]==home[4] && home[4]==home[8])
			{
				if (home[0]=='X')			
				return 1;
				else
				return 2; 
			}
		else if(home[2]==home[4] && home[4]==home[6])
			{
				if (home[2]=='X')			
				return 1;
				else
				return 2; 
			}
		else if(home[0]==home[3] && home[3]==home[6])
			{
				if(home[0]=='X')			
				return 1;
				else
				return 2; 
			}
	else
		return 0;			
}
void computer(int box,int j)//Here We Make A Functions That Control The Computer Moves In Game.//
{
	sleep(0.9);
	int rand;
	if(j==1)//Conditions For First Move.//
	{
		if(box==5)
		{
			do
			{
				rand=random(1,9);
			}while(rand==5);
			mark(2,rand);			
		}
		else
		{
			mark(2,5);
		}
	}
	else//Here The Things Of After First Move Happends.//
	{
		//Conditions For Fill The Third Home And Win The Game.//
		//Here We Say When You Find Two Home That Fill With 'O' Fill The Third Home So That 
		//Three Home In A Row Or Coloumn Or Diagonal Row  Fil;ed With 'O'.//
		//Row 1//
		 if(home[0]=='O' && home[1]=='O' && home[2]!='X')
		{
			mark(2,3);
		}
		else if(home[1]=='O' && home[2]=='0' && home[0]!='X')
		{
			mark(2,1);
		}
		else if(home[0]=='O' && home[2]=='O' && home[1]!='X')
		{
			mark(2,2);
		}
		//Row 2//
		else if(home[3]=='O' && home[4]=='O' && home[5]!='X')
		{
			mark(2,6);
		}
		else if(home[4]=='O' && home[5]=='O' && home[3]!='X')
		{
			mark(2,4);
		}
		else if(home[3]=='O' && home[5]=='O' && home[4]!='X')
		{
			mark(2,5);
		}
		//Row 3//
		else if(home[6]=='O' && home[7]=='O' && home[8]!='X')
		{
			mark(2,9);
		}
		else if(home[7]=='O' && home[8]=='O' && home[6]!='X')
		{
			mark(2,7);
		}
		else if(home[6]=='O' && home[8]=='O' && home[7]!='X')
		{
			mark(2,8);
		}
		//Coloumn 1//
		else if(home[0]=='O' && home[3]=='O' && home[6]!='X')
		{
			mark(2,7);
		}
		else if(home[3]=='O' && home[6]=='O' && home[0]!='X')
		{
			mark(2,1);
		}
		else if(home[0]=='O' && home[6]=='O' && home[3]!='X')
		{
			mark(2,4);
		}
		//Coloumn 2//
		else if(home[1]=='O' && home[4]=='O' && home[7]!='X')
		{
			mark(2,8);
		}
		else if(home[4]=='O' && home[7]=='O' && home[1]!='X')
		{
			mark(2,2);
		}
		else if(home[1]=='O' && home[7]=='O' && home[4]!='X')
		{
			mark(2,5);
		}
		//Coloumn 3//
		else if(home[2]=='O' && home[5]=='O' && home[8]!='X')
		{
			mark(2,9);
		}
		else if(home[5]=='O' && home[8]=='O' && home[2]!='X')
		{
			mark(2,3);
		}
		else if(home[2]=='O' && home[8]=='O' && home[5]!='X')
		{
			mark(2,6);
		}			
		//Diagonal Row 1//
		else if(home[0]=='O' && home[4]=='O' && home[8]!='X')
		{
			mark(2,9);
		}
		else if(home[4]=='O' && home[8]=='O' && home[0]!='X')
		{
			mark(2,1);
		}
		else if(home[0]=='O' && home[8]=='O' && home[4]!='X')
		{
			mark(2,5);
		}
		//Diagonal Row 2//
		else if(home[2]=='O' && home[4]=='O' && home[6]!='X')
		{
			mark(2,7);
		}
		else if(home[4]=='O' && home[6]=='O' && home[2]!='X')
		{
			mark(2,3);
		}
		else if(home[2]=='O' && home[6]=='O' && home[4]!='X')
		{
			mark(2,5);
		}
		//Here Are Some Conditions For When The User Has Two Homes Next To Each Other And With Another Choice Can Win The Game.//
		else if(home[0]=='X' && home[1]=='X' && home[2]=='3')
		{
			mark(2,3);
		}
		else if(home[1]=='X' && home[2]=='X' && home[0]=='1')
		{
			mark(2,1);
		}
		else if(home[0]=='X' && home[2]=='X' && home[1]=='2')
		{
			mark(2,2);
		}
		//Row 2//
		else if(home[3]=='X' && home[4]=='X' && home[5]=='6')
		{
			mark(2,6);
		}
		else if(home[4]=='X' && home[5]=='X' && home[3]=='4')
		{
			mark(2,4);
		}
		else if(home[3]=='X' && home[5]=='X' && home[4]=='5')
		{
			mark(2,5);
		}
		//Row 3//
		else if(home[6]=='X' && home[7]=='X' && home[8]=='9')
		{
			mark(2,9);
		}
		else if(home[7]=='X' && home[8]=='X' && home[6]=='7')
		{
			mark(2,7);
		}
		else if(home[6]=='X' && home[8]=='X' && home[7]=='8')
		{
			mark(2,8);
		}
		//Coloumn 1//
		else if(home[0]=='X' && home[3]=='X' && home[6]=='7')
		{
			mark(2,7);
		}
		else if(home[3]=='X' && home[6]=='X' && home[0]=='1')
		{
			mark(2,1);
		}
		else if(home[0]=='X' && home[6]=='X' && home[3]=='4')
		{
			mark(2,4);
		}
		//Coloumn 2//
		else if(home[1]=='X' && home[4]=='X' && home[7]=='8')
		{
			mark(2,8);
		}
		else if(home[4]=='X' && home[7]=='X' && home[1]=='2')
		{
			mark(2,2);
		}
		else if(home[1]=='X' && home[7]=='X' && home[4]=='5')
		{
			mark(2,5);
		}
		//Coloumn 3//
		else if(home[2]=='X' && home[5]=='X' && home[8]=='9')
		{
			mark(2,9);
		}
		else if(home[5]=='X' && home[8]=='X' && home[2]=='3')
		{
			mark(2,3);
		}
		else if(home[2]=='X' && home[8]=='X' && home[5]=='6')
		{
			mark(2,6);
		}			
		//Diagonal Row 1//
		else if(home[0]=='X' && home[4]=='X' && home[8]=='9')
		{
			mark(2,9);
		}
		else if(home[4]=='X' && home[8]=='X' && home[0]=='1')
		{
			mark(2,1);
		}
		else if(home[0]=='X' && home[8]=='X' && home[4]=='5')
		{
			mark(2,5);
		}
		//Diagonal Row 2//
		else if(home[2]=='X' && home[4]=='X' && home[6]=='7')
		{
			mark(2,7);
		}
		else if(home[4]=='X' && home[6]=='X' && home[2]=='3')
		{
			mark(2,3);
		}
		else if(home[2]=='X' && home[6]=='X' && home[4]=='5')
		{
			mark(2,5);
		}
		else
		{
			do
			{
				rand=random(1,9);
			}while(home[rand-1]=='X' || home[rand-1]=='O');
			mark(2,rand);
		}
	}
}
void sologame(string player1_name,string player2_name,int i)//This Function Perform The One Player Section.//
{
	int player1=1,player2=2;
	int rand,box,result,exc=0;
	rand=random(1,2);//We Produse A Random Number Between 1 And 2 To Determine That Who Should Start The Game First Or Second Player.//
	if(rand==1)
	{
		for(int j=1; j<5 ;j++)//Run Each Round 4 Times Because Each Player Have 4 Moves.//
		{
			cout<<"**You Can Enter 0 To Back To The Main Menu**";
			cout<<endl<<player1_name<<" Enter The Box You Want: ";
			cin>>box;
			Beep(723,150);
			if(box==0)
			{
				system("cls");
				menu();
			}
			while(home[box-1]=='X' || home[box-1]=='O')//If A Box Choose Before This While Get Box Number Again From User.//
			{
				if(home[box-1]=='X')
				{
					Beep(1023,550);
					cout<<"You Choose This Box Before"<<endl<<"Please Enter Another Box Number: ";
					cin>>box;
					Beep(723,150);
				}
				else if(home[box-1]=='O')
				{
					Beep(1023,550);
					cout<<"Computer Choose This Box Before"<<endl<<"Please Enter Another Box Number: ";
					cin>>box;
					Beep(723,150);
				}
			}
			while(chek_box(box)==0)
			{
				Beep(1023,550);
				cout<<"You Entered A Undefined Number"<<endl<<"Please Enter A Vaild Number: ";
				cin>>box;
				Beep(723,150);				
			}
			mark(player1,box);
			round(player1_name,player2_name,i);
			game_board();
			result=chek_winner();
			if(result==1)//If We Have A Winner His/Her's Score Increased And Game Goes To Next Round.//
			{
				p1_score++;
				round_winner=1;
				exc=1;			
				break;
			}
			else if(result==2)
			{
				computer_score++;
				round_winner=2;
				exc=1;			
				break;
			}

			computer(box,j);
			Beep(823,150);
			round(player1_name,player2_name,i);
			game_board();
			result=chek_winner();
			if(result==1)
			{
				p1_score++;
				round_winner=1;
				exc=1;			
				break;
			}
			else if(result==2)
			{
				computer_score++;
				round_winner=2;
				exc=1;			
				break;
			}			
		}
		if(exc==0)
			cout<<endl<<"Game Has No Winner";		
	}
	else if(rand==2)
	{
		for(int j=1; j<5 ;j++)
		{
			computer(box,j);
			Beep(823,150);
			round(player1_name,player2_name,i);
			game_board();
			result=chek_winner();
			if(result==1)
			{
				p1_score++;
				round_winner=1;
				exc=1;			
				break;
			}
			else if(result==2)
			{
				computer_score++;
				round_winner=2;
				exc=1;			
				break;
			}
			cout<<"**You Can Enter 0 To Back To The Main Menu**";
			cout<<endl<<player1_name<<" Enter The Box You Want: ";
			cin>>box;
			Beep(723,150);
			if(box==0)
			{
				system("cls");
				menu();
			}			
			while(home[box-1]=='X' || home[box-1]=='O')
			{
				if(home[box-1]=='X')
				{
					Beep(1023,550);
					cout<<"You Choose This Box Before"<<endl<<"Please Enter Another Box Number: ";
					cin>>box;
					Beep(723,150);
				}
				else if(home[box-1]=='O')
				{
					Beep(1023,550);
					cout<<"Computer Choose This Box Before"<<endl<<"Please Enter Another Box Number: ";
					cin>>box;
					Beep(723,150);
				}
			}
			while(chek_box(box)==0)
			{
				Beep(1023,550);
				cout<<"You Entered A Undefined Number"<<endl<<"Please Enter A Vaild Number: ";
				cin>>box;
				Beep(723,150);				
			}						
			mark(player1,box);
			round(player1_name,player2_name,i);
			game_board();
			result=chek_winner();
			if(result==1)
			{
				p1_score++;
				round_winner=1;
				exc=1;			
				break;
			}
			else if(result==2)
			{
				computer_score++;
				round_winner=2;
				exc=1;			
				break;
			}			
		}
		if(exc==0)
			cout<<endl<<"Game Has No Winner";		
	}
	temp_mark(i);	
}
void game(string player1_name,string player2_name,int i)//This Function Perform The Multy Player Section.//
{									//All The Functions Of This Function Are Simillar To The Pervious Function.//		
	int player1=1,player2=2;
	int rand,box,result,exc=0;
	rand=random(1,2);
	if(rand==1)
	{
		for(int j=1; j<5 ;j++)
		{
			cout<<"**You Can Enter 0 To Back To The Main Menu**";
			cout<<endl<<player1_name<<" Enter The Box You Want: ";
			cin>>box;
			Beep(723,150);
			if(box==0)
			{
				system("cls");
				menu();
			}			
			while(home[box-1]=='X' || home[box-1]=='O')
			{
				if(home[box-1]=='X')
				{
					Beep(1023,550);
					cout<<"You Choose This Box Before"<<endl<<"Please Enter Another Box Number: ";
					cin>>box;
					Beep(723,150);
				}
				else if(home[box-1]=='O')
				{
					Beep(1023,550);
					cout<<player2_name<<" Choose This Box Before"<<endl<<"Please Enter Another Box Number: ";
					cin>>box;
					Beep(723,150);
				}
			}			
			while(chek_box(box)==0)
			{
				Beep(1023,550);
				cout<<"You Entered A Undefined Number"<<endl<<"Please Enter A Vaild Number: ";
				cin>>box;
				Beep(723,150);				
			}						
			mark(player1,box);
			round(player1_name,player2_name,i);
			game_board();
			result=chek_winner();
			if(result==1)
			{
				p1_score++;
				round_winner=1;
				exc=1;			
				break;
			}
			else if(result==2)
			{
				p2_score++;
				round_winner==2;
				exc=1;			
				break;
			}
			cout<<"**You Can Enter 0 To Back To The Main Menu**";
			cout<<endl<<player2_name<<" Enter The Box You Want: ";
			cin>>box;
			Beep(723,150);
			if(box==0)
			{
				system("cls");
				menu();
			}			
			while(home[box-1]=='X' || home[box-1]=='O')
			{
				if(home[box-1]=='O')
				{
					Beep(1023,550);
					cout<<"You Choose This Box Before"<<endl<<"Please Enter Another Box Number: ";
					cin>>box;
					Beep(723,150);
				}
				else if(home[box-1]=='X')
				{
					Beep(1023,550);
					cout<<player1_name<<" Choose This Box Before"<<endl<<"Please Enter Another Box Number: ";
					cin>>box;
					Beep(723,150);
				}
			}			
			while(chek_box(box)==0)
			{
				Beep(1023,550);
				cout<<"You Entered A Undefined Number"<<endl<<"Please Enter A Vaild Number: ";
				cin>>box;
				Beep(723,150);				
			}							
			mark(player2,box);
			round(player1_name,player2_name,i);
			game_board();
			result=chek_winner();
			if(result==1)
			{
				p1_score++;
				round_winner=1;
				exc=1;			
				break;
			}
			else if(result==2)
			{
				p2_score++;
				round_winner=2;
				exc=1;			
				break;
			}
		}
		if(exc==0)
		cout<<endl<<"Game Has No Winner";
	}
	else if(rand==2)
	{
		for(int j=1; j<5 ;j++)
		{
			cout<<"**You Can Enter 0 To Back To The Main Menu**";
			cout<<endl<<player2_name<<" Enter The Box You Want: ";
			cin>>box;
			Beep(723,150);
			if(box==0)
			{
				system("cls");
				menu();
			}			
			while(home[box-1]=='X' || home[box-1]=='O')
			{
				if(home[box-1]=='O')
				{
					Beep(1023,550);
					cout<<"You Choose This Box Before"<<endl<<"Please Enter Another Box Number: ";
					cin>>box;
					Beep(723,150);
				}
				else if(home[box-1]=='X')
				{
					Beep(1023,550);
					cout<<player1_name<<" Choose This Box Before"<<endl<<"Please Enter Another Box Number: ";
					cin>>box;
					Beep(723,150);
				}
			}		
			while(chek_box(box)==0)
			{
				Beep(1023,550);
				cout<<"You Entered A Undefined Number"<<endl<<"Please Enter A Vaild Number: ";
				cin>>box;
				Beep(723,150);				
			}								
			mark(player2,box);
			round(player1_name,player2_name,i);
			game_board();
			result=chek_winner();
			if(result==1)
			{
				p1_score++;
				round_winner=1;
				exc=1;			
				break;
			}
			else if(result==2)
			{
				p2_score++;
				round_winner=2;
				exc=1;			
				break;
			}
			cout<<"**You Can Enter 0 To Back To The Main Menu**";
			cout<<endl<<player1_name<<" Enter The Box You Want: ";
			cin>>box;
			Beep(723,150);
			if(box==0)
			{
				system("cls");
				menu();
			}			
			while(home[box-1]=='X' || home[box-1]=='O')
			{
				if(home[box-1]=='X')
				{
					Beep(1023,550);
					cout<<"You Choose This Box Before"<<endl<<"Please Enter Another Box Number: ";
					cin>>box;
					Beep(723,150);
				}
				else if(home[box-1]=='O')
				{
					Beep(1023,550);
					cout<<player2_name<<" Choose This Box Before"<<endl<<"Please Enter Another Box Number: ";
					cin>>box;
					Beep(723,150);
				}
			}		
			while(chek_box(box)==0)
			{
				Beep(1023,550);
				cout<<"You Entered A Undefined Number"<<endl<<"Please Enter A Vaild Number: ";
				cin>>box;
				Beep(723,150);				
			}						
			mark(player1,box);
			round(player1_name,player2_name,i);
			game_board();
			result=chek_winner();
			if(result==1)
			{
				p1_score++;
				round_winner=1;
				exc=1;			
				break;
			}
			else if(result==2)
			{
				p2_score++;
				round_winner=2;
				exc=1;			
				break;
			}						
		}
		if(exc==0)
		cout<<endl<<"Game Has No Winner";		
	}
	temp_mark(i);
}
int main()//The Main Function.//
{
	system("Color 0E");//Set The Color Of Texts To Yellow.//
	start();
	cout<<" Enter 0 To Enter The Game: ";
	int n;
	cin>>n;
	Beep(723,150);
	switch(n)
	{
		case 0:
			system("cls");
			menu();
		break;	
	}
return 0;	
}
int menu()//This Is Our Menu Function.//
{
	cout<<endl<<" Please Enter The Number Of Operations You Want:"<<endl<<endl;
	cout<<"1.Game"<<endl<<endl<<"2.Winners"<<endl<<endl<<"3.Info"<<endl<<endl<<"0.Exit"<<endl<<endl;
	int n;
	cout<<"You Choose: ";
	cin>>n;
	Beep(723,150);
	switch(n)
	{
		case 0:
			system("cls");
			return 0;
		break;
		case 3://Some Informations About This Program.//
			{
				system("cls");
				cout<<endl<<"This Game Is Final Project Of Fundamental Programming Course Presented By Dr.Shekarian."<<endl<<"This Project Designed And Programmed By Soroush Mehrad, Student Of University Of Guilan In 2017."<<endl<<endl;
				cout<<"Enter 0 To Back: ";
				int n4;
				cin>>n4;
				Beep(723,150);
				switch(n4)
					{
						case 0:
							system("cls");
							menu();
						break;
					}
			break;
			}
			
		case 2://Show Us The Winners Of Last Games That Played.//
			{
				system("cls");
				string in,date,playername,pplayername,ppplayername,Winner,Between,And,Is,scores,ppppname,ppppscore,pppppname,pppppscore,line;
				fstream input_file("winners.txt",ios::in);
				while(input_file>>in>>date>>Winner>>Between>>playername>>And>>pplayername>>Is>>ppplayername>>scores>>ppppname>>ppppscore>>line>>pppppname>>pppppscore)
				{
					cout<<endl<<in<<" "<<date<<" "<<Winner<<" "<<Between<<" "<<playername<<" "<<And<<" "<<pplayername<<" "<<Is<<" "<<ppplayername<<" "<<scores<<" "<<ppppname<<" "<<ppppscore<<" "<<line<<" "<<pppppname<<" "<<pppppscore<<endl;
				}
				cout<<endl<<"Enter 0 To Back: ";
				int n2;
				cin>>n2;
				Beep(723,150);
				switch(n2)
				{
					case 0:
					{
						system("cls");
						menu();
						break;
					}
				}
			break;	
			}			
		case 1://Main Part Of Menu.//
		{
			
			system("cls");
			cout<<endl<<" Please Enter The Number Of Operation You Want:"<<endl<<endl;
			cout<<"1.One Player"<<endl<<endl<<"2.Multy Player"<<endl<<endl<<"0.Back"<<endl<<endl<<"You Choose: ";
			int n1;
			cin>>n1;
			Beep(723,150);
			switch(n1)
			{
				case 0:
					{
						system("cls");
						menu();
						break;
					}
				case 1://One Player Section.//
					{
	
					system("cls");
					cout<<" Player Please Enter Your Name: ";
					string p_name;
					cin>>p_name;
					Beep(723,150);
					string computer_name;
					computer_name="AI";
					for(int i=1; i<=5 ;i++)
					{
						w_message(i,p_name,computer_name);													
						r_message(i);
						round(p_name,computer_name,i);
						game_board();
						sologame(p_name,computer_name,i);
						remark();	
					}
					system("cls");
					cout<<endl<<"The Game Is Finished";
					sleep(2);
					system("cls");
					cout<<endl<<endl<<"    "<<p_name<<": "<<p1_score<<" | "<<computer_name<<": "<<computer_score;
					sleep(2);
					system("cls");
					if(p1_score>computer_score)
					{
						cout<<p_name<<" You Are Win The Game :)))"<<endl<<endl;
						cout<<"You Can Defeat Computer :))"<<endl;
						fstream output_file("winners.txt",ios::out | ios::app);
						output_file<<"In "<<currentdatetime()<<" Winner Between "<<p_name<<" And Computer Is: "<<p_name<<" scores: "<<p_name<<": "<<p1_score<<" | "<<"Computer: "<<computer_score<<endl;
					}
					else
					{
						cout<<p_name<<" You Are Loose :(("<<endl;
						cout<<"You Can't Win The Computer."<<endl;
						fstream output_file("winners.txt",ios::out | ios::app);
						output_file<<"In "<<currentdatetime()<<"Winner Between "<<p_name<<" And Computer Is: Computer"<<endl;						
					}
					cout<<endl<<"1.Show Game Boards"<<endl<<endl<<"0.back"<<endl<<endl<<"You Choose: ";
					int n5;
					cin>>n5;
					Beep(723,150);
					switch(n5)
					{
						case 0:
							system("cls");
							menu();
						break;
						case 1:
							system("cls");
							temp_board();
							cout<<"Enter 0 To Back To Menu: ";
							int n9;
							cin>>n9;
							Beep(723,150);
							switch(n9)
							{
								case 0: {
									system("cls");
									menu();
									break;
								}
							}							
						break;	
					}					
					break;	
					}
				case 2://Multy Player Section.//
					{
					system("cls");
					cout<<"player 1 Please Enter Your Name: ";
					string player1_name;
					cin>>player1_name;
					Beep(723,150);
					cout<<endl<<"player 2 Please Enter Your Name: ";
					string player2_name;
					cin>>player2_name;
					Beep(723,150);
					for(int i=1; i<=5 ;i++)
					{
					w_message(i,player1_name,player2_name);							
					r_message(i);
					round(player1_name,player2_name,i);					
					game_board();
					game(player1_name,player2_name,i);
					remark();
					}
					system("cls");
					cout<<endl<<"    The Game Is Finished";
					sleep(2);
					system("cls");
					cout<<endl<<endl<<"    "<<player1_name<<": "<<p1_score<<" | "<<player2_name<<": "<<p2_score;
					sleep(2);
					system("cls");
					if(p1_score>p2_score)
					{
						cout<<player1_name<<" You Are Win The Game :)))"<<endl<<endl;
						cout<<player2_name<<" You Are Loose :(("<<endl;
						fstream output_file("winners.txt",ios::out | ios::app);
						output_file<<"In "<<currentdatetime()<<" Winner Between "<<player1_name<<" And "<<player2_name<<" Is: "<<player1_name<<" scores: "<<player1_name<<": "<<p1_score<<" | "<<player2_name<<": "<<p2_score<<endl;
					}
					else
					{
						cout<<player2_name<<" You Are Win The Game :)))"<<endl<<endl;
						cout<<player1_name<<" You Are Loose :(("<<endl;
						fstream output_file("winners.txt",ios::out | ios::app);
						output_file<<"In "<<currentdatetime()<<" Winner Between "<<player1_name<<" And "<<player2_name<<" Is: "<<player2_name<<" scores: "<<player1_name<<": "<<p1_score<<" | "<<player2_name<<": "<<p2_score<<endl;						
					}
					cout<<endl<<"1.Show Game Boards"<<endl<<endl<<"0.back"<<endl<<endl<<"You Choose: ";
					int n2;
					cin>>n2;
					Beep(723,150);
					switch(n2)
					{
						case 0:
							{
							
								system("cls");
								menu();
							break;
							}
						case 1:
							{
								system("cls");
								temp_board();
								cout<<"Enter 0 To Back To Menu: ";
								int n8;
								cin>>n8;
								Beep(723,150);
								switch(n8)
								{
									case 0: {
										system("cls");
										menu();
										break;
									}
								}
							break;	
							}		
					}
					break;	
					}
			}
		break;
		}
	}
}
