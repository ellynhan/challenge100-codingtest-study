#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    node(int _n, int _t)
        :n(_n), time(_t)
    {}
    node(const node& _node)
        :n(_node.n), time(_node.time)
    {}
    int n;
    int time;
};

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int res = INT_MAX;
    bool v[100001] = {
        false,
    };
    bool v_d[100001] = {
        false,
    };
    int k;
    int n;
    node t(0,0);
    queue<node> q;

    cin >> n >> k;

    v[n] = true;
    q.push(node(n,0));
    while(!q.empty() && t.time < res)
    {
        t = q.front();
        q.pop();
        if(t.n == k)
            if(res > t.time)
                res = t.time;
        if(t.n > k)
        {
            if(res > t.time + t.n - k)
                res = t.time + t.n - k;
        }
        else
        {
            if(!v[t.n+1]){
                q.push(node(t.n + 1, t.time + 1));
                v[t.n+1] = true;
            }
            if (0 <= t.n - 1 && !v_d[t.n-1]){
                q.push(node(t.n - 1, t.time + 1));
                v_d[t.n - 1] = true;
            }
            if (0 < t.n * 2 && t.n * 2 <= INT_MAX)
                q.push(node(t.n * 2, t.time + 1));
        }
    }

    cout << res << '\n';
    return 0;
}