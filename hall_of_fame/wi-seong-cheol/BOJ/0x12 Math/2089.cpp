//
//  2089.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 -13
 [Output]
 110111
 */
// 시간복잡도: O(n)
// 최악시간: 11
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/2089

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    if(n == 0) {
        cout << 0;
        return 0;
    }
    while(n) {
        if(n < 0) {
            if(n % 2 == 0) {
                n = -(n/2);
                v.push_back(0);
            } else {
                n = -(n/2) + 1;
                v.push_back(1);
            }
        } else {
            v.push_back(n % 2);
            n = -(n/2);
        }
    }
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) cout << v[i];
    
    return 0;
}
