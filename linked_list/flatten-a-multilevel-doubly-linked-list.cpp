#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int v) : val(v), prev(nullptr), next(nullptr), child(nullptr) {}
};
*/

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int v) : val(v), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
    Node* helper(Node* head) {
        Node *current=head;
        Node *ans=nullptr;
        while(current){
            Node *next=current->next;
            if(current->child){
                Node* childTail=helper(current->child);
                current->next=current->child;
                current->next->prev=current;
                current->child=nullptr;
                if(next){
                    childTail->next=next;
                    childTail->next->prev=childTail;
                }
                current=childTail;
                ans=childTail;
            }
            else{
                ans=current;
            }
            current=current->next;
        }
        return ans;
    }
public:
    Node* flatten(Node* curr){
        if(!curr)return curr;
        helper(curr);
        return curr;
    }
};

// Utility to print flattened list
void printList(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    // Example:
    // 1 - 2 - 3
    //     |
    //     7 - 8

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    // Build top-level list: 1 <-> 2 <-> 3
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    // Add child: 2 -> child -> 7 <-> 8
    n2->child = n7;
    n7->next = n8;
    n8->prev = n7;

    // Flatten
    Solution sol;
    Node* flatHead = sol.flatten(n1);

    // Print result: should be 1 2 7 8 3
    cout << "Flattened list: ";
    printList(flatHead);

    return 0;
}
