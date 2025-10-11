#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int>s;
    vector<int> values={100,80,60,70,60,75,85};
    vector<int>span(values.size());
    for(int i=0;i<values.size();i++){
        while(!s.empty()&&values[s.top()]<=values[i]){
            s.pop();
        }
        if(s.empty())span[i]=i+1;
        else span[i]=i-s.top();
        s.push(i);
    }
    for(int i=0;i<values.size();i++)cout<<span[i]<<" ";
}