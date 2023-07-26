//
//  1477.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 6 7 800
 622 411 201 555 755 82
 [Output]
 70
 */
// 시간복잡도: O(nlogn)
// 최악시간: 200
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1477

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, l;
vector<int> a;

int binarySearch() {
    int st = 1;
    int en = l - 1;
    
    while(st <= en) {
        int mid = (st + en) / 2;
        int cnt = 0;
        for(int i = 1; i < n + 2; i++) {
            int section = a[i] - a[i - 1];
            cnt += section / mid;
            if(section % mid == 0) cnt--;
        }
        
        if(cnt > m) st = mid + 1;
        else en = mid - 1;
    }
    
    return st;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> l;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    a.push_back(0);
    a.push_back(l);
    sort(a.begin(), a.end());
    
    cout << binarySearch();
    
    return 0;
}
