#include<bits/stdc++.h>
class Node{
    public:
        int data;
        Node* next;
        Node(int val):data(val),next(nullptr){};
        Node(int val,Node* node):data(val),next(node){};
};
class LinkedList{
    public:
        Node* head=nullptr;
        void push_front(int val){
            if(head==nullptr){
                head=new Node(val);
                head->next=head;
                return;
            }
            Node* temp=head;
            while(temp->next!=head)temp=temp->next;
            Node *newnode=new Node(val,head);
            temp->next=newnode;
        }

};
int main(){

}