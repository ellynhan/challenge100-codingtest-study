//
//  2331.cpp
//  main
//
//  Created by wi_seong on 3/18/24.
//

/*
 [Input]
 57 2
 [Output]
 4
 */
// 시간복잡도: O(nlogn)
// 최악시간: 40,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/2331

#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;
int n, p;
int d[10001];
unordered_map<int, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> n >> p;
    d[1] = n;
    m[n] = 1;
    for(int i = 2; i <= 10000; i++) {
        int tmp = d[i - 1];
        int sum = 0;
        while(tmp) {
            sum += pow(tmp % 10, p);
            tmp /= 10;
        }
        m[sum]++;
        d[i] = sum;
    }
    int cnt = 0;
    for(auto element: m) {
        if(element.second == 1) cnt++;
    }
    cout << cnt;

	return 0;
}
