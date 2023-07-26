#include <iostream>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int dp[50001];

int getMaxRoot(int n){
    if(n==1) return 1;
    int tmp = 1;
    while(tmp*tmp <= n){
        tmp ++;
    }
    return tmp-1;
}


int main(){
    ioboost;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        dp[i]=5;
    }

    int maxValue = getMaxRoot(n);
    for(int i=1; i<=maxValue; i++){
        int square1 = i*i;
        dp[square1] = 1;

        for(int j=1; j<=i; j++){
            int square2 = j*j;
            int sum1 = square1 + square2;
            if(sum1 > n) break;
            dp[sum1] = min(dp[sum1], 2);

            for(int k=1; k<=j; k++){
                int square3 = k*k;
                int sum2 = sum1 + square3;
                if(sum2 > n) break;
                dp[sum2] = min(dp[sum2], 3);

                for(int l=1; l<=k; l++){
                    int square4 = l*l;
                    int sum3 = sum2 + square4;
                    if(sum3 > n) break;
                    dp[sum3] = min(dp[sum3], 4);
                }
            }
        }

    }
    cout<<dp[n];
}

