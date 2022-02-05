#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int a[1001];

    a[0] = 0;
    a[1] = 1;
    a[2] = 3;
    a[3] = 5;

    for( int i=4; i<=1000; i++ ) {
        a[i] = ( a[i-1] + a[i-2]*2 ) % 10007;
    }
    cin >> n;
    cout << a[n] << '\n';

    return 0;
}