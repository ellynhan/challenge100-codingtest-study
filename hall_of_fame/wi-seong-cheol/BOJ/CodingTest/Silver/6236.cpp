//
//  6236.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/07.
//

/*
 [Input]
 7 5
 100
 400
 300
 100
 500
 101
 400
 [Output]
 500
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Silver 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/6236

#include <iostream>

using namespace std;
int ans, sum;
int n, m;
int money[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> money[i];
        sum += money[i];
    }
    int low = 1;
    int high = sum;

    while(low <= high) {
        int mid = (low + high) / 2;
        int total = mid;
        int cnt = 1;
        bool flag = true;
        for(int i = 0; i < n; i++) {
            int day_money = money[i];
            if(day_money > mid) {
                flag = false;
                break;
            }
            if(day_money > total) {
                total = mid;
                cnt++;
            }
            total -= day_money;
        }

        if(!flag || cnt > m) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    cout << ans;

    return 0;
}
