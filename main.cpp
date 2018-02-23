#include "Tamagochi.h"


void ShowMenu(int iItem);

void printHotKeys();
void playMusik();

int main()
{
    int m_Health = 30;
    int m_Hanger = 30;
    int m_Mood = 30;

    Characteristics Tamagochi;
	Tamagochi.Hanger = 30;
	Tamagochi.Health = 30;
	Tamagochi.Mood = 30;
//------------------------< MENU >---------------------------------
    int iItem = 1;
    int nLast = 2;

    ShowMenu(iItem);
    while(TRUE){
        if(GetAsyncKeyState(VK_UP)){
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
        if(0 < iItem - 1)
            iItem = iItem - 1;
        else
            iItem = nLast;
        
        ShowMenu(iItem);
    }

    if(GetAsyncKeyState(VK_DOWN)){
        keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
    if(iItem < nLast)
        iItem = iItem + 1;
    else
        iItem = 1;

    ShowMenu(iItem);
    }

    if(GetAsyncKeyState(VK_RETURN)){
        keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
        ShowMenu(iItem);
        switch(iItem){
            case 1:
				
				system("cls");
				
                while(TRUE){
                    if(Dead != 1){	
                        printHotKeys();
                        
                        system("cls");
                        
                        printf("Enter the name your pet: ");
						scanf("%s", Tamagochi.name);
						
            			needs(&m_Hanger, &m_Mood, &m_Health, Tamagochi);
                	}
            	}
                break;
            case 2:
                printf ("\n");
                printf("\t\t\t\t Good luck...\n");
                getch();
                exit(1);
                break;
        }
    }
}
    system("pause");
    return 0;
}


//--------------<Print Hot Keys>--------------
void printHotKeys(){
	 	printf("Your hot keys for playing with the pet:\n");
    	printf("The 'm' key - raises the mood of your pet\n");
        printf("The 'e' key - raises the satiety  of your pet\n");
    	printf("The 'h' key - raises the health of your pet\n");
		printf("By pressing the 's' key, you go to sleep your pet for 180 seconds, this increases its level, and its parameters.\nMaximum level = 10\n");
    	printf("Press any key to continue");
    	
    	playMusik();
    	
		getchar();
		getch();
}
//--------------<Play Musik>------------------
void playMusik(){
	Beep(247, 500);
 	Beep(417, 500);
    Beep(417, 500);
   	Beep(370, 500);
    Beep(417, 500);
    Beep(329, 500);
    Beep(247, 500);
    Beep(247, 500);
    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(497, 500);
    Sleep(500);
    Beep(497, 500);
    Beep(277, 500);
    Beep(277, 500);
    Beep(440, 500);
    Beep(440, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(329, 500);
    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(329, 500);    
}

void ShowMenu(int iItem)
{
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);


SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE |
FOREGROUND_GREEN | FOREGROUND_INTENSITY);

system("cls");

printf ("\n\n\n\n");
printf ("\t\t\t\t ________________\n");
printf ("\t\t\t\t|                |\n");
printf ("\t\t\t\t|------MENU------|\n");
printf ("\t\t\t\t|________________|\n");
if (iItem == 1)
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
if (iItem == 2)
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_INTENSITY);
printf ("\t\t\t\t ________________ \n");
printf ("\t\t\t\t|                | \n");
printf("%s\t\t\t\t|   1 - Play     |\n",iItem == 1 ? " " : " ");
printf ("\t\t\t\t|________________|\n");
if (iItem == 1)
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_INTENSITY);
if (iItem == 2)
    SetConsoleTextAttribute(hStdOut,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
printf ("\t\t\t\t ________________\n");
printf ("\t\t\t\t|                | \n");
printf("%s\t\t\t\t|   2 - Exit     |\n", iItem == 2 ? " " : " ");
printf ("\t\t\t\t|________________|\n");

//system("pause");
}
