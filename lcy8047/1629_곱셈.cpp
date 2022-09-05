#include <cstdint>
#include <iostream>

using namespace std;

uint64_t solve( uint64_t a, uint64_t b, uint64_t c )
{
    if ( b == 1 ) {
        return a % c;
    }
    uint64_t t = solve( a, b / 2, c );
    if ( b % 2 == 1 ) {
        return ( (t * t) % c) * a % c;
    }
    else {
        return t * t % c;
    }
}

int main( void )
{
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    uint64_t a, b, c;
    cin >> a >> b >> c;

    cout << solve( a, b, c ) << "\n";

    return 0;
}