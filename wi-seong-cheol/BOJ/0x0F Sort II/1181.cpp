//
//  1181.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/30.
//

/*
 [Input]
 13
 but
 i
 wont
 hesitate
 no
 more
 no
 more
 it
 cannot
 wait
 im
 yours
 [Output]
 i
 im
 it
 no
 but
 more
 wait
 wont
 yours
 cannot
 hesitate
 */
// 시간복잡도: O(nlogn)
// 최악시간: 80,000
// 난이도: Silver 5
// Timer: 3m
// Url: https://www.acmicpc.net/problem/1181

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<string> v;

bool cmp(const string& s1, const string& s2) {
    if(s1.length() != s2.length()) return s1.length() < s2.length();
    return s1 < s2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0] << '\n';
    for(int i = 1; i < n; i++)
        if(v[i - 1] != v[i])
            cout << v[i] << '\n';
    
    return 0;
}
