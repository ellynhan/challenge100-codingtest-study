//
//  JOSEPHUS.cpp
//  main
//
//  Created by wi_seong on 1/19/24.
//

/*
 [Input]
 2
 6 3
 40 3
 [Output]
 3 5
 11 26
 */
// 시간복잡도: O(n * k)
// 최악시간: 1,000,000
// 난이도: 하
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/JOSEPHUS

#include <iostream>
#include <list>

using namespace std;
int t, n, k;

void solve() {
    list<int> survivors;
    for(int i = 1; i <= n; i++) {
        survivors.push_back(i);
    }

    auto it = survivors.begin();
    while(n > 2) {
        it = survivors.erase(it);
        if(it == survivors.end()) it = survivors.begin();
        n--;

        for(int i = 0; i < k - 1; i++) {
            it++;
            if(it == survivors.end()) it = survivors.begin();
        }
    }

    for(auto& i : survivors) {
        cout << i << " ";
    }
    cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        solve();
    }

	return 0;
}
