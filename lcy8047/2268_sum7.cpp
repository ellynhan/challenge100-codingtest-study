#include <bits/stdc++.h>

using namespace std;

vector<int> v;
long long *tree;
int n;

void UpdateTree( int idx, int value )
{
    int diff = value - v[idx];
    v[idx] = value;

    while( idx <= n ) {
        tree[idx] += diff;
        idx += idx&-idx;
    }   
}

long long FindSum( int idx )
{
    long long sum = 0;
    while( idx ) {
        sum += tree[idx];
        idx &= idx - 1;
    }

    return sum;
}

int main( void )
{
    ios_base ::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    int m;
    int cmd, a, b;

    cin >> n >> m;

    tree = new long long[n*2];
    v.resize( n+1 );
    fill( v.begin(), v.end(), 0 );

    for( int i=0; i<m; i++ ) {
        cin >> cmd >> a >> b;

        if( cmd == 0 ) {
            if( a > b ) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            if( a == 1 ) {
                cout << FindSum( b ) << '\n';
            }
            else {
                cout << FindSum( b ) - FindSum( a-1 ) << '\n';
            }
        }
        else {
            UpdateTree( a, b );
        }
    }


    return 0;
}