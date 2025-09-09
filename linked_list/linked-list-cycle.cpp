#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {
    // Create nodes
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    // Build linked list: 3 -> 2 -> 0 -> -4
    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Case 1: Create a cycle (-4 -> 2)
    node4->next = node2;
    Solution sol;
    cout << "Has cycle? " << (sol.hasCycle(head) ? "Yes" : "No") << endl;

    // Case 2: Break the cycle (-4 -> NULL)
    node4->next = NULL;
    cout << "Has cycle? " << (sol.hasCycle(head) ? "Yes" : "No") << endl;

    return 0;
}
