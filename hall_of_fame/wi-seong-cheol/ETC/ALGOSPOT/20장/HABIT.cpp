//
//  HABIT.cpp
//  main
//
//  Created by wi_seong on 1/22/24.
//

/*
 [Input]
 4
 2
 uhmhellouhmmynameislibe
 3
 banana
 1
 thatsagoodquestion
 3
 hello
 [Output]
 3
 1
 18
 0
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: 중
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/HABIT

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, k;
string s;

struct Comparator {
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& _group, int _t): group(_group), t(_t) {}
    bool operator () (int a, int b) {
        if(group[a] != group[b]) return group[a] < group[b];
        return group[a + t] < group[b + t];
    }
};

vector<int> getSuffixArray(string& s) {
    int n = int(s.size());
    int t = 1;
    vector<int> group(n + 1);
    for(int i = 0; i < n; i++) group[i] = s[i];
    group[n] = -1;
    vector<int> perm(n);
    for(int i = 0; i < n; i++) perm[i] = i;
    while(t < n) {
        Comparator cmp(group, t);
        sort(perm.begin(), perm.end(), cmp);
        t *= 2;
        if(t >= n) break;
        vector<int> newGroup(n + 1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        for(int i = 1; i < n; i++) {
            if(cmp(perm[i - 1], perm[i])) newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
            else newGroup[perm[i]] = newGroup[perm[i - 1]];
        }
        group = newGroup;
    }
    return perm;
}

int commonPrefix(string& s, int i, int j) {
    int k = 0;
    while(i < s.size() && j < s.size() && s[i] == s[j]) {
        i++;
        j++;
        k++;
    }
    return k;
}

int longestFrequent(int k, string& s) {
    vector<int> a = getSuffixArray(s);
    int ret = 0;
    for(int i = 0; i + k <= s.size(); i++) {
        ret = max(ret, commonPrefix(s, a[i], a[i + k - 1]));
    }
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> k >> s;
        cout << longestFrequent(k, s) << '\n';
    }

	return 0;
}
