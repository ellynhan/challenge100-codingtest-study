#include <iostream>
#include <cstring>
#include <queue>
#define FOR(i, j) for(int i=1; i<=j; i++)

using namespace std;
 
int N, M, Min=INT_MAX, ans; 
int visitedCnt[101];
bool isRelation[101][101];
queue<int> q;
 
void Input(){
    cin >> N >> M;
    int i;
    FOR(i, M)
    {
        int a, b;
        cin >> a >> b;
        isRelation[a][b] = true;
        isRelation[b][a] = true;
    }
}

void BFS(int user){
    visitedCnt[user] = true;
    q.push(user);
    while(!q.empty())
    {   
        user = q.front();
        q.pop();
        int i; 
        FOR(i, N)
        {
            if(isRelation[user][i] && visitedCnt[i] == 0)
            {
                visitedCnt[i] = visitedCnt[user] + 1;
                q.push(i);
            }
        }
    }
}

void findMin(int user){
    int i, sum = 0;
    FOR(i, N){
        if(i != user) sum+=visitedCnt[i];
    }
    if(Min > sum) {
        Min = sum;
        ans = user;
    }
}
int main(void)
{    
    Input();
    int i;
    FOR(i, N)
    {
        memset(visitedCnt, 0, 101);
        BFS(i);
        findMin(i);
    }
    cout << ans;
    return 0;
}
