//
//  1620.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 26 5
 Bulbasaur
 Ivysaur
 Venusaur
 Charmander
 Charmeleon
 Charizard
 Squirtle
 Wartortle
 Blastoise
 Caterpie
 Metapod
 Butterfree
 Weedle
 Kakuna
 Beedrill
 Pidgey
 Pidgeotto
 Pidgeot
 Rattata
 Raticate
 Spearow
 Fearow
 Ekans
 Arbok
 Pikachu
 Raichu
 25
 Raichu
 3
 Pidgey
 Kakuna
 [Output]
 Pikachu
 26
 Venusaur
 16
 14
 */
// 시간복잡도: O(n)
// 최악시간: 200,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1620

#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<string, int> s2i;
string i2s[100001];
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        i2s[i] = s;
        s2i.insert({s, i});
    }
    for(int i = 0; i < m; i++) {
        string s; cin >> s;
        if(isdigit(s[0]))
            cout << i2s[stoi(s)] << '\n';
        else
            cout << s2i[s] << '\n';
    }
    
    return 0;
}
