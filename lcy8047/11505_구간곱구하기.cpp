#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

int n;
vector<ULL> v;
ULL *tree;

ULL InitTree( int s, int e, int node )
{
    if( s == e ) {
        return tree[node] = v[s];
    }

    int mid = ( s + e ) / 2;

    tree[node] =  ( ( ULL ) InitTree( s, mid, node * 2 ) * InitTree( mid + 1, e, node * 2 + 1 ) ) % 1000000007;
    return tree[node];
}

ULL UpdateTree( int s, int e, int node, int idx, int value )
{
    if( ! ( s <= idx && idx <= e ) ) {
        return tree[node];
    }

    if ( s == e && e == idx ) {
        return tree[node] = v[idx] = value;
    }

    int mid = ( s + e ) / 2;

    return tree[node] =  ( (ULL) UpdateTree( s, mid, node * 2, idx, value ) * UpdateTree( mid + 1, e, node * 2 + 1, idx, value ) ) % 1000000007;
}

ULL FindProduct( int s, int e, int node, int find_s, int find_e )
{
    if ( find_s == s && find_e == e ) {
        return tree[node] ;
    }

    int mid = ( s + e ) / 2;
    if ( find_e <= mid ) {
        return FindProduct( s, mid, node * 2, find_s, find_e ) % 1000000007;
    }
    else if ( mid < find_s ) {
        return FindProduct( mid+1, e, node * 2 + 1, find_s, find_e ) % 1000000007;
    }

    return  ( ( ULL ) ( FindProduct( s, mid, node * 2, find_s, mid ) % 1000000007 ) * ( FindProduct( mid + 1, e, node * 2 + 1, mid + 1, find_e ) % 1000000007 ) ) % 1000000007;
}

int main( void )
{
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    int m, k, t;
    int a, b, c;

    cin >> n >> m >> k;
    tree = new ULL[4 * n];
    fill( tree, tree + 4 * n, 0 );

    v.resize( n + 1 );
    for( int i = 1; i <= n; i ++ ) {
        cin >> v[i];
    }

    InitTree( 1, n, 1 );

    for( int i = 0; i < m + k; i ++ ) {
        cin >> a >> b >> c;
        if( a == 1 ) {
            UpdateTree( 1, n, 1, b, c );
        }
        else {
            cout << FindProduct( 1, n, 1, b, c ) % 1000000007 << '\n';
        }
    }

    return 0;
}