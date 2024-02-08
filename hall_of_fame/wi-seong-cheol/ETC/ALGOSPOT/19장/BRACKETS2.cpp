//
//  BRACKETS2.cpp
//  main
//
//  Created by wi_seong on 1/20/24.
//

/*
 [Input]
 3
 ()()
 ({[}])
 ({}[(){}])
 [Output]
 YES
 NO
 YES
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: 하
// Timer: 10m
// Url: https://algospot.com/judge/problem/read/BRACKETS2

#include <iostream>
#include <stack>

using namespace std;
int t;
string s;

bool solve() {
    stack<char> S;

    for(char ch: s) {
        if(ch == '(' || ch == '{' || ch == '[') {
            S.push(ch);
        } else {
            if(S.empty()) {
                return false;
            } else {
                char top = S.top(); S.pop();

                if((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
    }

    return S.empty();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> s;
        bool isCorrect = solve();
        if(isCorrect) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

	return 0;
}
