//
//  16165.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3 4
 twice
 9
 jihyo
 dahyeon
 mina
 momo
 chaeyoung
 jeongyeon
 tzuyu
 sana
 nayeon
 blackpink
 4
 jisu
 lisa
 rose
 jenny
 redvelvet
 5
 wendy
 irene
 seulgi
 yeri
 joy
 sana
 1
 wendy
 1
 twice
 0
 rose
 1
 [Output]
 twice
 redvelvet
 chaeyoung
 dahyeon
 jeongyeon
 jihyo
 mina
 momo
 nayeon
 sana
 tzuyu
 blackpink
 */
// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/16165

#include <iostream>
#include <map>

using namespace std;
#define X first
#define Y second
int n, m, cnt, type;
string input, team, member;
map<string, string> group;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(n--) {
        cin >> team >> cnt;
        while(cnt--) {
            cin >> member;
            group.insert({member, team});
        }
    }
    while(m--) {
        cin >> input >> type;
        if(type == 0) {
            for(auto data: group)
                if(data.Y == input)
                    cout << data.X << '\n';
        } else {
            cout << group.at(input) << '\n';
        }
    }
    
    return 0;
}
