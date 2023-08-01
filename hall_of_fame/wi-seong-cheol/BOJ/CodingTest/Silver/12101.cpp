//
//  12101.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/16.
//

/*
 [Input]
 4 8
 [Output]
 -1
 */
// 시간복잡도: O(2^n)
// 최악시간: 32,768
// 난이도: Silver 1
// Timer: 20m
// Url: https://www.acmicpc.net/problem/12101

#include <iostream>
#include <vector>

using namespace std;
int n, m, cnt;
bool flag;
vector<int> a;

void func(int sum) {
    if(sum > n) return;
    if(sum == n) {
        cnt++;
        if(cnt == m) {
            for(int i = 0; i < a.size() - 1; i++)
                cout << a[i] << '+';
            cout << a.back();
            flag = true;
        }
        return;
    }
    
    for(int i = 1; i <= 3; i++) {
        a.push_back(i);
        func(sum + i);
        a.pop_back();
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    func(0);
    if(!flag) cout << -1;
    
    return 0;
}
