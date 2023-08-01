//
//  17829.cpp
//  main
//
//  Created by wi_seong on 2023/02/28.
//

/*
 [Input]
 8
 -1 2 14 7 4 -5 8 9
 10 6 23 2 -1 -1 7 11
 9 3 5 -2 4 4 6 6
 7 15 0 8 21 20 6 6
 19 8 12 -8 4 5 2 9
 1 2 3 4 5 6 7 8
 9 10 11 12 13 14 15 16
 17 18 19 20 21 22 23 24
 [Output]
 17
 */
// 시간복잡도: O((nlogn)^2)
// 최악시간: 9,000,000
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/17829

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int dx[] = {0, 1, 0, 1};
int dy[] = {0, 0, 1, 1};

int func(int n, vector<vector<int>>& v) {
    if(n == 1) {
        return v[0][0];
    }
    vector<vector<int>> ret(n / 2);
    for(int i = 0; i < n / 2; i++)
        ret[i].resize(n / 2);
    for(int i = 0; i < n; i += 2) {
        for(int j = 0; j < n; j += 2) {
            vector<int> arr;
            for(int k = 0; k < 4; k++)
                arr.push_back(v[i + dx[k]][j + dy[k]]);
            sort(arr.begin(), arr.end());
            ret[i / 2][j / 2] = arr[2];
        }
    }
    return func(n / 2, ret);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++) {
        v[i].resize(n);
        for(int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    cout << func(n, v);
    
    return 0;
}
