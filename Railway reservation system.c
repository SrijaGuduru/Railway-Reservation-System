

#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
void viewinfo();
void bookticket();
void cancelticket();
void admin();
void password();
void viewpassenger();
void addtrain();
void dlttrain();
struct adddata
{
char si[10];
char train_number[10];
char train_name[20];
char start[10];
char destination[10];
char price[10];
int seat;
char time[10];
} add[1000];

struct bookticket
{
char train_number[20];
char name[20];
char phone[20];
char date[20];
int seat;
}book[1000];
int k=0,u=0;
char trn_nmbr[100],name[100],phn[100];
int main()
{
system("CLS");
int ch;
time_t currentTime;
time(&currentTime);
printf("\n\t\t\t %s\n",ctime(&currentTime));
printf("\t\t\t***RAILWAY RESERVATION SYSTEM*\n");
printf("\n\t\t\t<<<<<<<<<<WELCOME USERS>>>>>>>>>>\n");
printf("\n\n\t\t\t\t MENU\n");
printf("\n\t\t\t[1] VIEW INFORMATION\n");
printf("\n\t\t\t[2] BOOK TICKET\n");
printf("\n\t\t\t[3] CANCEL TICKET\n");
printf("\n\t\t\t[4] ADMIN");
printf("\n\n\t\t\t[5] EXIT\n");
printf("\n\t\t\t******");
printf("\n\t\t\tENTER YOUR CHOICE: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
viewinfo();
break;
case 2:
bookticket();
break;
case 3:
cancelticket();
break;
case 4:
password();
break;
case 5:

system("cls");
printf("\t\t\t *RAILWAY RESERVATION SYSTEM*\n");
printf("\t\t\t-------------------------------------");
printf("\n\n\t\t\twrong option\n\n");
getch();
exit(0);
break;
default:
system("cls");
printf("\t\t\t *RAILWAY RESERVATIONSYSTEM*\n");
printf("\t\t\t -------------------------\n");
printf("\n\n\t\t\t<<<<<YOU ENTERED WRONGCHOICE>>>>>>\n\n");
getch();
system("cls");
}
return 0;
}
void bookticket()
{ int c,j,n,i,found=-1;
char v,train_number[10];
system ("cls");
printf("\n\t\t\t**RAILWAY RESERVATION SYSTEM**\n");
printf("\t\t\t------------------------------------------");
printf("\n\n\t\t\thow many ticket do you want to buy: ");
scanf("%d",&n);
for(j=u;j<u+n;j++)
{
printf("\n\n\t\t\tEnter train number: ");
scanf("%s", book[j].train_number);
for(i=0;i<k;i++)
{
if(strcmp(book[j].train_number,add[i].train_number)==0)
{
if(add[i].seat==0)
{
printf("\n\n\t\t\tnot available seat");

getch();
system("cls");
main();
}
else
{
found=1;
printf("\n\t\t\tenter book %d no ticket: ",j+1);
printf("\n\t\t\tenter date: ");
scanf("%s",book[j].date);
printf("\n\t\t\tenter your name: ");
scanf("%s",book[j].name);
printf("\n\t\t\tenter your phone number: ");
scanf("%s",book[j].phone);
printf("\n\t\t\tseat number : %d",add[i].seat );
book[j].seat=add[i].seat;
}
}
}
if(found==-1)
{
printf("\n\n\t\t\ttrain not found!!!");
getch();
system("cls");
main();
}
} u=j;
printf("\n\n\t\t\tenter '1' for main menu & press any key to exit:");
scanf("%d",&c);
if(c==1)
{
system("cls");
main();
}
if(c!=1)
{ exit;

}
}
void cancelticket()
{
char pnnmbr[100];
int location = -1,e;
printf ("\n\n\t\t\tenter phone number: ");
scanf ("%s",pnnmbr);
for (e=0;e<u;e++)
{
if (strcmp(pnnmbr,book[e].phone)==0)
{
location=e;
break;
}
}
if (location==-1)
{
printf ("\n\n\t\t\t<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>>\n");
getch();
system("cls");
main();
}
else
{
for (e=location;e<u;e++)
{
strcpy(book[e].date,book[e+1].date);
strcpy(book[e].train_number,book[e+1].train_number);
strcpy(book[e].name,book[e+1].name);
strcpy(book[e].phone,book[e+1].phone);
} u--;

printf("\n\n\t\t\t<<<<<<<<<<ticket cancelled successfully>>>>>>>>>>");
getch();
system("cls");
main();
}
}
void admin()
{
int chhh;
system("cls");
printf("\n **RAILWAY RESERVATION SYSTEM***");
printf("\n -------------------------------------------------");
printf("\n\n");
printf(" <<<<<<<<<<<WELCOME_ADMIN>>>>>>>>>>>>>>>\n");
printf("\n\n");
printf(" || CHOOSE YOUR OPERATION ||\n");
printf(" ||[1] VIEW PASSENGERS ||\n");
printf(" || [2] ADD TRAIN ||\n");
printf(" || [3] DELETE TRAIN||\n");
printf(" || [4] BACK ||\n");
printf(" || ||\n");
printf(" --------------------------\n");
printf("\n\t\tENTER YOUR CHOICE: ");
scanf("%d",&chhh);
switch(chhh)
{
case 1:
viewpassenger();
break;
case 2:
addtrain();
break;
case 3:
dlttrain();
break;
case 4:
system("cls");

getch();
main();
break;
default:
getch();
printf("\n\t\t\tyou entered wrong KEY!!!!");
getch();
system("cls");
main();
}
getch();
}
void password()
{
int number=1234567;
int pass;
printf("\n\t\t\tenter password: ");
scanf("%d",&pass);
if(pass==number)
{
printf("\n\n\t\t\t<<<<<login successfully>>>>>");
getch();
system("cls");
admin();
}
else
{
printf("\n\n\t\t\t\t ERROR!!!!!");
printf("\n\n\t\t\t<<<<<<<<wrong password>>>>>>>>");
getch();
system("cls");
main();
}
}
void dlttrain()
{
char train[100];
int location = -1,f;

printf ("\n\n\tenter train number: ");
scanf ("%s",train);
for(f=0;f<k;f++)
{
if (strcmp(train,add[f].train_number)==0)
{
location=f;
break;
}
}
if (location==-1)
{
printf ("\n\t-----------------Data Not Found----------------\n");
getch();
system("cls");
admin();
}
else
{
for (f=location;f<k;f++)
{ strcpy(add[f].si,add[f+1].si);
strcpy(add[f].train_number,add[f+1].train_number);
strcpy(add[f].train_name,add[f+1].train_name);
strcpy(add[f].start,add[f+1].start);
strcpy(add[f].destination,add[f+1].destination);
strcpy(add[f].price,add[f+1].price);
strcpy(add[f].time,add[f+1].time);
} k--;
printf("\n\n\t------------------train deleted successfully-----------------");
getch();
system("cls");
admin();

}
}
void viewpassenger()
{ int a,j;
system("cls");
printf("\n\t\t\t **RAILWAY RESERVATION SYSTEM**");
printf("\n\n\t\t\ttrainnumber\t\tname\t\tphonenumber\t\tdate\t\t se\n");
printf("\n\t\t\t-----------------------------");
for(j=0;j<u;j++)
{
printf("\n\t\t\t%s\t\t\t%s\t\t%s\t\t%s\t%d",book[j].train_number,book[j].name,book[j].phone,book[j].date,book[j].seat);
book[j].seat++;
}
printf("\n\t\t\t**********\n");
printf("\n\n\t\t\tenter '1' for main menu & enter '0' for back: ");
scanf("%d",&a); if(a==1)
{
system("cls");
main();
}
if(a==0)
{
system("cls");
admin();
}
}
void addtrain()
{
system("cls");
int ch;
int i,a;

printf("\n\t\t **RAILWAY RESERVATION SYSTEM**");
printf("\n\t\t ********");
printf("\n\n\t\t\thow many trains do you want to add: ");
scanf("%d",&a);
for(i=k;i<k+a;i++)
{
printf("\n\t\t\tenter %d train details: ",i+1);
printf("\n\t\t\tenter serial number: ");
scanf("%s",add[i].si);
printf("\n\t\t\tenter train number: ");
scanf("%s",add[i].train_number);
printf("\n\t\t\tenter train name: ");
scanf("%s",add[i].train_name);
printf("\n\t\t\tenter start place: ");
scanf("%s",add[i].start);
printf("\n\t\t\tenter destination place: ");
scanf("%s",add[i].destination);
printf("\n\t\t\t enter price: ");
scanf("%s",add[i].price);
printf("\n\t\t\t enter seat: ");
scanf("%d", &add[i].seat);
printf("\n\t\t\t enter time: ");
scanf("%s",add[i].time);
}
printf("\n\n\t\t\tconfirm train: (y=1/n=0):- ");
scanf("%d",&ch);
if(ch==1)
{ k=i; system("cls");
printf("\n\t\t\t****RAILWAY RESERVATION SYSTEM**");
printf("\n\t\t\t********");
printf("\n\n");
printf("\n\t\t\t\t <<<<<train add successfully>>>>>");
getch();
system("cls");
main();
}
if(ch==0)

{
system("cls");
admin();
}
if((ch!=1)&&(ch!=0))
{
system("cls");
main();
}
}
void viewinfo()
{ int ch,i;
system("cls")
;
printf("\n\t\t **RAILWAY RESERVATION SYSTEM**");
printf("\n\t\t ********");
printf("\n\n\n SI\ttrain number\t train name\tstart place\tdestination place\tprice\t\tseat\t\ttime\n\n");
for(i=0;i<k;i++)
{
printf(" %s\t\t%s\t\t%s\t\t%s\t%s\t\t%s\t\t%d\t\t%s\n",add[i].si,add[i].train_number,add[i].train_name,add[i].start,add[i].destination,add[i].price,add[i].seat,add[i].time);
}
printf(" -------------------------------\n");
printf("\n\t\t\tpress '1' for main menu & press any key for exit: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
system("cls")
; main();

break;
default:
exit(0);
}
}
