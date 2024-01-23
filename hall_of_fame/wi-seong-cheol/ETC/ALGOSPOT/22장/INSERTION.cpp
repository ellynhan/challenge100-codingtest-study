//
//  INSERTION.cpp
//  main
//
//  Created by wi_seong on 1/23/24.
//

/*
 [Input]
 2
 5
 0 1 1 2 3
 4
 0 1 2 3
 [Output]
 5 1 4 3 2
 4 3 2 1
 */
// 시간복잡도: O(nlogn)
// 최악시간: 200,000
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/INSERTION

#include <iostream>
#include <cstring>

using namespace std;
struct Node {
    int key;
    int priority, size;
    Node *left, *right;
    Node(const int& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
    void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
    void setRight(Node* newRight) { right = newRight; calcSize(); }
    void calcSize() {
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }
};
typedef pair<Node*, Node*> NodePair;
int t, n;
int shift[50000], ans[50000];

NodePair split(Node* root, int key) {
    if (!root) return NodePair(NULL, NULL);
    if (root->key < key) {
        NodePair rs = split(root->right, key);
        root->setRight(rs.first);
        return NodePair(root, rs.second);
    }
    NodePair ls = split(root->left, key);
    root->setLeft(ls.second);
    return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* node) {
    if (!root) return node;
    if (root->priority < node->priority) {
        NodePair splitted = split(root, node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    } else if (node->key < root->key) {
        root->setLeft(insert(root->left, node));
    } else {
        root->setRight(insert(root->right, node));
    }
    return root;
}

Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->priority < b->priority) {
        b->setLeft(merge(a, b->left));
        return b;
    }
    a->setRight(merge(a->right, b));
    return a;
}

Node* erase(Node* root, int key) {
    if (!root) return root;
    if (root->key == key) {
        Node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    if (key < root->key) {
        root->setLeft(erase(root->left, key));
    } else {
        root->setRight(erase(root->right, key));
    }
    return root;
}

Node* kth(Node* root, int k) {
    int leftSize = 0;
    if (root->left) leftSize = root->left->size;
    if (k <= leftSize) return kth(root->left, k);
    if (k == leftSize + 1) return root;
    return kth(root->right, k - leftSize - 1);
}

void solve() {
    Node* candidates = NULL;
    for (int i = 1; i <= n; i++) {
        candidates = insert(candidates, new Node(i));
    }
    for (int i = n - 1; i >= 0; i--) {
        int larger = shift[i];
        Node* k = kth(candidates, i + 1 - larger);
        ans[i] = k->key;
        candidates = erase(candidates, k->key);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < n; i++) {
            cin >> shift[i];
        }
        solve();
    }

	return 0;
}
