#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    int *s[2];

    cin >> n;
    for(int i=0; i<2; i++)
        s[i] = new int[n];

    for(int i=0; i<n; i++)
    {
        cin >> t;
        for (int j = 0; j < 2; j++)
            s[j][i] = t;
    }

    s[1][1] += s[1][0];
    for (int i = 2; i < n; i++)
    {
        s[0][i] += max(s[0][i-2],s[1][i-2]);
        s[1][i] += s[0][i-1];
    }
    cout << max(s[0][n-1], s[1][n-1]) << '\n';

    return 0;
}