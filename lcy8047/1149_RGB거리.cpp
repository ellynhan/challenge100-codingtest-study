#include <iostream>
#include <queue>

using namespace std;

int n;
int **budget;

int solve( void )
{
    int **dp;
    dp = new int*[n];
    for ( int i = 0; i < n; ++ i ) {
        dp[i] = new int[3];
        if ( i == 0 ) {
            dp[i][0] = budget[0][0];
            dp[i][1] = budget[0][1];
            dp[i][2] = budget[0][2];
            continue;
        }
        dp[i][0] = budget[i][0] + min( dp[i-1][1], dp[i-1][2] );
        dp[i][1] = budget[i][1] + min( dp[i-1][0], dp[i-1][2] );
        dp[i][2] = budget[i][2] + min( dp[i-1][0], dp[i-1][1] );
    }

    return min( dp[n-1][0], min( dp[n-1][1], dp[n-1][2] ) );
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    budget = new int*[n];
    for ( int i = 0; i < n; ++ i ) {
        budget[i] = new int[3];
        for ( int j = 0; j < 3; ++ j ) {
            cin >> budget[i][j];
        }
    }

    cout << solve() << "\n";

    return 0;
}