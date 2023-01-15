#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main( void )
{
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    deque<int> s;
    vector<bool> b;
    b.resize( 2000000001 );

    int n;
    int m;
    cin >> n >> m;

    for ( int i = 0; i < n; ++ i )
    {
        int tmp;
        cin >> tmp;
        s.push_back( tmp );
        b[tmp+1000000000] = true;
    }
    sort( s.begin(), s.end() );

    map<int,int> sorted_idx_map;
    int count = 0;
    int prev_num = -INT_MAX;
    for ( int e : s )
    {
        if ( prev_num == e )
        {
            count ++;
            prev_num = e;
            continue;
        }
        sorted_idx_map[e] = count;
        count ++;
        prev_num = e;
    }

    for ( int i = 0; i < m; ++ i )
    {
        int q;
        cin >> q;
        if ( b[q+1000000000] )
        {
            cout << sorted_idx_map[q] << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}