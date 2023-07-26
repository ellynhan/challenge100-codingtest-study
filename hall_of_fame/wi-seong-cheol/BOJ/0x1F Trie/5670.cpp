//
//  5670.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4
 hello
 hell
 heaven
 goodbye
 [Output]
 2.00
 */
// 시간복잡도: O(V)
// 최악시간: 1,000,000
// 난이도: Platinum 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/5670

#include <iostream>
#include <vector>

using namespace std;
const int MX = 1000001;
const int ROOT = 1;
int n, keystroke_total;
int unused;
int chk[MX];
string s;
vector<string> words;
vector<pair<int, int>> nxt[MX]; // 자식을 동적 배열로 관리

// node의 자손 중, c에 해당하는 자손이 있는지 체크합니다.
int getchild(int node, char c) {
    for(auto [id, c_] : nxt[node])
        if(c == c_) return id;
    return -1;
}

void insert(string& s) {
    int cur = ROOT;
    for(char c: s) {
        int child = getchild(cur, c);
        if(child == -1) {
            child = unused;
            nxt[cur].push_back({unused++, c});
        }
        cur = child;
    }
    chk[cur] = true;
}

void dfs(int cur, int key_strokes) {
    if(chk[cur])
        keystroke_total += ++key_strokes;
    else if(nxt[cur].size() > 1)
        key_strokes++;
    for(auto [nxt_node, _] : nxt[cur])
        dfs(nxt_node, key_strokes);
}

void init() {
    keystroke_total = 0;
    unused = ROOT + 1;
    words.clear();
    words.resize(n);
    fill(chk, chk + MX, false);
    for(int i = 0; i < MX; i++)
        nxt[i].clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(2);
    
    while(cin >> n) {
        init();
        for(int i = 0; i < n; i++) {
            cin >> words[i];
            insert(words[i]);
        }
        for(auto [id, _] : nxt[ROOT]) dfs(id, 0);
        cout << 1.0 * keystroke_total / words.size() << '\n';
    }
    
    return 0;
}
