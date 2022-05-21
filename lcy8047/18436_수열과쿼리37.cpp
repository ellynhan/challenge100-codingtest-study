#include <bits/stdc++.h>

using namespace std;

vector<int> nums;
int *OddTree;
int *EvenTree;
int n;

void InitTree( int s, int e, int node )
{
    if ( s == e ) {
        if ( nums[s] % 2 == 1 ) {
            OddTree[node] ++;
        }
        else {
            EvenTree[node] ++;
        }
        return;
    }

    int mid = ( s + e ) / 2;

    InitTree( s, mid, node * 2 );
    InitTree( mid + 1, e, node * 2 + 1 );
    OddTree[node] = OddTree[node * 2] + OddTree[node * 2 + 1];
    EvenTree[node] = EvenTree[node * 2] + EvenTree[node * 2 + 1];
}

void UpdateTree( int s, int e, int node, int changeIdx, int newValue ) 
{
    if ( ! ( s <= changeIdx && changeIdx <= e ) ) {
        return;
    }

    if ( s == e && e == changeIdx ) {
        if ( newValue % 2 == 1 ) {
            OddTree[node] ++;
        }
        else {
            EvenTree[node] ++;
        }
        if ( nums[changeIdx] % 2 == 1 ) {
            OddTree[node] --;
        }
        else {
            EvenTree[node] --;
        }
        nums[changeIdx] = newValue;
        return;
    }
    
    int mid = ( s + e ) / 2;
    UpdateTree( s, mid, node * 2, changeIdx, newValue );
    UpdateTree( mid + 1, e, node * 2 + 1, changeIdx, newValue );
    OddTree[node] = OddTree[node * 2] + OddTree[node * 2 + 1];
    EvenTree[node] = EvenTree[node * 2] + EvenTree[node * 2 + 1];
}

int FindOddCount( int s, int e, int node, int find_s, int find_e )
{
    if ( s == find_s && e == find_e ) {
        return OddTree[node];
    }

    int mid = ( s + e ) / 2;

    if ( find_e <= mid ) {
        return FindOddCount( s, mid, node * 2, find_s, find_e );
    }
    else if ( mid < find_s ) {
        return FindOddCount( mid + 1, e, node * 2 + 1, find_s, find_e );
    }

    return FindOddCount( s, mid, node * 2, find_s, mid ) + FindOddCount( mid + 1, e, node * 2 + 1, mid + 1, find_e );
}

int FindEvenCount( int s, int e, int node, int find_s, int find_e )
{
    if ( s == find_s && e == find_e ) {
        return EvenTree[node];
    }

    int mid = ( s + e ) / 2;

    if ( find_e <= mid ) {
        return FindEvenCount( s, mid, node * 2, find_s, find_e );
    }
    else if ( mid < find_s ) {
        return FindEvenCount( mid + 1, e, node * 2 + 1, find_s, find_e );
    }

    return FindEvenCount( s, mid, node * 2, find_s, mid ) + FindEvenCount( mid + 1, e, node * 2 + 1, mid + 1, find_e );
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    nums.resize( n + 1 );
    fill( nums.begin(), nums.end(), 0 );

    OddTree = new int[4 * n];
    fill( OddTree, OddTree + 4 * n, 0 );
    EvenTree = new int[4 * n];
    fill( EvenTree, EvenTree + 4 * n, 0 );

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
            cout << FindEvenCount( 1, n, 1, a, b ) << '\n';
        }
        else if ( cmd == 3 ) {
            cout << FindOddCount( 1, n, 1, a, b ) << '\n';
        }
        else {
            // Wrong Input
        }
    }

    return 0;
}