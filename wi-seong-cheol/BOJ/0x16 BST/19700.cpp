//
//  .cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 172 1
 161 2
 188 4
 154 2
 180 1
 [Output]
 3
 */
// 시간복잡도: O(nlogn)
// 최악시간: 15,000,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/19700

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
#define X first
#define Y second
int n, ans;
pair<int, int> arr[500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i].X >> arr[i].Y;
    sort(arr, arr + n, greater<>());
    multiset<int> group;
    
    for(int i = 0; i < n; i++) {
        auto lower = group.lower_bound(arr[i].Y);
        if(lower == group.begin()) {
            group.insert(1);
        } else {
            int size = (*prev(lower));
            group.erase(prev(lower));
            group.insert(size + 1);
        }
    }
    
    cout << group.size();
    
    return 0;
}
