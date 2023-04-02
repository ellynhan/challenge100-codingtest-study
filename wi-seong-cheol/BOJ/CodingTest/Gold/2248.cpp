//
//  2248.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 900
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2248

#include <iostream>

using namespace std;
#define ll long long
int N, L;
ll I;
ll d[33][33];
string ans;

void findfunc(int N, int L, long long I) { // L은 채울수있는 1의개수 I는 남은 순서 수
    if(N == 0) return;
    if(L == 0) {
        for(int i = 0; i < N; i++)
            ans += '0';
        return;
    }

    long long skip = 0;
    for(int i = 0; i <= L; i++)
        skip += d[N - 1][i];

    if(skip >= I) {
        ans += '0';
        findfunc(N - 1, L, I);
    }
    else {
        ans += '1';
        findfunc(N - 1, L - 1, I - skip);
    }

    return;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> L >> I;
    d[0][0] = 1;
    for(int i = 1; i < 33; i++) {
        d[i][0] = 1;
        d[i][i] = 1;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 1; j <= i; j++) {
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
        }
    }

    findfunc(N, L, I);
    cout<< ans;

    return 0;
}
