#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr={6,8,0,1,3};
    stack<int>s;
    vector<int>ans(arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        while(!s.empty()&&arr[s.top()]<=arr[i])s.pop();
        if(s.empty())ans[i]=-1;
        else ans[i]=arr[s.top()];
        s.push(i);
    }
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
}