//
//  15649.cpp
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
 2 1
 2 3
 2 4
 3 1
 3 2
 3 4
 4 1
 4 2
 4 3
 */
// 시간복잡도: O(2 ^ n)
// 최악시간: 256
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/15649

#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> arr;
bool isused[9];

void func(int k) {
    if(k == m) {
        for(int x: arr)
            cout << x << ' ';
        cout << '\n';
        return;
    }
    
    for(int i = 1; i <= n; i++) {
        if(!isused[i]) {
            isused[i] = true;
            arr.push_back(i);
            func(k + 1);
            arr.pop_back();
            isused[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    func(0);
    
    return 0;
}
