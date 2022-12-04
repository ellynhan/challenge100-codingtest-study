#include<iostream>
#define INF 100000000
#define MAX 101
using namespace std;
int N, M;
int map[101][101];

void Init()
{
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i!=j) map[i][j] = INF;
        }
    }
}

void Input()
{
    cin >> N >> M;
    Init();
    for(int i=0; i<M; i++)
    {
        int from, to, value;
        cin >> from >> to >> value;
        if(map[from][to] > value) map[from][to] = value;
    }
}

void Output()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++){
            if(map[i][j] == INF) cout << 0 << ' ';
            else cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}

void Floyd()
{
    for(int k=1; k<=N; k++)
    {
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++){
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
}

int main()
{
    Input();
    Floyd();
    Output();
}