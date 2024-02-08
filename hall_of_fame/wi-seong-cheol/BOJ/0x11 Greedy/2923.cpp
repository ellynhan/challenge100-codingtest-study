//
//  2923.cpp
//  main
//
//  Created by wi_seong on 1/22/24.
//

/*
 [Input]
 3
 2 8
 3 1
 1 4
 [Output]
 10
 10
 9
 */
// 시간복잡도: O(100)
// 최악시간: 100
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2923

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> a(101 , 0), b(101, 0);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[x]++; b[y]++;

        vector<int> va(a);
        vector<int> vb(b);

        int left = 1, right = 100;
        int ans = 0;

        while(left <= 100 && right >= 1) {
            if(va[left] == 0) {
                left++;
                continue;
            }
            if(vb[right] == 0) {
                right--;
                continue;
            }
            int mn = min(va[left], vb[right]);
            ans = max(ans, left + right);
            va[left] -= mn;
            vb[right] -= mn;
        }
        cout << ans << '\n';
    }

	return 0;
}
