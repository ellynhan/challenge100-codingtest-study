//
//  10610.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 80875542
 [Output]
 88755420
 */
// 시간복잡도: O(L)
// 최악시간: 5
// 난이도: Silver 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/10610

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
string n;
vector<int> nums;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(char c: n)
        nums.push_back(c - '0');
    sort(nums.begin(), nums.end(), greater<>());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % 3 == 0 && nums.back() == 0)
        for(int x: nums) cout << x;
    else
        cout << -1;
    
    return 0;
}
