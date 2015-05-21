#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
	int low, high = -1, count = 0;
	while (1) {
		low = high + 1;
		while (low + 1 < pricesSize && prices[low] >= prices[low + 1])
			low++;

		if (low + 1 >= pricesSize)
			break;

		high = low + 1;
		while (high + 1 < pricesSize && prices[high] <= prices[high + 1])
			high++;

		count += prices[high] - prices[low];
	}

	return count;
}

int main() {
	int prices[] = { 3, 2, 6, 5, 0, 3 };
	printf("%d",maxProfit(&prices, 6));
	getchar();
}