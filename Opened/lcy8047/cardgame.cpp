#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    int sum=0;
    while( cin >> t ) {
        sum += t;
    }
    cout << sum << '\n';
    return 0;
}