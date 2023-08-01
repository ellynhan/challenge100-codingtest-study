//
//  10597.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/17.
//

/*
 [Input]
 4111109876532
 [Output]
 4 1 11 10 9 8 7 6 5 3 2 
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 2,500
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/10597

#include <iostream>
#include <vector>

using namespace std;
string num;
int n;
vector<int> ans;
bool isused[51];

void func(int k, int pos) {
    if(k == n) {
        for(int x: ans)
            cout << x << ' ';
        exit(0);
    }
    
    for(int i = 1; i <= n; i++) {
        int val = 0;
        
        if(i < 10) val = stoi(num.substr(pos, 1));
        else val = stoi(num.substr(pos, 2));
                              
        if(!isused[i] && val == i) {
            isused[i] = true;
            ans.push_back(i);
            int npos = pos + 1 + (i >= 10);
            func(k + 1, npos);
            ans.pop_back();
            isused[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> num;
    int len = (int)num.length();
    if(len < 10) n = len;
    else n = 9 + (len - 9) / 2;
    func(0, 0);
    
    return 0;
}
