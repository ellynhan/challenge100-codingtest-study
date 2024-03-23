//
//  11576.cpp
//  main
//
//  Created by wi_seong on 3/18/24.
//

/*
 [Input]
 17 8
 2
 2 16
 [Output]
 6 2
 */
// 시간복잡도: O(n)
// 최악시간: 25
// 난이도: Silver 5
// Timer: 10m
// Url: https://www.acmicpc.net/problem/11576

#include <iostream>
#include <stack>
#include <cmath>

using namespace std;
int a, b, m, x;
stack<int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> a >> b;
    cin >> m;
    int val = 0;
    for(int i = m - 1; i >= 0; i--) {
        cin >> x;
        val += x * pow(a, i);
    }

    while(val) {
        ans.push(val % b);
        val /= b;
    }
    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }

	return 0;
}
