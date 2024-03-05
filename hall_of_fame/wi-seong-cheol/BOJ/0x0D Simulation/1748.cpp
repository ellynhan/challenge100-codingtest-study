//
//  1748.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 120
 [Output]
 252
 */
// 시간복잡도: O(nlogn)
// 최악시간: 10
// 난이도: Silver 4
// Timer: 17m
// Url: https://www.acmicpc.net/problem/1748

#include <iostream>

using namespace std;
int answer;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    int len = 1;
    int val = 10;
    while(true) {
        if(n >= val) {
            answer += (val - (val / 10)) * len;
            val *= 10;
            len++;
        } else {
            answer += (n - (val / 10) + 1) * len;
            break;
        }
    }
    cout << answer;

	return 0;
}
