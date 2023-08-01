//
//  1543.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/10.
//

/*
 [Input]
 aaaaaaaa
 aa
 [Output]
 4
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 6,250,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1543

#include <iostream>

using namespace std;
int n, m, ans;
string a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, a);
    getline(cin, b);
    n = (int)a.size();
    m = (int)b.size();
    for(int i = 0; i <= n - m; i++) {
        string tmp = a.substr(i, m);
        if(tmp == b) {
            i += m - 1;
            ans++;
        }
    }
    cout << ans;
    
    return 0;
}
