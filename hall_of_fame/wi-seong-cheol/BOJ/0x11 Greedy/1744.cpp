//
//  1744.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 4
 -1
 2
 1
 3
 [Output]
 6
 */
// 시간복잡도: O(nlogn)
// 최악시간: 100
// 난이도: Gold 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1744

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long
ll ans;
int n;
vector<int> seqP, seqN;

void seqSum(vector<int> v) {
    while(1 < v.size()) {
        ans += *(v.end() - 1) * *(v.end() - 2);
        v.pop_back();
        v.pop_back();
    }
    if(!v.empty()) ans += v.front();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == 1) ans++;
        else if(0 < x)
            seqP.push_back(x);
        else
            seqN.push_back(x);
    }
    sort(seqP.begin(), seqP.end());
    sort(seqN.begin(), seqN.end(), greater<>());
    seqSum(seqP);
    seqSum(seqN);
    cout << ans;
    
    return 0;
}
