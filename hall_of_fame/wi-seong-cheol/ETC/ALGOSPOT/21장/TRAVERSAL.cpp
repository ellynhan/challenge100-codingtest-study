//
//  TRAVERSAL.cpp
//  main
//
//  Created by wi_seong on 1/22/24.
//

/*
 [Input]
 2
 7
 27 16 9 12 54 36 72
 9 12 16 27 36 54 72
 6
 409 479 10 838 150 441
 409 10 479 150 838 441
 [Output]
 12 9 16 36 72 54 27
 10 150 441 838 479 409
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: 하
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/TRAVERSAL

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n;
vector<int> preorder, inorder;

vector<int> slice(const vector<int>& v, int a, int b) {
    return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
    const int N = int(preorder.size());

    if(preorder.empty()) return;
    const int root = preorder[0];
    const int L = int(find(inorder.begin(), inorder.end(), root) - inorder.begin());
    const int R = N - 1 - L;

    printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
    printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));

    cout << root << " ";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        preorder.resize(n);
        inorder.resize(n);
        for(int i = 0; i < n; i++) cin >> preorder[i];
        for(int i = 0; i < n; i++) cin >> inorder[i];
        printPostOrder(preorder, inorder);
    }

	return 0;
}
