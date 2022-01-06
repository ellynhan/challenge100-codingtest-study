#include <bits/stdc++.h>

using namespace std;

int n;
int **a;
bool **v;
int min_cost;

void dfs( int y, int x, int cost, int depth )
{
    if( x < 1 || y < 1 || x >= n-1 || y >= n-1 || 
        v[y][x] || v[y][x-1] || v[y][x+1] || v[y-1][x] || v[y+1][x] ) {
        return;
    }
    
    v[y][x] = true;
    v[y-1][x] = true;
    v[y+1][x] = true;
    v[y][x-1] = true;
    v[y][x+1] = true;
    if( depth == 3 ) {
        min_cost = min( min_cost, cost );
    }
    else {
        for( int i=1; i<n-1; i++ ) {
            for( int j=1; j<n-1; j++ ) {
                dfs( i, j, cost + a[i][j] + a[i][j-1] + a[i][j+1] + a[i-1][j] + a[i+1][j], depth+1 );
            }
        }
    }

    v[y][x] = false;
    v[y-1][x] = false;
    v[y+1][x] = false;
    v[y][x-1] = false;
    v[y][x+1] = false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    a = new int*[n];
    v = new bool*[n];
    min_cost = INT_MAX;

    for( int i=0; i<n; i++ ) {
        a[i] = new int[n];
        for( int j=0; j<n; j++ ) {
            cin >> a[i][j];
        }
        v[i] = new bool[n];
        memset(v[i], false, sizeof(bool)*n);
    }

    for( int i=1; i<n-1; i++ ) {
        for( int j=1; j<n-1; j++ ) {
            dfs( i, j, a[i][j] + a[i][j-1] + a[i][j+1] + a[i-1][j] + a[i+1][j], 1 );
        }
    }

    cout << min_cost << '\n';

    return 0;
}