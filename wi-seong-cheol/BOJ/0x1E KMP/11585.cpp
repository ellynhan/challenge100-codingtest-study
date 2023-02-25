//
//  11585.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 9
 I W A N T M E A T
 E A T I W A N T M
 [Output]
 1/9
 */
// 시간복잡도: O(n + m)
// 최악시간: 3,000,000
// 난이도: Platinum 5
// Timer: 50m
// Url: https://www.acmicpc.net/problem/11585

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1e6 + 5;
int n;
vector<int> f;
char a[SIZE * 2];
char b[SIZE];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

vector<int> failure() {
    vector<int> f(n);
    int j = 0;
    for(int i = 1; i < n; i++) {
        while(j > 0 && b[i] != b[j]) j = f[j - 1];
        if(b[i] == b[j]) f[i] = ++j;
    }
    return f;
}

int kmp() {
    int cnt = 0;
    int j = 0;
    f = failure();
    for(int i = 0; i < 2 * n - 1; i++) {
        while(j > 0 && a[i] != b[j]) j = f[j - 1];
        if(a[i] == b[j]) j++;
        if(j == n) {
            cnt++;
            j = f[j - 1];
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        char ch; cin >> ch;
        a[i] = ch;
        a[n + i] = ch;
    }
    for(int i = 0; i < n; i++)
        cin >> b[i];
    int cnt = kmp();
    int d = gcd(cnt, n);
    cout << cnt / d << '/' << n / d;

    return 0;
}
