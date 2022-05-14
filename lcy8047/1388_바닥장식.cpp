#include <iostream>
#include <cstdint>

using namespace std;
/*
    연속된 행이나 열이 같은 모양이면 같은 나무 판자
    -> dfs로 판단
    2중 for문으로 순차적으로 순회하고 방문 했으면 pass 방문하지 않았으면 count ++ 하고 dfs로 연결된 것이 있는지 판단
    dfs는 방향따라 다른 함수 사용 -> 탐색 시작한 방향으로 계속 탐색.
    입력 저장할 2차원배열과 방문표시할 2차원 배열, count 변수 필요
    입력이 공백으로 띄워지지 않으므로 string배열로 사용 -> string* 타입으로 선언
*/

int n;
int m;
string *floor;
bool **visited;

void dfs_col( int y, int x, int direction )
{
    if ( y < 0 || y >= n || visited[y][x] || floor[y][x] == '-') {
        return;
    }

    visited[y][x] = true;
    dfs_col( y + direction, x, direction );
}

void dfs_row( int y, int x, int direction )
{
    if ( x < 0 || x >= m || visited[y][x] || floor[y][x] == '|' ) {
        return;
    }

    visited[y][x] = true;
    dfs_row( y, x + direction, direction );
}

uint32_t solve( void )
{
    uint32_t plank_count = 0;
    for ( int i = 0; i < n; ++ i ) {
        for ( int j = 0; j < m; ++ j ) {
            if ( visited[i][j] ) {
                continue;
            }
            
            plank_count ++;
            visited[i][j] = true;
            if ( floor[i][j] == '-' ) {
                dfs_row( i, j - 1, -1 );
                dfs_row( i, j + 1, 1 );
            }
            else {  // floor[i][j] == '|'
                dfs_col( i - 1, j, -1 );
                dfs_col( i + 1, j, 1 );
            }
        }
    }

    return plank_count;
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    floor = new string[n];
    visited = new bool*[n];
    for ( int i = 0; i < n; ++ i ) {
        cin >> floor[i];
        visited[i] = new bool[m];
        fill( visited[i], visited[i] + m, false );
    }

    cout << solve() << "\n";

    return 0;
}