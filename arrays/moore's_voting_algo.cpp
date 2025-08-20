#include<iostream>
using namespace std
int main(){
    int len=10;
    int arr[len]={1,2,4,2,1,2,2,2,4,2};
    int count=0,elem=0;
    for(int i=0;i<len;i++){
        if(count==0){
            elem=arr[i];
            count=1;
        }
        else if(elem==arr[i]){
            count++;
        }
        else if(elem!=arr[i]){
            count--;
        }
    }
    cout<<elem;
    return 0;
}//Moore's voting algorithm is used to find the number in an array with frequency > n/2 times, with time complexity of O(n) most optimal. However, 
//it is necessary that such an element with frequency>n/2 exists, so, once you get final answer, check the frequency using for loop and if that is greater
//than n/2 then it is correct.