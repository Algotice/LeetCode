#include <iostream>
#include <vector>
#include <math.h>
#include <iterator>

using namespace std;

class Solution {
public:
	int countPrimes(int n) {

		vector<bool> judge(n, true);

		for (int i = 2; i <= sqrt(n); i++){
			if (judge[i]) {
				for (int j = pow(i, 2); j < n; j+=i){
					judge[j] = false;
				}
			}
		}

		int count = 0;
		for (unsigned int i = 2; i < judge.size();i++) {
			if (judge[i])
				count++;
		}

		return count;
	}
};

int main() {
	Solution s;
	cout<<s.countPrimes(2);
}