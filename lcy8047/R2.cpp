#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int res = 0;
    cin >> t;
    res -= t;
    cin >> t;
    res += 2*t;
    cout << res << '\n';

    return 0;
}