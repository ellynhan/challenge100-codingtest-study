#include <iostream>
#include <queue>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int ladder[101]={0};
int snake[101]={0};
int dp[101];

void bfs(int start){
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        int next;
        if(ladder[curr]!=0){ //사다리가 있는 경우
            next = ladder[curr];
            if(dp[next]==-1 || (dp[next]!=-1 && dp[next]>dp[curr])){ 
                dp[next] = dp[curr];
                q.push(next);
            }
        }else if(snake[curr]!=0){ //뱀이 있는 경우
            next = snake[curr];
            if(dp[next]==-1 || (dp[next]!= -1 && dp[next]>dp[curr])){
                dp[next] = dp[curr];
                q.push(next);
            }
        }else{ 
            for(int i=1; i<=6; i++){
                next = curr + i;
                if(next > 100) break;
                if(dp[next]==-1 || (dp[next]!=-1 && dp[next]>dp[curr]+1)){
                    dp[next] = dp[curr]+1;
                    q.push(next);
                }
            }
        }
    }
}

int main(){
    ioboost;;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int start, end;
        cin >> start >> end;
        ladder[start]=end;
    }    
    for(int i=0; i<m; i++){
        int start, end;
        cin >> start >> end;
        snake[start]=end;
    }
    dp[1]=0;
    for(int i=2; i<=100; i++){
        dp[i]=-1;
    }
    bfs(1);
    cout<<dp[100];
}