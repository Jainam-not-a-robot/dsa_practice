#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node* prev;
        Node(int val){
            data=val;
            next=NULL;
            prev=NULL;
        }
};
class List{
    Node* head;
    Node* tail;
    public:
        List(){
            head=tail=NULL;
        }
        void push_front(int val){
            if(head==NULL){
                head=tail=new Node(val);
            }
            else{
                Node *temp=head;
                head=new Node(val);
                head->next=temp;
                temp->prev=head;
            }
        }
        void push_back(int val){
            if(tail==NULL){
                head=tail=new Node(val);
            }
            else{
                Node* temp=tail;
                tail=new Node(val);
                temp->next=tail;
                tail->prev=temp;
            }
        }
        void display(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL";
        }
};
int main(){
    List l1;
    l1.push_front(4);
    l1.push_front(3);
    l1.push_back(5);
    l1.display();
    return 0;
}