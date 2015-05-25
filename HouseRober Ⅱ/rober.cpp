#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();

		if (n == 0){
			return 0;
		}
		if (n == 1){
			return nums[0];
		}
		if (n == 2){
			return nums[0] > nums[1] ? nums[0] : nums[1];
		}

		vector<int> f(n - 1, 0);
		f[0] = nums[0];
		f[1] = nums[0] > nums[1] ? nums[0] : nums[1];
		for (int i = 2; i < n - 1; i++){
			f[i] = f[i - 1] > f[i - 2] + nums[i] ? f[i - 1] : f[i - 2] + nums[i];
		}

		vector<int> g(n - 1, 0);
		g[0] = nums[1];
		g[1] = nums[1] > nums[2] ? nums[1] : nums[2];
		for (int i = 3; i < n; i++){
			g[i - 1] = g[i - 2] > g[i - 3] + nums[i] ? g[i - 2] : g[i - 3] + nums[i];
		}

		return f[n - 2] > g[n - 2] ? f[n - 2] : g[n - 2];
	}
};

//5 2 3 2 6 7