#include <iostream>
using namespace std;

int N, M;
string arr[20];
bool checked[26] = {false};
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int answer = 0;

void dfs(int ci, int cj, int cnt){
    answer = max(answer, cnt);

    int ni, nj;
    for(int i=0; i<4; i++){
        ni = ci + di[i]; nj = cj + dj[i];

        if(0 > ni || ni >= N || 0 > nj || nj >= M) continue;
        if(checked[arr[ni][nj] - 'A']) continue;

        checked[arr[ni][nj] - 'A'] = true;
        dfs(ni, nj, cnt+1);
        checked[arr[ni][nj] - 'A'] = false;
    }
}

int main(){
    cin >> N  >> M;
    for(int i=0; i<N; i++) cin >> arr[i];

    checked[arr[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << answer;
}
