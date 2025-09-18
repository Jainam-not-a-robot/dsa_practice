#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
        char arr[100];
        int top=-1;
        void push(char val){
            top++;
            if(top>=100){
                cout<<"Stack overloaded"<<endl;
                return;
            }
            arr[top]=val;
            return;
        }
        char pop(){
            if(top==-1){
                cout<<"Stack is empty"<<endl;
                return;
            }
            top--;
            return arr[top+1];
        }
};
int main(){

}