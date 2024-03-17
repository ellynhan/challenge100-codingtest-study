//
//  9009.cpp
//  main
//
//  Created by wi_seong on 3/12/24.
//

/*
 [Input]
 4
 100
 200
 12345
 1003
 [Output]
 3 8 89
 1 55 144
 1 34 377 987 10946
 3 13 987
 */
// 시간복잡도: O(n)
// 최악시간: 44
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/9009

#include <iostream>
#include <vector>

using namespace std;
int t, n;
vector<int> fibo(46);

int f(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(fibo[n]) return fibo[n];
    return fibo[n] = f(n - 1) + f(n - 2);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    f(45);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> ans;
        for(int i = 44; i > 0; i--) {
            if(fibo[i] <= n) {
                n -= fibo[i];
                ans.push_back(fibo[i]);
            }
            if(n == 0) break;
        }
        for(int i = int(ans.size()) - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }

	return 0;
}
