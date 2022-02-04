#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    char **path;

    cin >> n;

    path = new char*[n];
    for( int i=0; i<n; i++ ) {
        path[i] = new char[n];
        memset(path[i], 0, n);
        for( int j=0; j<n; j++ ) {
            cin >> path[i][j];
        }
    }

    for( int m=0; m<n; m++ ) {
        for( int i=0; i<n; i++ ) {
            for( int j=0; j<n; j++ ) {
                if( path[i][m] == '1' && path[m][j] == '1' ) {
                    path[i][j] = '1';
                }
            }
        }
    }

    for( int i=0; i<n; i++ ) {
        for( int j=0; j<n; j++ ) {
            cout << path[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}