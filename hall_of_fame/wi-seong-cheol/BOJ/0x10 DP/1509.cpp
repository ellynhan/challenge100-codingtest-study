//
//  1509.cpp
//  main
//
//  Created by wi_seong on 1/10/24.
//

/*
 [Input]
 BBCDDECAECBDABADDCEBACCCBDCAABDBADD
 [Output]
 22
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 6,250,000
// 난이도: Gold 1
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1509

#include <iostream>
#include <algorithm>

using namespace std;
#define INF 987654321
string s;
int cache[2501][2501];

bool isPalindrome(int st, int length) {
    string sub = s.substr(st, length);
    for(int i = 0; i < int(sub.size()) / 2; i++)
        if(sub[i] != sub[sub.size() - 1 - i])
            return false;
    return true;
}

int countDivide(int st, int en) {
    if(isPalindrome(st, en - st)) return 1;
    int &ret = cache[st][en];
    if(ret != 0) return ret;

    ret = INF;
    for(int len = en; len > 0; len--) {
        if(isPalindrome(st, len)) {
            ret = min(ret, 1 + countDivide(st + len, en));
        }
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> s;
    cout << countDivide(0, int(s.length()));

	return 0;
}
