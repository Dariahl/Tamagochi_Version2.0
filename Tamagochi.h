//#ifndef _TAMAGOCHI_H
//#define _TAMAGOCHI_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <string.h>
#include <conio.h>

//----- For print cat ------
#define FILENAME "cote.txt"
#define SIZE 256

static char buf[SIZE] = {0};
static FILE* file;

//--------------------------

typedef struct 
{
  char name[40];
  int Health;
  int Hanger;
  int Mood;
}Characteristics;

static int TamLvl;
static int Dead;
static int i;

//-----  Print Cat ---------
void printCote();

//------- Sleep (lvl ++ ) ----------
void lvlPlas(Characteristics *tamagochi);

//------ Needs -- ----------
void needs(int *m_hanger, int *m_mood, int *m_health, Characteristics tamagochi);
void Need_Hanger(int *m_hanger, int *m_mood);   
void Need_Health(int *m_health, int *m_mood);  
void Need_Mood(int *m_mood);

//------ Needs ++ -----------
void Gochi_Eat(int *m_hanger, Characteristics tamagochi);
void Gochi_Mood(int *m_mood, Characteristics tamagochi);
void Gochi_Health(int *m_health, Characteristics tamagochi);

//#endif // _TAMAGOCHI_H
