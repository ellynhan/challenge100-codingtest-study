#include<iostream>
using namespace std;

int ans_seq[10];
int M, N;

void dfs(int currNum,int depth)
{
    if(depth == N){
        for(int i=0; i<N; i++)
            cout << ans_seq[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=currNum; i<=M; i++){
        ans_seq[depth] = i;
        dfs(i+1, depth+1);
    }
}

int main()
{
    cin >> M >> N;
    dfs(1, 0);
}