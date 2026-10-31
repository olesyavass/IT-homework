#include <stdio.h>
int main(void){
	printf("Enter your sequence of characters:\n");
	int c;
	int cnt_w = 0;
	int cnt_n = 0;
	int in = 0;
	int number = 1;
	int word = 1;
	while ((c = getchar()) != '\n' && c != EOF) {
		if (c == ' ' || c == '\t') {
			if (in) {
				if (number) {
					cnt_n += 1;
				}
				else if (word) {
					cnt_w += 1;
				}
				in = 0;
			}
		}
		else {
			if (!in) {
				in = 1;
				number = 1;
				word = 1;
			}
			if (c < '0' || c>'9') {
				number = 0;
			}
			int eng = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
			int rus = ((unsigned char)c >= 128);
			if (!eng && !rus) {
					word =  0;
			}
		}
	}
	if (in) {
		if (number) {
			cnt_n += 1;
		}
		else if (word) {
			cnt_w += 1;
		}
	}
	printf("Number of words: %d\n", cnt_w);
	printf("Number of numbers: %d\n", cnt_n);
	return 0;
}
