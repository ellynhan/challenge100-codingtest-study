//
//  4354.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 abcd
 aaaa
 ababab
 .
 [Output]
 1
 4
 3
 */
// 시간복잡도: O(2L)
// 최악시간: 2,000,000
// 난이도: Platinum 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/4354

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
string s;
vector<int> f;

vector<int> failure(string& s) {
    vector<int> f(s.size());
    int j = 0;
    for(int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) j = f[j - 1];
        if(s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        cin >> s;
        if(s == ".") break;
        f = failure(s);
        int n = (int)s.size();
        int mxLen = n - f[n - 1];
        if(n % mxLen != 0)
            cout << "1\n";
        else
            cout << n / mxLen << '\n';
    }
    
    return 0;
}
// abababa
/*
 abcd
 aaaa
 ababab
 .
 */
