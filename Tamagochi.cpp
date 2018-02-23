#include "Tamagochi.h"


//----------------<Print Cote>----------------
void printCote(){
 	
 	file = fopen(FILENAME, "r");
 	
  	printf("\n\n");
 	
 	while (fgets(buf, SIZE, file) != NULL){
		printf("%s", buf);
    }
	
    fclose(file);
}

//----------------<LVL>-----------------------
void lvlPlas(Characteristics *tamagochi){

	int p = 0;
	
		while(TamLvl <= 10){  
		if(p != 1){
			
			printf("Your pet is sleeping 180s\n");              
    		sleep(180);
           	tamagochi->Mood   += 50;
            tamagochi->Hanger += 50;
            tamagochi->Health += 50;

            i++;
            printf("LVL %d:\nMood: %d\n", i, tamagochi->Mood);
            printf("Hanger: %d\n", tamagochi->Hanger);
            printf("Health: %d\n", tamagochi->Health);
            sleep(1);
            system("cls");
            p++; 
    	}
    	else break;
	}
    p = 0;
		
    TamLvl++;
    if(TamLvl == 10)
    {
        printf("Your pet will die in 5 minutes\n");
        sleep(300);
        Dead = 1;
        exit(1);
    }         
}

//------------------< NEDDS -- >--------------------------

void Need_Mood(int *m_mood)
{
        if(*m_mood != 0){
        	*m_mood -= 1;
		}
}

void Need_Hanger(int *m_hanger, int *m_mood)
{   
    int b = 0 , moodPr = 0;
    b = *m_mood;
    moodPr = b * 50 / 100;  

        if(*m_mood == moodPr){
            *m_hanger -= 2;
        }
        else {
            *m_hanger -= 1;
        }
    
    if(*m_hanger == 0){
        printf("Your Tamagotchi died\n");
        Dead = 1;
        exit(0);
    }
}

void Need_Health(int* m_health, int *m_mood)
{
    int b = 0 , moodPr = 0;
    b = *m_mood;
    moodPr = b * 50 / 100;  

        if(*m_mood == moodPr){
            *m_health -= 2;
        }
        else {
            *m_health -= 1;
        }

    if(*m_health == 0){
        printf("Your Tamagotchi died\n");
        Dead = 1;
        exit(0);
    }
}

void needs(int *m_hanger, int *m_mood, int *m_health, Characteristics tamagochi)
{
	HANDLE hStdOut = GetStdHandle (STD_OUTPUT_HANDLE);
	
    *m_mood = tamagochi.Hanger;
    *m_hanger = tamagochi.Hanger;
    *m_health = tamagochi.Health;
	
    while(TRUE){
    	if(m_hanger != 0 || m_health != 0){
			if(kbhit()){
				switch(getch()){
					case 109: {
						Gochi_Mood(m_mood, tamagochi); 
						break;
					}
					case 101: {
                    	Gochi_Eat(m_hanger, tamagochi);
						break;
					}
					case 104: {
                    	Gochi_Health(m_health, tamagochi);
						break;
					}
					case 115: {
                    	lvlPlas(&tamagochi); 
						break;
					}
				default: continue;
				}	
			}
			else{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				printCote();
				
				sleep(1);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);	
        		Need_Mood(m_mood);
        		Need_Hanger(m_hanger, m_mood);
        		Need_Health(m_health, m_mood);
        		
        		system("cls");
        		printf ("\t\t\t\t ___________________\n");
				printf ("\t\t\t\t     Mood = %d      \n", *m_mood);
				printf ("\t\t\t\t    Hanger = %d     \n", *m_hanger);
				printf ("\t\t\t\t    Health = %d     \n", *m_health);
				printf ("\t\t\t\t____________________\n");
			}
		}
    }
}

//------------------<Gochi needs ++>----------------------------------

void Gochi_Eat(int *m_hanger, Characteristics tamagochi){
	if(tamagochi.Hanger > *m_hanger){
		*m_hanger += 5; printf("You're doing fine! His Hanger = %i\n", *m_hanger);	
		Beep(600, 1000);
	}
    else printf("Your pet is not hungry\n");
}

void Gochi_Mood(int *m_mood, Characteristics tamagochi){
	if(tamagochi.Mood > *m_mood){
		*m_mood += 5; printf("You're doing fine! His Mood = %i\n", *m_mood);
		Beep(600, 1000);
	}
    else printf("Your pet does not want to play\n");
}

void Gochi_Health(int *m_health, Characteristics tamagochi){
	if(tamagochi.Health > *m_health){
		*m_health += 5; printf("You're doing fine! His Health = %i\n", *m_health);
		Beep(600, 1000);
	}
	else printf("Your pet is healty\n");
}
