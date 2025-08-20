#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
bool isValid(int mid,int m,int sum,vector<int> v){
    int m2=1,sum2=0;
    for(int i=0;i<v.size();i++){//1,3,5,4,2
        sum2+=v[i];
        if(sum2>mid){
            m2++;
            sum2=v[i];
        }  
    }
    if(m2>m){
            return false;
        }
    return true;

}
int recurse(int l,int r,int m,int sum,int answer,vector<int> v){
    int mid=(l+r)/2;
    if(l>r){
        return answer;
    }
    if(isValid(mid,m,sum,v)){
        answer=min(answer,mid);
        return recurse(l,mid-1,m,sum,answer,v);
    }
    else{
        return recurse(mid+1,r,m,sum,answer,v);
    }
}
int main(){
    vector<int> v={1,3,5,4,2};
    int sum=accumulate(v.begin(),v.end(),0);
    int m=3;
    int ans=recurse(0,sum-1,m,sum,sum,v);
    cout<<ans<<endl;
    return 0;
}//KYA DIMAAG LAGAYA BC WAAH