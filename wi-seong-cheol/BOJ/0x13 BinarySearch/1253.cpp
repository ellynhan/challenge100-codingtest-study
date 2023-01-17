//
//  .cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 10
 1 2 3 4 5 6 7 8 9 10
 [Output]
 8
 */
// 시간복잡도: O(n^2)
// 최악시간: 4,000,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1253

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int n, ans;
int a[2001];
map<int,int> occur;
vector<int> sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        occur[a[i]]++;
    }
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) continue;
        for(int j = i + 1; j < n; j++) {
            if(a[j] == 0) continue;
            sum.push_back(a[i] + a[j]);
        }
    }
    sort(sum.begin(), sum.end());
    for(int i = 0; i < n; i++) {
        if(binary_search(sum.begin(), sum.end(), a[i])) {
            ans++;
            continue;
        }
        if(a[i] == 0) {
            if(occur[0] >= 3) {
                ans++;
            }
            continue;
        }
        if(occur[0] >= 1 and occur[a[i]] >= 2)
            ans++;
    }
    cout << ans;
    
    return 0;
}
