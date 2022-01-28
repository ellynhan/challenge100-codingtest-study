#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int n[6] = {1, 1, 2, 2, 2, 8};
    
    for( int i=0; i<6; i++ ) {
        cin >> t;
        cout << n[i] - t << " ";
    }

    return 0;
}