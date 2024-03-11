//
//  1105.cpp
//  main
//
//  Created by wi_seong on 3/11/24.
//

/*
 [Input]
 8 80
 [Output]
 0
 */
// 시간복잡도: O(logn)
// 최악시간: 10
// 난이도: Silver 1
// Timer: 11m
// Url: https://www.acmicpc.net/problem/1105

#include <iostream>

using namespace std;
string L, R;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> L >> R;
    int lenL = int(L.length());
    int lenR = int(R.length());
    int diff = lenR - lenL;
    if(diff > 0) {
        cout << 0;
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < lenL; i++) {
        if(L[i] != R[i]) break;
        if(L[i] == '8') ans++;
    }
    cout << ans;

	return 0;
}
