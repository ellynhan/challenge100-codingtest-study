#include<iostream>
#include<queue>
#define MAX 100001
#define INF 999999999
using namespace std;

int N, K;
int visit[MAX];

int BFS()
{
    queue<int> q;
    q.push(N);
    visit[N] = 0;
    while(!q.empty())
    {
        int loc = q.front();
        q.pop();

        if(loc == K) return visit[K];

        if(loc * 2 < MAX && visit[loc*2] > visit[loc]){
            q.push(loc * 2);
            visit[loc*2] = visit[loc];
        }

        if(loc + 1 < MAX && visit[loc + 1] > visit[loc] + 1)
        {
            q.push(loc + 1);
            visit[loc + 1] = visit[loc] + 1;
        }

        if(loc - 1 >= 0 && visit[loc - 1] > visit[loc] + 1){
            q.push(loc - 1);
            visit[loc - 1] = visit[loc] + 1;
        }
    }
    return 0;
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i <= MAX; i++)
    {
        visit[i] = INF;
    }
    cout << BFS();
}