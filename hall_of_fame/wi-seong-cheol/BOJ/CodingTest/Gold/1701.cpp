//
//  1701.cpp
//  main
//
//  Created by wi_seong on 2023/03/23.
//

/*
 [Input]
 abcdabcabb
 [Output]
 3
 */
// 시간복잡도: O(n + m)
// 최악시간: 100,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1701

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int SIZE = 5001;
string s;
int n, ans;
vector<int> f;
char a[SIZE * 2];

vector<int> failure(const string &pattern) {
    int m = (int)pattern.length();
    vector<int> f(m);
    int j = 0;
    for(int i = 1; i < m; i++) {
        while(j > 0 && pattern[i] != pattern[j]) j = f[j - 1];
        if(pattern[i] == pattern[j]) f[i] = ++j;
    }
    return f;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    n = (int)s.size();
    for(int i = 0; i < n - 1; i++) {
        string subtext = s.substr(i);
        vector<int> f = failure(subtext);
        for(int len : f)
            ans = max(ans, len);
    }
    cout << ans;

    return 0;
}
