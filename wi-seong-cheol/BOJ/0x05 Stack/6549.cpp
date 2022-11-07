//
//  6549.cpp
//  main
//
//  Created by wi_seong on 2022/11/07.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O()
// 최악시간:
// 난이도:
// Timer: 17 + 
// Url: https://www.acmicpc.net/problem/6549

#include <iostream>
#include <stack>

using namespace std;
#define X first
#define Y second
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        int n; cin >> n;
        if(n == 0) break;
        ll ans = 0;
        stack<pair<int, int>> S;
        for(int i = 0; i < n; i++) {
            int h; cin >> h;
            
        }
        cout << ans;
    }
    return 0;
}
