#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void recurse(int l,int r, vector<int> v){
    int m=(l+r)/2;
    if(l>r){
        return;
    }
    if(m==0&&v[0]!=v[1]){
        cout<<v[0]<<endl;
        return;
    }
    if(m==v.size()-1&&v[m]!=v[m-1]){
        cout<<v[m]<<endl;
        return;
    }
    if(v[m]!=v[m+1]&&v[m]!=v[m-1]){
        cout<<v[m]<<endl;
        return;
    }

    if(v[m]==v[m+1]){
        if(m%2==0){
            recurse(m+2,r,v);
        }
        else{
            recurse(l,m-1,v);
        }
    }
    else if(v[m]==v[m-1]){
        if(m%2==0){
            recurse(l,m-2,v);
        }
        else{
            recurse(m+1,r,v);
        }
    }

    
}
int main(){
    vector<int> v={2,2,3,3,4,4,5,5,6};
    int l=0,r=v.size()-1;
    recurse(l,r,v);
}