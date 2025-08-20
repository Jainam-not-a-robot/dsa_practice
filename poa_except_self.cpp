#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int len=5;
    int arr[len]={1,3,5,2,4};
    int ans[len]={0};
    int prod=1;
    for(int i=0;i<len-1;i++){
        prod*=arr[i];
        ans[i+1]+=prod;
    }
    ans[0]=1;
    prod=1;
    for(int i=len-1;i>0;i--){
        prod*=arr[i];
        ans[i-1]*=prod;
    }
    for(int i=0;i<len;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}//This approach takes O(n) time complexity and O(1) space complexity