//
//  10814.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/30.
//

/*
 [Input]
 3
 21 Junkyu
 21 Dohyun
 20 Sunyoung
 [Output]
 20 Sunyoung
 21 Junkyu
 21 Dohyun
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Silver 5
// Timer: 5m
// Url: https://www.acmicpc.net/problem/10814

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second
int n, age;
string name;
vector<pair<int, string>> v;

bool cmp(const pair<int, string>& element1, const pair<int, string>& element2) {
    return element1.X < element2.X;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> age >> name;
        v.push_back({age, name});
    }
    stable_sort(v.begin(), v.end(), cmp);
    for(auto element: v)
        cout << element.X << ' ' << element.Y << '\n';
    
    return 0;
}
