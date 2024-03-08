//
//  2161.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 7
 [Output]
 1 3 5 7 4 2 6
 */
// 시간복잡도: O(n)
// 최악시간: 2,000
// 난이도: Silver 5
// Timer: 2m
// Url: https://www.acmicpc.net/problem/2161

#include <iostream>
#include <deque>

using namespace std;
int n;
deque<int> d;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        d.push_back(i);
    while(!d.empty()) {
        cout << d.front() << ' ';
        d.pop_front();
        d.push_back(d.front());
        d.pop_front();
    }

	return 0;
}
