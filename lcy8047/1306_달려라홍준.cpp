#include <bits/stdc++.h>

using namespace std;

int n;
int m;
vector<int> lights;
int *tree;

void InitTree( int s, int e, int node )
{
    if ( s == e ) {
        tree[node] = lights[s];
        return;
    }

    int mid = ( s + e ) / 2;

    InitTree( s, mid, node * 2 );
    InitTree( mid + 1, e, node * 2 + 1 );
    tree[node] = max( tree[node * 2], tree[node * 2 + 1] );
}

int FindMaxBrightness( int s, int e, int node, int find_s, int find_e )
{
    if ( s == find_s && e == find_e ) {
        return tree[node];
    }

    int mid = ( s + e ) / 2;

    if ( find_e <= mid ) {
        return FindMaxBrightness( s, mid, node * 2 , find_s, find_e );
    }
    else if ( mid < find_s ) {
        return FindMaxBrightness( mid + 1, e, node * 2 + 1, find_s, find_e );
    }

    return max( FindMaxBrightness( s, mid, node * 2 , find_s, mid ), FindMaxBrightness( mid + 1, e, node * 2 + 1, mid + 1, find_e ) );
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    lights.resize( n + 1 );
    fill( lights.begin(), lights.end(), 0 );

    tree = new int[4 * n];
    fill( tree, tree + 4 * n, 0 );

    for ( int i = 1; i <= n; i ++ ) {
        cin >> lights[i];
    }

    InitTree( 1, n, 1 );

    for ( int i = m; i <= n - m + 1; i ++ ) {
        cout << FindMaxBrightness( 1, n, 1, i - ( m - 1 ), i + m - 1 ) << " ";
    }
    cout << '\n';

    return 0;
}