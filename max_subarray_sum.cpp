#include<iostream>
using namespace std;
int max(int a,int b){
    if(a>=b) return a;
    else return b;
}
int main(){
    int arr[10]={3,-4,5,4,-1,7,-8};
    int max_sum=0;
    int curr_sum=0;
    int len=7;
    for(int i=0;i<len;i++){
        curr_sum=0;
        for(int j=i;j<len;j++){
            curr_sum+=arr[j];
            max_sum=max(curr_sum,max_sum);
        }
    }
    cout<<max_sum;
    return 0;
}//This is Kadane's algorithm, normally by brute force approach, time complexity is O(x**3) but by this method it is O(x**2)