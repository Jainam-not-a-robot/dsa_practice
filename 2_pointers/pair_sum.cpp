#include<iostream>
using namespace std;

int main(){
    int sorted_arr[10]={2,7,11,15};
    int target=17;
    int len=4;
    int l=0,r=len-1;
    while(r>l){
        if(sorted_arr[l]+sorted_arr[r]>target){
            r--;
        }
        else if(sorted_arr[l]+sorted_arr[r]<target){
            l++;
        }
        else{
            cout<<"Elements:"<<sorted_arr[l]<<" "<<sorted_arr[r];
            return 0;
        }
    }
    cout<<"No such numbers exist";
    return 1;
}//We used two pointer approach here, approaching from both the sides.