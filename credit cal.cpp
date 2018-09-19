#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include"windows.h"
using namespace std;
/* function definition for setting cursor position in the console window*/
void gotoxy(int x,int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
/*Class definition */
class applicant
{
	/*defining data members for storing applicant details*/
	string name;
	int age;
	string address;
	int m_sal;
	int h_loan;
	int p_loan;
	int no_chq_bounce;
	char own_house;
	char spouse_working;
	char dependent_parents;
	int company_tier;
	
	public:
		/*class function declaration*/
		void get_data();
		int calc_liability();
		void display_score();
};

void applicant ::get_data()
{
	system("cls");
	cout<<"name of applicant"<<endl;
	cin>>name;
	cout<<endl<<"age="<<endl;
	cin>>age;
	cin.clear();
	cin.ignore(1000,'\n');
	cout<<"address"<<endl;
	getline(cin,address);
	cin.clear();
	cin.ignore(1000,'\n');
	cout<<"monthly salary="<<endl;
	cin>>m_sal;
	cout<<"total home loan EMI"<<endl;
	cin>>h_loan;
	cout<<"total personal loan EMI"<<endl;
	cin>>p_loan;
	cout<<"number of cheque bounces in last six months="<<endl;
	cin>>no_chq_bounce;
	cout<<"own house? (y or n)"<<endl;
	cin>>own_house;
	cout<<"Spouse working? (y or n)?"<<endl;
	cin>>spouse_working;
	cout<<"dependent parents?(y or n)"<<endl;
	cin>>dependent_parents;
	cout<<"company tier?(y or n)"<<endl;
	cin>>company_tier;
}
/*function for calculting credit score*/
int applicant ::calc_liability()
{
		int score=0;
		int liability;
		if(age>22 && age<=30)
			score=score+2;
		else if(age>30 && age<=35)
			score=score+1;
		else 
		score=score-1;
	liability=h_loan+p_loan;
	if(liability <=(m_sal/4))
	score=score+5;
	if(liability> m_sal/4 && liability <= m_sal/3)
	score=score+3;
	if(liability>m_sal/3 && liability <= m_sal/2)
	score=score+1;
	if(liability >m_sal/2)
	score=score-1;
	if(no_chq_bounce>1)
	score=score-2;
	if(no_chq_bounce==1)
	score=score-1;
	if(no_chq_bounce==0)
	score=score+1;
	if(p_loan >h_loan)
	score=score-1;
	else
	score=score+1;
	if(own_house=='y')
	score=score+1;
	if(spouse_working=='y')
	score=score+1;
	if(dependent_parents=='y')
	score=score-1;
	else
	score=score+1;
	if(company_tier==1)
	score=score+3;
	if(company_tier==2)
	score=score+2;
	else
	score=score+1;
	
	return (score);
}
/*function for displaying credit score and applicant rating*/
void applicant::display_score()
{
	int sc=calc_liability();/*calling calc_liability() function to calculate applicant's credit score*/
	system("cls");
	/*displaying results*/
	if(sc>9)
	cout<<"the applicant="<<name<<"\n is at low risk.\n credit score="<<sc<<"\n credit can be given";
	else
	{
		if(sc>5&&sc<=9)
		cout<<"the applicant="<<name<<"\n is at average risk.\n credit score="<<sc<<"\n credit can be given with due precaution";
		else
		cout<<"the applicant="<<name<<"\n is at high risk.\ncredit score="<<sc<<"\n credit can not be given";
	 } 
	 
}
int main()
{
	char flag='f';
	applicant a;
	char ch;
	while(1)
	{
		system("cls");
		gotoxy(31,8);
		cout<<"credit calc";
		gotoxy(31,9);
		cout<<"_________";
		gotoxy(22,12);
		cout<<"1-enter loan applicant's details";
		gotoxy(22,13);
		cout<<"2-display credit score";
		gotoxy(22,14);
		cout<<"3-exit";
		gotoxy(22,16);
		cout<<"select an option by taping the numeric code=";
		ch=getch();
		switch(ch)
		{
			case('1'):
			{
				a.get_data();
				flag='t';
				break;
			}
			case('2'):
			{
				if(flag=='f')
				{
					gotoxy(22,18);
					cout<<"loan applicant's details not yet entered !press any key to continue...";
					getch();
				}
				else
				a.display_score();
				break;
			}
			case('3'):
			{
				exit(1);
				break;
			}
			default:
				{
					gotoxy(22,18);
					cout<<"invalid choice! press any key to continue..";
					getch();
				}
				
		}
		getch();
	}
}
