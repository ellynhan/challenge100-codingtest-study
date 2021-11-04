#include <iostream>
#include <queue>
using namespace std;
int dp[100000][5][5]={0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int command;
    cin >> command;

    int add[4] = {3,4,3,1};
    int phase = 0;
    queue<pair<int, int>> curr;

    //첫 동작
    if(command != 0){        
        curr.push({command,0});
        dp[0][command][0]=2;
        phase ++;
        cin >> command;
    }    
    while(command!=0){
        queue<pair<int, int>> next;
        while(!curr.empty()){
            pair<int, int> p = curr.front();
            curr.pop();
            for(int i=0; i<4; i++){
                int left = (p.first + i)%4+1;
                int addNum = add[i];
                if(p.first == 0){
                    addNum = 2;
                }
                if(left != command)continue;
                if(dp[phase][left][p.second]==0){ //처음 밟음
                    dp[phase][left][p.second]=dp[phase-1][p.first][p.second]+addNum;
                    next.push({left,p.second});
                }else{ //기록했던 적이 있음
                    if(dp[phase][left][p.second]>dp[phase-1][p.first][p.second]+addNum){
                        dp[phase][left][p.second]=dp[phase-1][p.first][p.second]+addNum;
                        next.push({left,p.second});
                    }
                }
            }
            for(int i=0; i<4; i++){
                int right = (p.second + i)%4+1;
                int addNum = add[i];
                if(p.second == 0){
                    addNum = 2;
                }
                if(right != command)continue;
                if(dp[phase][p.first][right]==0){
                    dp[phase][p.first][right]=dp[phase-1][p.first][p.second]+addNum;
                    next.push({p.first,right});
                }else{
                    if(dp[phase][p.first][right]>dp[phase-1][p.first][p.second]+addNum){
                        dp[phase][p.first][right]=dp[phase-1][p.first][p.second]+addNum;
                        next.push({p.first,right});
                    }
                }
                
            }
        }
        curr  = next;
        phase ++;
        cin >> command;
    }

    int minAnswer = INT32_MAX;
    if(phase==0){
        cout<<0;
    }else{
        for(int i=0; i<=4; i++){
            for(int j=0; j<=4; j++){
                if(dp[phase-1][i][j]==0)continue;
                minAnswer = min(minAnswer, dp[phase-1][i][j]);
            }
        }
        cout<<minAnswer;
    }   
}
