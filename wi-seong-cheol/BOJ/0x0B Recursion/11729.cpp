//
//  11729.cpp
//  main
//
//  Created by wi_seong on 2022/11/21.
//

/*
 [Input]
 3
 [Output]
 7
 1 3
 1 2
 3 2
 1 3
 2 1
 2 3
 1 3
 */
// 시간복잡도: O()
// 최악시간: 
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/11729

#include <iostream>

using namespace std;

void func(int a, int b, int n) {
    if(n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    func(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    func(6 - a - b, b, n - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    cout << (1<<n) - 1 << '\n';
    func(1, 3, n);
    
    return 0;
}
