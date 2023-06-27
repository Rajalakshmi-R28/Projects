#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<process.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
void format(char x='=',int n=79)
{
 cout<<"\n";
 for(int i=1;i<=n;i++)
  cout<<x;
 cout<<"\n";
}
class movie                     //Main Class
{  char mname[25];
   char lang[20];
   char certi[3];
   long int movieid;
   int duration;
   char hname[30];
   float rate;
   public:
    void in()                     //Member function to get movie details
    {   cout<<"ENTER THE MOVIE NAME       :";
	gets(mname);
	cout<<"ENTER THE LANGUAGE         :";
	gets(lang);
	cout<<"ENTER THE CERTIFICATION    :";
	gets(certi);
	cout<<"ENTER THE MOVIE ID         :";
	cin>>movieid;
	cout<<"ENTER THE DURATION IN MINS :";
	cin>>duration;
	cout<<"ENTER THE HERO NAME        :";
	gets(hname);
	cout<<"ENTER THE RATING FOR 5     :";
	cin>>rate;
     }
     void disp()           //Member function to diplay movie details
     {  cout<<"\n\n\tMOVIE ID       :";cout<<movieid;
	cout<<"\t\n\tMOVIE NAME     :";puts(mname);
	cout<<"\tLANGUAGE       :";puts(lang);
	cout<<"\tCERTIFICATION  :";puts(certi);
	cout<<"\tDURATION       :";cout<<duration<<" min";
	cout<<"\t\n\tHERO NAME      :";puts(hname);
	cout<<"\tRATING FOR 5   :";cout<<rate;
	cout<<"\n\n";   }
     long int retid()                   //Function to return movieid
    {  return movieid; }
 };
 char name[20];
 char mail[40];
 char ph[12];
 void ticin()
 {
  cout<<"\nENTER YOUR NAME       :";
  gets(name);
  cout<<"\nENTER YOUR CONTACT NO :";
  gets(ph);
  cout<<"\nENTER EMAIL ID        :";
  gets(mail);
  }
void  ticout()
{
cout<<"\nCUSTOMER NAME           :";
puts(name);
cout<<"\nCONTACT NO OF CUSTOMER  :";
puts(ph);
cout<<"\nCUSTOMER EMAIL ID       :";
puts(mail);
}

  void lineprint(char x='*')   //Function to display a line of
 {  cout<<"\n";
    for(int i=1;i<=80;i++)
    cout<<x;
    cout<<"\n";
  }
    void display()                    //Function to display movie details
   {   clrscr();
       movie m;
       ifstream f;
       cout<<"\n                          \4\4 MOVIES LIST \4\4\n";
       f.open("zineamovies.dat",ios::in|ios::binary);
      while(f.read((char*)&m,sizeof(m)))
      {
	m.disp();
	format('-',40);
	gotoxy(10,31);
	cout<<"PRESS ANY KEY....";
	getch();

      }
	 f.close();
    }
 void disp2( int a)              //Function to display movie details
 {  movie m2;	//in bill
    ifstream f2;
    f2.open("zineamovies.dat",ios::in|ios::binary);
    while(f2.read((char*)&m2,sizeof(m2)))
   {
      if(m2.retid()==a)
	m2.disp();
    }
   f2.close();        }

 void func1()          //Function to admin side
 {
   clrscr();
   int ch1;
   char oldpass[20];
   char pass[20];
   char newpass[20];
   char verifyp[20];

   l1:
   clrscr();
   format();
   cout<<"\n                          WELCOME TO MAX MOVIE COMPLEX ";
   format();
   cout<<"\n\t\t\t\tLOGIN SCREEN\n";
   cout<<"\n\n\tUser Name:"<<" Maxmoviecomplex";
   cout<<"\n\n\n\tEnter the Password:";
 for(int x=0;x<8;x++)
  {   pass[x]=getch();
      cout<<"*";
    }
  pass[x]='\0';
  if (strcmpi(pass,"password")==0)
    {
     cout<<"\n\n\t\t\t\tLogin Successful!!!";
     getch();
    }
else
    {
       cout<<"\n\t\t OOPS... Try again";
       getch();
       goto l1;
    }
     cout<<"\nYOUR PASSWORD IS TOO OLD";
   cout<<"\n\n1.CHANGE THE PASSWORD RIGHT NOW.\n\n2.CHANGE THE PASSWORD LATER.";
   cout<<"\n\nENTER YOUR CHOICE:";
   cin>>ch1;
   clrscr();
   switch(ch1)
   {
   case 1:cout<<"\nENTER YOUR OLD PASSWORD:";
   gets(oldpass);
     if(strcmpi(oldpass,pass)==0)
      {
     a1:cout<<"\nENTER YOUR NEW PASSWORD OF 8 CHARACTERS:";
	gets(newpass);
	if(strlen(newpass)>8)
	{
	cout<<"\nYOUR PASSWORD EXCEEDS 8 CHARACTERS";
	goto a1;
	}
	cout<<"\nVERIFY YOUR NEW PASSWORD:";
	gets(verifyp);
		if(strcmpi(verifyp,newpass)==0)
		{
		cout<<"\nPASSWORD MATCHES..";
		getch();
		strcpy(pass,newpass);
		cout<<"\nPASSWORD CHANGED....";
		getch();
		}
		  else
		 {
		 getch();
		 cout<<"\nPASSWORD DOESNOT MATCH..."<<"\nTRY AGAIN LATER...";
		 getch();
		 }

      }
      else
      {
      cout<<"\n THE OLD PASSWORD ENTERED IS WRONG";
      cout<<"\nTRY AGAIN LATER";
      getch();
      goto l1;
      }
      break;
   case 2:
    cout<<"\nCHANGE YOUR PASSWORD SOON";
    getch();
   break;
   default:cout<<"\nPRESS ANY KEY...";
     getch();
     break;
     }
   int ch;
   l2:
   clrscr();
   format('*');
   cout<<"                              \3\3\3 MAX MULTIPLEX \3\3\3";
   format('*');
   cout<<"\n\t1.DISPLAY THE MOVIES\n\t2.ADD A NEW MOVIE\n\t3.DELETE A MOVIE\n\t4.EXIT";
   format('*');
   cout<<"\n\t SELECT ANY ONE OPTION:";
   cin>>ch;
   switch(ch)
   {  case 1:
	    display();
	    break;
     case 2:
	    ofstream g;
	    char c;
	    movie n;
	    g.open("zineamovies.dat",ios::app|ios::binary);
	    do
	   {   n.in();
		g.write((char*)&n,sizeof(n));
		cout<<"PRESS Y TO ADD MORE INPUTS\n";
		cin>>c;
	    }   while (c=='y'||c=='Y');
	    g.close();
	    break;
     case 3:
	    movie m1;
	    ifstream f2;
	    ofstream f3;
	    int found=0;
	    f2.open("zineamovies.dat",ios::in|ios::binary);
	    f3.open("temp.dat",ios::out|ios::binary);
	    cout<<"\nENTER THE MOVIE ID TO BE DELETED:";
	    int t_id;
	    cin>>t_id;
	    while(f2.read((char*)&m1,sizeof(m1)))
	    {
	     if(t_id!=m1.retid())
		 f3.write((char*)&m1,sizeof(m1));
	     else
		  found=1;
	    }
	    f2.close();
	    f3.close();
	    if(found==1)
	       cout<<"\nRECORD HAS BEEN SUCCESSFULLY DELETED";
	    else
	       cout<<"\nRECORD NOT FOUND";
	    remove("zineamovies.dat");
	    rename("temp.dat","zineamovies.dat");
	    break;
     case 4:
	   cout<<"\nBACK TO MAIN MENU..";
	   return;
     default:
	   cout<<"\nINVALID OPTION";
   }
   gotoxy(10,24);
   cout<<"PRESS ANY KEY......";
   getch();
   goto l2;

 }

void bill1(int r,char row1[1],char col1[1],char cl)
 {	//Function to generate bill if no. of seats is 1

   int gd=DETECT,gm;
 initgraph(&gd,&gm,"\c:\\TURBOC3\\bgi");
 int x=317,y=236;
 int v1=0,v2=0,v3=0,num=0,n=0;
 while(1)
 {
 cleardevice();
 gotoxy(40,15);
 cout<<num<<"%";
 setcolor(YELLOW);
 outtextxy(282,80,"PREPARING YOUR TICKET BILL");
 setlinestyle(0,0,3);
 setcolor(GREEN);
 arc(x,y,270+v2,90+v2,40);
 setcolor(LIGHTRED);
 arc(x,y,320-v2,120-v2,70);
 arc(x,y,320-v2,120-v2,72);
 setcolor(CYAN);
 arc(x,y,30+v1,160+v1,920);
 setcolor(BLUE);
 arc(x,y,300-v1,40-v1,111);
 setcolor(LIGHTMAGENTA);
 arc(x,y,300+v3,140+v3,131);
 arc(x,y,300+v3,140+v3,133);
if(num>=100)
 {
 num+=0;
 delay(500);
 cleardevice();
 setcolor(YELLOW);
 outtextxy(200,150,"BILL IS READY");
 setcolor(MAGENTA);
 outtextxy(180,300,"PRESS ANY KEY TO SEE..");
 getch();
 closegraph();
 goto r1;
 }
 v1+=4+rand()%8;
 v2+=6+rand()%8;
 v3+=3+rand()%8;
 randomize();
 num=num+n;
 n=rand()%2;
 delay(30);

 }

 r1:  clrscr();
   float amount;
   format('-');
   cout<<"\n\t\t\t\t MAX MULTIPLEX  	";
   format('-');
   cout<<"\n\t\t\t\t  ---BILL--- ";
   cout<<"\nTHE TICKET DETAILS ARE:";
  ticout();
   cout<<"\n\tNumber Of Seats: "<<r;
   cout<<"\n\tSeat Number: ";
   cout<<"\n\t\t"<<row1<<col1;
   cout<<"\n\tCost Per Ticket:";
   if(cl=='g')
  {
      amount=r*300;
      cout<<"Rs.300";
      cout<<"\n\tClass:Gold";
      cout<<"\n\tNet Bill Amount:";
     cout<<"Rs."<<amount<<"/-";
     cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
  }
  if(cl=='p')
  {
     amount=r*500;
     cout<<"Rs.500";
     cout<<"\n\tClass:Platinum";
     cout<<"\n\tNet Bill Amount:";
     cout<<"Rs."<<amount<<"/-";
     cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
  }
   getch();     }

 void bill2(int r,char row1[1],char col1[1],char row2[1],char col2[1],char  cl)    //Function to generate bill if no. of
 {	//seats is 2
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"\c:\\TURBOC3\\bgi");
 int x=317,y=236;
 int v1=0,v2=0,v3=0,num=0,n=0;
 while(1)
 {
 cleardevice();
 gotoxy(40,15);
 cout<<num<<"%";
 setcolor(YELLOW);
 outtextxy(282,80,"PREPARING YOUR TICKET BILL");
 setlinestyle(0,0,3);
 setcolor(GREEN);
 arc(x,y,270+v2,90+v2,40);
 setcolor(LIGHTRED);
 arc(x,y,320-v2,120-v2,70);
 arc(x,y,320-v2,120-v2,72);
 setcolor(CYAN);
 arc(x,y,30+v1,160+v1,920);
 setcolor(BLUE);
 arc(x,y,300-v1,40-v1,111);
 setcolor(LIGHTMAGENTA);
 arc(x,y,300+v3,140+v3,131);
 arc(x,y,300+v3,140+v3,133);
if(num>=100)
 {
 num+=0;
 delay(500);
 cleardevice();
 setcolor(YELLOW);
 outtextxy(200,150,"BILL IS READY");
 setcolor(MAGENTA);
 outtextxy(180,300,"PRESS ANY KEY TO SEE..");
 getch();
 closegraph();
 goto r2;
 }
 v1+=4+rand()%8;
 v2+=6+rand()%8;
 v3+=3+rand()%8;
 randomize();
 num=num+n;
 n=rand()%2;
 delay(30);
 }

  r2:  clrscr();
    float amount;
    cout<<"\n-------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\tMAX MULTIPLEX ";
    cout<<"\n-------------------------------------------------------------------------------  ";
    cout<<"\n\t\t\t\t   ---BILL---";
     cout<<"\nTHE TICKET DETAILS ARE:";
   ticout();
    cout<<"\n\tNumber Of Seats: "<<"2";
    cout<<"\n\tSeat Numbers: ";
    cout<<"\n\t\tSeat 1:"<<row1<<col1;
    cout<<"\n\t\tSeat 2:"<<row2<<col2;
    cout<<"\n\tCost Per Ticket:";
    if(cl=='g')
   {
      amount=r*300;
      cout<<"Rs.300";
      cout<<"\n\tNet Bill Amount:";
      cout<<"Rs."<<amount<<"/-";
      cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
   }

   if(cl=='p')
   {
      amount=r*500;
      cout<<"Rs.500";
      cout<<"\n\tNet Bill Amount:";
      cout<<"Rs."<<amount<<"/-";
      cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
   }
   getch();
 }

 void bill3(int r,char row1[1],char col1[1],char row2[1],char col2[1],char  row3[1],char col3[1],char cl)
 {   int gd=DETECT,gm;
 initgraph(&gd,&gm,"\c:\\TURBOC3\\bgi");
 int x=317,y=236;
 int v1=0,v2=0,v3=0,num=0,n=0;
 while(1)
 {
 cleardevice();
 gotoxy(40,15);
 cout<<num<<"%";
 setcolor(YELLOW);
 outtextxy(282,80,"PREPARING YOUR TICKET BILL");
 setlinestyle(0,0,3);
 setcolor(GREEN);
 arc(x,y,270+v2,90+v2,40);
 setcolor(LIGHTRED);
 arc(x,y,320-v2,120-v2,70);
 arc(x,y,320-v2,120-v2,72);
 setcolor(CYAN);
 arc(x,y,30+v1,160+v1,920);
 setcolor(BLUE);
 arc(x,y,300-v1,40-v1,111);
 setcolor(LIGHTMAGENTA);
 arc(x,y,300+v3,140+v3,131);
 arc(x,y,300+v3,140+v3,133);
if(num>=100)
 {
 num+=0;
 delay(500);
 cleardevice();
 setcolor(YELLOW);
 outtextxy(200,150,"BILL IS READY");
 setcolor(MAGENTA);
 outtextxy(180,300,"PRESS ANY KEY TO SEE..");
 getch();
 closegraph();
 goto r3;
 }
 v1+=4+rand()%8;
 v2+=6+rand()%8;
 v3+=3+rand()%8;
 randomize();
 num=num+n;
 n=rand()%2;
 delay(30);
 }
  //Function to generate bill if no. of seat is 3
   r3: clrscr();
    float amount;
    cout<<"\n-------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t  MAX MULTIPLEX ";
    cout<<"\n------------------------------------------------------------------------------- ";
    cout<<"\n\t\t\t\t    ---BILL---";

     cout<<"\nTHE TICKET DETAILS ARE:";
     ticout();

    cout<<"\n\tNumber Of Seats: "<<r;
    cout<<"\n\tSeat Numbers: ";
    cout<<"\n\t\tSeat 1:"<<row1<<col1;
    cout<<"\n\t\tSeat 2:"<<row2<<col2;
    cout<<"\n\t\tSeat 3:"<<row3<<col3;
    cout<<"\n\tCost Per Ticket:";
    if(cl=='g')
   {
       amount=r*300;
       cout<<"Rs.300";
       cout<<"\n\tNet Bill Amount:";
       cout<<"Rs."<<amount<<"/-";
       cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
   }
   if(cl=='p')
   {
	amount=r*500;
       cout<<"Rs.500";
      cout<<"\n\tNet Bill Amount:";
      cout<<"Rs."<<amount<<"/-";
      cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
   }
   getch();
 }

 void bill4(int r,char row1[1],char col1[1],char row2[1],char col2[1],char row3[1],char col3[1],char row4[1],char col4[1],char cl)
 {
		     //Function to generate bill if no. of seats is 4
		     int gd=DETECT,gm;
 initgraph(&gd,&gm,"\c:\\TURBOC3\\bgi");
 int x=317,y=236;
 int v1=0,v2=0,v3=0,num=0,n=0;
 while(1)
 {
 cleardevice();
 gotoxy(40,15);
 cout<<num<<"%";
 setcolor(YELLOW);
 outtextxy(282,80,"PREPARING YOUR TICKET BILL");
 setlinestyle(0,0,3);
 setcolor(GREEN);
 arc(x,y,270+v2,90+v2,40);
 setcolor(LIGHTRED);
 arc(x,y,320-v2,120-v2,70);
 arc(x,y,320-v2,120-v2,72);
 setcolor(CYAN);
 arc(x,y,30+v1,160+v1,920);
 setcolor(BLUE);
 arc(x,y,300-v1,40-v1,111);
 setcolor(LIGHTMAGENTA);
 arc(x,y,300+v3,140+v3,131);
 arc(x,y,300+v3,140+v3,133);
if(num>=100)
 {
 num+=0;
 delay(500);
 cleardevice();
 setcolor(YELLOW);
 outtextxy(200,150,"BILL IS READY");
 setcolor(MAGENTA);
 outtextxy(180,300,"PRESS ANY KEY TO SEE..");
 getch();
 closegraph();
 goto r4;
 }
 v1+=4+rand()%8;
 v2+=6+rand()%8;
 v3+=3+rand()%8;
 randomize();
 num=num+n;
 n=rand()%2;
 delay(30);
 }
  r4: clrscr();
   float amount;
   cout<<"\n-------------------------------------------------------------------------------";
   cout<<"\n\t\t\t\tMAX MULTIPLEX ";
   cout<<"\n-------------------------------------------------------------------------------";
   cout<<"\n\t\t\t\t    ---BILL---";
    cout<<"\nTHE TICKET DETAILS ARE:";
    ticout();

   cout<<"\n\tNumber Of Seats: "<<r;
   cout<<"\n\tSeat Numbers:";
   cout<<"\n\t\tSeat 1:"<<row1<<col1;
   cout<<"\n\t\tSeat 2:"<<row2<<col2;
   cout<<"\n\t\tSeat 3:"<<row3<<col3;
   cout<<"\n\t\tSeat 4:"<<row4<<col4;
   cout<<"\n\tCost Per Ticket:";
   if(cl=='g')
   {
       amount=r*300;
       cout<<"Rs.300";
       cout<<"\n\tNet Bill Amount:";
       cout<<"Rs."<<amount<<"/-";
      cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
   }
   if(cl=='p')
   {
       amount=r*500;
       cout<<"Rs.500";
       cout<<"\n\tNet Bill Amount:";
       cout<<"Rs."<<amount<<"/-";
      cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
   }
     getch();   }

 void bill5(int r,char row1[1],char col1[1],char row2[1],char col2[1],char  row3[1],char col3[1],char row4[1],char col4[1],char row5[1],char col5[1],char cl)
 {                    //Function to generate bill if no. of seats is 5
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"\c:\\TURBOC3\\bgi");
 int x=317,y=236;
 int v1=0,v2=0,v3=0,num=0,n=0;
 while(1)
 {
 cleardevice();
 gotoxy(40,15);
 cout<<num<<"%";
 setcolor(YELLOW);
 outtextxy(282,80,"PREPARING YOUR TICKET BILL");
 setlinestyle(0,0,3);
 setcolor(GREEN);
 arc(x,y,270+v2,90+v2,40);
 setcolor(LIGHTRED);
 arc(x,y,320-v2,120-v2,70);
 arc(x,y,320-v2,120-v2,72);
 setcolor(CYAN);
 arc(x,y,30+v1,160+v1,920);
 setcolor(BLUE);
 arc(x,y,300-v1,40-v1,111);
 setcolor(LIGHTMAGENTA);
 arc(x,y,300+v3,140+v3,131);
 arc(x,y,300+v3,140+v3,133);
if(num>=100)
 {
 num+=0;
 delay(500);
 cleardevice();
 setcolor(YELLOW);
 outtextxy(200,150,"BILL IS READY");
 setcolor(MAGENTA);
 outtextxy(180,300,"PRESS ANY KEY TO SEE..");
 getch();
 closegraph();
 goto r5;
 }
 v1+=4+rand()%8;
 v2+=6+rand()%8;
 v3+=3+rand()%8;
 randomize();
 num=num+n;
 n=rand()%2;
 delay(30);
 }
  r5:  clrscr();
    float amount;
    cout<<"\n-------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\tMAX MULTIPLEX ";
    cout<<"\n-------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t    ---BILL---";

     cout<<"\nTHE TICKET DETAILS ARE:";
     ticout();

    cout<<"\n\tNumber Of Seats: "<<r;
    cout<<"\n\tSeat Numbers: ";
    cout<<"\n\t\tSeat 1:"<<row1<<col1;
    cout<<"\n\t\tSeat 2:"<<row2<<col2;
    cout<<"\n\t\tSeat 3:"<<row3<<col3;
    cout<<"\n\t\tSeat 4:"<<row4<<col4;
    cout<<"\n\t\tSeat 5:"<<row5<<col5;
    cout<<"\n\tCost Per Ticket:";
    if(cl=='g')
   {
	amount=r*300;
	cout<<"Rs.300";
       cout<<"\n\tNet Bill Amount:";
       cout<<"Rs."<<amount<<"/-";
       cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
   }
   if(cl=='p')
   {
       amount=r*500;
      cout<<"Rs.500";
      cout<<"\n\tNet Bill Amount:";
      cout<<"Rs."<<amount<<"/";
      cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
    }
    getch();
  }
  void seat(int r)        //Function for seating arrangements

{   format();
    cout<<"\n\n\t\tA1 | A2 | A3 | A4 | A5 | A6 | A7 | A8 | A9 ";
    cout<<"\n\n\t\tB1 | B2 | B3 | B4 | B5 | B6 | B7 | B8 | B9";
    cout<<"\n\n\t\tC1 | C2 | C3 | C4 | C5 | C6 | C7 | C8 | C9";
    cout<<"\n\n\t\tD1 | D2 | D3 | D4 | D5 | D6 | D7 | D8 | D9";
    cout<<"\n\n\t\tE1 | E2 | E3 | E4 | E5 | E6 | E7 | E8 | E9";
    format();
    char row1[1] , col1[1] , row2[1] , col2[1] , row3[1] , col3[1] , row4[1] ,  col4[1] ,row5[1],col5[1];
   char cl;
   if(r==0)
   {   cout<<"\nSORRY!! No Are Seats Available!!!";
       getch();
      exit(1);
     }
   if(r==1)
   {   cout<<"\nSelect Row(A-E):->";
       gets(row1);
       strupr(row1);
       cout<<"\nSelect Column(1-9):->";
       gets(col1);
       cout<<"\nGold Class(g) or Platinum Class(p):";
       cin>>cl;
       bill1(r,row1,col1,cl);
    }
    if(r==2)
   {  cout<<"\nSelect Row(A-E) For Seat-1:->";
      gets(row1);
      strupr(row1);
      cout<<"\nSelect Column(1-9) For Seat-1:->";
      gets(col1);
      cout<<"\nSelect Row(A-E) For Seat-2:->";
      gets(row2);
      strupr(row2);
      cout<<"\nSelect Column(1-9) For Seat-2:->";
      gets(col2);
      cout<<"\nGold Class(g) or Platinum Class(p):";
      cin>>cl;
      bill2(r,row1,col1,row2,col2,cl);
   }
   if(r==3)
  {  cout<<"\nSelect Row(A-E) For Seat-1:->";
     gets(row1);
     strupr(row1);
     cout<<"\nSelect Column(1-9) For Seat-1:->";
     gets(col1);
     cout<<"\nSelect Row(A-E) For Seat-2:->";
     gets(row2);
     strupr(row2);
     cout<<"\nSelect Column(1-9) For Seat-2:->";
     gets(col2);
     cout<<"\nSelect Row(A-E) For Seat-3:->";
     gets(row3);
     strupr(row3);
     cout<<"\nSelect Column(1-9) For Seat-3:->";
     gets(col3);
     cout<<"\nGold Class(g) or Platinum Class(p):";
     cin>>cl;
     bill3(r,row1,col1,row2,col2,row3,col3,cl);
    }
   if(r==4)
  { cout<<"\nSelect Row(A-E) For Seat-1:->";
    gets(row1);
    strupr(row1);
    cout<<"\nSelect Column(1-9) For Seat-1:->";
    gets(col1);
    cout<<"\nSelect Row(A-E) For Seat-2:->";
    gets(row2);
    strupr(row2);
    cout<<"\nSelect Column(1-9) For Seat-2:->";
    gets(col2);
    cout<<"\nSelect Row(A-E) For Seat-3:->";
    gets(row3);
    strupr(row3);
    cout<<"\nSelect Column(1-9) For Seat-3:->";
    gets(col3);
    cout<<"\nSelect Row(A-E) For Seat-4:->";
    gets(row4);
    strupr(row4);
    cout<<"\nSelect Column(1-9) For Seat-4:->";
    gets(col4);
    cout<<"\nGold Class(g) or Platinum Class(p):";
    cin>>cl;
    bill4(r,row1,col1,row2,col2,row3,col3,row4,col4,cl);
    }
   if(r==5)
  { cout<<"\nSelect Row(A-E) For Seat-1:->";
    gets(row1);
    strupr(row1);
    cout<<"\nSelect Column(1-9) For Seat-1:->";
    gets(col1);
    cout<<"\nSelect Row(A-E) For Seat-2:->";
    gets(row2);
    strupr(row2);
    cout<<"\nSelect Column(1-9) For Seat-2:->";
    gets(col2);
    cout<<"Select Row(A-E) For Seat-3:->";
    gets(row3);
    strupr(row4);
    cout<<"\nSelect Column(1-9) For Seat-3:->";
    gets(col3);
    cout<<"\nSelect Row(A-E) For Seat-4:->";
    gets(row4);
    strupr(row4);
    cout<<"\nSelect Column(1-9) For Seat-4:->";
    gets(col4);
    cout<<"\nSelect Row(A-E) For Seat-5:->";
    gets(row5);
    strupr(row5);
    cout<<"\nSelect Column(1-9) For Seat-5:->";
    gets(col5);
    cout<<"\nGold Class(g) or Platinum Class(p):";
    cin>>cl;

bill5(r,row1,col1,row2,col2,row3,col3,row4,col4,row5,col5,cl);
    }
  }
 void func2()                      //Function to admin side
 {

    int a;
    l3:
    clrscr();
    lineprint('=');
    cout<<"                               MAX MULTIPLEX         ";
    lineprint('=');
    cout<<"MAX MULTIPLEX IS THE LARGEST AND MOST POPULAR MOVIE TICKET RESERVATION WEBSITE.";
   int k;
   cout<<"\n\n\t\t\t\t1.SELECT THE MOVIE  ";
   cout<<"\n\t\t\t\t2.BACK TO MAIN MENU ";
   cout<<"\n\n\t\t\t\n ENTER YOUR CHOICE:";
   cin>>k;
   switch(k)
   {
     case 1: int se,show,mid;

      clrscr();
       cout<<"\nMOVIES AVAILABLE ARE:"<<"\n";
       display();
       clrscr();
       cout<<"\nENTER THE FOLLOWING DETAILS TO CONTINUE THE TICKET BOOKING";
       ticin();
       cout<<"\nENTER THE MOVIE ID THAT YOU WISH TO SEE:";
       cin>>mid;
       cout<<"\nENTER THE NO OF SEATS (MAX 5):";
       cin>>se;
       cout<<"\nENTER THE SHOW YOU WISH TO SEE:\n1.FIRST SHOW\n2.MATINEE SHOW \n3.EVENING SHOW\n4.SECOND SHOW";
       cout<<"\nENTER THE NUMBER OF THE SHOW:";
       cin>>show;
       clrscr();
       seat(se);
       goto l3;
    case 2:
	return;
    default:
       cout<<"\n PRESS ANY VALID KEY..PLEASE";
       goto l3;
 }
 }


void main()             //Main Program
 {
 textbackground(BLACK);
 textcolor(LIGHTBLUE);
     clrscr();
     int mi;
     m1:
     clrscr();
     lineprint();
     cout<<"                                MAX MULTIPLEX";
     lineprint();
     cout<<"\n       WELCOME TO THE INDIA'S POPULAR MOVIE TICKET RESERVATION WEBSITE.";
     cout<<"\n\t\t\t          1.ADMIN \n\t\t\t          2.USER \n\t\t\t          3.EXIT";
     lineprint();
     gotoxy(30,50);
     cout<<"\nENTER YOUR CHOICE: ";
     gotoxy(40,50);
     cin>>mi;
     cout<<"\n\n\n\n\n\n\n\n\n\n";
     switch(mi)
     {   case 1:
	       func1();
	       break;
	 case 2:
	       func2();
	       break;
	case 3:
	       exit(1);
	default:cout<<"\nTHANKYOU";
	getch();
     }
     getch();
     goto m1;
}








