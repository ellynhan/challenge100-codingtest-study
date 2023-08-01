//
//  15927.cpp
//  main
//
//  Created by wi_seong on 2023/03/23.
//

/*
 [Input]
 AABBB
 [Output]
 5
 */
// 시간복잡도: O(n)
// 최악시간:
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/15927

#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string &s) {
    int n = (int)s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    int n = (int)input.length();

    if (!is_palindrome(input)) {
        cout << n << '\n';
    } else if (!is_palindrome(input.substr(0, n - 1))) {
        cout << n - 1 << '\n';
    } else {
        cout << "-1" << '\n';
    }

    return 0;
}
