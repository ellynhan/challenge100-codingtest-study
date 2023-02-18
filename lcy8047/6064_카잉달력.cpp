#include <cstdint>
#include <iostream>

using namespace std;

int gcd( int a, int b ) {
    if ( a % b != 0 ) {
        return gcd( b, a % b );
    }
    return b;
}

int lcm( int a, int b ) {
    return a * b / gcd( a, b );
}

int calc( int m, int n, int target_x, int target_y )
{
    int x = target_x;
    int x_count = 0;
    int y = target_y;
    int y_count = 0;
    int cur_lcm = lcm( max(m, n), min(m, n) );

    while ( y <= cur_lcm ) {
        while ( x <= cur_lcm ) {
            if ( x > y ) {
                break;
            }
            if ( x == y ) {
                return x;
            }
            x += m;
        }
        y += n;
    }
    return -1;
}

int main( void )
{
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    int k;
    cin >> k;

    for ( int i = 0; i < k; ++ i ) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        if ( x == y ) {
            cout << x << "\n";
        }
        else {
            cout << calc( m, n, x, y ) << "\n";
        }
        
    }

    return 0;
}