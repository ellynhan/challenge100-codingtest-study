#include <bits/stdc++.h>

using namespace std;

class P
{
public:
    P(int _y, int _x, int _d)
        : y(_y), x(_x), depth(_d)
    {
    }
    P(const P &p)
        : x(p.x), y(p.y), depth(p.depth)
    {
    }
    int x;
    int y;
    int depth;
};

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int **tomato;
    bool **v;
    int n, m;
    int res = 0;
    queue<P> q;
    P p_tmp = P(0,0,0);

    cin >> m >> n;
    tomato = new int *[n];
    v = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = new bool [m];
        memset(v[i], 0, sizeof(bool) * m);

        tomato[i] = new int[m];
        for (int j = 0; j < m; j++){
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
            {
                q.push(P(i, j, 0));
            }
        }
    }

    
    while (!q.empty())
    {
        p_tmp = q.front();
        q.pop();

        if (v[p_tmp.y][p_tmp.x] || tomato[p_tmp.y][p_tmp.x] == -1)
            continue;
        v[p_tmp.y][p_tmp.x] = true;
        tomato[p_tmp.y][p_tmp.x] = 1;
        res = p_tmp.depth;

        if (p_tmp.x + 1 < m && tomato[p_tmp.y][p_tmp.x + 1] == 0)
        {
            q.push(P(p_tmp.y, p_tmp.x + 1, p_tmp.depth + 1));
        }
        if (p_tmp.y + 1 < n && tomato[p_tmp.y+1][p_tmp.x] == 0)
        {
            q.push(P(p_tmp.y + 1, p_tmp.x, p_tmp.depth + 1));
        }
        if (p_tmp.x - 1 >= 0 && tomato[p_tmp.y][p_tmp.x - 1] == 0)
        {
            q.push(P(p_tmp.y, p_tmp.x - 1, p_tmp.depth + 1));
        }
        if (p_tmp.y - 1 >= 0 && tomato[p_tmp.y-1][p_tmp.x] == 0)
        {
            q.push(P(p_tmp.y - 1, p_tmp.x, p_tmp.depth + 1));
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(tomato[i][j] == 0){
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << res << '\n';
    return 0;
}
