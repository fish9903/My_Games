#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


// Same as Practice.c

int* Create_Number();

int main()
{
	int* number;

	number = Create_Number();	// Create the number to guess

	printf("\n");
	printf("\t\t// GUESS MY NUMBER //\n");
	printf("\t     // NUMBER : 1000 ~ 9999 //\n");
	printf("// The number of each digit of the number is different //\n");

	while (1)
	{
		int number_in;
		int temp_number_in;

		int strike = 0;
		int ball = 0;

		if (scanf("%d", &number_in) != 1)	// Enter the number you guess. Or enter none number, show the answer
		{
			printf("The answer : ");

			for (int i = 0; i < 4; i++)
			{
				printf("%d", number[i]);
			}
			printf("\n");

			getchar();

			continue;
		}
		
		temp_number_in = number_in;

		int num_in[4] = { 0, };

		for (int i = 0; i < 4; i++)	// Convert number to arr.
		{
			num_in[3 - i] = number_in % 10;

			number_in /= 10;
		}
		number_in = temp_number_in;

		int temp = 0;		// Compare
		for (int i = 0; i < 4; i++)
		{
			if (number[i] == num_in[i])
				temp++;	
		}
		
		if (temp == 4)
		{
			printf("// CORRECT! //\n");
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			if (num_in[i] == number[i]) 
				strike++;
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				if (num_in[i] == number[j] && i != j)
					ball++;
		}

		if (strike == 0 && ball == 0)
			printf("OUT!\n\n");
		else
			printf("%dS %dB\n\n", strike, ball);
	}

	return 0;
}

int* Create_Number()
{
	static int number[4] = { -1, -1, -1, -1};
	int temp_number;
	srand((int)time(NULL));

	for (int i = 0; i < 4; i++)
	{
		int temp;
		temp = rand() % 10;

		if (i == 0 && temp == 0)
		{
			while (temp == 0)
				temp = rand() % 10;
		}

		for (int j = 0; j < 4; j++)
		{
			if (number[0] == temp || number[1] == temp || number[2] == temp || number[3] == temp)
			{
				while (number[0] == temp || number[1] == temp || number[2] == temp || number[3] == temp)
					temp = rand() % 10;
			}
		}
		number[i] = temp;
	}

	return number;
}