#include <iostream>
#include <string>
#include <queue>
#define MAX 1001
using namespace std;

struct Pos{
    int x;
    int y;
    int dist;
    bool state;
};

int N, M, result=-1;
string map[MAX];
bool visit[MAX][MAX][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// int dist[MAX][MAX];
void BFS()
{
    queue<Pos> q;
    q.push({0, 0, 1, false});
    visit[0][0][0] = visit[0][0][1] = true;
    // dist[0][0] = 1;
    
    while(!q.empty()){
        Pos pos = q.front();
        int curr_x = pos.x;
        int curr_y = pos.y;
        int curr_dist = pos.dist;
        bool curr_state = pos.state;
        q.pop();

        if(curr_x == M-1 && curr_y == N-1){
            result = curr_dist;
            return;
        }

        for(int i=0; i<4; i++){
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];

            if(next_x >= 0 && next_y >= 0 && next_x < M &&  next_y < N){
                if(map[next_y][next_x] == '0' && !visit[next_y][next_x][curr_state]){ 
                    q.push({next_x, next_y, curr_dist + 1, curr_state});
                    visit[next_y][next_x][curr_state] = true;
                }
                if(map[next_y][next_x] == '1' && !visit[next_y][next_x][1] && !curr_state){
                    q.push({next_x, next_y, curr_dist + 1, true});
                    visit[next_y][next_x][1] = true;
                }
            }
        }
    }
}
void Input()
{
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> map[i];
    }
}
int main()
{
    Input();
    BFS();
    cout << result;
}   