#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    unsigned long long a[101] = {0,};
    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    a[4] = 2;
    a[5] = 2;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for(int j = 6; j<=n; j++)
        {
            a[j] = a[j-1] + a[j-5];
        }
        cout << a[n] << '\n';
    }

    return 0;
}