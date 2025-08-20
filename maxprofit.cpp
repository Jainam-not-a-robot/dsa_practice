#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int len=6;
    int stockprice[len]={2,5,1,3,6,2};
    int best_buy=stockprice[0];
    int best_sell;
    int maxprofit=0;
    for(int i=1;i<len;i++){
        if(stockprice[i]>best_buy){
            maxprofit=max((stockprice[i]-best_buy),maxprofit);
        }
        best_buy=min(best_buy,stockprice[i]);
    }
    cout<<maxprofit;
    return 0;
}