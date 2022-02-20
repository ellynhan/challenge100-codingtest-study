#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, e;
    int cnt = 0;
    int cur_n = 1;
    int sum = 0;

    cin >> s >> e;
    for( int i=1; i<=e; i++ ) {
        if( i >= s ) {
            sum += cur_n;
        }

        cnt ++;
        if( cur_n == cnt ) {
            cur_n ++;
            cnt = 0;
        }
    }

    cout << sum << '\n';

    return 0;
}