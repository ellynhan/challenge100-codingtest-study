//
//  19583.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 22:00 23:00 23:30
 21:30 malkoring
 21:33 tolelom
 21:34 minjae705
 21:35 hhan14
 21:36 dicohy27
 21:40 906bc
 23:00 906bc
 23:01 tolelom
 23:10 minjae705
 23:11 hhan14
 23:20 dicohy27
 [Output]
 5
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 2
// Timer: 20m
// Url: https://www.acmicpc.net/problem/19583

#include <iostream>
#include <unordered_set>

using namespace std;
string S, E, Q, t, nick;
unordered_set<string> list;
unordered_set<string> ans_list;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> E >> Q;
    while(true) {
        cin >> t >> nick;
        if(cin.eof() == true) break;
        
        if(t <= S) {
            list.insert(nick);
        } else if(E <= t && t <= Q){
            if(list.find(nick) != list.end())
                ans_list.insert(nick);
        }
    }
    cout << ans_list.size();

    return 0;
}
