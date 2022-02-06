#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> nums;
int *tree;

void InitTree( int s, int e, int node )
{
    if ( s == e ) {
        tree[node] = nums[s];
        return;
    }

    int mid = ( s + e ) / 2;

    InitTree( s, mid, node * 2 );
    InitTree( mid + 1, e, node * 2 + 1 );
    tree[node] = min( tree[node * 2], tree[node * 2 + 1] );
}

void UpdateTree( int s, int e, int node, int changeIdx, int newValue )
{
    if ( ! ( s <= changeIdx && changeIdx <= e ) ) {
        return;
    }

    if ( s == e && e == changeIdx ) {
        tree[node] = newValue;
        nums[changeIdx] = newValue;
        return;
    }

    int mid = ( s + e ) / 2;

    UpdateTree( s, mid, node * 2, changeIdx, newValue );
    UpdateTree( mid + 1, e, node * 2 + 1, changeIdx, newValue );
    tree[node] = min( tree[node * 2], tree[node * 2 + 1] );
}

int FindMinValue( int s, int e, int node, int find_s, int find_e )
{
    if ( s == find_s && e == find_e ) {
        return tree[node];
    }

    int mid = ( s + e ) / 2;

    if ( find_e <= mid ) {
        return FindMinValue( s, mid, node * 2, find_s, find_e );
    }
    else if ( mid < find_s ) {
        return FindMinValue( mid + 1, e, node * 2 + 1, find_s, find_e );
    }
    return min( FindMinValue( s, mid, node * 2, find_s, mid ), FindMinValue( mid + 1, e, node * 2 + 1, mid + 1, find_e ) );
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    tree = new int[4 * n];
    fill( tree, tree + 4 * n, INT_MAX );

    nums.resize( n + 1 );
    fill( nums.begin(), nums.end(), 0 );

    for ( int i = 1; i <= n; i ++ ) {
        cin >> nums[i];
    }

    InitTree( 1, n, 1 );

    int queryCount;
    cin >> queryCount;

    for ( int i = 0; i < queryCount; i ++ ) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if ( cmd == 1 ) {
            UpdateTree( 1, n, 1, a, b );
        }
        else if ( cmd == 2 ) {
            cout << FindMinValue( 1, n, 1, a, b ) << '\n';
        }
        else {
            // WrongInput
        }
    }

    return 0;
}