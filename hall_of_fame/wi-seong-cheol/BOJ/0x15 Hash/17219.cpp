//
//  17219.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 16 4
 noj.am IU
 acmicpc.net UAENA
 startlink.io THEKINGOD
 google.com ZEZE
 nate.com VOICEMAIL
 naver.com REDQUEEN
 daum.net MODERNTIMES
 utube.com BLACKOUT
 zum.com LASTFANTASY
 dreamwiz.com RAINDROP
 hanyang.ac.kr SOMEDAY
 dhlottery.co.kr BOO
 duksoo.hs.kr HAVANA
 hanyang-u.ms.kr OBLIVIATE
 yd.es.kr LOVEATTACK
 mcc.hanyang.ac.kr ADREAMER
 startlink.io
 acmicpc.net
 noj.am
 mcc.hanyang.ac.kr
 [Output]
 THEKINGOD
 UAENA
 IU
 ADREAMER
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 4
// Timer: 5m
// Url: https://www.acmicpc.net/problem/17219

#include <iostream>
#include <unordered_map>

using namespace std;
int n, m;
string site, password;
unordered_map<string, string> note;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(n--) {
        cin >> site >> password;
        note.insert({site, password});
    }
    while(m--) {
        cin >> site;
        cout << note.at(site) << '\n';
    }
    
    return 0;
}
