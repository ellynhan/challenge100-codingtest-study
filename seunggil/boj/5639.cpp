#include <iostream>
#include <stack>
#include <list>

using namespace std;

class binaryTree {
public :
	int key;
	binaryTree* left = nullptr;
	binaryTree* right = nullptr;

	binaryTree(int newKey) : key(newKey){}

	void add(int newKey) {
		binaryTree* nowTree = this;
		while(true){
			if (nowTree->key > newKey) {
				if (nowTree->left != nullptr)
					nowTree = nowTree->left;
				else {
					nowTree->left = new binaryTree(newKey);
					break;
				}
			}
			else { // key > newKey
				if (nowTree->right != nullptr)
					nowTree = nowTree->right;
				else {
					nowTree->right = new binaryTree(newKey);
					break;
				}
			}
		}
	}

	~binaryTree() {
		if (left != nullptr)
			delete left;
		if (right != nullptr)
			delete right;
	}
};


int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a;
	cin >> a;
	binaryTree* inputData = new binaryTree(a);

	while (cin >> a)
		inputData->add(a);

	stack<binaryTree*> dfs;
	dfs.push(inputData);

	list<int> answer;
	while (!dfs.empty()) {
		binaryTree* now = dfs.top();
		dfs.pop();
		answer.push_back(now->key);

		if (now->left)
			dfs.push(now->left);
		if (now->right)
			dfs.push(now->right);
	}

	for (list<int>::const_reverse_iterator iter = answer.rbegin(); iter != answer.rend(); iter++)
		cout << *iter << '\n';
	
	delete inputData;

	return 0;
}