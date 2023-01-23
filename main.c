#include <stdio.h>
#include "input.h"

#define COLS 40
#define ROWS 20

#define clearScreen() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

typedef struct _SnakeBody
{
	int x;
	int y;
} SnakeBody;

typedef enum _direction{UP, DOWN, LEFT, RIGHT} direction;

typedef struct _Snake
{
	int x;
	int y;
	char character;
	direction dir;
	SnakeBody* snakeBodies;	
} Snake;

void printSnake(Snake snake)
{
	gotoxy(snake.x, snake.y);
	printf("%c", snake.character);	
}

void drawMap(Snake snake)
{
	clearScreen();
	for (int y = 0; y < ROWS; ++y)
	{
		for (int x = 0; x < COLS; ++x)
		{
			if (x == 0 || x == COLS - 1 || y == 0 || y == ROWS - 1)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
	printSnake(snake);
}

void start(void)
{
	clearScreen();

	printf("Movement:\n");
	printf("UP: 'i'\n");
	printf("DOWN: 'k'\n");
	printf("LEFT: 'j'\n");
	printf("RIGHT: 'l'\n");
	printf("\n");
	printf("To quit during gameplay: 'q'\n");
	printf("\n");
	printf("Press Enter to start");
	getchar();	
}

Snake processInput(Snake snake, char input)
{
	return snake;
}

void update(Snake snake, char input)
{
	snake = processInput(snake, input);
}

void render(Snake snake)
{
	drawMap(snake);
}

int main(void)
{
	start();

	Snake snake;

	snake.x = COLS/2;
	snake.y = ROWS/2;
	snake.character = 'S';

	drawMap(snake);

	char input;
	while( input != 'q' )
	{
		if ( kbhit() ) 
			input = getchar();

		update(snake, input);
		render(snake);
	}

	// Put cursor to the end
	gotoxy(COLS, ROWS);
	printf("\n");
	return 0;
}
