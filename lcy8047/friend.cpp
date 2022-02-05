#include <bits/stdc++.h>

using namespace std;

int n;
int maxFriendCount = 0;
string *f;
string *updated;

void updateFriend( void )
{
    int friendCount;

    for( int i=0; i<n; i++ ) {
        for( int j=0; j<n; j++ ) {
            if( f[i][j] == 'Y' && i != j) {
                for( int k=0; k<n; k++ ) {
                    if( f[i][k] == 'N' && f[j][k] == 'Y' && i != k && j != k) {
                        updated[i][k] = 'Y';
                    }
                }
            }
        }
        friendCount = 0;
        for( int j=0; j<n; j++ ) {
            if( updated[i][j] == 'Y' ) {
                friendCount ++;
            }
        }
        if( maxFriendCount < friendCount ) {
            maxFriendCount = friendCount;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    cin >> n;

    f = new string[n];
    updated = new string[n];
    for( int i=0; i<n; i++ ) {
        cin >> f[i];
        updated[i] = f[i];
    }

    updateFriend();

    cout << maxFriendCount << '\n';

    return 0;
}