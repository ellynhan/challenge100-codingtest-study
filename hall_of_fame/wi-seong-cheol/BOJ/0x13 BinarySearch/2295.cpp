//
//  2295.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 2
 3
 5
 10
 18
 [Output]
 18
 */
// 시간복잡도: O(n^2logn)
// 최악시간: 3,000,000
// 난이도: Gold 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/2295

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int a[1001];
vector<int> two;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            two.push_back(a[i] + a[j]);
    sort(two.begin(), two.end());
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(binary_search(two.begin(), two.end(), a[i] - a[j])) {
                cout << a[i];
                return 0;
            }
        }
    }
    
    return 0;
}
