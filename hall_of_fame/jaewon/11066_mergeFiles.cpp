#include <iostream>
using namespace std;

int method[501][501]={0};
int dp[501][501]={0};

int getDp(int from, int to){
    if(dp[from][to]!=0){
        return dp[from][to];
    }
    if(from == to)return 0; //이 부분을 간과해서 고민한 시간이 길어졌다. dp는 cost일 뿐이었다.
    int minValue = 1000000000;
    for(int i=from; i<to; i++){
        int curr = getDp(from,i)+getDp(i+1,to);
        minValue = min(minValue,curr+method[from][to]);
    }
    dp[from][to]=minValue;
    return dp[from][to];
}

int main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
        int chapter;
        cin >> chapter;
        for(int i=1; i<=chapter; i++){
            cin >> method[i][i];
            for(int j=1; j<=chapter; j++){
                dp[i][j]=0;
            }
        }
        for(int i=1; i<chapter; i++){
            for(int j=i+1; j<=chapter; j++){
                method[i][j] = 0;
                for(int k=i; k<=j; k++){
                    method[i][j] += method[k][k];
                }
            }
        }
        cout<<getDp(1,chapter)<<endl;
    }
}
