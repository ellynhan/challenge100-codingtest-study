#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int N;
int L, R;
int arr[50][50];
int visit[50][50];

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

bool changeFlag = true;
queue<pair<int, int>> que;

void bfs(int ci, int cj){
    visit[ci][cj] = true;

    vector<pair<int, int>> vec;
    que.push({ci, cj});
    vec.push_back({ci, cj});

    int ni, nj;
    int sum = 0, calc;
    while(!que.empty()){
        ci = que.front().first; cj = que.front().second;
        que.pop();
        sum += arr[ci][cj];

        for(int i=0; i<4; i++){
            ni = ci + di[i]; nj = cj + dj[i];

            if(0 > ni || ni >= N || 0 > nj || nj >= N) continue;
            if(visit[ni][nj]) continue;
            calc = abs(arr[ci][cj] - arr[ni][nj]);
            if(L > calc || calc > R) continue;

            visit[ni][nj] = true;
            que.push({ni, nj});
            vec.push_back({ni, nj});
        }
    }

    int people = sum / vec.size();
    for(int i=0; i<vec.size(); i++){
        ci = vec[i].first; cj = vec[i].second;
        arr[ci][cj] = people;
    }

    if(vec.size() > 1) changeFlag = true;
}

int main(){
    cin >> N >> L >> R;

    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) cin >> arr[i][j];

    int day=0;

    while(1){
        changeFlag = false;
        memset(visit, false, sizeof(visit));
        for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) if(!visit[i][j]){
            bfs(i, j);
        }
        if(!changeFlag) break;
        day++;
    }

    cout << day;
}
