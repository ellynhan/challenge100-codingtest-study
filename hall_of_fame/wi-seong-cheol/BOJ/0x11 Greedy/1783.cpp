//
//  1783.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/11/24.
//

/*
 [Input]
 100 50
 [Output]
 48
 */
// 시간복잡도: O(1)
// 최악시간: 1
// 난이도: Silver 3
// Timer: 7m
// Url: https://www.acmicpc.net/problem/1783

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> n >> m;
    if(n == 1) cout << 1;
    else if(n == 2) cout << min(4, (m + 1) / 2);
    else if(m < 7) cout << min(4, m);
    else cout << m - 2;

	return 0;
}
