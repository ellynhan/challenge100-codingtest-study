#include <iostream>
#define for(a, b, c)  for(int a=b; a<c; a++)
using namespace std;

int N, M;
int arr[500][500];
int visited[500][500] = {0, };
int answer = 0;

void dfs(int ci, int cj, int cnt, int sum){
    if(cnt == 0){
        answer = max(answer, sum);
        return;
    }

    int di[] = {0, 1, 0, -1};
    int dj[] = {1, 0, -1, 0};
    
    for(i, 0, 4){
        int ni = ci + di[i];
        int nj = cj + dj[i];
        if(0 > ni || ni >= N || 0 > nj || nj >= M) continue;
        if(visited[ni][nj] == 1) continue;

        visited[ni][nj] = 1;
        dfs(ni, nj, cnt - 1, sum + arr[ni][nj]);
        visited[ni][nj] = 0;
    }
}

void shape(int i, int j){
    int sum;
    if(i < N-2 && 0 < j){ // ㅓ
        sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j-1];
        answer = max(answer, sum); 
    }
    if(i < N-2 && j < M-1){ // ㅏ
        sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1];
        answer = max(answer, sum); 
    }
    if(0 < i && j < M-2){ // ㅗ
        sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i-1][j+1];
        answer = max(answer, sum); 
    }
    if(i < N-1 && j < M-2){ // ㅜ
        sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1];
        answer = max(answer, sum); 
    }
}


int main(){
    cin >> N >> M;
    for(i, 0, N)
        for(j, 0, M) cin >> arr[i][j];

    for(i, 0, N)
    for(j, 0, M){
        visited[i][j] = 1;
        dfs(i, j, 3, arr[i][j]);
        visited[i][j] = 0;
        shape(i, j);
    }

    cout << answer;
}
