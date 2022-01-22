#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int *min_tree;
int n;
int m;

int InitMinTree( int start, int end, int node )
{
    if( start == end ) {
        return min_tree[node] = v[start];
    }

    int mid = (start + end) / 2;

    return min_tree[node] = min( InitMinTree(start, mid, node*2), InitMinTree(mid+1, end, node*2+1) );
}

int FindMin( int start, int end, int find_s, int find_e, int node )
{
    if( start == find_s && end == find_e ) {
        return min_tree[node];
    }

    int mid = ( start + end ) / 2;

    if( find_e <= mid ) {
        return FindMin( start, mid, find_s, find_e, node*2 );
    }
    else if( mid < find_s ) {
        return FindMin( mid+1, end, find_s, find_e, node*2+1 );
    }

    return min( FindMin( start, mid, find_s, mid, node*2 ), FindMin( mid+1, end, mid+1, find_e, node*2+1 ) );
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int a, b;

    cin >> n >> m;

    min_tree = new int[4*n];
    memset( min_tree, 0, sizeof(int)*4*n );

    for( int i=0; i<n; i++ ) {
        cin >> t;
        v.push_back( t );
    }

    InitMinTree( 0, n-1, 1 );

    for( int i=0; i<m; i++ ) {
        cin >> a >> b;
        cout << FindMin( 0, n-1, a-1, b-1, 1 ) << '\n';
    }

    return 0;
}