#include <iostream>

using namespace std;

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)	//p == q == NULL doesn't work
			return true;
		else if (p == NULL || q == NULL)
			return false;
		else
		{
			if (p->val != q->val)
				return false;
			else
			{
				if (!isSameTree(p->left, q->left))
					return false;
				return isSameTree(p->right, q->right);
			}
		}

	}
};

int main(){
	

	return 0;
}