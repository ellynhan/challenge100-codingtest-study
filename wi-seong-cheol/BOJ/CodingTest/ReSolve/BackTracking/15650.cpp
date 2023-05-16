//
//  15650.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/14.
//

/*
 [Input]
 4 2
 [Output]
 1 2
 1 3
 1 4
 2 3
 2 4
 3 4
 */
// 시간복잡도: O(2 ^ n)
// 최악시간: 256
// 난이도: Silver 3
// Timer: 5m
// Url: https://www.acmicpc.net/problem/15650

#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> a;
bool isused[9];

void func(int k, int cur) {
    if(k == m) {
        for(int x: a)
            cout << x << ' ';
        cout << '\n';
        return;
    }
    
    for(int i = cur + 1; i <= n; i++) {
        if(!isused[i]) {
            isused[i] = true;
            a.push_back(i);
            func(k + 1, i);
            a.pop_back();
            isused[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    func(0, 0);
    
    return 0;
}
