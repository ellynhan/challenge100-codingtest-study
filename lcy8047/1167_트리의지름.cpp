#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int n;
unordered_map<int, unordered_map<int, int>*> table;
int result = 0;
bool *visited;

int dfs( int prev, int target, int length, int prev_length )
{
    if ( visited[target] ) {
        return -1;
    }
    visited[target] = true;

    int max_len = 0;
    int second_max_len = 0;
    for ( auto edge : *table[target] ) {
        int calced_len = dfs( target, edge.first, length + edge.second, edge.second );
        if ( max_len <= calced_len ) {
            second_max_len = max_len;
            max_len = calced_len;
        }
        else if( second_max_len < calced_len ) {
            second_max_len = calced_len;
        }
    }

    int return_val = max_len;


    if ( max_len < length ) {
        second_max_len = max_len;
        max_len = length;
    }
    else {
        second_max_len = max( second_max_len, length );
    }

    if ( result < max_len + second_max_len ) {
        result = max_len + second_max_len;
    }

    return return_val + prev_length;
}

void solve( void )
{
    for ( auto edge : *table[1] ) {
        dfs( 0, 1, 0, edge.second );
    }
}

int main(void)
{
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    cin >> n;

    visited = new bool[n + 1];
    fill( visited, visited + n + 1, false );

    for ( int i = 1; i <= n; ++ i ) {
        int target_v;
        cin >> target_v;
        table.emplace( target_v, new unordered_map<int, int> );
        while ( true ) {
            int v, e;
            cin >> v;
            if ( v == -1 ) break;
            cin >> e;
            table[target_v]->emplace( v, e );
        }
    }
    solve( );
    cout << result << "\n";

    return 0;
}