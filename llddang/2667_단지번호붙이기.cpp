#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
string map[25];

struct node{int i, j;};
queue<node> q;
vector<int> apartment;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

void bfs(int ci, int cj){
    q.push({ci, cj}); map[ci][cj] = '0';

    node n;
    int ni, nj;
    int cnt = 1;
    while(!q.empty()){
        n = q.front(); q.pop();

        for(int i=0; i<4; i++){
            ni = n.i + di[i]; nj = n.j + dj[i];

            if(0 > ni || ni >= N || 0 > nj || nj >= N) continue;
            if(map[ni][nj] == '0') continue;

            q.push({ni, nj});
            map[ni][nj] = '0';
            cnt++;
        }
    }
    apartment.push_back(cnt);
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> map[i];

    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
        if(map[i][j] == '1')
            bfs(i, j);

    sort(apartment.begin(), apartment.end());

    cout << apartment.size() << "\n";
    for(int a : apartment)
        cout << a << "\n";
}
