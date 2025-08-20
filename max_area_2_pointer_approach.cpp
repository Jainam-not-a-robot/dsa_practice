#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    int len=9;
    int waterheight[len]={1,8,6,2,5,4,8,3,7};
    int lp=0,rp=len-1;
    int maxarea=0;
    while(lp<rp){
        int w=rp-lp;
        int h=min(waterheight[lp],waterheight[rp]);
        maxarea=max(maxarea,w*h);
        if(waterheight[lp]>waterheight[rp]){
            rp--;
        }
        else{
            lp++;
        }
        
    }
    cout<<maxarea;
    return 0;
}//This approach is known as 2 pointer approach where we start from end point and starting point, just like we do in finding palindrome