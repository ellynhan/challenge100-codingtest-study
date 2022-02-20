#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int a;
    int i;
    int l;
    int res = 0;
    vector<int> v;

    v.push_back(0);

    cin >> l;
    for( i=0; i<l; i++ ) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    cin >> n;

    for( i=1; i<=l; i++ ) {
        if( v[i] == n ) {
            res = 0;
            break;
        }
        if( v[i] > n ) {
            break;
        }
    }

    if( v[i] != n )
        res = (n - (v[i-1]+1)) * (v[i] - n) + (v[i] - n - 1);

    cout << res << '\n';

    return 0;
}