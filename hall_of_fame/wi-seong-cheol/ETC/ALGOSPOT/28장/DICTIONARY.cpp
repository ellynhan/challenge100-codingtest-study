//
//  DICTIONARY.cpp
//  main
//
//  Created by wi_seong on 1/24/24.
//

/*
 [Input]
 3
 3
 ba
 aa
 ab
 5
 gg
 kia
 lotte
 lg
 hanhwa
 6
 dictionary
 english
 is
 ordered
 ordinary
 this
 [Output]
 INVALID HYPOTHESIS
 zyxwvutsrqponmjigklhfedcba
 zyxwvusrqpnmlkjhgfdeiotcba
 */
// 시간복잡도: O(n * L)
// 최악시간: 20,000
// 난이도: 하
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/DICTIONARY

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n;
vector<vector<int>> adj;
vector<int> seen, order;

void makeGraph(const vector<string>& words) {
    adj = vector<vector<int>>(26, vector<int>(26, 0));
    for(int j = 1; j < words.size(); j++) {
        int i = j - 1, len = int(min(words[i].size(), words[j].size()));
        for(int k = 0; k < len; k++) {
            if(words[i][k] != words[j][k]) {
                int a = words[i][k] - 'a';
                int b = words[j][k] - 'a';
                adj[a][b] = 1;
                break;
            }
        }
    }
}

void dfs(int here) {
    seen[here] = 1;
    for(int there = 0; there < adj.size(); there++) {
        if(adj[here][there] && !seen[there]) {
            dfs(there);
        }
    }
    order.push_back(here);
}

vector<int> topologicalSort() {
    int m = int(adj.size());
    seen = vector<int>(m, 0);
    order.clear();
    for(int i = 0; i < m; i++) {
        if(!seen[i]) {
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            if(adj[order[j]][order[i]]) {
                return vector<int>();
            }
        }
    }
    return order;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        vector<string> words(n);
        for(int i = 0; i < n; i++) {
            cin >> words[i];
        }
        makeGraph(words);
        vector<int> result = topologicalSort();
        if(result.empty()) {
            cout << "INVALID HYPOTHESIS" << '\n';
        } else {
            for(int i = 0; i < result.size(); i++) {
                cout << char(result[i] + 'a');
            }
            cout << '\n';
        }
    }

	return 0;
}
