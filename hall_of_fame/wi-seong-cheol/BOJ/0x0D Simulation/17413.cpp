//
//  17413.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 baekjoon online judge
 [Output]
 noojkeab enilno egduj
 */
// 시간복잡도: O(n)
// 최악시간: 200,000
// 난이도: Silver 3
// Timer: 11m
// Url: https://www.acmicpc.net/problem/17413

#include <iostream>
#include <algorithm>

using namespace std;
string s, result, tmp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    bool flag = false;
    getline(cin, s);
    for(char ch: s) {
        if(ch == ' ' && !flag) {
            reverse(tmp.begin(), tmp.end());
            result += tmp + " ";
            tmp = "";
            continue;
        }
        if(ch == '<') {
            flag = true;
            reverse(tmp.begin(), tmp.end());
            result += tmp;
            tmp = "";
        }
        if(ch == '>') {
            flag = false;
            result += tmp + ">";
            tmp = "";
            continue;
        }
        tmp += ch;
    }
    reverse(tmp.begin(), tmp.end());
    result += tmp;
    cout << result;

	return 0;
}
