#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> 

#define MAX_CODE 6
#define MAX_DIFF 25
#define EAZY 20
#define MODERATE 15
#define HARD 10


int secret1 = 0, secret2 = 0, secret3 = 0, secret4 = 0,rounds = 0,code1 = 0, code2 = 0, code3 = 0, code4 = 0, numberOfRounds = 0, hits = 0, misses = 0;
char ans = 'y';

void intro();
int difficult();
int randcode();
int playerCode();
void codedebug();
void check();
void tax();
void lose();
void win();

int main()
{
	srand(time(NULL));
	intro();
	difficult();
	randcode();
	
}

void intro()
{
	printf("Welcome to \"MAGSHIMIM CODE-BREAKER\"!!!\n"
	"A secret password was chosen to protect the credit card of Pancratius,\n"
	"the descendant of Antiochus.\n"
	"Your mission is to stop Pancratius by revealing his secret password.\n\n"
	"The rules are as follows:\n"
	"\n1. In each round you try to guess the secret password (4 distinct digits)\n"
	"\n2. After every guess you'll receive two hints about the password"
	   "\n   HITS:   The number of digits in your guess which were exactly right."
	   "\n   MISSES: The number of digits in your guess which belongs to"
           "\n   the password but were miss-placed.\n"
	"\n3. If you'll fail to guess the password after a certain number of rounds"
	   "\n   Pancratius will buy all the gifts for Hanukkah!!!\n\n");
}

int difficult()
{
	int diff = 0;
	
	printf("\n\nPlease choose the game level:\n"
			"1 - Easy (20 rounds)\n"
			"2 - Moderate (15 rounds)\n"
			"3 - Hard (10 rounds)\n"
			"4 - Crazy (random number of rounds 5-25)\n"
			"Make a Choice: ");
	scanf("%d", &diff);
	
	do
	{
		switch(diff)
		{
			case 1:
				rounds = EAZY;
				break;
			case 2:
				rounds = MODERATE;
				break;
			case 3:
				rounds = HARD;
				break;
			case 4:
				rounds = rand() %(MAX_DIFF)+1;
				break;
			default:
				printf("Make a choice: ");
				scanf("%d", &diff);
				break;
		}
	}while(diff == 0|| diff >4);
	
}


int randcode()
{
	secret1 = rand() %(MAX_CODE)+1;
	secret2 = rand() %(MAX_CODE)+1;
	secret3 = rand() %(MAX_CODE)+1;
	secret4 = rand() %(MAX_CODE)+1;
	
	while(secret1 == secret2||secret1 == secret3||secret1 == secret4||secret2 == secret4||secret3 == secret2||secret4 == secret3)
	{
		if(secret1 == secret2||secret1 == secret3||secret1 == secret4)
		{
			secret1 = rand() %(MAX_CODE)+1;
		}
		else if(secret2 == secret1||secret2 == secret3||secret2 == secret4)
		{
			secret2 = rand() %(MAX_CODE)+1;
		}
		else if(secret3 == secret2||secret3 == secret1||secret3 == secret4)
		{
			secret3 = rand() %(MAX_CODE)+1;
		}
		else if(secret4 == secret2||secret4 == secret3||secret4 == secret1)
		{
			secret4 = rand() %(MAX_CODE)+1;
		}
	}
	playerCode();
}

int playerCode()
{
	if(numberOfRounds<rounds)
	{
		printf("%d guesses left\n", rounds-numberOfRounds);

		numberOfRounds ++;
		printf("Write your guess (only 1-6, no ENTER is needed): ");
		printf("%c", code1 = getch());
		printf("%c", code2 = getch());
		printf("%c", code3 = getch());
		printf("%c\n", code4 = getch());
		code1 -= 48;
		code2 -= 48;
		code3 -= 48;
		code4 -= 48;

		codedebug();
	}
	else
	{
		lose();
	}
}

void codedebug()
{
	if(code1 > MAX_CODE || code1 < 1 || code2 > MAX_CODE || code2 < 1 || code3> MAX_CODE || code3 < 1 || code4 > MAX_CODE || code4 < 1||code1 == code2||code1 == code3||code1 == code4||code2 == code4||code3 == code2||code4 == code3)
	{
		numberOfRounds ++;
		playerCode();
	}
	else
	{
		check();
	}
}

void check()
{
	hits = 0;
	misses = 0;
	if(code1 == secret1)
	{
		hits ++;
	}
	else if(code1 == secret2 || code1 == secret3 ||code1 ==  secret4)
	{
		misses ++;
	}
	
	if(code2 == secret2)
	{
		hits ++;
	}
	else if(code2 == secret1 || code2 == secret3 ||code2 ==  secret4)
	{
		misses ++;
	}
	
	if(code3 == secret3)
	{
		hits ++;
	}
	else if(code3 == secret2 || code3 == secret1 ||code3 ==  secret4)
	{
		misses ++;
	}
	
	if(code4 == secret4)
	{
		hits ++;
	}
	else if(code4 == secret2 || code4 == secret3 ||code4 ==  secret1)
	{
		misses ++;
	}
	tax();
}

void tax()
{
	if (hits == 4)
	{
		win();
	}
	else
	{
		printf("you got: %d hits and %d misses.",hits,misses);
		playerCode();
	}
}

void win()
{
	printf("you win!");
	printf("\nplay again?(n/y): %c", ans = getch());
}

void lose()
{
	printf("\nyou lose!");
	printf("\nplay again?(n/y): %c", ans = getch());
}