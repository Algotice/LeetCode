#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		const int INTERVAL = 64;
		const int CYCLE = 26;

		int count = 0;
		for (int i = 0; i < s.length(); i++) {
			count += (s.at(i) - INTERVAL) * pow(CYCLE, s.length() - i - 1);
		}

		return count;
	}
};

//int main() {
//	Solution s;
//	cout << s.titleToNumber("Z");
//}