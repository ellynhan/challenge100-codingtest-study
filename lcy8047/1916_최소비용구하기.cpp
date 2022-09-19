#include <iostream>
#include <vector>

using namespace std;

int64_t **edge;
vector<bool> visited;
vector<int64_t> path;

bool isAllVisited( void )
{
    for ( int64_t i = 1; i < visited.size(); ++ i ) {
        if ( ! visited[i] ) {
            return false;
        }
    }
    return true;
}

int64_t getMinVertex( void )
{
    int64_t min_val = INT32_MAX;
    int64_t min;
    for ( int64_t i = 1; i < visited.size(); ++ i ) {
        if ( ! visited[i] ) {
            min = i;
            break;
        }
    }
    for ( int64_t i = 1; i < path.size(); ++ i ) {
        if ( visited[i] ) {
            continue;
        }
        if ( min_val > path[i] ) {
            min = i;
            min_val = path[i];
        }
    }
    return min;
}

int main( void )
{
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    int64_t n;
    int64_t m;
    cin >> n >> m;

    path.resize( n + 1, INT32_MAX );
    visited.resize( n + 1, false );

    edge = new int64_t*[n + 1];
    for ( int64_t i = 0; i < n + 1; ++ i ) {
        edge[i] = new int64_t[n+1];
        fill( edge[i], edge[i] + n + 1, -1 );
    }

    for ( int64_t i = 0; i < m; ++ i ) {
        int64_t s, e, c;
        cin >> s >> e >> c;
        if ( edge[s][e] != -1 ) {
            edge[s][e] = min( c, edge[s][e]);
        }
        else {
            edge[s][e] = c;
        }
        
    }

    int64_t start;
    int64_t end;
    cin >> start >> end;
    path[start] = 0;

    while( ! isAllVisited() ) {
        int64_t target = getMinVertex();

        visited[target] = true;
        if ( target == end ) {
            break;
        }

        for ( int64_t i = 1; i <= n; ++ i ) {
            if ( edge[target][i] == -1 ) {
                continue;
            }
            if ( path[i] > path[target] + edge[target][i] ) {
                path[i] = path[target] + edge[target][i];
            }
        }
    }

    cout << path[end] << "\n";

    return 0;
}