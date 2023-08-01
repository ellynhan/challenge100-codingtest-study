//
//  2407.cpp
//  main
//
//  Created by wi_seong on 2023/02/08.
//

/*
 [Input]
 100 6
 [Output]
 1192052400
 */
// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/2407

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
string d[101][101];

string makeStringSum(string a, string b) {
    int sum = 0;
    string ans = "";
    
    while(!a.empty() || !b.empty() || sum != 0) {
        if(!a.empty()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if(!b.empty()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        ans.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string combination(int n, int r) {
    if(n == r || r == 0) return "1";
    if(d[n][r] != "") return d[n][r];
    
    d[n][r] = makeStringSum(combination(n - 1, r - 1), combination(n - 1, r));
    
    return d[n][r];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    cout << combination(n, m);
    
    return 0;
}
