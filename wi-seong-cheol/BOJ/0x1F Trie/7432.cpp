//
//  7432.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7
 WINNT\SYSTEM32\CONFIG
 GAMES
 WINNT\DRIVERS
 HOME
 WIN\SOFT
 GAMES\DRIVERS
 WINNT\SYSTEM32\CERTSRV\CERTCO~1\X86
 [Output]
 GAMES
  DRIVERS
 HOME
 WIN
  SOFT
 WINNT
  DRIVERS
  SYSTEM32
   CERTSRV
    CERTCO~1
     X86
   CONFIG
 */
// 시간복잡도: O((M * L) ^ 2)
// 최악시간: 400,000,000
// 난이도: Gold 2
// Timer: 1시간
// Url: https://www.acmicpc.net/problem/7432

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
#define X first
#define Y second
const int MX = 500 * 40 + 1;
const int ROOT = 1;
int n;
int unused = ROOT + 1;
string s;
unordered_map<string, int> nxt[MX];  // nxt[v][r] -> v번 노드의 자식 중 이름이 r인 노드의 번호
int depth[MX];                       // 노드의 깊이를 나타내며 ROOT의 깊이는 -1로 정의
string name[MX];                     // 노드의 이름

void insert(vector<string>& route) {
    int v = ROOT;
    for(auto r: route) {
        int nv = nxt[v][r];
        if(nv == 0)
            nv = nxt[v][r] = unused++;
        depth[nv] = depth[v] + 1;
        name[nv] = r;
        v = nv;
    }
}

void dfs(int v) {
    if(v != ROOT) {
        for(int i = 0; i < depth[v]; i++) cout << ' ';
        cout << name[v] << '\n';
    }
    vector<pair<string, int>> m(nxt[v].begin(), nxt[v].end());
    sort(m.begin(), m.end());
    for(auto mm: m) dfs(mm.Y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    depth[ROOT] = -1;
    while(n--) {
        cin >> s;
        char separator = '\\';
        istringstream iss(s);
        string str_buf;
        vector<string> route;
        while(getline(iss, str_buf, separator)) {
            route.push_back(str_buf);
        }
        insert(route);
    }
    dfs(ROOT);
    
    return 0;
}
