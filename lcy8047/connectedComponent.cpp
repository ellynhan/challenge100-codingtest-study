#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int a, b;
    int **e;
    vector<int> visited;
    bool *visit;
    queue<int> q;
    int result = 0;

    cin >> n >> m;

    e = new int*[n+1];
    for(int i=1; i<=n; i++)
    {
        e[i] = new int[n+1];
        memset(e[i], 0, sizeof(int)*(n+1));
    }

    visit = new bool[n + 1];
    memset(visit, false, sizeof(bool) * (n + 1));

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        e[a][b] = 1;
        e[b][a] = 1;
    }

    while(visited.size() != n)
    {
        for(int i=1; i<=n; i++)
        {
            if(!visit[i]) {
                q.push(i);
                visit[i] = true;
                visited.push_back(i);
                break;
            }
        }
        while(!q.empty())
        {
            int cur_v = q.front();
            q.pop();

            for(int i=1; i<=n; i++)
            {
                if(e[cur_v][i] == 1 && !visit[i])
                {
                    q.push(i);
                    visit[i] = true;
                    visited.push_back(i);
                }
            }
        }
        result ++;
    }
    cout << result << '\n';

    return 0;
}