#include <bits/stdc++.h>

typedef unsigned long long ULL;

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    int a[10] = {0,};

    cin >> s;

    for(int i=0; i<s.size(); i++)
    {
        a[s[i] - 0x30] ++;
    }

    for(int i=9; i>=0; i--)
    {
        for(int j=0; j<a[i]; j++)
        {
            cout << i;
        }
    }
    cout << '\n';

    return 0;

}