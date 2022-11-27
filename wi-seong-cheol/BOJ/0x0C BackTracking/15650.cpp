//
//  15650.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
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
// 시간복잡도: O(2^n)
// 최악시간: 256
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/15650

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<bool> isused;
    for(int i = 0; i < n; i++)
        isused.push_back(i < m ? 0 : 1);
    do {
        for(int i = 0; i < n; i++)
            if(!isused[i]) cout << i + 1 << ' ';
        cout << '\n';
    } while(next_permutation(isused.begin(), isused.end()));
    
    return 0;
}
