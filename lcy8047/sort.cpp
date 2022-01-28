#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, t;
    vector<int> v;

    cin >> n >> k;
    for( int i=0; i<n; i++ ) {
        cin >> t;
        v.push_back( t );
    }
    sort( v.begin(), v.end() );

    cout << v[k-1] << '\n';

    return 0;
}