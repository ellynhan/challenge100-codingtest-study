//
//  12015.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 6
 10 20 10 30 20 50
 [Output]
 4
 */
// 시간복잡도: O(nlogn)
// 최악시간: 6,000,000
// 난이도: Gold 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/12015

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int input; cin >> input;
        if(a.empty() || a.back() < input) {
            a.push_back(input);
        } else {
            *lower_bound(a.begin(), a.end(), input) = input;
        }
    }
    cout << a.size();
    
    return 0;
}
