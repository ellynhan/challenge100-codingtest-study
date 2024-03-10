//
//  10973.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/6/24.
//

/*
 [Input]
 5
 5 4 3 2 1
 [Output]
 5 4 3 1 2
 */
// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/10973

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> arr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    if(prev_permutation(arr.begin(), arr.end())) {
        for(int val: arr)
            cout << val << ' ';
    } else {
        cout << -1;
    }

	return 0;
}
