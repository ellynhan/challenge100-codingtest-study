//
//  2477.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 7
 4 50
 2 160
 3 30
 1 60
 3 20
 1 100
 [Output]
 47600
 */
// 시간복잡도: O(n)
// 최악시간: 12
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2477

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int k;
pair<int, int> a[12];
int size1, size2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> k;
    for(int i = 0; i < 6; i++) {
        int dir, val;
        cin >> dir >> val;
        a[i] = a[i + 6] = {dir, val};
    }
    for(int i = 3; i < 12; i++) {
        if(a[i].first == a[i - 2].first
           && a[i - 1].first == a[i - 3].first) {

            size1 = a[i + 1].second * a[i + 2].second;
            size2 = a[i - 1].second * a[i - 2].second;

            break;
        }
    }
    cout << (size1 - size2) * k;

	return 0;
}
