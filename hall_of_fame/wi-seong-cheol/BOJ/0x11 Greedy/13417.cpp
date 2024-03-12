//
//  13417.cpp
//  main
//
//  Created by wi_seong on 3/12/24.
//

/*
 [Input]
 3
 3
 M K U
 5
 A S D F G
 7
 B A C A B A C
 [Output]
 KMU
 ASDFG
 AAABCBC
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 3
// Timer: 2m
// Url: https://www.acmicpc.net/problem/13417

#include <iostream>

using namespace std;
int t, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        string s = "";
        for(int i = 0; i < n; i++) {
            char ch; cin >> ch;
            if(s.empty()) s += ch;
            else if(s[0] >= ch) s = ch + s;
            else s += ch;
        }
        cout << s << '\n';
    }

	return 0;
}
