//
//  15904.cpp
//  main
//
//  Created by wi_seong on 3/11/24.
//

/*
 [Input]
 Union of Computer Programming Contest club contest
 [Output]
 I love UCPC
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 5
// Timer: 3m
// Url: https://www.acmicpc.net/problem/15904

#include <iostream>

using namespace std;
string s = "UCPC";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    bool flag = false;
    int cnt = 0;
    string str;
    getline(cin, str);
    for(char ch: str) {
        if(ch == s[cnt]) {
            cnt++;
            if(cnt == 4) {
                flag = true;
                break;
            }
        }
    }

    if(flag) cout << "I love UCPC";
    else cout << "I hate UCPC";

	return 0;
}
