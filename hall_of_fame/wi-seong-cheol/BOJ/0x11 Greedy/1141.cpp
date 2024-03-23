//
//  1141.cpp
//  main
//
//  Created by wi_seong on 3/17/24.
//

/*
 [Input]
 6
 hello
 hi
 h
 run
 rerun
 running
 [Output]
 4
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 125,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1141

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int ans;
vector<string> s;

bool cmp(const string& a, const string& b) {
    return a.length() < b.length();
}

bool isPrefix(const string& a, const string& b) {
    int len = int(a.length());
    for(int i = 0; i < len; i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        s.push_back(str);
    }
    
    sort(s.begin(), s.end(), cmp);
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(isPrefix(s[i], s[j])) {
                ans++;
                break;
            }
        }
    }
    cout << n - ans;

	return 0;
}
