//
//  길 찾기 게임.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/03.
//

// 시간복잡도: O(nlogn)
// 최악시간: 3,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42892

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
struct TREE {
    int X;
    int Y;
    int Idx;
    TREE *Left;
    TREE *Right;
};
int parent[1001], l[1001], r[1001];

bool cmp(const TREE& A, const TREE& B) {
    if(A.Y >= B.Y) {
        if(A.Y == B.Y) {
            if(A.X < B.X) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void makeTree(TREE* root, TREE* child) {
    if(root -> X > child -> X) {
        if(root -> Left == NULL) {
            root -> Left = child;
            return;
        }
        makeTree(root -> Left, child);
    }
    else {
        if(root -> Right == NULL) {
            root -> Right = child;
            return;
        }
        makeTree(root -> Right, child);
    }
}
 
void preOrder(TREE* root, vector<int>& answer) {
    if(root == NULL) return;
    answer.push_back(root -> Idx);
    preOrder(root -> Left, answer);
    preOrder(root -> Right, answer);
}
 
void postOrder(TREE* root, vector<int>& answer) {
    if(root == NULL) return;
    postOrder(root -> Left, answer);
    postOrder(root -> Right, answer);
    answer.push_back(root -> Idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int n = nodeinfo.size();
    vector<TREE> tree;
    
    for(int i = 0; i < n; i++)
        tree.push_back({nodeinfo[i][0], nodeinfo[i][1], i + 1, NULL, NULL});
    sort(tree.begin(), tree.end(), cmp);
    TREE* root = &tree.front();
    
    for(int i = 1; i < n; i++)
        makeTree(root, &tree[i]);
    vector<int> pre_V;
    preOrder(root, pre_V);
    
    vector<int> post_V;
    postOrder(root, post_V);
    
    answer.push_back(pre_V);
    answer.push_back(post_V);
    
    return answer;
}
