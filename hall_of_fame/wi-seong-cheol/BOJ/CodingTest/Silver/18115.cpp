//
//  18115.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/04.
//

/*
 [Input]
 5
 1 1 1 1 1
 [Output]
 5 4 3 2 1
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 3
// Timer: 20m
// Url: https://www.acmicpc.net/problem/18115

#include <iostream>
#include <vector>
#include <deque>

using namespace std;
int n;
deque<int> ans;
vector<int> skill;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        skill.push_back(x);
    }
    int card = 1;
    for(int i = n - 1; i >= 0; i--) {
        if(skill[i] == 1) {
            ans.push_back(card);
        } else if(skill[i] == 2) {
            int tmp = ans.back();
            ans.pop_back();
            ans.push_back(card);
            ans.push_back(tmp);
        } else {
            ans.push_front(card);
        }
        card++;
    }
    for(int i = n - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    
    return 0;
}
