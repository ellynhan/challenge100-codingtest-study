//
//  5430.cpp
//  main
//
//  Created by wi_seong on 2022/11/10.
//

/*
 [Input]
 4
 RDD
 4
 [1,2,3,4]
 DD
 1
 [42]
 RRD
 6
 [1,1,2,3,5,8]
 D
 0
 []
 [Output]
 [2,1]
 error
 [1,2,3,5,8]
 error
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Gold 5
// Timer: 40m
// Url: https://www.acmicpc.net/problem/5430

#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string p; cin >> p;
        int n; cin >> n;
        string arr; cin >> arr;
        
        bool dir = true;
        bool err = false;
        deque<int> dq;
        
        stringstream iss(arr.substr(1, arr.size() - 1));
        string token;
        while (getline(iss, token, ',')) {
            if(token != "]") dq.push_back(stoi(token));
        }
        for(auto op: p) {
            if(op == 'R') {
                dir = dir ? false : true;
            } else {
                if(dq.empty()) {
                    err = true;
                    break;
                }
                if(dir) dq.pop_front();
                else dq.pop_back();
            }
        }
        if(err) cout << "error\n";
        else {
            if(!dir) reverse(dq.begin(), dq.end());
            cout << '[';
            for(int i = 0; i < dq.size(); i++) {
                cout << dq[i];
                if(i != dq.size() - 1) cout << ',';
            }
            cout << "]\n";
        }
    }
    
    return 0;
}
