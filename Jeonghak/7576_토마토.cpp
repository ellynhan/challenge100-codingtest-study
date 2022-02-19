#include<iostream>
#include<queue>
using namespace std;
queue<pair<int,int>> q;
bool visit[1001][1001];
int map[1001][1001];
int M, N, maxDay, cnt;
int dx[4] = {0, 0, 1, -1 };  // x 축
int dy[4] = {-1, 1, 0, 0};        // y cnr

void output(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
void solve(){
    while(!q.empty()){
        // output();
        cnt++;
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(nextX < N && nextY < M && nextX >= 0 && nextY >= 0)
            {            
                if(!visit[nextX][nextY]){
                    visit[nextX][nextY] = true;
                    if(map[nextX][nextY] == 0){
                        map[nextX][nextY] = map[curX][curY] + 1;
                        q.push({nextY, nextX});
                        maxDay = max(maxDay, map[nextX][nextY]);
                    }
                else continue;
                }
            }
        }
    }
}

int main() 
{
    int zero=0;
    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int t;
            cin >> t;
            if(t==1) {
                q.push({j,i});
                cnt--;
            }
            else if(t==0) zero++;
            map[i][j] = t;
        }
    }
    if(zero == 0) {cout << 0; return 0;}
    solve();
    if(zero == cnt)
        cout << maxDay-1;
    else cout << -1;
}
