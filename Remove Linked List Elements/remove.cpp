#include <iostream>

using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode *p = head, *pr = head;

		while (head != NULL && head->val == val) {
			head = head->next;
		}

		if (head == NULL)
			return head;

		while (p->next != NULL)
		{
			p = p->next;

			if (p->val == val) {
				pr->next = p->next;
			}

			if (pr->next != p->next)
				pr = pr->next;
		}

		return head;
	}
};

int main() {
	ListNode *l = new ListNode(1);
	l->next = new ListNode(1);
	Solution s;
	l = s.removeElements(l, 1);

}