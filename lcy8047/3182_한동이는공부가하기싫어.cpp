/*
    단방향 그래프 -> dfs로 가장 깊은 정점 찾기
    현재 노드에서 갈 수 있는 방향을 순차적으로 dfs, 그 중 가장 깊이가 깊은 노드로 리턴.
*/

#include <iostream>
#include <cstdint>

using namespace std;

int n;
int *table;
bool *visited;

uint32_t dfs( int node, int depth )
{
    if ( visited[node] ) {
        return depth;
    }
    visited[node] = true;
    int result = dfs( table[node], depth + 1 );
    visited[node] = false;

    return result;
}

uint32_t solve( void )
{
    uint32_t max_depth = 0;
    uint32_t result = 0;
    for ( int i = 1; i <= n; ++ i ) {
        uint32_t cur_depth = dfs( i, 0 );
        if ( max_depth < cur_depth ) {
            max_depth = cur_depth;
            result = i;
        }
    }

    return result;
}

int main( void )
{
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    cin >> n;
    table = new int[n + 1];
    fill( table, table + n + 1, 0 );
    visited = new bool[n + 1];
    fill( visited, visited + n + 1, false );

    for ( int i = 1; i <= n; ++ i ) {
        int a;
        cin >> a;
        table[i] = a;
    }

    cout << solve() << endl;

    return 0;
}