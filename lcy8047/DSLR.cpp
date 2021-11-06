#include <bits/stdc++.h>

using namespace std;

class P
{
public:
    P(int _n, string _command)
        : n(_n)
        , commands(_command)
    {
    }
    P(const P &p)
        : n(p.n)
        , commands(p.commands)
    {
    }
    int n;
    string commands;

    int L(void) {
        return (n*10)%10000+n/1000;
    }

    int R(void)
    {
        return (n%10)*1000+n/10;
    }
};

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool v[10000] = {false, };
    queue<P> q;
    string res;

    int t;
    int a, b;

    cin >> t;

    for(int i=0; i<t; i++)
    {
        res.clear();
        memset(v,false,sizeof(bool)*10000);

        cin >> a >> b;
        while(!q.empty())
            q.pop();
        q.push(P(a, ""));
        v[a] = true;
        while(res.size() <= 0)
        {
            P temp = q.front();
            q.pop();
            if(temp.n == b)
            {
                res = temp.commands;
                break;
            }
            if ( !v[(temp.n * 2) % 10000] ) {
                q.push(P((temp.n * 2) % 10000, temp.commands + "D"));
                v[(temp.n * 2) % 10000] = true;
            }
            if ( !v[(temp.n - 1 < 0 ? 9999 : temp.n - 1)] ) {
                q.push(P((temp.n - 1 < 0 ? 9999 : temp.n - 1), temp.commands + "S"));
                v[(temp.n - 1 < 0 ? 9999 : temp.n - 1)] = true;
            }
            if (!v[temp.L()]) {
                q.push(P(temp.L(), temp.commands + "L"));
                v[temp.L()] = true;
            }
            if (!v[temp.R()]) {
                q.push(P(temp.R(), temp.commands + "R"));
                v[temp.R()] = true;
            }
        }
        cout << res << '\n';
    }

    return 0;
}