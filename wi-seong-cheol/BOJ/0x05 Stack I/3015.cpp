//
//  3015.cpp
//  main
//
//  Created by wi_seong on 2022/11/07.
//

/*
 [Input]
 7
 2
 4
 1
 2
 2
 5
 1
 [Output]
 10
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Gold 1
// Timer: 19m
// Url: https://www.acmicpc.net/problem/3015

#include <iostream>
#include <stack>

using namespace std;
#define X first
#define Y second
#define ll long long
int n;
ll ans;
stack<pair<int, int>> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        int x; cin >> x;
        int cnt = 1;
        while(!S.empty() && S.top().X <= x) {
            ans += S.top().Y;
            if(S.top().X == x) cnt += S.top().Y;
            S.pop();
        }
        if(!S.empty()) ans++;
        S.push({x, cnt});
    }
    cout << ans;
    
    return 0;
}
