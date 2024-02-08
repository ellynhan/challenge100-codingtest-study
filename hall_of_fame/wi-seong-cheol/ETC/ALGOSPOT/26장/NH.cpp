//
//  NH.cpp
//  main
//
//  Created by wi_seong on 1/23/24.
//

/*
 [Input]
 3
 2 2
 rm
 dd
 4 4
 a
 b
 c
 d
 100 4
 aa
 ba
 ab
 cd
 [Output]
 674
 4095
 5293
 */
// 시간복잡도: O(N * A * L ^ 2)
// 최악시간: 1,000,000
// 난이도: 상
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/NH

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
const int ALPHABETS = 26;
const int MOD = 10007;

int toNumber(char ch) { return ch - 'a'; }

struct TrieNode {
    TrieNode* children[26];
    TrieNode* next[26];

    int terminal;

    int no;

    TrieNode* fail;

    vector<int> output;

    TrieNode() : terminal(-1) {
        memset(children, 0, sizeof(children));
    }

    ~TrieNode() {
        for(int i = 0; i < 26; i++) {
            if(children[i]) delete children[i];
        }
    }

    void insert(const char* key, int id) {
        if(*key == 0) {
            terminal = id;
        } else {
            int next = toNumber(*key);
            if(children[next] == NULL) {
                children[next] = new TrieNode();
            }
            children[next]->insert(key + 1, id);
        }
    }

    TrieNode* find(const char* key) {
        if(*key == 0) return this;
        int next = toNumber(*key);
        if(children[next] == NULL) return NULL;
        return children[next]->find(key + 1);
    }
};

int cache[101][1001];
int t, n, m;

int count(int length, TrieNode* state) {
    if(state->output.size()) return 0;
    if(length == 0) return 1;

    int& ret = cache[length][state->no];
    if(ret != -1) return ret;
    ret = 0;
    for(int letter = 0; letter < ALPHABETS; letter++) {
        ret += count(length - 1, state->next[letter]);
        ret %= MOD;
    }
    return ret;
}

void computeTransition(TrieNode* here, int& nodeCounter) {
    here->no = nodeCounter++;

    for(int chr = 0; chr < ALPHABETS; chr++) {
        TrieNode* next = here;
        while(next != next->fail && next->children[chr] == NULL) {
            next = next->fail;
        }
        if(next->children[chr]) {
            next = next->children[chr];
        }
        here->next[chr] = next;
        if(here->children[chr])
            computeTransition(here->children[chr], nodeCounter);
    }
}

void computeFailFunc(TrieNode* root) {
    queue<TrieNode*> q;
    root->fail = root;
    q.push(root);

    while(!q.empty()) {
        TrieNode* here = q.front();
        q.pop();

        for(int edge = 0; edge < ALPHABETS; edge++) {
            TrieNode* child = here->children[edge];
            if(!child) continue;

            if(here == root) {
                child->fail = root;
            } else {
                TrieNode* t = here->fail;
                while(t != root && t->children[edge] == NULL) {
                    t = t->fail;
                }
                if(t->children[edge]) t = t->children[edge];
                child->fail = t;
            }
            child->output = child->fail->output;
            if(child->terminal != -1) {
                child->output.push_back(child->terminal);
            }
            q.push(child);
        }
    }
}

int solve(int length, const vector<string>& patterns) {
    TrieNode trie;
    for(int i = 0; i < patterns.size(); i++)
        trie.insert(patterns[i].c_str(), i);

    computeFailFunc(&trie);

    int t = 0;
    computeTransition(&trie, t);

    memset(cache, -1, sizeof(cache));
    return count(length, &trie);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<string> patterns(m);
        for(int i = 0; i < m; i++)
            cin >> patterns[i];
        cout << solve(n, patterns) << endl;
    }

	return 0;
}
