#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int choice;
	printf("Select the mode:\n");
	printf("Mode 1 - guess the number\n");
	printf("Mode 2 - make up a number\n");
	scanf_s("%d", &choice);
	if (choice == 1) {
		int cnt = 1;
		int secret = rand() % 1000 + 1;
		int user_guess;
		printf("Enter a number: ");
		scanf_s("%d", &user_guess);
		while (user_guess != secret) {
			if (user_guess < secret) {
				printf("Incorrect, the guessed number is greater. Try again: ");
				scanf_s("%d", &user_guess);
			}
			else {
				printf("Incorrect, the guessed number is smaller. Try again: ");
				scanf_s("%d", &user_guess);
			}
			cnt += 1;
		}
		printf("That`s right! This is the number %d\n", secret);
		printf("Number of attempts: %d", cnt);
		return 0;
	}
	else {
		int user_number;
		printf("Make up a number from 1 to 1000: ");
		scanf_s("%d", &user_number);
		int low = 1;
		int high = 1000;
		int cnt = 0;
		char answer = ' ';

		while (answer != '=') {
			int guess = (low + high) / 2;
			cnt += 1;
			printf("It is your number %d? Enter (<, >, =): ", guess);
			scanf_s(" %c", &answer, 1);
			if (answer == '>') {
				low = guess + 1;
			}
			else  if (answer == '<') {
				high = guess - 1;
			}
		}
		printf("I guessed your number!! It is %d;))\n", user_number);
		printf("Number of attempts: %d\n", cnt);
		return 0;
	}
	return 0;
}