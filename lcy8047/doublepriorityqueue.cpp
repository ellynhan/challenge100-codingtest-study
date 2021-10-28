#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int, int> m;

    int t, k;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> k;
        char cmd;
        int n;
        m.clear();
        for(int j=0; j<k; j++)
        {
            cin >> cmd >> n;
            if(cmd == 'I')
            {
                if(m.find(n) == m.end())
                    m.emplace(n, 1);
                else{
                    m[n] ++;
                }
            }
            else
            {
                if(m.empty())
                    continue;
                if(n == 1) {
                    if(m.rbegin()->second > 1)
                        m.rbegin()->second --;
                    else
                        m.erase(m.rbegin()->first);
                }
                else {
                    if (m.begin()->second > 1)
                        m.begin()->second --;
                    else
                        m.erase(m.begin()->first);
                }
            }
        }
        if(m.empty())
            cout << "EMPTY" << '\n';
        else
            cout << m.rbegin()->first << ' ' << m.begin()->first << '\n';
    }

    return 0;
}