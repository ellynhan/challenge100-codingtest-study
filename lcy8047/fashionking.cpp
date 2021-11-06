#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    string s;

    unordered_map<string, int> m;

    cin >> t;
    for(int i=0; i<t; i++)
    {
        m.clear();
        cin >> n;
        for(int j=0; j<n; j++)
        {
            cin >> s >> s;
            if( m.find(s) == m.end() )
                m[s] = 1;
            else
                m[s] ++;
        }
        int res = 1;
        for(auto it = m.begin(); it!=m.end(); it++)
        {
            res *= (*it).second+1;
        }
        cout << res-1 << '\n';
    }


    return 0;
}