#include <stdio.h>

int trailingZeroes(int n) {
	int sum = 0;
	while ((sum += n / 5) && (n /= 5));
	return sum;
}

int main() {
	trailingZeroes(10);
}

// 0ms ...