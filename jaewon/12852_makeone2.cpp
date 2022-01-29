#include <iostream>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int dp[1000001]={0};

int main(){
    int x;
    cin >> x;
    dp[1]=0;
    for(int i=1; i<x; i++){
        if(i<=x/3){
            if(dp[i*3]==0)dp[i*3]=1000001;
            dp[i*3] = min(dp[i] + 1, dp[i*3]);  
        }
        if(i<=x/2){
            if(dp[i*2]==0)dp[i*2]=1000001;
            dp[i*2] = min(dp[i] + 1, dp[i*2]);
        }
        if(dp[i+1]==0)dp[i+1]=1000001;
        dp[i+1] = min(dp[i] + 1, dp[i+1]);
    }
    cout<<dp[x]<<'\n';
    for(int i=x; i>=1;){
        cout<<i<<" ";
        if(i%3==0 && i%2==0){
            if(dp[i/3]<=dp[i/2]){
                if(dp[i/3]<=dp[i-1]){
                    i/=3;
                }else{
                    i-=1;
                }
            }else{
                if(dp[i/2]<=dp[i-1]){
                    i/=2;
                }else{
                    i-=1;
                }
            }
        }else if(i%3==0 && i%2!=0){
            if(dp[i/3]<=dp[i-1]){
                i/=3;
            }else{
                i-=1;
            }
        }else if(i%3!=0 && i%2==0){
            if(dp[i/2]<=dp[i-1]){
                i/=2;
            }else{
                i-=1;
            }
        }else {
            i-=1;
        }
    }
}
