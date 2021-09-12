#include <bits/stdc++.h>

using namespace std;

bool broken[10] = {
    false,
};
int res = INT_MAX;
int n;

void solve(string s)
{
    string t;
    for (int i = 0; i < 10; i++)
    {
        if (!broken[i])
        {
            t = s + to_string(i);
            res = min(res, abs(n - stoi(t)) + (int)t.size());
            if (t.size() < 6)
                solve(t);
        }
    }
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, t;

    cin >> n >> m;

    if (n > 100)
        res = n - 100;
    else
    {
        res = 100 - n;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> t;
        broken[t] = true;
    }

    if (m != 10)
    {
        solve("");
    }

    cout << res << '\n';
    return 0;
}