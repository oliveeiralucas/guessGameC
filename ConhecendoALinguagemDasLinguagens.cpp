#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int pontuation(int guess, int secretNumber) {
	return abs(guess - secretNumber) / 2;
}

int tabuada() {
	printf("Input the number that you want to see the table of the number: ");
	int number;
	scanf_s("%d", &number);

	printf("Input the number that you want to see the lenght of the table of numbers ");
	int length;
	scanf_s("%d", &length);

	if (length < 0) {
		printf("Please insert a positive number for the length of the table.\n");
		return 1;
	}

	for (int i = 0; i <= length; i++)
	{
		printf("%d x %d = %d\n", number, i, (number * i));
	}

	return 0;
}

int main()
{
	tabuada();
	printf("***********************\n");
	printf("Welcome to your guess game\n");
	printf("***********************\n");

	srand((unsigned)time(NULL));

	bool gameOn = true;
	short range = 100;
	const short secretNumber = (rand() % range) + 1;
	const short MAX_GUESS_TIMES = 10;
	int guess;
	short attempts = 0;
	double points = 1000;
	do
	{
		printf("What is your guess? ");
		if (scanf_s("%d", &guess) != 1) {
			printf("Invalid input\n");
			continue;
		}

		if (guess < 0)
		{
			printf("Invalid input\n, negatives numbers are not possible in this game");
			continue;
		}

		if (guess < 1 || guess > range)
		{
			printf("The number needs to be between [0, %d]\n", range);
			continue;
		}

		attempts++;
		int lostPoints = pontuation(guess, secretNumber);
		points = points - lostPoints;

		if (secretNumber > guess)
		{
			printf("Too low, try again...\n");
		}
		else if (secretNumber < guess)
		{
			printf("Too high, try again...\n");
		}
		else {
			gameOn = false;
			printf("Congratulations you guess the number!!\n");
			break;
		}

		if (attempts >= MAX_GUESS_TIMES)
		{
			printf("Sorry, you have used all your attempts! The number was %d\n", secretNumber);
			break;
		}
	} while (gameOn);
	printf("Total Points: %.2f\n", points);
	return 0;
}