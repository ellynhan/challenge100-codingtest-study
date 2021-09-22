#include <bits/stdc++.h>

using namespace std;

class P
{
public:
    P(int _y, int _x, int _d)
        : y(_y), x(_x), depth(_d)
    {}
    P(const P& p)
        : x(p.x)
        , y(p.y)
        , depth(p.depth)
    {}
    int x;
    int y;
    int depth;
};

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int n;
    int m;
    string *maze;
    bool **v;
    int res = INT_MAX;
    queue<P> q;
    P p_tmp(0,0,0);

    cin >> n >> m;
    v = new bool*[n];
    maze = new string[n];
    for(int i=0; i<n; i++)
    {
        cin >> maze[i];
        v[i] = new bool[m];
        memset(v[i], false, sizeof(bool)*m);
    }
    
    q.push(P(0,0,1));
    while(!q.empty())
    {
        p_tmp = q.front();
        q.pop();

        if (v[p_tmp.y][p_tmp.x] || maze[p_tmp.y][p_tmp.x] == '0')
            continue;
        v[p_tmp.y][p_tmp.x] = true;
        
        if(p_tmp.x == m-1 && p_tmp.y == n-1 && res > p_tmp.depth)
        {
            res = p_tmp.depth;
        }

        if (p_tmp.x + 1 < m && p_tmp.depth + 1 < res)
        {
            q.push(P(p_tmp.y, p_tmp.x+1, p_tmp.depth + 1));
        }
        if (p_tmp.y + 1 < n && p_tmp.depth + 1 < res )
        {
            q.push(P(p_tmp.y+1, p_tmp.x, p_tmp.depth + 1));
        }
        if (p_tmp.x - 1 >= 0 && p_tmp.depth + 1 < res )
        {
            q.push(P(p_tmp.y, p_tmp.x - 1, p_tmp.depth + 1));
        }
        if (p_tmp.y - 1 >= 0 && p_tmp.depth + 1 < res )
        {
            q.push(P(p_tmp.y - 1, p_tmp.x, p_tmp.depth + 1));
        }
    }

    cout << res << '\n';

    return 0;
}