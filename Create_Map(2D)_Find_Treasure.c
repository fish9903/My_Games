#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

int* Create_Map(int row, int col);

int main()
{
	// Create map
	int row, col;
	scanf("%d %d%*c", &row, &col);

	int** map = Create_Map(row, col);

	// Set position of treasure
	int row_treasure, col_treasure;

	srand((unsigned int)time(NULL));

	row_treasure = rand() % row;
	col_treasure = rand() % col;

	map[row_treasure][col_treasure] = 1;

	// Start position
	int row_start, col_start;

	row_start = rand() % row;
	col_start = rand() % col;

	while (row_treasure == row_start && col_treasure == col_start)
	{
		row_start = rand() % row;
		col_start = rand() % col;
	}
	map[row_start][col_start] = 7;


	printf("\ntreasure(1) = (%drow, %dcol)\nstart(7) = (%drow, %dcol)\n\n", row_treasure, col_treasure, row_start, col_start);

	while (1)
	{
		// Find treasure
		if (map[row_treasure][col_treasure] == map[row_start][col_start])
		{
			break;
		}

		
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				printf("%d ", map[i][j]);
			printf("\n");
		}
		printf("\n");


		char movement;
		int error = 0;

		scanf("%c%*c", &movement);

		if (movement == 'w')	// Up
		{
			if (row_start > 0)
			{
				map[row_start][col_start] = 0;
				row_start--;
			}
			else
			{
				printf("Wrong movement\n");
				error = 1;
			}

			if (error == 1)
				continue;
		}
		else if(movement == 'a')	// Left
		{
			if (col_start > 0)
			{
				map[row_start][col_start] = 0;
				col_start--;
			}				
			else
			{
				printf("Wrong movement\n");
				error = 1;
			}
			if (error == 1)
				continue;
		}
		else if(movement == 's')	// Down
		{
			if (row_start < row - 1)
			{
				map[row_start][col_start] = 0;
				row_start++;
			}
			else
			{
				printf("Wrong movement\n");
				error = 1;
			}
			if (error == 1)
				continue;
		}
		else if(movement == 'd')	// Right
		{
			if (col_start < col - 1)
			{
				map[row_start][col_start] = 0;
				col_start++;
			}
			else
			{
				printf("Wrong movement\n");
				error = 1;
			}
			if (error == 1)
				continue;
		}
		else
		{
			printf("Wrong movement\n");
			continue;
		}

		map[row_start][col_start] = 7;
	}

	
	printf("Congratulaion!!");

	// free
	for (int i = 0; i < row; i++)
	{
		free(map[i]);
	}

	free(map);

	return 0;
}

int* Create_Map(int row, int col)
{
	int** arr = malloc(sizeof(int*) * row);

	for (int i = 0; i < row; i++)
	{
		arr[i] = malloc(sizeof(int) * col);
	}

	for (int i = 0; i < row; i++)
	{
		memset(arr[i], 0, sizeof(arr[i]));
	}

	return arr;
}