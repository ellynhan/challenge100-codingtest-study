//
//  13144.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 1 2 3 4 5
 [Output]
 15
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Gold 4
// Timer: 40m
// Url: https://www.acmicpc.net/problem/13144

#include <iostream>
#include <vector>

using namespace std;
#define ll long long
int n;
vector<int> a(100001);
vector<bool> check(100001);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    int en = 0;
    check[a[0]] = true;
    ll cnt = 0;
    for(int st = 0; st < n; st++) {
        while(en < n - 1 && !check[a[en + 1]]) {
            en++;
            check[a[en]] = true;
        }
        cnt += (en - st + 1);
        check[a[st]] = false;
    }
    cout << cnt;
    
    return 0;
}
