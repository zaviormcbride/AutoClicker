#include "autoheader.h"
#include <stdio.h>
#include <Windows.h>
#include <Wincon.h>
#include <winuser.h>
/*
FOREGROUND_BLUE
Text color contains blue.
FOREGROUND_GREEN
Text color contains green.
FOREGROUND_RED
Text color contains red.
FOREGROUND_INTENSITY
Text color is intensified.
BACKGROUND_BLUE
Background color contains blue.
BACKGROUND_GREEN
Background color contains green.
BACKGROUND_RED
Background color contains red.
BACKGROUND_INTENSITY
*/
extern char  START;
extern char STOP;
extern char  CHANGE;
void autoclicker(char START, char STOP, char CHANGE)
{
    
    int n=500;
    short click = 0;
    short x=0;
    while (1)
	{
	    if(GetAsyncKeyState(CHANGE))
        {
            system("CLS");
            x=meniu_settings();
            if(x==1)
              n=ChangeCPS();
            else 
                if(x==2)
                 {
                    ChangeBind(&START, &STOP, &CHANGE);
                 }
            meniu( START,  STOP,  CHANGE);
            
        }

		if (GetAsyncKeyState(START))
		{
            Sleep(500);
			click = 1;
        
		}
		if (GetAsyncKeyState(STOP))
        {
            Sleep(500);
			click = 0;
            
		}
		if (click)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(n);
		}

	}
}


void meniu(char START, char STOP, char CHANGE)
{
    
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    printf("%c - START         \n",START);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    printf("%c - STOP          \n",STOP);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    printf("%c - SETTINGS      ", CHANGE);
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 );

    printf("\n\n AutoClicker made by DarAlex");

}

int ChangeCPS()
{
    
    int n;
    system("CLS"); 
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    printf("CHANGE CLICKS PER SECOND (measured in milliseconds)\n\n\n");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 );
    scanf("%d", &n);
   /* if((char)n != (int)n)
    {printf("NOT A NUMBER");
    return 50;};*/
    while(n<50)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        printf("%d milliseconds is too fast! Please choose a more reasonable value.\n", n);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 );
        Sleep(1000);
        scanf("%d", &n);
    }
    system("CLS");
    return n;
}


int meniu_settings()
{
    int a=0;
    while(1)
    {   
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY );
    printf("1 - Change CPS  \n2 - Change BINDS\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 );
    scanf("%d", &a);
    printf("%d", a);
        if((a != 1) && (a != 2))
         {  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            printf("\nUnknown command, please try again!\n");
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 );
             Sleep(1000);
            system("CLS");
         }
        else 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 );
            system("CLS");
            break;
        }
    }
    return a;
}
void ChangeBind(char *ST , char *STP, char *CH)
{
    scanf("%c", ST);//Dummy read;
    printf("START: \n");
    scanf("%c", ST);
    if(*ST>=97)
    *ST-=32;    
    scanf("%c", STP);
    printf("STOP: \n");
    scanf("%c", STP);
    if(*STP>=97)
    *STP-=32;  
    scanf("%c", CH);
    printf("SETTINGS: \n");
    scanf("%c", CH);
    if(*CH>=97)
    *CH-=32;  
    system("CLS");

}