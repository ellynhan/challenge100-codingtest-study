//
//  4673.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 -
 [Output]
 1
 3
 5
 7
 9
 20
 31
 42
 53
 64
  |
  |       <-- a lot more numbers
  |
 9903
 9914
 9925
 9927
 9938
 9949
 9960
 9971
 9982
 9993
 */
// 시간복잡도: O(nlogn)
// 최악시간: 40,000
// 난이도: Silver 5
// Timer: 5m
// Url: https://www.acmicpc.net/problem/4673

#include <iostream>

using namespace std;
int cnt[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    for(int i = 1; i <= 10000; i++) {
        if(cnt[i] == 0) cout << i << '\n';
        int sum = i;
        int tmp = i;
        while(tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if(sum <= 10000) cnt[sum]++;
    }

	return 0;
}
