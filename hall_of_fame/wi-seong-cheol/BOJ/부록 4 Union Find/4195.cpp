//
//  4195.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/27.
//

/*
 [Input]
 2
 3
 Fred Barney
 Barney Betty
 Betty Wilma
 3
 Fred Barney
 Betty Wilma
 Barney Betty
 [Output]
 2
 3
 4
 2
 2
 4
 */
// 시간복잡도: O(α(n) * n)
// 최악시간: 400,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/4195

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
const int SIZE = 200'001;
int t, n;
string s1, s2;
int parent[SIZE];
int netSize[SIZE];

int Find(int node) {
    if(node == parent[node]) return node;
    return parent[node] = Find(parent[node]);
}

void Union(int node1, int node2) {
    node1 = Find(node1);
    node2 = Find(node2);
    if(node1 != node2) {
        if(netSize[node1] < netSize[node2]) swap(node1, node2);

        parent[node2] = node1;
        netSize[node1] += netSize[node2];
        netSize[node2] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        int index = 0;
        map<string, int> m;
        
        cin >> n;
        
        for(int i = 0; i < SIZE; i++) {
            parent[i] = i;
            netSize[i] = 1;
        }
        
        for(int i = 0; i < n ;i++) {
            cin >> s1 >> s2;
            if(m.find(s1) == m.end()) m[s1] = index++;
            if(m.find(s2) == m.end()) m[s2] = index++;
            
            int p1 = Find(m[s1]);
            int p2 = Find(m[s2]);
            
            if(p1 == p2) {
                cout << max(netSize[p1], netSize[p2]) << "\n";
            } else {
                Union(p1, p2);
                cout << max(netSize[p1], netSize[p2]) << "\n";
            }
        }
    }
    
    return 0;
}
