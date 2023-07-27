#include <iostream>
using namespace std;
int num[2000];
int dp[2000][2000]={0};
int mid_len[2000][2]={0};

int check(int from, int to){
    if(dp[from][to]!=0){
        return dp[from][to];
    }

    int sum = from+to;
    int mid = sum/2;
    if(sum%2!=0){
        for(int i=0; i<to-mid; i++){
            if(num[mid-i]==num[mid+i+1]){
                dp[mid-i][mid+i+1]=1;
            }else{
                for(int j=i; j<to-mid; j++){
                    dp[mid-j][mid+j+1]=-1;
                }
                break;
            }
        }
    }else{
        for(int i=0; i<=to-mid; i++){
            if(num[mid-i]==num[mid+i]){
                dp[mid-i][mid+i]=1;
            }else{
                for(int j=i; j<=to-mid; j++){
                    dp[mid-j][mid+j]=-1;
                }
                break;
            }
        }
    }
    return dp[from][to];
}

int main(){
    int n, m;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&num[i]);
    }
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        int from, to;
        scanf("%d%d",&from,&to);
        int answer = check(from-1, to-1);
        if(answer<0){
            printf("%d\n",0);
        }else{
            printf("%d\n",answer);
        }
    }
}
