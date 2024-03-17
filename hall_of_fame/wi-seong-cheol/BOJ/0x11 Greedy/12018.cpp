//
//  12018.cpp
//  main
//
//  Created by wi_seong on 3/12/24.
//

/*
 [Input]
 5 76
 5 4
 36 25 1 36 36
 4 4
 30 24 25 20
 6 4
 36 36 36 36 36 36
 2 4
 3 7
 5 4
 27 15 26 8 14
 [Output]
 4
 */
// 시간복잡도: O(nlogn)
// 최악시간: 200
// 난이도: Silver 3
// Timer: 6m
// Url: https://www.acmicpc.net/problem/12018

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, mile, P, L;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> mile;
    vector<int> subject;

    for(int i = 0; i < n; i++) {
        cin >> P >> L;
        vector<int> v;
        for(int j = 0; j < P; j++) {
            int x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end(), greater<int>());
        if(P < L) subject.push_back(1);
        else subject.push_back(v[L - 1]);
    }
    sort(subject.begin(), subject.end());

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(mile < subject[i]) break;
        mile -= subject[i];
        ans++;
    }
    cout << ans;

	return 0;
}
