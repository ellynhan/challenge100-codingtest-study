#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> edge;
int *visited;
int visit_count = 1;

void dfs( int vertex )
{
    if ( visited[vertex] != 0 )
    {
        return;
    }
    visited[vertex] = visit_count;
    visit_count ++;

    for ( int v : edge[vertex] )
    {
        dfs( v );
    }
}

int main( void )
{
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    int n;
    int m;
    int start_vertex;
    cin >> n >> m >> start_vertex;

    visited = new int[n + 1];
    fill( visited, visited + n + 1, 0 );

    for ( int i = 0; i < m; ++ i )
    {
        int s, e;
        cin >> s >> e;
        edge[s].push_back( e );
        edge[e].push_back( s );
    }

    for ( int i = 1; i <= n; ++ i )
    {
        sort( edge[i].begin(), edge[i].end(), std::greater<int>() );
    }

    dfs( start_vertex );

    for ( int i = 1; i <= n; ++ i )
    {
        std::cout << visited[i] << "\n";
    }

    return 0;
}