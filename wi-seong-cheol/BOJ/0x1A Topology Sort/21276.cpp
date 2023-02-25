//
//  21276.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7
 daeil sangdo yuri hoseok minji doha haeun
 7
 hoseok sangdo
 yuri minji
 hoseok daeil
 daeil sangdo
 haeun doha
 doha minji
 haeun minji
 [Output]
 2
 minji sangdo
 daeil 1 hoseok
 doha 1 haeun
 haeun 0
 hoseok 0
 minji 2 doha yuri
 sangdo 1 daeil
 yuri 0
 */
// 시간복잡도: O(n + m)
// 최악시간: 501,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/21276

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
int n, m;
string s1, s2;

vector<string> root;
string name[1001];
unordered_map<string, int> id;

int deg[1001];
vector<int> adj[1001];
vector<int> ch[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> name[i];
    sort(name + 1, name + n + 1);
    for(int i = 1; i <= n; i++)
        id[name[i]] = i;
    
    cin >> m;
    while(m--) {
        cin >> s1 >> s2;
        adj[id[s2]].push_back(id[s1]);
        deg[id[s1]]++;
    }
    
    for(int i = 1; i <= n; i++)
        if(!deg[i]) root.push_back(name[i]);
    
    cout << root.size() << '\n';
    for(string r: root)
        cout << r << ' ';
    cout << '\n';
    
    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        for(int c: adj[i])
            if(deg[c] - deg[i] == 1) ch[i].push_back(c);
    }
    
    for(int i = 1; i <= n; i++) {
        int sz = (int)ch[i].size();
        cout << name[i] << ' ' << sz << ' ';
        for(int c : ch[i])
            cout << name[c] << ' ';
        cout << '\n';
    }
    
    return 0;
}
