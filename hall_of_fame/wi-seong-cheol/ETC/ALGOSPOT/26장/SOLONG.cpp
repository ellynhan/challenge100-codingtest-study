//
//  SOLONG.cpp
//  main
//
//  Created by wi_seong on 1/23/24.
//

/*
 [Input]
 2
 7 8
 ALL 4
 AND 3
 FISH 8
 FOR 6
 SO 4
 THANKS 9
 THE 9
 SO LONG AND THANKS FOR ALL THE FISH
 7 8
 ALL 4
 AND 5
 FISH 3
 FOR 6
 SO 8
 THANKS 1
 THE 2
 SO LONG AND THANKS FOR ALL THE FISH
 [Output]
 28
 29
 */
// 시간복잡도: O(K * N * logN + L)
// 최악시간: 600,000
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/SOLONG

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
int toNumber(char ch) { return ch - 'A'; }

struct TrieNode {
    TrieNode* children[26];
    
    int terminal, first;

    TrieNode() : terminal(-1), first(-1) {
        memset(children, 0, sizeof(children));
    }

    ~TrieNode() {
        for(int i = 0; i < 26; i++) {
            if(children[i]) delete children[i];
        }
    }

    void insert(const char* key, int id) {
        if(first == -1) first = id;
        if(*key == 0)
            terminal = id;
        else {
            int next = toNumber(*key);
            if(children[next] == NULL)
                children[next] = new TrieNode();
            children[next]->insert(key + 1, id);
        }
    }

    TrieNode* find(const char* key) {
        if(*key == 0) return this;
        int next = toNumber(*key);
        if(children[next] == NULL) return NULL;
        return children[next]->find(key + 1);
    }

    int type(const char* key, int id) {
        if(*key == 0) return 0;
        if(first == id) return 1;
        int next = toNumber(*key);
        return 1 + children[next]->type(key + 1, id);
    }
};
int t, n, m;

int countKeys(TrieNode* trie, const char* word) {
    TrieNode* node = trie->find(word);
    if(node == NULL || node->terminal == -1) return int(strlen(word));
    return trie->type(word, node->terminal);
}

TrieNode* readInput(int words) {
    vector<pair<int, string>> input;
    for(int i = 0; i < words; i++) {
        string s;
        int freq;
        cin >> s >> freq;
        input.push_back({-freq, s});
    }
    sort(input.begin(), input.end());
    TrieNode* trie = new TrieNode();
    for(int i = 0; i < words; i++) {
        trie->insert(input[i].second.c_str(), i);
    }
    trie->first = -1;
    return trie;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        TrieNode* trie = readInput(n);
        int ans = m - 1;
        for(int i = 0; i < m; i++) {
            string s; cin >> s;
            ans += countKeys(trie, s.c_str());
        }
        cout << ans << '\n';
    }

	return 0;
}
