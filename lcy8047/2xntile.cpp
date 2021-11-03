#include <bits/stdc++.h>

typedef unsigned long long ULL;

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ULL a[1001];

    cin >> n;

    a[0] = 0;
    a[1] = 1;
    a[2] = 2;

    for(int i=3; i<=n; i++)
    {
        a[i] = (a[i-2]+a[i-1])%10007;
    }

    cout << a[n]%10007 << '\n';



    return 0;
}