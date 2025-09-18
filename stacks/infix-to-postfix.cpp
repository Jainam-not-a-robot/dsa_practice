#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
        char arr[100];
        int high=-1;
        void push(char val){
            high++;
            if(high>=100){
                cout<<"Stack overloaded"<<endl;
                return;
            }
            arr[high]=val;
            return;
        }
        char pop(){
            if(high==-1){
                cout<<"Stack is empty"<<endl;
                return ' ';
            }
            high--;
            return arr[high+1];
        }
        char top(){
            if(high<0)return ' ';
            return arr[high];
        }
};
void postfix(string infix,string &ans){
    Stack s;
    for(auto &x:infix){
        if(x=='-'||x=='+'){
            while(s.top()!=' '&&s.top()!='('){
                ans+=s.pop();
            }
            s.push(x);
        }
        else if(x=='*'||x=='/'){
            while(s.top()!=' '&&s.top()!='-'&&s.top()!='+')ans+=s.pop();
            s.push(x);

        }
        else if(x=='(')s.push(x);
        else if(x==')'){
            while(s.top()!='(')ans+=s.pop();
            s.pop();
        }
        else ans+=x;
    }
    while(s.top()!=' ')ans+=s.pop();
    return;
}
int main(){
    string infix="(a+b)-c*d";
    string ans="";
    postfix(infix,ans);
    cout<<ans<<endl;
}