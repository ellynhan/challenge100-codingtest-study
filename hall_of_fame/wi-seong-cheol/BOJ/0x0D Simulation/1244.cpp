//
//  1244.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 8
 0 1 0 1 0 0 0 1
 2
 1 3
 2 3
 [Output]
 1 0 0 0 1 1 0 1
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 40,000
// 난이도: Silver 4
// Timer: 14m
// Url: https://www.acmicpc.net/problem/1244

#include <iostream>

using namespace std;
int n;
int arr[101];

bool OOB(int x) { return x < 0 || x >= n; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(a == 1) {
            for(int i = b - 1; i < n; i += b) {
                arr[i] = (arr[i] + 1) % 2;
            }
        } else {
            b--;
            arr[b] = (arr[b] + 1) % 2;
            int left = b - 1;
            int right = b + 1;
            while(!OOB(left) && !OOB(right)) {
                if(arr[left] != arr[right]) break;
                arr[left--] = (arr[left] + 1) % 2;
                arr[right++] = (arr[right] + 1) % 2;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(i > 0 && i % 20 == 0) cout << '\n';
        cout << arr[i] << ' ';
    }

	return 0;
}
