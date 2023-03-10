//
//  11509.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/10.
//

/*
 [Input]
 6
 5 4 4 3 3 2
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Gold 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/11509

#include <iostream>

using namespace std;
int n, x, ans;
int dart[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(dart[x] == 0) {
            ans++;
            dart[x - 1]++;
        } else {
            dart[x]--;
            dart[x - 1]++;
        }
    }
    cout << ans;
    
    return 0;
}
