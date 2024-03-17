//
//  1049.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/11/24.
//

/*
 [Input]
 4 2
 12 3
 15 4
 [Output]
 12
 */
// 시간복잡도: O(nlogn)
// 최악시간: 200
// 난이도: Silver 4
// Timer: 3m
// Url: https://www.acmicpc.net/problem/1049

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> pack;
vector<int> piece;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        pack.push_back(a);
        piece.push_back(b);
    }
    sort(pack.begin(), pack.end());
    sort(piece.begin(), piece.end());

    int ans = 0;
    if(pack[0] < piece[0] * 6) {
        ans = (n / 6) * pack[0];
        n %= 6;
        if(n * piece[0] < pack[0]) ans += n * piece[0];
        else ans += pack[0];
    } else {
        ans = n * piece[0];
    }
    cout << ans;

	return 0;
}
