//
//  FORTRESS.cpp
//  main
//
//  Created by wi_seong on 1/22/24.
//

/*
 [Input]
 2
 3
 5 5 15
 5 5 10
 5 5 5
 8
 21 15 20
 15 15 10
 13 12 5
 12 12 3
 19 19 2
 30 24 5
 32 10 7
 32 9 4
 [Output]
 2
 5
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/FORTRESS

#include <iostream>
#include <algorithm>

using namespace std;
struct TreeNode {
    vector<TreeNode*> children;
};
int t, n, longest;
int x[100], y[100], r[100];

int sq(int x) {
    return x * x;
}

int sqrdist(int a, int b) {
    return sq(x[a] - x[b]) + sq(y[a] - y[b]);
}

bool encloses(int a, int b) {
    return r[a] > r[b] && sqrdist(a, b) < sq(r[a] - r[b]);
}

bool isChild(int parent, int child) {
    if(!encloses(parent, child)) return false;
    for(int i = 0; i < n; i++) {
        if(i != parent && i != child && encloses(parent, i) && encloses(i, child))
            return false;
    }
    return true;
}

TreeNode* getTree(int root) {
    TreeNode* ret = new TreeNode();
    for(int ch = 0; ch < n; ch++) {
        if(isChild(root, ch))
            ret->children.push_back(getTree(ch));
    }
    return ret;
}

int height(TreeNode* root) {
    vector<int> heights;
    for(int i = 0; i < root->children.size(); i++) {
        heights.push_back(height(root->children[i]));
    }
    if(heights.empty()) return 0;
    sort(heights.begin(), heights.end());
    if(heights.size() >= 2) {
        longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
    }
    return heights.back() + 1;
}

int solve(TreeNode* root) {
    longest = 0;
    int h = height(root);
    return max(longest, h);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> r[i];
        }
        TreeNode* root = getTree(0);
        cout << solve(root) << '\n';
    }

    return 0;
}
