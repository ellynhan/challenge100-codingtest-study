#include <bits/stdc++.h>

using namespace std;

vector<int> values;
int *minValueTree;
int *minIdxTree;
int seqSize;

int InitTree( int s, int e, int node )
{
    if ( s == e ) {
        minIdxTree[node] = s;
        return minValueTree[node] = values[s];
    }

    int mid = ( s + e ) / 2;

    int node1 = InitTree( s, mid, node * 2 );
    int node2 = InitTree( mid + 1, e, node * 2 + 1 );

    if ( node1 < node2 ) {
        minIdxTree[node] = minIdxTree[node * 2];
    }
    else if ( node1 > node2 ) {
        minIdxTree[node] = minIdxTree[node * 2 + 1];
    }
    else {
        minIdxTree[node] = min( minIdxTree[node * 2], minIdxTree[node * 2 + 1] );
    }

    return minValueTree[node] = min( node1, node2 );
}

int UpdateTree( int s, int e, int node, int idx, int newValue )
{
    if ( ! ( s <= idx && idx <= e ) ) {
        return minValueTree[node];
    }

    if ( s == e && e == idx ) {
        return minValueTree[node] = values[idx] = newValue;
    }

    int mid = ( s + e ) / 2;

    int node1 = UpdateTree( s, mid, node * 2, idx, newValue );
    int node2 = UpdateTree( mid + 1, e, node * 2 + 1, idx, newValue );

    if ( node1 < node2 ) {
        minIdxTree[node] = minIdxTree[node * 2];
    }
    else if ( node1 > node2 ) {
        minIdxTree[node] = minIdxTree[node * 2 + 1];
    }
    else {
        minIdxTree[node] = min( minIdxTree[node * 2], minIdxTree[node * 2 + 1] );
    }

    return minValueTree[node] = min( node1, node2 );
}

int FindMinIndex( int s, int e, int node, int find_s, int find_e )
{
    if ( s == find_s && e == find_e ) {
        return minIdxTree[node];
    }

    int mid = ( s + e ) / 2;

    if ( find_e <= mid ) {
        return FindMinIndex( s, mid, node * 2, find_s, find_e );
    }
    else if ( mid < find_s ) {
        return FindMinIndex( mid + 1, e, node * 2 + 1, find_s, find_e );
    }
    int node1 = FindMinIndex( s, mid, node * 2, find_s, mid );
    int node2 = FindMinIndex( mid + 1, e, node * 2 + 1, mid + 1, find_e );

    return values[node1] < values[node2] ? node1 : values[node1] == values[node2] ? min( node1, node2 ) : node2;
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> seqSize;

    values.resize( seqSize + 1 );
    fill( values.begin(), values.end(), 0 );
    minValueTree = new int[seqSize * 4];
    fill( minValueTree, minValueTree + seqSize, 0 );
    minIdxTree = new int[seqSize * 4];
    fill( minIdxTree, minIdxTree + seqSize, 0 );

    for ( int i = 1; i <= seqSize; i ++ ) {
        cin >> values[i];
    }

    InitTree( 1, seqSize, 1 );

    int querySize;
    cin >> querySize;

    for ( int i = 0; i < querySize; i ++ ) {
        int command;
        cin >> command;

        if ( command == 1 ) {
            int changeIdx, newValue;
            cin >> changeIdx >> newValue;
            UpdateTree( 1, seqSize, 1, changeIdx, newValue );
        }
        else if ( command == 2 ) {
            int findStartIdx, findEndIdx;
            cin >> findStartIdx >> findEndIdx;
            cout << FindMinIndex( 1, seqSize, 1, findStartIdx, findEndIdx ) << '\n';
        }
        else {
            // wrong input
        }
    }

    return 0;
}