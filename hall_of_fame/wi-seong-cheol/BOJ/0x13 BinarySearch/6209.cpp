//
//  6209.cpp
//  main
//
//  Created by wi_seong on 1/8/24.
//

/*
 [Input]
 25 5 2
 2
 14
 11
 21
 17
 [Output]
 4
 */
// 시간복잡도: O(nlogd + nlogn)
// 최악시간: 400,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/6209

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define INF 987654321
int d, n, m;
vector<int> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> d >> n >> m;
    a.push_back(0);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    a.push_back(d);
    
    sort(a.begin(), a.end());

    int left = 0, right = d;
    int ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int sum = 0;
        int cur = 0;

        for(int i = 1; i < a.size(); i++) {
            if(a[i] - a[cur] < mid) sum++;
            else cur = i;
        }
        
        if(sum > m) right = mid - 1;
        else {
            ans = mid;
            left = mid + 1;
        }
    }

    cout << ans;

	return 0;
}
