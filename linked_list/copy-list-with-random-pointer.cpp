#include <iostream>
#include <unordered_map>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;
        if (head == NULL) return NULL;

        // First copy head
        Node* copiedList = new Node(head->val);
        Node* temp = head;
        Node* tempcopy = copiedList;
        m[head] = copiedList;

        // Copy nodes and build next pointers
        while (temp->next != NULL) {
            temp = temp->next;
            Node* newnode = new Node(temp->val);
            tempcopy->next = newnode;
            tempcopy = tempcopy->next;
            m[temp] = tempcopy;
        }

        // Assign random pointers
        temp = head;
        tempcopy = copiedList;
        while (temp != NULL) {
            if (temp->random != NULL) {
                tempcopy->random = m[temp->random];
            }
            tempcopy = tempcopy->next;
            temp = temp->next;
        }

        return copiedList;
    }
};

// Helper function to print list with random pointers
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << "Node val: " << curr->val;
        if (curr->random) {
            cout << ", Random points to: " << curr->random->val;
        } else {
            cout << ", Random points to: NULL";
        }
        cout << endl;
        curr = curr->next;
    }
    cout << "----" << endl;
}

int main() {
    // Build list: 7 -> 13 -> 11 -> 10 -> 1
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Assign random pointers
    n1->random = NULL;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    cout << "Original list:" << endl;
    printList(n1);

    Solution sol;
    Node* copiedHead = sol.copyRandomList(n1);

    cout << "Copied list:" << endl;
    printList(copiedHead);

    return 0;
}
