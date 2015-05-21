#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0){
			return 0;
		}
		if (nums.size() == 1){
			return nums[0];
		}
		if (nums.size() == 2){
			return nums[0] > nums[1] ? nums[0] : nums[1];
		}

		int n = nums.size();
		vector<int> f (n, 0);
		f[0] = nums[0];
		f[1] = nums[0] > nums[1] ? nums[0] : nums[1];
		for (int i = 2; i < n; i++){
			f[i] = f[i - 1] > f[i - 2] + nums[i] ? f[i - 1] : f[i - 2] + nums[i];
		}
		return f[n-1];
	}
private:
	int i = 0;
};

int main() {
	Solution s;
	//int array[] = { 155, 44, 52, 58, 250, 225, 109, 118, 211, 73, 137, 96, 137, 89, 174, 66, 134, 26, 25, 205, 239, 85, 146, 73 };
	int array[] = { 155, 44, 52, 58, 250, 225, 109, 118, 211, 73, 137, 96, 137, 89, 174, 66, 134, 26, 25, 205, 239, 85, 146, 73, 55, 6, 122, 196, 128, 50, 61, 230, 94, 208, 46, 243, 105, 81, 157, 89, 205, 78, 249, 203, 238, 239, 217, 212, 241, 242, 157, 79, 133, 66, 36, 165 };
	vector<int> v (array, array + sizeof(array) / sizeof(int));
	cout<<s.rob(v);
}