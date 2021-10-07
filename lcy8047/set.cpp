#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    string op;
    int n;
    vector<bool> set;
    set.resize(21);
    fill(set.begin(), set.end(), false);

    cin >> m;
    for(int i=0; i<m; i++)
    {
        cin >> op;
        if (op.compare("all") == 0)
        {
            fill(set.begin(), set.end(), true);
        }
        else if (op.compare("empty") == 0)
        {
            fill(set.begin(), set.end(), false);
        }
        else {
            cin >> n;
            if (op.compare("add") == 0)
            {
                set[n] = true;
            }
            if (op.compare("remove") == 0)
            {
                set[n] = false;
            }
            if (op.compare("check") == 0)
            {
                if(set[n]) cout << 1;
                else cout << 0;
                cout << '\n';
            }
            if (op.compare("toggle") == 0)
            {
                set[n] = !set[n];
            }
        }
    }

    return 0;
}