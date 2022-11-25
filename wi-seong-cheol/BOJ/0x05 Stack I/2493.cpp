//
//  2493.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/07.
//

/*
 [Input]
 5
 6 9 5 7 4
 [Output]
 0 0 2 2 4
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Gold 5
// Timer: 18m
// Url: https://www.acmicpc.net/problem/

#include <iostream>
#include <stack>

using namespace std;
#define X first
#define Y second
stack<pair<int, int>> S;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    S.push({100000001, 0});
    for(int i = 1; i <= n; i++) {
        int height; cin >> height;
        while(S.top().X < height)
            S.pop();
        cout << S.top().Y << ' ';
        S.push({height, i});
    }
    
    return 0;
}
