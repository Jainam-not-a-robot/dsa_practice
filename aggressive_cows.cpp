#include <bits/stdc++.h>
using namespace std;
bool isPossible(int m,vector<int> v,int cows){
    int last_cow_val=v[0];
    int cnt=1;
    for(int i=1;i<v.size();i++){
        if(v[i]-last_cow_val>=m){
            cnt++;
            last_cow_val=v[i];
        }
    }
    if(cnt>=cows)return true;
    else return false;
}
int main() {
    int a;
    cin>>a;
    int minval=INT_MAX,maxval=INT_MIN;
    vector<int> v(a);
    int cows;
    cin>>cows;
    for(int i=0;i<a;i++){
        cin>>v[i];
        minval=min(v[i],minval);
        maxval=max(v[i],maxval);
    }
    sort(v.begin(),v.end());
    int l=1,r=maxval-minval;
    int ans=-1;
    while(l<=r){
        int m=(l+r)/2;
        if(isPossible(m,v,cows)){
            ans=m;
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}