//
//  13164.cpp
//  main
//
//  Created by wi_seong on 2023/02/11.
//

/*
 [Input]
 5 3
 1 3 5 6 10
 [Output]
 3
 */
// 시간복잡도: O(nlogn)
// 최악시간: 1,500,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/13164

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, x;
vector<int> a;
vector<int> df;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    a.resize(n);
    df.resize(n - 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i != 0)
            df[i - 1] = a[i] - a[i - 1];
    }
    sort(df.begin(), df.end(), greater<>());
    int dif = a[n - 1] - a[0];
    for(int i = 0; i < m - 1; i++)
        dif -= df[i];
    cout << dif;
    
    return 0;
}
