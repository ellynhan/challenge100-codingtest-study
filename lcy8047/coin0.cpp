#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int k;
    int coin;
    int count = 0;
    vector<int> coins;
    
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> coin;
        coins.push_back(coin);
    }

    while(k > 0) {
        coin = coins[--n];
        while(k >= coin) {
            k -= coin;
            count ++;
        }
    }

    cout << count << '\n';

    return 0;
}