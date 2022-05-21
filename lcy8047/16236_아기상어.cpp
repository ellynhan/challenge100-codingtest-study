#include <bits/stdc++.h>

using namespace std;

class Point {
public:
    Point( const int _y=0, const int _x=0, const int _dist=0 )
        : y( _y )
        , x( _x )
        , dist( _dist )
    {}

    Point( const Point &_p ) 
        : y( _p.y )
        , x( _p.x )
        , dist( _p.dist )
    {}

    int y;
    int x;
    int dist;
};

bool operator==( const Point &p1, const Point &p2 ) {
    return p1.x == p2.x && p1.y == p2.y;
}

int n;
int **table;
Point cur;
int cur_size = 2;
int ate_fish_count = 0;

int CalcDistance( Point dst_point )
{
    bool **is_visit;
    is_visit = new bool*[n];
    for ( int i = 0; i < n; i ++ ) {
        is_visit[i] = new bool[n];
        fill( is_visit[i], is_visit[i] + n, false );
    }

    queue<Point> q;
    q.push( Point( cur.y + 1, cur.x, cur.dist + 1 ) );
    q.push( Point( cur.y - 1, cur.x, cur.dist + 1 ) );
    q.push( Point( cur.y, cur.x + 1, cur.dist + 1 ) );
    q.push( Point( cur.y, cur.x - 1, cur.dist + 1 ) );

    while ( !q.empty() ) {
        Point p = q.front();
        q.pop();
        
        if( p.x < 0 || p.x >= n || p.y < 0 || p.y >= n || 
            table[p.y][p.x] == 9 || table[p.y][p.x] > cur_size || is_visit[p.y][p.x] ) {
            continue;
        }

        if ( p == dst_point ) {
            return p.dist;
        }

        is_visit[p.y][p.x] = true;
        q.push( Point( p.y + 1, p.x, p.dist + 1 ) );
        q.push( Point( p.y - 1, p.x, p.dist + 1 ) );
        q.push( Point( p.y, p.x + 1, p.dist + 1 ) );
        q.push( Point( p.y, p.x - 1, p.dist + 1 ) );

    }


    return __INT_MAX__;
}

void UpdateState( Point new_point )
{
    table[cur.y][cur.x] = 0;
    table[new_point.y][new_point.x] = 9;
    cur = new_point;

    ate_fish_count ++;
    if( ate_fish_count == cur_size ) {
        cur_size ++;
        ate_fish_count = 0;
    }
}

int Solve( void )
{
    Point target_fish_point;
    int total_dist = 0;

    while ( true ) {
        bool found_fish = false;
        int dist = __INT_MAX__;
        for ( int i = 0; i < n; i ++ ) {
            for ( int j = 0; j < n; j ++ ) {
                if ( table[i][j] != 9 && table[i][j] != 0 && table[i][j] < cur_size ) {
                    int calc_dist = CalcDistance( Point( i, j ) );
                    if ( dist > calc_dist ) {
                        dist = calc_dist;
                        target_fish_point = Point( i, j );
                    }
                    found_fish = true;
                }
            }
        }

        if ( dist == __INT_MAX__ || !found_fish ) {
            return total_dist;
        }

        total_dist += dist;
        UpdateState( target_fish_point );
    }
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    table = new int*[n];
    for ( int i = 0; i < n; i ++ ) {
        table[i] = new int[n];
        for ( int j = 0; j < n; j ++ ) {
            cin >> table[i][j];
            if ( table[i][j] == 9 ) {
                cur.y = i;
                cur.x = j;
            }
        }
        
    }

    cout << Solve() << endl;

    return 0;
}