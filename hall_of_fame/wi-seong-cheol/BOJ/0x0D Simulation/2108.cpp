//
//  2108.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 5
 1
 3
 8
 -2
 2
 [Output]
 2
 2
 1
 10
 */
// 시간복잡도: O(nlogn)
// 최악시간: 2,500,000
// 난이도: Silver 3
// Timer: 22m
// Url: https://www.acmicpc.net/problem/2108

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;
int n;
int sum;
unordered_map<int, int> m;
vector<int> v;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
        sum += x;
        m[x]++;
    }
    sort(v.begin(), v.end());

    // 산술 평균
    cout << floor(double(sum) / double(v.size()) + 0.5) << '\n';
    // 중앙 값
    cout << v[int(v.size()) / 2] << '\n';
    // 최빈값
    vector<pair<int, int>> a(m.begin(), m.end());
    sort(a.begin(), a.end(), cmp);
    if(int(a.size()) > 1 && a[0].second == a[1].second)
        cout << a[1].first << '\n';
    else
        cout << a[0].first << '\n';
    // 범위
    cout << abs(v.front() - v.back()) << '\n';

	return 0;
}
