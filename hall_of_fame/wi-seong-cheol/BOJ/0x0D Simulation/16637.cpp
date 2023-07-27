//
//  16637.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 19
 1-9-1-9-1-9-1-9-1-9
 [Output]
 24
 */
// 시간복잡도: O(2 ^ n)
// 최악시간: 1,048,576
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/16637

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
int n, ans = INT_MIN;
string str;

int cal(int a, int b, char op) {
    int result = a;
    
    if(op == '+') result += b;
    else if(op == '*') result *= b;
    else result -= b;
    
    return result;
}

void solve(int idx, int cur) {
    if(idx > n - 1) {
        ans = max(ans, cur);
        return;
    }
    char op = (idx == 0) ? '+' : str[idx - 1];

    if(idx + 2 < n) {
        int bracket = cal(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
        solve(idx + 4, cal(cur, bracket, op));
    }
    solve(idx + 2, cal(cur, str[idx] - '0', op));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> str;
    solve(0, 0);
    cout << ans;
    
    return 0;
}
