//
//  1138.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/6/24.
//

/*
 [Input]
 6
 5 4 3 2 1 0
 [Output]
 6 5 4 3 2 1
 */
// 시간복잡도: O(2 ^ n)
// 최악시간: 2,000
// 난이도: Silver 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1138

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[11];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> v;
    for(int i = 1; i <= n; i++)
        v.push_back(i);
    do {
        int cnt[n];
        bool flag = true;
        for(int i = 0; i < n; i++) {
            cnt[v[i]] = 0;
            for(int j = 0; j < i; j++) {
                if(v[j] > v[i]) cnt[v[i]]++;
            }
            if(cnt[v[i]] != arr[v[i] - 1]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            for(int val: v)
                cout << val << ' ';
            break;
        }
    } while(next_permutation(v.begin(), v.end()));

	return 0;
}
