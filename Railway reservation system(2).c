#include<stdio.h>
#include<string.h>
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
void awrite();
void aread(); 
void bookticket_write(); 
void viewpassengers_read();
struct adddata
{
char si[10]; 
char train_number[10]; 
char train_name[20]; 
char start[100]; 
char destination[100]; 
char price[10]; 
int seat; 
char time[10];
} add[1000];

struct bookticket
{
char 
train_number[20]; 
char name[20]; 
char phone[20]; 
char date[20]; 
int seat; 
}book[1000];
int k=0,u=0;
char trn_nmbr[100],name[100],phn[100]; 
int main()
{
aread(); 
viewpassengers_read(); 
system("CLS"); 
int ch; 
time_t currentTime; 
time(&currentTime); 
printf("\n\t\t\t %s\n",ctime(&currentTime)); 
printf("\n\t\t\t RAILWAY RESERVATION SYSTEM \n");
printf("\n\t\t\t<<<<<<<<<<WELCOMEUSERS>>>>>>>>>>\n"); 
printf("\n\t\t\t----------------------------------");
printf("\n\n\t\t\t\t MENU\n"); 
printf("\n\t\t\t[1] VIEW INFORMATION\n"); 
printf("\n\t\t\t[2] BOOK TICKET\n"); 
printf("\n\t\t\t[3] CANCEL TICKET\n"); 
printf("\n\t\t\t[4] ADMIN");
printf("\n\n\t\t\t[5] EXIT\n");
printf("\n\t\t\t---------------------------------");
printf("\n\t\t\tENTER YOUR CHOICE: "); 
scanf("%d",&ch); switch(ch)
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
printf("\t\t\t RAILWAY RESERVATION SYSTEM \n");
break; 
default:
printf("\n\n\t\t\t<<<<<<<<ENTERED WRONG CHOICE>>>>>>>>\n");
system("cls");
main();
}
return 0;
}
void bookticket()
{ int c,j,n,i,found=-1; 
char v,train_number[10]; 
system ("cls");
aread();
printf("\n\t\t\t RAILWAY RESERVATION SYSTEM \n"); 
printf("\n\n\t\t\tHow many ticket do you want to buy?: "); 
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
printf("\n\n\t\t\tseats are not available"); 
system("cls");
main();
}
else
{
found=1; printf("\n\t\t\tenter book %d no ticket: ",j+1);
printf("\n\t\t\tenter date: "); 
scanf("%s",book[j].date); 
printf("\n\t\t\tenter your name: "); 
scanf("%s",book[j].name); 
printf("\n\t\t\tenter your phone number: "); 
scanf("%s",book[j].phone);
printf("\n\t\t\tseat number : %d",add[i].seat );
book[j].seat=add[i].seat; 
bookticket_write(); 
add[i].seat--; awrite();
}
}
}
if(found==-1)
{
printf("\n\n\t\t\ttrain not found"); 
getch(); 
system("cls");
main();
}
} u=j;

bookticket_write(); 
printf("\n\n\t\t\tenter '1' for main menu & press any key to exit: "); 
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
viewpassengers_read(); 
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
printf("\n\n\t\t\t<<<<<<<<<<<<DataNotFound>>>>>>>>>>>>>>\n"); 
getch(); 
system("cls")
;
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
bookticket_write();
}
u--;
bookticket_write();
printf("\n\n\t\t\t<<<<<<<ticketcancelledsuccessfully>>>>>>>>>"); 
getch(); 
system("cls");
main();
}
}
void admin()
{
int chhh; 
system("cls");
printf("\n\n");
printf(" <<<<<<WELCOME_ADMIN>>>>>>>\n");
printf("\n\n");
printf(" CHOOSE YOUR CHOICE \n");
printf("--------------------------------\n"); 
printf(" [1] VIEW PASSENGERS \n"); 
printf(" [2] ADD TRAIN \n"); 
printf(" [3] DELETE TRAIN \n");
printf(" [4] BACK \n");
printf(" \n");

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
printf("\n\t\t\tyou entered wrong key!!!!");
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
printf("\n\n\t\t\t<<<<<login successful>>>>>"); 
getch(); 
system("cls");
admin();

}
else
{
printf("\n\n\t\t\t<<<<<<<<wrongpassword>>>>>>>>"); 
getch(); 
system("cls");
main();
}
}
void dlttrain()
{
aread(); 
char train[100]; 
int location = -1,f;
printf ("\n\n\tenter train number: ");
scanf ("%s",train);
for (f=0;f<k;f++)
{
if (strcmp(train,add[f].train_number)==0)
{
location=f;
break;
}
}
if (location==-1)
{
printf("\n\n\t<<<<<<<<DataNotFound>>>>>>>>>>>>>>> \n"); 
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
awrite();
} k--; 
awrite();
printf("\n\n\t<<<<<<train deleted successfully>>>>>>>>>>>>>"); 
getch(); 
system("cls");
admin();
}
}
void viewpassenger()
{ int a,j; 
system("cls"); 
viewpassengers_read();
printf("\n\t\t\t RAILWAY RESERVATION SYSTEM ");
printf("\n\n\t\t\ttrainnumber\t\tname\t\tphonenumber\t\tseat\n"); 
for(j=0;j<u;j++)
{
printf("\n\t\t\t%s\t\t\t%s\t\t%s\t\t%s\t%d",book[j].train_number,book[j].name,book[j].phone,book[j].date,book[j].seat); 
book[j].seat++;
}
printf("\n\n\t\t\tenter '1' for main menu & enter '0' for back: ");
scanf("%d",&a);
if(a==1)
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
int ch; aread();
int i,a;
printf("\n\t\t RAILWAY RESERVATION SYSTEM "); 
printf("\n\n\t\t\tHow many trains do you want to add?: "); 
scanf("%d",&a);
for(i=k;i<k+a;i++)
{
printf("\n\t\t\tenter %d train details: ",i+1); 
printf("\n\t\t\tenter serial number: "); 
scanf("%d",add[i].si); 
printf("\n\t\t\tenter train number: "); 
scanf("%d",add[i].train_number); 
printf("\n\t\t\tenter train name: "); 
scanf("%s",add[i].train_name); 
printf("\n\t\t\tenter start place: "); 
scanf("%s",add[i].start);
printf("\n\t\t\tenter destination place: "); 
scanf("%s",add[i].destination); 
printf("\n\t\t\t enter price: "); 
scanf("%d",add[i].price); 
printf("\n\t\t\t enter seat: "); 
scanf("%d", & add[i].seat); 
printf("\n\t\t\t enter time: ");

scanf("%s",add[i].time);
}
printf("\n\n\t\t\tconfirm train: (y=1/n=0):- "); 
scanf("%d",&ch);
if(ch==1)
{ awrite();
 k=i; 
awrite();
system("cls");
printf("\n\t\t\ RAILWAY RESERVATION SYSTEM ");
printf("\n\n");
printf("\n\t\t\t\<<<<< train add successfully>>>>>");
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
system("cls");
aread();
printf("\n\t\t RAILWAY RESERVATION SYSTEM");

printf("\n\n\nSI\ttrainnumber\ttrainname\t\tstart place\tdestination place\tprice\tseat\ttime\n\n"); 
for(i=0;i<k;i++)
{
printf("\n\n\n%d\t%d\n",add[i].si,add[i].train_number,add[i].train_name,add[i].start,add[i].destination,add[i].price,add[i].seat,add[i].time);
}
printf("\n\t\t\tpress '1' for main menu & press any key for exit: "); 
scanf("%d",&ch);
 switch(ch)
{
case 1: 
system("cls"); 
main(); 
break; 
default:
exit(0);
}
}
void bookticket_write()
{
FILE *booklist; 
booklist=fopen("booklist.txt","w"); 
fwrite(&book,sizeof(book),1,booklist); 
fclose(booklist);
FILE *booklistreport; 
booklistreport=fopen("booklistreport.txt","w"); 
fwrite(&u,sizeof(u),1,booklistreport); 
fclose(booklistreport);
}
void viewpassengers_read()

{
FILE *booklist; 
booklist=fopen("booklist.txt","r"); 
fread(&book,sizeof(book),1,booklist); 
fclose(booklist);
FILE *booklistreport; 
booklistreport=fopen("booklistreport.txt","r"); 
fread(&u,sizeof(u),1,booklistreport); 
fclose(booklistreport);
}
void awrite()
{
FILE *train_details; train_details = fopen("train_details.txt","w"); 
fwrite(&add,sizeof(add),1,train_details);
fclose(train_details); FILE *train_report; 
train_report = fopen("train_report.txt","w"); 
fwrite(&k,sizeof(k),1,train_report); 
fclose(train_report);
}
void aread()
{
FILE *train_details; train_details = fopen("train_details.txt","r"); 
fread(&add,sizeof(add),1,train_details); 
fclose(train_details);
FILE *train_report; train_report = fopen("train_report.txt","r"); 
fread(&k,sizeof(k),1,train_report); 
fclose(train_report);
}
