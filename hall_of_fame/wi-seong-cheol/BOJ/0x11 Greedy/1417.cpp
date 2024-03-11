//
//  1417.cpp
//  main
//
//  Created by wi_seong on 3/11/24.
//

/*
 [Input]
 3
 5
 7
 7
 [Output]
 2
 */
// 시간복잡도: O(nlogn)
// 최악시간: 20,000
// 난이도: Silver 5
// Timer: 7m
// Url: https://www.acmicpc.net/problem/1417

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, dasom;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    cin >> dasom;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), greater<int>());
    int cnt = 0;
    while(dasom <= v[0]) {
        v[0]--;
        dasom++;
        cnt++;
        sort(v.begin(), v.end(), greater<int>());
    }
    cout << cnt;

	return 0;
}
