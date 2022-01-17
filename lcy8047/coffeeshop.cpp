#include <bits/stdc++.h>

using namespace std;

vector<int> v;
long long *tree;
int n;

long long InitTree( int s, int e, int node )
{
    if( s == e ) {
        return tree[node] = v[s];
    }

    int mid = ( s + e ) / 2;

    return tree[node] = InitTree( s, mid, node*2 ) + InitTree( mid+1, e, node*2+1 );
}

long long FindSum( int s, int e, int find_s, int find_e, int node ) 
{
    int mid = ( s + e ) / 2;
    if( find_s == s && find_e == e ) {
        return tree[node];
    }
    else if( find_e <= mid ) {
        return FindSum( s, mid, find_s, find_e, node*2);
    }
    else if( mid < find_s ) {
        return FindSum( mid+1, e, find_s, find_e, node*2+1 );
    }

    return FindSum( s, mid, find_s, mid, node*2 ) + FindSum( mid+1, e, mid+1, find_e, node*2+1 );
}

void UpdateTree( int s, int e, int idx, int node, int newValue )
{
    if( s == idx && e == idx ) {
        tree[node] = newValue;
        return ;
    }

    int mid = ( s + e ) / 2;

    if( idx <= mid ) {
        tree[node] -= v[idx];
        tree[node] += newValue;
        UpdateTree( s, mid, idx, node*2, newValue );
        return ;
    }
    else if( mid < idx ) {
        tree[node] -= v[idx];
        tree[node] += newValue;
        UpdateTree( mid+1, e, idx, node*2+1, newValue );
        return ;
    }
}

int main( void )
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    int t;
    int x, y, a, b;

    cin >> n >> m;

    tree = new long long[4*n];

    for( int i=0; i<n; i++ ) {
        cin >> t;
        v.push_back( t );
    }

    InitTree( 0, n-1, 1 );

    for( int i=0; i<m; i++ ) {
        cin >> x >> y >> a >> b;
        if( x < y ) {
            cout << FindSum(0, n-1, x-1, y-1, 1) << '\n';
        }
        else {
            cout << FindSum(0, n-1, y-1, x-1, 1) << '\n';
        }
        
        UpdateTree( 0, n-1, a-1, 1, b );
        v[a-1] = b;
    }


    return 0;
}