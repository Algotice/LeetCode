#include <stdio.h>
#include <math.h>

int titleToNumber(char* s) {
	const int INTERVAL = 64;
	const int CYCLE = 26;

	int count = 0;
	int length = 0;
	int i;

	while (s[length] != '\0'){
		length++;
	}

	for (i = 0; i < length; i++) {
		count += (s[i] - INTERVAL) * (int)pow(CYCLE, length - i - 1);
	}

	return count;
}

int main() {
	printf ("%d",titleToNumber("AA"));
}