#include <iostream>

using namespace std;

int N;
int parent[50];
int eraseNode;
bool isItLeaf[50] = {true, };

void showParentArr() {	
	for (int i = 0; i < N; i++) {
		cout << parent[i] << " ";
	}
	cout << endl;	
}

void showIsItLeaf() {
	for (int i = 0; i < N; i++) {
		cout << isItLeaf[i] << " ";
	}
	cout << endl;
}
	
void eraseAllChildNodes(const int eraseNode) {
	parent[eraseNode] = -1;
	isItLeaf[eraseNode] = false;
	for (int i = 0; i < N; i++) {
		if (parent[i] == eraseNode) {
			eraseAllChildNodes(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		isItLeaf[i] = true;
		cin >> parent[i];
	}
	cin >> eraseNode;
	
	// erase all child nodes by DFS
	eraseAllChildNodes(eraseNode);
	// showParentArr();
	
	
	// find all leaf node
	for (int i = 0; i < N; i++) {
		// showIsItLeaf();
		for (int j = 0; j < N; j++) {
			if (parent[j] == i) {
				isItLeaf[i] = false;
			}
		}
	}
	
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (isItLeaf[i] == true) {
			count++;
		}
	}
	cout << count << endl;
	
	return 0;
}
