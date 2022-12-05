//
//  2910.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/30.
//

/*
 [Input]
 5 2
 2 1 2 1 2
 [Output]
 2 2 2 1 1
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,500
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/2910

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long
#define X first
#define Y second
int n;
ll x, c;
vector<ll> arr;
vector<pair<int, ll>> v;

bool cmp(const pair<int, ll>& element1, const pair<int, ll>& element2) {
    return element1.X > element2.X;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> x;
        bool isFind = false;
        for(auto& element: v) {
            if(element.Y == x) {
                element.X++;
                isFind = true;
                break;
            }
        }
        if(!isFind) v.push_back({1, x});
    }
    stable_sort(v.begin(), v.end(), cmp);
    for(auto element: v)
        while(element.X--)
            cout << element.Y << ' ';
    
    return 0;
}
