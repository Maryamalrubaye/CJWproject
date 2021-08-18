#include "mylibrary.h"
#include <stdio.h>
#include <string.h>
#include <time.h>


    // this function shows the specific date and time on the top of the screen.
//void timetable();

    // this function allowed the user to enter his user name and password in order to enter to the program for security reasons.
//void password();

void password()
{
    char username [20];
    char password [10];
    int i;
    for (i=0;i<=5;i++)
    {
        printf("PLEASE ENTER YOUR USERNAME : ");
        scanf("%s",&username);
        printf("\nPLEASE ENTER YOUR PASSWORD : ");
        scanf("%s",&password);
        printf("\n\t\t________________________________\n");
        //if (!strcmp(username,"maryam_alrubaye") && !strcmp(password,"maryam"))
             if ( (strcmp(username,"maryam_alrubaye")==0) &&  (strcmp(password,"maryam")==0))
        {
        	system("cls");
                printf ("SUCCESSFULLY LOGIN  \t\t {PRESS ANY TO GO TO THE MAIN PAGE}\n\n");

                break;
        }
        else
        {
        	system("cls");
            printf(" login is failed please try again\n\n");
        }
    }

    getch();
}
void timetable ()
{

    time_t now;
    time (&now);

    printf(" \t\t\t\t\t\t\t\t\t\t\t\t%s",ctime(&now));

}
