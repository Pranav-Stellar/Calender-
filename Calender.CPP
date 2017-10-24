#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>
class date
{
	private:
		int dd,mm,yy;
	public:
		date()
		{
			this->dd=1;
			this->mm=1;
			this->yy=1;
		}
		date(int D,int M=1,int Y =2016)
		{
			this->dd=D;
			this->mm=M;
			this->yy=Y;
		}
		int valid()
		{
			if(this->dd<=0 || this->mm<=0 || this->yy<=0)
			return 0;
			else if (this->mm>12)
				return 0;
			else if(this->yy>0)
			{
				if(this->mm==1 || this->mm==3 || this->mm==5 || this->mm==7 || this->mm==8 || this->mm==10 || this->mm==12)

				{
					if(this->dd>=1 && this->dd<=31)
						return 1;
					else
						return 0;
				}
				else if(this->mm==4 || this->mm==6 ||this->mm==9 || this->mm==11)

				{
					if(this->dd>=1 && this->dd<=30)
						return 1;
					else
						return 0;
				}
				else
				{
					if(this->yy%4==0 && this->yy%100!=0 || this->yy%400==0)
					{
						if (this->dd>=1 && this->dd<=29)
						{
							return 1;

						}
						else
							return 0;
					}
					else
					{
						if (this->dd>=1 && this->dd<=28)
							return 1;
						else
							return 0;
					}
				}


			}

		}
			date add()
		{
			date temp;
			if (mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
			{
				temp.dd=this->dd+5;
				temp.mm=this->mm;
				temp.yy=this->yy;
				if (temp.dd>31)
				{
					temp.dd=temp.dd-31;
					temp.mm=temp.mm+1;


					if(mm==12)
					{
						temp.yy=temp.yy+1;
						temp.mm=1;
					}
				}
			}
			else if (mm==4||mm==6||mm==9||mm==11)
			{
				temp.dd=this->dd+5;
				temp.mm=this->mm;
				temp.yy=this->yy;
				if (temp.dd>30)
				{
					temp.dd=temp.dd-30;
					temp.mm=temp.mm+1;
				}

			}
			else if (mm==2)
			{
				temp.dd=this->dd+5;
				temp.mm=this->mm;
				temp.yy=this->yy;
				if (yy%4==0 && yy%100!=0 ||yy/400==0)
				{

					if(temp.dd>29)
					{

						temp.dd=temp.dd-29;
						temp.mm=temp.mm+1;
					}
				}
				else
				{
					if (temp.dd>28)
					{
						temp.dd=temp.dd-28;
						temp.mm=temp.mm+1;
					}
				}
			}
			return temp;

		}
		void display()
		{
		       //	cout<<endl<<"New Date -> "<<this->dd<<"/"<<this->mm<<"/"<<this->yy;
			char hor=196,ver=179;
			int i;
			char buffer[15];
			gotoxy(28,8);

			for (i=0;i<=41;i++)
			{
				cout<<hor;
			}
			for (i=0;i<=16;i++)
			{
				gotoxy(70,8+i);
				cout<<ver;
			}
			gotoxy(28,9);
			cout<<"\t\t     Calender";
			gotoxy(28,10);
		       cout<<"\t\t    "<<this->dd<<"/"<<this->mm<<"/"<<this->yy;
			gotoxy(28,11);
			for (i=0;i<=41;i++)
			{
				cout<<hor;

			}
			gotoxy(28,13);
			for(i=0;i<=41;i++)
			{
				cout<<hor;
			}


			gotoxy(28,8);
			for(i=0;i<=16;i++)
			{
				gotoxy(28,8+i);
				cout<<ver;
			}
			gotoxy(29,25);
			for(i=0;i<=41;i++)
			{
				cout<<hor;
			}
			gotoxy(28,11);
			int c=28, d;
			for(d=0;d<6;d++)
			{
				c=c+6;
				for(i=0;i<=13;i++)
				{

					gotoxy(c,11+i);
					cout<<ver;
				}

			}
			gotoxy(29,12);
			cout<<" sun";
			gotoxy(35,12);
			cout<<" mon";
			gotoxy(41,12);
			cout<<" tue";
			gotoxy(47,12);
			cout<<" wed";
			gotoxy(53,12);
			cout<<" thu";
			gotoxy(59,12);
			cout<<" fri";
			gotoxy(65,12);
			cout<<" sat";
			int year,a,b,n,res=0,date,doomsday,sum;
			year=this->yy;
			int month;
			month=this->mm;
			for(i=0;i<=1;i++)
			{
				n=year%10;
				year=year/10;
				res=res+n*pow(10,i);
			}
			year=this->yy;
			a=res/12;
			b=res-12*a;
			c=b/4;
			if(year>=1800 && year<=1899)
			d=5;
			else if(year>=1900 && year<=1999)
			d=3;
			else if(year>=2000 && year<=2099)
			d=2;
			else if(year>=2100 && year<=2199)
			d=0;
			sum=a+b+c+d;
			for(i=0;;i++)
			{
				if(sum>7)
				sum=sum-7;
				else
				{
					doomsday=sum;
					break;
				}

			}
			if(month==1)
			{
				if(year%4==0 && year%100!=0 || year%400==0)
				{
					if (doomsday>=3)
					{
						date=doomsday-3;
					}
					else
					{
						date=doomsday+4;
					}
				}
				else
				{
					if(doomsday>=2)
					{
						date=doomsday-2 ;

					}
					else
					{
						date=doomsday+5;
					}
				}
			}
			else if(month==2)
			{
				if(year%4==0 && year%100!=0 || year%400==0)
				{
					date=doomsday;

				}
				else
				{
					if(doomsday!=6)
						date=doomsday;
					else
						date=0;
				}
			}
			else if(month==3)
			{
				if(doomsday!=6)
					date=doomsday+1;
				else
					date=0;
			}
			else if(month==4)
			{
				if(doomsday>=3)
				{
					date=doomsday-3;
				}
				else
					date=doomsday+4;

			}
			else if(month==5)
			{
				if(doomsday>=1)
					date=doomsday-1;
				else
					date=doomsday+6;
			}
			else if(month==6)
			{
				if(doomsday>=5)
					date=doomsday-5;
				else
					date=doomsday+2;
			}
			else if(month==7)
			{
				if(doomsday>=3)
					date=doomsday-3;
				else
					date=doomsday+4;
			}
			else if(month==8)
			{
				date=doomsday;
			}
			else if(month==9)
			{
				if(doomsday>=4)
					date=doomsday-4;
				else
					date=doomsday+3;

			}
			else if(month==10)
			{
				if(doomsday>=2)
					date=doomsday-2;
				else
					date=doomsday+5;
			}
			else if(month==11)
			{
				if(doomsday!=6)
					date=doomsday+1;
				else
					date=doomsday;
			}
			else if(month==12)
			{
				if(doomsday>=4)
					date=doomsday-4;
				else
					date=doomsday+3;
			}

			int j=29,k=14;
			if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
			{
				int s=31;
				if(date==0)
				{
					gotoxy(29,14);

					for(i=1;i<=s;i++)
					{
						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}


						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==7 || i==14 || i==21 || i==28)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}
				}
				else if(date==1)
				{
					gotoxy(35,14);
					j=35;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==6 || i==13 || i==20 || i==27)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==2)
				{
					gotoxy(41,14);
					j=41;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==5 || i==12 || i==19 || i==26)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==3)
				{
					gotoxy(47,14);
					j=47;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}

						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==4 || i==11 || i==18 || i==25)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
					else if(date==4)
				{
					gotoxy(53,14);
					j=53;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==3 || i==10 || i==17 || i==24)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==5)
				{
					gotoxy(59,14);
					j=59;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==2 || i==9 || i==16 || i==23 || i==30)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==6)
				{
					gotoxy(65,14);
					j=65;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==1 || i==8 || i==15 || i==22||i==29)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}

			}
			j=29,k=14;
			if(month==4 || month==6 || month==9 || month==11)
			{
				int s=30;
				if(date==0)
				{
					gotoxy(29,14);

					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==7 || i==14 || i==21 || i==28)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}
				}
				else if(date==1)
				{
					gotoxy(35,14);
					j=35;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==6 || i==13 || i==20 || i==27)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==2)
				{
					gotoxy(41,14);
					j=41;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==5 || i==12 || i==19 || i==26)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==3)
				{
					gotoxy(47,14);
					j=47;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==4 || i==11 || i==18 || i==25)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
					else if(date==4)
				{
					gotoxy(53,14);
					j=53;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==3 || i==10 || i==17 || i==24)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==5)
				{
					gotoxy(59,14);
					j=59;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==2 || i==9 || i==16 || i==23)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==6)
				{
					gotoxy(65,14);
					j=65;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==1 || i==8 || i==15 || i==22 || i==29)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}

			}
			 j=29,k=14;
			if(month==2)
			{
				if(year%4==0 && year%100!=0 || year%400==0)
				{
				int s=29;
				if(date==0)
				{
					gotoxy(29,14);

					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==7 || i==14 || i==21 || i==28)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}
				}
				else if(date==1)
				{
					gotoxy(35,14);
					j=35;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==6 || i==13 || i==20 || i==27)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==2)
				{
					gotoxy(41,14);
					j=41;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==5 || i==12 || i==19 || i==26)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==3)
				{
					gotoxy(47,14);
					j=47;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==4 || i==11 || i==18 || i==25)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
					else if(date==4)
				{
					gotoxy(53,14);
					j=53;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==3 || i==10 || i==17 || i==24)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==5)
				{
					gotoxy(59,14);
					j=59;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==2 || i==9 || i==16 || i==23)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==6)
				{
					gotoxy(65,14);
					j=65;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==1 || i==8 || i==15 || i==22 || i==29)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				}
				else
				{
				int s=28;
				if(date==0)
				{
					gotoxy(29,14);

					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==7 || i==14 || i==21 || i==28)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}
				}
				else if(date==1)
				{
					gotoxy(35,14);
					j=35;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==6 || i==13 || i==20 || i==27)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==2)
				{
					gotoxy(41,14);
					j=41;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{

						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==5 || i==12 || i==19 || i==26)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==3)
				{
					gotoxy(47,14);
					j=47;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==4 || i==11 || i==18 || i==25)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
					else if(date==4)
				{
					gotoxy(53,14);
					j=53;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==3 || i==10 || i==17 || i==24)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==5)
				{
					gotoxy(59,14);
					j=59;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s" ,buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==2 || i==9 || i==16 || i==23)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				else if(date==6)
				{
					gotoxy(65,14);
					j=65;
					k=14;
					for(i=1;i<=s;i++)
					{

						if(i==this->dd)
						{
								textcolor(4);
								textbackground(15);
								itoa(i,buffer,10);
								cprintf(" %s",buffer);
						}
						else
						{
						cout<<" "<<i;
						}
						j=j+6;
						gotoxy(j,k);
						if(i==1 || i==8 || i==15 || i==22 || i==29)
						{
							k=k+2;
							gotoxy(29,k);
							j=29;

						}

					}

				}
				}
			}


		}
		void desplay()
		{

			cout<<endl<<"After 5 Days New Date :- "<<this->dd<<"/"<<this->mm<<"/"<<this->yy;

		}



};

main()
{
	int c,i,j,k;
	date b;
	clrscr();
	cout<<endl<<"enter date in format dd/mm/yyyy:-"<<endl;
	cin>>i>>j>>k;
	date a(i,j,k);
	c=a.valid();
	if (c==1)
	cout<<"Valid date" ;
	else
	{
		cout<<"Invaid date";
		goto a;
	}
	b=a.add();
	b.desplay();
	a.display();
	a:
	getch();

}
