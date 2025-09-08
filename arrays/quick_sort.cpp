#include <bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr,int l,int r){
    int j=l;
    if(l<r){
        for(int idx=l;idx<r;idx++){
            if(arr[idx]<=arr[r]){
                swap(arr[j++],arr[idx]);
            }            
        }
        swap(arr[j],arr[r]);
    }
    return j;
}
void recurse(vector<int>&arr,int l,int r){
    if(l<r){
        int pivot_idx=partition(arr,l,r);
        recurse(arr,l,pivot_idx-1);
        recurse(arr,pivot_idx+1,r);
    }
}
int main(){
    vector<int>arr={3,2,6,5,1,8,4};
    int pivot=arr[arr.size()-1];
    recurse(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<' ';
    return 0;
}