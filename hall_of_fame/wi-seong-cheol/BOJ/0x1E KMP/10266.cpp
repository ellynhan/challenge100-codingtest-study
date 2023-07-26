//
//  10266.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7
 140 130 110 120 125 100 105
 235 205 215 220 225 200 240
 [Output]
 impossible
 */
// 시간복잡도: O(n + m)
// 최악시간: 1,180,000
// 난이도: Platinum 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/10266

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 360000;
int n, x;
bool a[SIZE * 2 + 1];
bool b[SIZE + 1];
vector<int> f;

vector<int> failure() {
    vector<int> f(SIZE);
    int j = 0;
    for(int i = 1; i < SIZE; i++) {
        while(j > 0 && b[i] != b[j]) j = f[j - 1];
        if(b[i] == b[j]) f[i] = ++j;
    }
    return f;
}

void kmp() {
    f = failure();
    bool isPossible = false;
    int j = 0;
    for(int i = 0; i < 2 * SIZE; i++) {
        while(j > 0 && a[i] != b[j]) j = f[j - 1];
        if(a[i] == b[j]) j++;
        if(j == SIZE - 1) {
            isPossible = true;
            break;
        }
    }
    if(isPossible)
        cout << "possible";
    else
        cout << "impossible";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x] = true;
        a[x + SIZE] = true;
    }

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        b[x] = true;
    }
    kmp();

    return 0;
}
