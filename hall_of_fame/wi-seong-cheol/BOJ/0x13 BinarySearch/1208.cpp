//
//  1208.cpp
//  main
//
//  Created by wi_seong on 1/9/24.
//

/*
 [Input]
 5 0
 -7 -3 -2 5 8
 [Output]
 1
 */
// 시간복잡도: O(2 ^ (n / 2))
// 최악시간: 1,048,576
// 난이도: Gold 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1208

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
#define ll long long
int n, k;
ll ans;
int arr[41];
unordered_map<int, int> sumMap;

void leftSeq(int idx, int sum) {
    if(idx == n/2) {
        sumMap[sum]++;
        return;
    }
    leftSeq(idx+1, sum + arr[idx]);
    leftSeq(idx+1, sum);
}

void rightSeq(int idx, int sum) {
    if(idx == n) {
        ans += sumMap[k - sum];
        return;
    }
    rightSeq(idx+1, sum + arr[idx]);
    rightSeq(idx+1, sum);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    leftSeq(0, 0);
    rightSeq(n/2, 0);

    if(k == 0) {
        ans--;
    }
    cout << ans;

	return 0;
}
