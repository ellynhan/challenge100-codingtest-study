//
//  12738.cpp
//  main
//
//  Created by wi_seong on 1/8/24.
//

/*
 [Input]
 6
 10 20 10 30 20 50
 [Output]
 4
 */
// 시간복잡도: O(nlogn)
// 최악시간: 6'000'000
// 난이도: 골드 2
// Timer: 5분
// Url: https://www.acmicpc.net/problem/12738

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(a.empty() || a.back() < x) {
            a.push_back(x);
        } else {
            *lower_bound(a.begin(), a.end(), x) = x;
        }
    }
    cout << a.size();

	return 0;
}
