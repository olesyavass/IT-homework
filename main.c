#include <stdio.h>
int main(void) {
	int x1, y1;
	int x2, y2;
	int figure;
	printf("Enter x1, y1 from 1 to 8:");
	scanf_s("%d %d", &x1, &y1);
	printf("Enter x2, y2 from 1 to 8:");
	scanf_s("%d %d", &x2, &y2);
	int dx = x2 - x1;
	if (dx < 0) {
		dx = -dx;
	}
	int dy = y2 - y1;
	if (dy < 0) {
		dy = -dy;
	}
	printf("Select a figure:\n");
	printf("1 - Korol\n2 - Ferz\n3 - Ladya\n4 - Slon\n5 - Kon\n");
	printf("Your choice: ");
	scanf_s("%d", &figure);

	int can_1 = (dx <= 1 && dy <= 1);
	int can_2 = (dx == dy || dx == 0 || dy == 0);
	int can_3 = (dx == 0 || dy == 0);
	int can_4 = (dx == dy);
	int can_5 = (dx == 2 && dy == 1) || (dx == 1 && dy == 2);

	int p;
	if (figure == 1) p = can_1;
	if (figure == 2) p = can_2;
	if (figure == 3) p = can_3;
	if (figure == 4) p = can_4;
	if (figure == 5) p = can_5;
	if (p == 1) {
		printf("Yes, the figure could go like that!\n");
	}
	else {
		printf("No, the figure can`t go like that:(\n");
		printf("Other figures, that could go this way:\n");
		if (figure != 1 && can_1 == 1) printf("Korol\n");
		if (figure != 2 && can_2 == 1) printf("Ferz\n");
		if (figure != 3 && can_3 == 1) printf("Ladya\n");
		if (figure != 4 && can_4 == 1) printf("Slon\n");
		if (figure != 5 && can_5 == 1) printf("Kon\n");
	}
	return 0;
}