//
//  1193.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/30.
//

/*
 [Input]
 14
 [Output]
 2/4
 */
// 시간복잡도: O(n)
// 최악시간: 4471
// 난이도: Silver 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1193

#include <iostream>

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int i = 1;
    while(n > i) {
        n -= i;
        i++;
    }
    
    int nume = n;
    int deno = i + 1 - n;
    if(i % 2 == 1) swap(nume, deno);
    cout << nume << '/' << deno << '\n';
    
    return 0;
}
