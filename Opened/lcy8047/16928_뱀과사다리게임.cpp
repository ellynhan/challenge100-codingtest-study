#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node( int _cur, int _count )
        : cur(_cur)
        , count(_count)
    {}
    int cur;
    int count;
};

bool *v;
int result = INT_MAX;
int *snake;
int *r_snake;

int main( void )
{
    ios_base ::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    int x, y;
    int ladder_count;
    int snake_count;
    queue<Node> q;

    cin >> ladder_count >> snake_count;
    snake_count += ladder_count;

    snake = new int[101];
    fill( snake, snake+101, 0 );
    v = new bool[101];
    memset( v, 0, sizeof( bool ) * 101 );

    for( int i = 0; i < snake_count; i ++ ) {
        cin >> x >> y;
        snake[x] = y;
    }
    q.push(Node(1, 0));
    while( !q.empty() ) {
        Node cur_node = q.front();
        q.pop();

        if( v[cur_node.cur] || cur_node.cur > 100 || cur_node.count >= result ) {
            continue;
        }

        v[cur_node.cur] = true;

        if( cur_node.cur == 100 ) {
            if( cur_node.count < result ) {
                result = cur_node.count;
            }
            continue;
        }

        if( snake[cur_node.cur] != 0 ) {
            cur_node.cur = snake[cur_node.cur];
        }

        v[cur_node.cur] = true;

        for ( int k = 1; k <= 6; k ++ ) {
            if( !v[cur_node.cur + k] )
                q.push( Node( cur_node.cur + k, cur_node.count + 1 ) );
        }
    }

    cout << result << '\n';

    return 0;
}