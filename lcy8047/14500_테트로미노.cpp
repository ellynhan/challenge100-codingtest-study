#include <bits/stdc++.h>

using namespace std;

enum DIR{
    R,
    L,
    U,
    D,
};

int n;
int m;
int **a;
bool **v;
int result;

void dfs( int y, int x, int depth, int sum, DIR direct, bool is_continuous )
{
    if( x < 0 || x >= m || y < 0 || y >= n || v[y][x] ) {
        return;
    }
    
    if( depth == 4 ) {
        if( sum+a[y][x] > result ) {
            result = sum+a[y][x];
        }
        return;
    }
    v[y][x] = true;
    if( is_continuous ) {
        if( direct == R ) {
            if( depth == 3 ) {
                dfs( y+1, x-1, depth+1, sum+a[y][x], U, false );
                dfs( y-1, x-1, depth+1, sum+a[y][x], D, false );
            }
            dfs( y, x+1, depth+1, sum+a[y][x], R, true );
        }
        else {
            dfs( y, x+1, depth+1, sum+a[y][x], R, false );
        }
        if( direct == D ) {
            if( depth == 3 ) {
                dfs( y-1, x-1, depth+1, sum+a[y][x], L, false );
                dfs( y-1, x+1, depth+1, sum+a[y][x], R, false );
            }
            dfs( y+1, x, depth+1, sum+a[y][x], D, true );
        }
        else {
            dfs( y+1, x, depth+1, sum+a[y][x], D, false );
        }
        if( direct == L ) {
            if( depth == 3 ) {
                dfs( y+1, x+1, depth+1, sum+a[y][x], U, false );
                dfs( y-1, x+1, depth+1, sum+a[y][x], D, false );
            }
            dfs( y, x-1, depth+1, sum+a[y][x], L, true );
        }
        else {
            dfs( y, x-1, depth+1, sum+a[y][x], L, false );
        }
        if( direct == U ) {
            if( depth == 3 ) {
                dfs( y+1, x-1, depth+1, sum+a[y][x], L, false );
                dfs( y+1, x+1, depth+1, sum+a[y][x], R, false );
            }
            dfs( y-1, x, depth+1, sum+a[y][x], U, true );
        }
        else {
            dfs( y-1, x, depth+1, sum+a[y][x], U, false );
        }
    }
    else {
        if( depth == 1 ) {
            dfs( y, x+1, depth+1, sum+a[y][x], R, true );
            dfs( y, x-1, depth+1, sum+a[y][x], L, true );
            dfs( y-1, x, depth+1, sum+a[y][x], U, true );
            dfs( y+1, x, depth+1, sum+a[y][x], D, true );
        }
        else {
            dfs( y, x+1, depth+1, sum+a[y][x], R, false );
            dfs( y, x-1, depth+1, sum+a[y][x], L, false );
            dfs( y-1, x, depth+1, sum+a[y][x], U, false );
            dfs( y+1, x, depth+1, sum+a[y][x], D, false );
        }
    }
    v[y][x] = false;
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    a = new int*[n];
    v = new bool*[n];
    result = 0;

    for( int i=0; i<n; i++ ) {
        a[i] = new int[m];
        memset( a[i], 0, sizeof(int)*m );
        for( int j=0; j<m; j++ ) {
            cin >> a[i][j];
        }
        
        v[i] = new bool[m];
        memset( v[i], 0, sizeof(bool)*m );
    }

    for( int i=0; i<n; i++ ) {
        for( int j=0; j<m; j++ ) {
            dfs( i, j, 1, 0, R, false );
        }
    }
    cout << result << '\n';

    return 0;
}