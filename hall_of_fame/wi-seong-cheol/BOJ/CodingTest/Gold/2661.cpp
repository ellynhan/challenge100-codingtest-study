//
//  2661.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/07.
//

/*
 [Input]
 7
 [Output]
 1213121
 */
// 시간복잡도: O(n)
// 최악시간: 80
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2661

#include <iostream>
#include <algorithm>

using namespace std;
int n;
bool finish;
string ans;

bool check(string str) {
    int size = (int)str.size();
    for(int i = 1; i <= size / 2; i++)
        if(str.substr(size - i, i) == str.substr(size - 2 * i, i))
            return false;
    return true;
}

void solve(int k, string str) {
    if(finish || !check(str)) return;
    if(k == n) {
        ans = str;
        finish = true;
        return;
    }
    for(int i = 1; i <= 3; i++) {
        solve(k + 1, str + to_string(i));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    solve(0, "");
    cout << ans;
    
    return 0;
}
