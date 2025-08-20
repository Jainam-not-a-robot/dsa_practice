#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int len=10;
    int arr[len]={8,9,10,1,2,3,4,5,6,7};//assuming ascending
    int target=6;
    int l=0,r=len-1;
    int m=(l+r)/2;
    while(l<=r){

        m=(l+r)/2;
        if(arr[m]==target){
            cout<<m;
            return 0;
        }
        if(arr[l]>arr[m]){//right is sorted
            if(target>=arr[m]&&target<=arr[r]){
                l=m+1;
            }
            
            else{
                r=m-1;
            }
        }
        else{//left half is sorted
            if(target<=arr[m]&&target>=arr[l]){
                r=m-1;
            }
            
            else{
                l=m+1;
            }
        }
    }
    cout<<"Number not found";
    return 0;
}



