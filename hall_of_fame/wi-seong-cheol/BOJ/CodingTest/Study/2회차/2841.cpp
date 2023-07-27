//
//  2841.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/09.
//

/*
 [Input]
 7 15
 1 5
 2 3
 2 5
 2 7
 2 4
 1 5
 1 3
 [Output]
 9
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Silver 1
// Timer: 20m
// Url: https://www.acmicpc.net/problem/2841

#include <iostream>
#include <stack>

using namespace std;
int n, p, a, b, ans;
stack<int> S[7];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> p;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        int cnt = 1;
        while(!S[a].empty() && b <= S[a].top()) {
            if(b == S[a].top()) cnt--;
            else cnt++;
            S[a].pop();
        }
        S[a].push(b);
        ans += cnt;
    }
    cout << ans;
    
    return 0;
}
