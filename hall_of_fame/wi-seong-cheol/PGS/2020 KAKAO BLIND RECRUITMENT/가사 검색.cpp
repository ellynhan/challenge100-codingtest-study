//
//  가사 검색.cpp
//  main
//
//  Created by wi_seong on 2/2/24.
//

// 시간복잡도: O(N * logN + L)
// 최악시간: 510,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/60060

#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int toNumber(char ch) { return ch - 'a'; }
struct TrieNode {
    TrieNode* children[26];

    int count;

    TrieNode(): count(0) {
        memset(children, 0, sizeof(children));
    }

    ~TrieNode() {
        for(int i = 0; i < 26; i++)
            if(children[i]) delete children[i];
    }

    void insert(const string str) {
        TrieNode* now = this;
        for(char ch: str) {
            now->count++;
            int next = toNumber(ch);
            if (now->children[next] == NULL)
                now->children[next] = new TrieNode();
            now = now->children[next];
        }
    }

    int find(const string str) {
        TrieNode* now = this;
        for(char ch: str) {
            int next = toNumber(ch);
            if(ch == '?')
                return now->count;
            now = now->children[next];
            if(now == NULL)
                return 0;
        }
        return -1;
    }
};
TrieNode TrieRoot[10001];
TrieNode ReTrieRoot[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    int n = int(words.size());
    int m = int(queries.size());

    for(int i = 0; i < n; i++) {
        int len = int(words[i].length());
        TrieRoot[len].insert(words[i]);
        reverse(words[i].begin(), words[i].end());
        ReTrieRoot[len].insert(words[i]);
    }

    for(string querie: queries) {
        int len = int(querie.size());
        if(querie[0] == '?') {
            reverse(querie.begin(), querie.end());
            answer.push_back(ReTrieRoot[len].find(querie));
        } else {
            answer.push_back(TrieRoot[len].find(querie));
        }
    }

    return answer;
}
