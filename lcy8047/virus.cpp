#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int e;
    int x,y;
    int curNode;
    int **c;
    bool *visit;
    int res = 0;
    queue<int> q;

    cin >> n;

    c = new int*[n+1];
    for(int i=0; i<n+1; i++)
    {
        c[i] = new int[n+1];
        memset(c[i], 0, sizeof(int)*(n+1));
    }
    visit = new bool[n + 1];
    memset(visit, 0, sizeof(bool)*(n+1));

    cin >> e;
    for(int i=0; i<e; i++)
    {
        cin >> x >> y;
        c[x][y] = 1;
        c[y][x] = 1;
    }

    q.push(1);
    visit[1] = true;
    while(!q.empty())
    {
        curNode = q.front();
        q.pop();
        for(int i=1; i<n+1; i++)
        {
            if(c[curNode][i] == 1 && !visit[i])
            {
                res ++;
                q.push(i);
                visit[i] = true;
            }
        }
    }

    cout << res << '\n';

    return 0;
}