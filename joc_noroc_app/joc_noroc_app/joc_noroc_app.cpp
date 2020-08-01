#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

int numbers_comparison(int current_number, int next_number) {
	if (next_number < current_number) {
		return 1;
	}
	else {
		if (next_number > current_number) {
			return 0;
		}

	}
}

void game_play() {
	srand(time(0));
	int credits = 0;
	int current_number = rand() % 20;
	printf("\033[1;35mNumber: %d\n\n\033[0m", current_number);

	while (1) {
		printf("\033[1;35mHow do you think the next number will be, smaller or bigger? Choose 1 for smaller and 2 for bigger \033[0m");
		int a;
		scanf("%d", &a);
		printf("\n");
		int next_number = rand() % 20;
		system(CLEAR_SCREEN);

		if (a == 1) {
			if (numbers_comparison(current_number, next_number) == 1) {
				credits = credits + 100;
				printf("Good guess! The number was %d.\n\n", next_number);
				printf("\033[0;32mCredits: %d\n\n\033[0m", credits);
			}
			else {
				if (numbers_comparison(current_number, next_number) == 0) {
					if (credits == 0) {
						printf("You lost. The number was %d and it was bigger\n\n", next_number);
						break;
					}
					else {
						credits = credits - 100;
						printf("Incorrect! The number was %d and it was bigger. You lost 100 credits.\n\n", next_number);
						printf("\033[0;32mCredits: %d\n\n\033[0m", credits);
					}
				}
			}
		}
		else {
			if (a == 2) {
				if (numbers_comparison(current_number, next_number) == 0) {
					credits = credits + 100;
					printf("Good guess! The number was %d.\n\n", next_number);
					printf("\033[0;32mCredits: %d\n\n\033[0m", credits);
				}
				else {
					if (numbers_comparison(current_number, next_number) == 1) {
						if (credits == 0) {
							printf("You lost. The number was %d and it was smaller.\n\n", next_number);
							break;
						}
						else {
							credits = credits - 100;
							printf("Incorrect! The number was %d and it was smaller. You lost 100 credits.\n\n", next_number);
							printf("\033[0;32mCredits: %d\n\n\033[0m", credits);
						}
					}
				}
			}
		}
		if (credits == 0) {
			printf("You lost the game:(\n\n");
			break;
		}
		current_number = next_number;
	}
}

int main() {
	int b;
	game_play();
	while (1) {
		printf("\033[1;36mDo you want to play again? Choose 1 for YES or 0 for NO \033[0m");
		scanf("%d", &b);

		if (b == 1) {
			system(CLEAR_SCREEN);
			game_play();
		}
		else {
			if (b == 0) {
				return 0;
			}
		}
	}
}