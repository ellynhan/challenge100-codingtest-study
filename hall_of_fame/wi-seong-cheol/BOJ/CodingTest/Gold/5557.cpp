//
//  5557.cpp
//  main
//
//  Created by wi_seong on 2023/02/28.
//

/*
 [Input]
 11
 8 3 2 4 8 7 2 4 0 8 8
 [Output]
 10
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 2,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/5557

#include <iostream>

using namespace std;
#define ll long long
int n;
ll a[101];
ll d[21][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    d[a[0]][0] = 1;
    for(int i = 1; i < n - 1; i++)
        for(int j = 0; j <= 20; j++)
            if(d[j][i - 1] > 0) {
                if(0 <= j + a[i] && j + a[i] <= 20)
                    d[j + a[i]][i] += d[j][i - 1];
                if(0 <= j - a[i] && j - a[i] <= 20)
                    d[j - a[i]][i] += d[j][i - 1];
            }
    cout << d[a[n - 1]][n - 2];
    
    return 0;
}
