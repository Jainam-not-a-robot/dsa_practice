#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int len=11;
    int arr[len]={1,3,6,9,8,2,-1,-4,-5,-6,-7};//assuming ascending
    // int target=6;
    int l=0,r=len-1;
    int m=(l+r)/2;
    while(l<=r){

        m=(l+r)/2;
        if(arr[m]>arr[m-1]&&arr[m]>arr[m+1]){
            cout<<m<<endl;
            return 0;
        }
        if(arr[m]>arr[m-1]&&arr[m]<arr[m+1]){//left than target
            l=m+1;
        }
        else{//left half is sorted
            r=m-1;
        }
    }
    cout<<"Number not found"<<endl;
    return 0;
}