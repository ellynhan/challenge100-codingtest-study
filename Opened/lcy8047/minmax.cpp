#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int *max_tree;
int *min_tree;
int n;

int InitMinTree( int start, int end, int cur_node )
{
    if( start == end ) {
        return min_tree[cur_node] = v[start];
    }

    int mid = ( start + end ) / 2;
    
    return min_tree[cur_node] = min( InitMinTree( start, mid, cur_node*2 ),
                                     InitMinTree( mid+1, end, cur_node*2+1) );
}

int InitMaxTree( int start, int end, int cur_node )
{
    if( start == end ) {
        return max_tree[cur_node] = v[start];
    }

    int mid = ( start + end ) / 2;
    
    return max_tree[cur_node] = max( InitMaxTree( start, mid, cur_node*2 ),
                                     InitMaxTree( mid+1, end, cur_node*2+1) );
}

int FindMinValue( int start, int end, int find_s, int find_e, int cur_node)
{
    int mid = ( start + end ) / 2;

    if( start == find_s && end == find_e )
        return min_tree[cur_node];

    if( find_e <= mid ) {
        return FindMinValue( start, mid, find_s, find_e, cur_node*2 );
    }
    else if( mid < find_s ) {
        return FindMinValue( mid+1, end, find_s, find_e, cur_node*2+1 );
    }
    return min( FindMinValue( start, mid, find_s, mid, cur_node*2 ), 
                FindMinValue( mid+1, end, mid+1, find_e, cur_node*2+1 ) );
}

int FindMaxValue( int start, int end, int find_s, int find_e, int cur_node)
{
    int mid = ( start + end ) / 2;

    if( start == find_s && end == find_e )
        return max_tree[cur_node];

    if( find_e <= mid ) {
        return FindMaxValue( start, mid, find_s, find_e, cur_node*2 );
    }
    else if( mid < find_s ) {
        return FindMaxValue( mid+1, end, find_s, find_e, cur_node*2+1 );
    }
    return max( FindMaxValue( start, mid, find_s, mid, cur_node*2 ), 
                FindMaxValue( mid+1, end, mid+1, find_e, cur_node*2+1 ) );
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int t;
    int a, b;
    int min_v, max_v;
    int level_check = 2;

    cin >> n >> m;

    for( int i=0; i<n; i++ ) {
        cin >> t;
        v.push_back(t);
    }

    min_tree = new int[4*n];
    max_tree = new int[4*n];
    InitMinTree( 0, n-1, 1 );
    InitMaxTree( 0, n-1, 1 );

    for( int i=0; i<m; i++ ) {
        cin >> a >> b;
        cout << FindMinValue( 0, n-1, a-1, b-1, 1 ) << " ";
        cout << FindMaxValue( 0, n-1, a-1, b-1, 1 ) << '\n';
    }

    return 0;
}