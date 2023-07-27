#include <iostream>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
//1123 ~ 34

int coins[10]={0};

int main(){
    ioboost;
    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> coins[i];
    }

    int left = k;
    int count = 0;
    while(left != 0){
        int index = 0;
        int currCount = 0;
        for(int i=0; i<n-1; i++){
            if(coins[index+1] <= left){
                index ++ ;
            }else{
                break;
            }
        }
        currCount = left/coins[index];
        left -= currCount*coins[index];
        count += currCount;
    }

    cout<<count;    
}
