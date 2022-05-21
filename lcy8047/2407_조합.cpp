#include <iostream>
#include <cstdint>

using namespace std;

string solve( void )
{
    __uint128_t result = 1;
    int n;
    int m;
    cin >> n >> m;
    if ( n == m ) {
        return "1";
    }
    if ( n/2 < m ) {
        m = n-m;
    }
    __uint128_t j = 2;
    for ( __uint128_t i = n; i > n-m; -- i ) {
        result *= i;
        while ( j <= m && result % j == 0 ) {
            result /= j;
            j ++;
        }
    }

    string r;
    while ( result != 0 ) {
        int digit = result % 10;
        r = to_string( digit ) + r;
        result /= 10;
    }

    return r;
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solve() << "\n";

    return 0;
}