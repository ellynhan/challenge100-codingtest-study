//
//  MATCHORDER.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 1/12/24.
//

/*
 [Input]
 3
 6
 3000 2700 2800 2200 2500 1900
 2800 2750 2995 1800 2600 2000
 3
 1 2 3
 3 2 1
 4
 2 3 4 5
 1 2 3 4
 [Output]
 5
 3
 3
 */
// 시간복잡도: O(nlogn)
// 최악시간: 200
// 난이도: 하
// Timer: 20m
// Url: https://algospot.com/judge/problem/read/MATCHORDER

#include <iostream>
#include <algorithm>

using namespace std;
int t, n;
int russian[101], korean[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> russian[i];
        for(int i = 0; i < n; i++) cin >> korean[i];

        sort(russian, russian + n);
        sort(korean, korean + n);

        int ans = 0;
        int j = 0;

        for(int i = 0; i < n; i++) {
            for(; j < n; j++) {
                if(russian[i] <= korean[j]) {
                    ans++;
                    j++;
                    break;
                }
            }
        }

        cout << ans << '\n';
    }

	return 0;
}
