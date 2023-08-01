//
//  16922.cpp
//  main
//
//  Created by wi_seong on 2023/03/27.
//

/*
 [Input]
 10
 [Output]
 244
 */
// 시간복잡도: O(2 ^ n)
// 최악시간: 1,048,576
// 난이도: Silver 3
// Timer: 5m
// Url: https://www.acmicpc.net/problem/16922

#include <iostream>
#include <unordered_set>

using namespace std;
int n;
unordered_set<int> s;
int num[4] = {1, 5, 10, 50};

void func(int k, int sum, int idx) {
    if(k == n) {
        s.insert(sum);
        return;
    }
    
    for(int i = idx; i < 4; i++)
        func(k + 1, sum + num[i], i);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    func(0, 0, 0);
    cout << s.size();
    
    return 0;
}
