#include<iostream>
#include<string>
#include <regex>
using namespace std;

int N, cnt, blindnessCnt;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visit[101][101];
string picture[101];
void DFS(int x, int y)
{
    int currColor = picture[x][y];
    visit[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < N && ny < N)
        {
            if(!visit[nx][ny] && currColor == picture[nx][ny]){
                DFS(nx, ny);
            }
        }
    }
}
// 이전 탐색한게 G or R 이었어도 다음 탐색을 B 먼저 해버리면 논리적 허점 존재.
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i=0;i<N; i++){
        cin >> picture[i];
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(!visit[i][j]){
                DFS(i, j);
                cnt++; 
            }
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(!visit[i][j]){
                DFS(i, j);
                cnt++; 
            }
        }
    }
    memset(visit, false, sizeof(visit));
    for(int i=0; i<N; i++){
        picture[i] = regex_replace(picture[i], regex("R"), "G");
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(!visit[i][j]){
                DFS(i, j);
                blindnessCnt++; 
            }
        }
    }
    cout << cnt << ' ' << blindnessCnt;
}