//
//  9655.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 5
 [Output]
 SK
 */
// 시간복잡도: O(1)
// 최악시간: 1
// 난이도: Silver 5
// Timer: 5m
// Url: https://www.acmicpc.net/problem/9655

#include <iostream>

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    if(n % 2 == 1) cout << "SK";
    else cout << "CY";
    
    return 0;
}
