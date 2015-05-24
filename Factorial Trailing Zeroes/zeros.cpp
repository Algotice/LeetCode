#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int trailingZeroes(int n) {
		int sum = 0;
		while ((sum += n / 5) > 0 && (n /= 5) != 0);
		return sum;
	}
};

int main() {
	Solution s;
	cout << s.trailingZeroes(100);
}