//unfinished
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
int stat = 0;
void room(int id, int status);
int change(int total);
int bill();
int confirm ( int Boolean );
main()
{
    char rmst;
    int rn,total,trans;
menu:
    room(rn, stat);
    printf("\nEnter Room # : ");
    scanf("%d",&rn);
    switch(rn)
    {
    case 101:
        total=bill();
        printf("Total bill : %d",total);
        getch();
        change(total);
        break;
    case 102:
        total=bill();
        printf("Total bill : %d",total);
        getch();
        change(total);
        break;
    case 103:
        total=bill();
        printf("Total bill : %d",total);
        getch();
        change(total);
        break;
    case 104:
        total=bill();
        printf("Total bill : %d",total);
        getch();
        change(total);
        break;
    case 105:
        total=bill();
        printf("Total bill : %d",total);
        getch();
        change(total);
        break;
    default:
        printf("\ninvalid...");
        getch();
        getch();
        clrscr();
        goto menu;
    }
ask:
    printf("\n1.Menu\n2.Exit\n:");
    scanf("%d",&trans);
    if(trans == 1 )
    {
        goto menu;
    }
    else if(trans == 2)
        return 0;
    else
        goto ask;
    clrscr();
}
void room(int id, int status)
{
    static char s[10]="EEEEE";
    if(status == true)
    {
        if(id == 101)
        {
            s[0] ='O';
        }
        else if(id == 102)
        {
            s[1] = 'O';
        }
        else if(id == 103)
        {
            s[2] = 'O';
        }
        else if(id == 104)
        {
            s[3] = 'O';
        }
        else if(id == 105)
        {
            s[4] = 'O';
        }
    }
    printf("\n------------------------------------");
    printf("\n| Room Number | Rent\\hour | Status |");
    printf("\n------------------------------------");
    printf("\n|  •Room 101  |   100$    |%6c  |",s[0]);
    printf("\n------------------------------------");
    printf("\n|  •Room 102  |   100$    |%6c  |",s[1]);
    printf("\n------------------------------------");
    printf("\n|  •Room 103  |   100$    |%6c  |",s[2]);
    printf("\n------------------------------------");
    printf("\n|  •Room 104  |   100$    |%6c  |",s[3]);
    printf("\n------------------------------------");
    printf("\n|  •Room 105  |   100$    |%6c  |",s[4]);
    printf("\n------------------------------------");


}
int bill()
{
    int hour;
    printf("\nNo. of hours checkin : ");
    scanf("%d",&hour);
    return (hour<24?hour*100:hour*70);
}
int change(int total)
{
    char trans;
    int money;
ask:
    printf("\nproceed to payment?y/n\n:");
    trans = getchar();
    if (trans == 'y')
    {
payment:
        clrscr();
        printf("Money : ");
        scanf("%d",&money);
        if(total>money)
        {
            printf("insufficient");
ask1:
            printf("\n1.Continue\n2.Cancel\n:");
            scanf("%d",&trans);
            if(trans == 1)
            {
                goto payment;
                stat = confirm(false);
            }
            else if(trans == 2)
                return 0;
            else
            {
                clrscr();
                goto ask1;
            }
        }
        else
            stat = confirm(true);
        return money-total;
    }
    else if(trans == 'n')
    {
        return 0;
    }
    else
    {
        clrscr();
        goto ask;
    }
}
int confirm ( int Boolean )
{
    return (Boolean == 1 ? true : false);
}