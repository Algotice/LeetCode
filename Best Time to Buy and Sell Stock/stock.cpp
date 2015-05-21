#include <iostream>
#include <vector>

using namespace std;

//使用cpp，RunTime 超越大部分同语言，在跳出判断上稍作处理
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//int low = 0, high = 0, count = 0;
		int low, high = -1, count = 0;
		prices.push_back(-2);
		prices.push_back(-1);

		while (true) {
			//if (high != 0) {
			//	low = high + 1;
			//}

			low = high + 1;
			while (prices[low] >= prices[low + 1] || prices[low] == 0)
				low++;

			if (prices[low] < 0)
				break;

			high = low + 1;
			while (prices[high] <= prices[high + 1])
				high++;


			count += prices[high] - prices[low];
		}

		return count;
	}
};

//int main() {
//	Solution s;
//	int array[] = { 1, 7, 5, 4, 7, 8, 2, 6, 7 };
//	vector<int> v(array, array+ sizeof(array)/sizeof(int));
//	cout << s.maxProfit(v);
//}