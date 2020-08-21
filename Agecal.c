#include <stdio.h>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
int imp();
typedef struct DATE{
    int d;
    int m;
    int y;
}date;

void pos(int x, int y)
{
    HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { y, x };
    SetConsoleCursorPosition(t, position);
}

void txtclr(unsigned char c)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, c);
}


int countleapyear(int m,int y)
{
    if(m<=2)
        y--;
    return y/4-y/100+y/400;
}
int isLeapYear(int year, int mon)
{
    int g = 0;
    if (year % 100 == 0)
{
    if (year % 400 == 0)
        {
          if (mon == 2)
                {
                  g = 1;
                }
        }
}
    else if (year % 4 == 0)
      {
       if (mon == 2)
            {
                    g = 1;
            }
      }
    return (g);
}
void box(int top, int left, int bottom, int right, unsigned char color)
{
   int i;

   txtclr(color);
   pos( top, left );
   printf("%c",218);
   for(i=1; i<(right-left); i++)
      printf("%c",196);
   printf("%c",191);

   for(i=1; i<(bottom-top); i++)
   {
      pos( top+i, left );
      printf("%c",179);
      pos( top+i, right );
      printf("%c",179);
   }

   pos( bottom, left );
   printf("%c",192);
   for(i=1; i<(right-left); i++)
      printf("%c",196);
   printf("%c",217);
}
void age1(int bd,int bm,int by,int pd,int pm,int py)
{
  int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
   if(pd<bd)
   {
       pd=pd+month[pm-2];
       pm=pm-1;
   }
   if(pm<bm)
   {
       pm=pm+12;
       py=py-1;
   }
   if(isLeapYear(by,bm))
   {
       pd=pd+1;
   }
   int fd=pd-bd;
   int fm=pm-bm;
   int fy=py-by;
   pos(19,3);
   txtclr(0xF4);
   printf("Your Age is : %d Years %d months %d days\n\n\n\n\n\n\n",fy,fm,fd);
   txtclr(0xf0);

}
void age2(int bm,int pm,int py,int by)
{
    if(pm<bm)
    {
       py=py-1;
    }
    pos(19,3);
    txtclr(0xF4);
    printf("Your Age is : %d Years\n\n\n\n\n\n\n",py-by);
    txtclr(0xf0);

}
void age3(int by,int bm,int py,int pm)
{
    if(pm<bm)
   {
       pm=pm+12;
       py=py-1;
   }
   int fm=pm-bm;
   int fy=py-by;
   int ffm=(fy*12)+fm;
   pos(19,3);
   txtclr(0xF4);
   printf("Your Age is : %d Months\n\n\n\n\n\n\n",ffm);
   txtclr(0xf0);

}
int age4(int bd,int bm,int by,int pd,int pm,int py)
{

    int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    long int n1=by*365+bd;
    for(int i=0;i<bm-1;i++)
    {
        n1=n1+month[i];
    }
    n1=n1+countleapyear(bm,by);
    long int n2=py*365+pd;
    for(int j=0;j<pm-1;j++)
    {
        n2=n2+month[j];
    }
    n2=n2+countleapyear(pm,py);
    int n3;
    n3=n2-n1;
    pos(19,3);
    txtclr(0xf4);
    printf("Your Age is : %d Days\n\n",n3);
    txtclr(0xf0);

}
int imp()
{
    system("COLOR f0");
    box(0,0,27,115,0xf1);
    pos(2,53);
    txtclr(0xf9);
    printf("AGE CALCULATOR\n");
    txtclr(0xf0);
    date dob,aaj;
    SYSTEMTIME stime;
    GetSystemTime(&stime);
    aaj.d=stime.wDay;
    aaj.m=stime.wMonth;
    aaj.y=stime.wYear;
    pos(4,48);
    txtclr(0xfc);
    printf("Present Date : %d/%d/%d\n\n",aaj.d,aaj.m,aaj.y);
    txtclr(0xf0);
    int n;
    aaj.d=stime.wDay;
    aaj.m=stime.wMonth;
    aaj.y=stime.wYear;
     txtclr(0xf5);
    pos(6,3);
    printf("Enter your Date of Birth");
       pos(7,20);
    printf("[DD MM YYY] : ");
        scanf("%d%d%d",&dob.d,&dob.m,&dob.y);
        txtclr(0xf0);
    printf("\n");
    if(dob.y>aaj.y || (dob.y==aaj.y && (dob.m>aaj.m || dob.d>aaj.d)))
    {   txtclr(0xf4);
        pos(14,3);
        printf("You have Entered a Wrong Input!!");
        txtclr(0xf0);
        return 0;
    }
    txtclr(0xf3);
    pos(9,3);
    printf("Select Option for Calculating Age");
    pos(10,10);
        printf("1) Age in Years-Months-Days [YY Years MM Months DD Days] Format");
    pos(11,10);
        printf("2) Age in Years             [YY Years] Format");
    pos(12,10);
        printf("3) Age in Months            [MMM Months]Format");
    pos(13,10);
        printf("4) Age in Days              [DDDD Days]Format\n\n");
    pos(14,10);
        printf("5) Enter another Date of Birth");
    pos(15,10);
        printf("6) Exit");
    pos(17,3);
        printf("Enter Your Choice [1-6] : ");
        scanf("%d",&n);
        txtclr(0xf0);
        printf("\n\n");
        if(n==1)
   {
       age1(dob.d,dob.m,dob.y,aaj.d,aaj.m,aaj.y);
   }
   if(n==2)
   {
       age2(dob.m,aaj.m,aaj.y,dob.y);
   }
   if(n==3)
   {
       age3(dob.y,dob.m,aaj.y,aaj.m);
   }
   if(n==4)
   {
       age4(dob.d,dob.m,dob.y,aaj.d,aaj.m,aaj.y);
   }
   if (n==5)
   {
       system("cls");
       imp();
   }

    if(n==6)
   {
       printf("\n\n\n\n");
       return 0;
   }
   else if(n!=1 && n!=2 && n!=3 && n!=4 && n!=5 && n!=6)
    {  pos(19,3);
        txtclr(0xf4);
        printf("Wrong Input!!");
        txtclr(0xf0);
    }
}
int main()
{
   char a;
    while(1)
    {
        imp();
        pos(21, 3);
        txtclr(0xf6);
        printf("Try Again? [ Y / N ] : ");
        a=getch();
        txtclr(0xf0);
        if(a=='Y' || a=='y')
         {
            system("cls");
         }
         else
            break;
    }
    printf("\n\n\n\n\n\n\n\n\n");
}

