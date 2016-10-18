#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<iomanip.h>
#include<dos.h>
#include<string.h>

//***********************************************(Opening of class)
fstream z;
class bill{
       char na[20],add[70];
       int regis,unit,c;
public:
       void getinfo();
       void putinfo();
       void calc();
       int getregis();
       void regis_update(int t);

}x;

//***********************************************(End of class)
       void menu();
       void save();
       void search();
       void modify();
       void del();
       void check();
       void line();
       void intro();
       void exit();

void main()
{
	intro();
	menu();
	clrscr();
	exit();
}

//*********************************************End of main


void intro()
{
int e=0,f=0;
char pwd[20];
clrscr();
cout<<"\n\n\n\n\n";
line();
cout<<"\n\n";
cout<<setw(43)<<"Welcome"<<endl;
cout<<setw(62)<<"Computer Science project: Electricity Bill"<<endl;
cout<<setw(44)<<"Code: 083"<<endl;
cout<<"\n\n";
line();
cout<<endl<<endl;
cout<<"Please enter the password : ";


while(e<3)
{
gets(pwd);
if(strcmp(pwd,"tanmay22")==0)
f++;
if(f)
{
clrscr();
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<setw(50)<<"LOADING YOUR PROJECT"<<endl;
cout<<setw(50)<<"PLEASE WAIT.........";
delay(500);
gotoxy(1,20);
cout<<"10 % completed..";
delay(500);
gotoxy(1,20);
cout<<"20 % completed...";
delay(500);
gotoxy(1,20);
cout<<"30 % completed....";
delay(500);
gotoxy(1,20);
cout<<"40 % completed.....";
delay(500);
gotoxy(1,20);
cout<<"50 % completed......";
delay(500);
gotoxy(1,20);
cout<<"60 % completed.......";
delay(500);
gotoxy(1,20);
cout<<"70 % completed........";
delay(500);
gotoxy(1,20);
cout<<"80 % completed.........";
delay(500);
gotoxy(1,20);
cout<<"90 % completed..........";
delay(500);
gotoxy(1,20);
cout<<"100 % completed...........";
delay(800);
break;
}
else if(e==1)
{
cout<<endl;
cout<<"Incorrect password.(Last attemp) Enter again: ";
e++;
}
else if(e==2)
{
exit(0);
}
else
{
e++;
cout<<endl;
cout<<"Incorrect password. Enter again: ";
}
}
}

void exit()
{
cout<<"\n\n\n\n";
line();
cout<<"\n\n";
cout<<setw(44)<<"Thank you"<<endl;
cout<<setw(43)<<"Made by"<<endl;
cout<<setw(51)<<"Tanmay Jha of class SS2B"<<endl;
cout<<"\n\n";
line();
cout<<endl;
cout<<endl;
system("pause");
}

void bill::regis_update(int t)
{
regis=t;
}

void bill::getinfo()
{int rst;
regis_exists:
clrscr();
gotoxy(0,3);
line();
gotoxy(27,5);
cout<<"Enter your personal detail"<<endl;
gotoxy(27,6);
cout<<"__________________________"<<endl;
gotoxy(25,8);
cout<<"Enter name :"<<endl;
gotoxy(38,8);
gets(na);
gotoxy(25,10);
cout<<"Enter the registration id :"<<endl;
gotoxy(53,10);
cin>>regis;
gotoxy(25,12);
cout<<"Enter the address :"<<endl;
gotoxy(45,12);
gets(add);
gotoxy(25,14);
cout<<"Enter the units consumed :"<<endl;
gotoxy(52,14);
cin>>unit;
cout<<endl<<endl<<endl;
line();
cout<<endl<<endl;
system("pause");
}

void bill::putinfo()
{
clrscr();
gotoxy(0,2);
line();
gotoxy(26,3);
cout<<"Your personal detail and bill are : "<<endl;
gotoxy(26,4);
cout<<"____________________________________"<<endl;
gotoxy(33,7);
cout<<"Name :"<<endl;
gotoxy(40,7);
puts(na);
gotoxy(33,9);
cout<<"Registration id :"<<endl;
gotoxy(51,9);
cout<<regis;
gotoxy(33,11);
cout<<"Address :"<<endl;
gotoxy(43,11);
puts(add);
calc();
}

void bill::calc()
{
if(unit<200)
{
c=unit*2.2;
gotoxy(33,13);
cout<<"Your bill : ";
gotoxy(45,13);
cout<<c;
gotoxy(33,15);
cout<<"Tax : ";
gotoxy(39,15);
cout<<c*0.008;
gotoxy(33,17);
cout<<"Total bill : ";
gotoxy(46,17);
cout<<c+c*0.008;
cout<<endl<<endl;
line();
cout<<endl;
}
else
{
c=unit*2.2+(unit-200)*2;
gotoxy(33,13);
cout<<"Your bill : ";
gotoxy(45,13);
cout<<c;
gotoxy(33,15);
cout<<"Tax : ";
gotoxy(39,15);
cout<<c*0.008;
gotoxy(33,17);
cout<<"Total bill : ";
gotoxy(46,17);
cout<<c+c*0.008;
cout<<endl<<endl;
line();
cout<<endl;
}
}

int bill::getregis()
{
return regis;
}

void save(bill x)
{
char ans;
cout<<endl;
cout<<"Do you want to save this bill"<<endl;
cin>>ans;
if(ans=='y'||ans=='Y')
{
z.open("billz.dat",ios::binary|ios::app);
z.write((char*)&x,sizeof(x));
z.close();
cout<<"Bill has been saved"<<endl;
sleep(2);
}
}

void modify(bill x)
{
clrscr();
int records=0,g,rnew;
clrscr();
char confirm;
z.open("billz.dat",ios::binary|ios::out|ios::in);
cout<<endl<<endl<<endl;
cout<<"Enter the registration no. of the record which you want to update : ";
cin>>rnew;
while(z.read((char*)&x,sizeof(x)))
{
records++;
if(x.getregis()==rnew)
{
x.putinfo();
cout<<"Are you sure that you want to update"<<endl;
cin>>confirm;
if(confirm=='y'||confirm=='Y')
{
x.getinfo();
z.seekg((records-1)*sizeof(x));
z.write((char*)&x,sizeof(x));
cout<<"Your information has been updated";
sleep(2);
}
}
}
z.close();
}

void del(bill x)
{
clrscr(); int rnew;
z.open("billz.dat",ios::binary|ios::in|ios::out);
char found='n',confirm;
cout<<"\n \n \n Enter the registration no. to be deleted : ";
cin>>rnew;
while(z.read((char*)&x,sizeof(x)))
{
if(x.getregis()==rnew)
{
found='y';
break;
}
}
if(found=='n')
cout<<"The registration number doesn't exist.";
if(found=='y')
{
x.putinfo();
cout<<"Are you sure"<<endl;
cin>>confirm;
if(confirm=='y'||confirm=='Y')
{
z.seekp(z.tellp()-sizeof(x));
x.regis_update(0);
z.write((char*)&x,sizeof(x));
cout<<"Your information has been deleted"<<endl;
sleep(2);
}
}
z.close();
}

void search(bill x)
{
clrscr();  int rnew;
z.open("billz.dat",ios::binary|ios::in);
int k=0;
cout<<endl<<endl<<endl;
cout<<"Enter your regis no. : ";
cin>>rnew;
cout<<endl<<endl;
while(z.read((char*)&x,sizeof(x)))
{
if(x.getregis()==rnew)
{
x.putinfo();
k++;
}
}
if(!k)
{
clrscr();
cout<<endl<<endl<<endl;
cout<<"No registration has been done under this id"<<endl;
}
z.close();
system("pause");
}

void check(bill x)
{
z.open("billz.dat",ios::binary|ios::in);
clrscr();
int cnt=0;
cout<<"Data present on file is"<<endl;
while(z.read((char*)&x,sizeof(x)))
{
x.putinfo();
cnt++;
}
cout<<endl<<cnt<<" Records found ";
system("pause");
z.close();
}

void line()
{
for(int i=0;i<80;i++)
{
cout<<"_";
delay(12);
}
}

void menu()
{
int ch;
do
{
clrscr();
cout<<"\n\n\n";
line();
cout<<"\n\n";
cout<<setw(43)<<"Main Menu"<<endl;
cout<<endl;
cout<<setw(47)<<"1.Add a new employ"<<endl<<endl;
cout<<setw(54)<<"2.Update an existing data"<<endl<<endl;
cout<<setw(42)<<"3.Delete data"<<endl<<endl;
cout<<setw(40)<<"4.View Bill"<<endl<<endl;
cout<<setw(35)<<"5.Quit"<<endl<<endl;
cout<<"\n\n";
line();
cout<<endl;
cout<<"Enter your choice : ";
cin>>ch;
switch(ch)
{
case 1:
x.getinfo();
x.putinfo();
save(x);
break;

case 2:
modify(x);
break;

case 3:
del(x);
break;

case 4:
search(x);
break;

case 6:
check(x);
break;

}
}while(ch!=5);
}




