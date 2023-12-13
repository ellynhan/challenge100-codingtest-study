#include <iostream>
#include <vector>

using namespace std;

int cnt{};

int findPos(char c, vector<pair<char, pair<char, char>>>* v) {
	for (int i = 0; i < v->size(); i++) {
		if (v->at(i).first == c) return i;
	}
	return -1;
}

// 전위 순회
void preorder(vector<pair<char, pair<char, char>>>* v, int pos) {
	cnt--;
	if (cnt < 0) return;
	cout << v->at(pos).first; // 탐색 위치 출력

	char left = v->at(pos).second.first;
	char right = v->at(pos).second.second;
	if (left != '.') {
		preorder(v, findPos(left, v)); // 다음(왼) 노드 탐색
	}
	if (right != '.') {
		preorder(v, findPos(right, v)); // 다음(오) 노드 탐색
	}
}

void inorder(vector<pair<char, pair<char, char>>>* v, int pos) {
	cnt--;
	if (cnt < 0) return;

	char left = v->at(pos).second.first;
	char right = v->at(pos).second.second;
	if (left != '.') {
		inorder(v, findPos(left, v)); // 다음(왼) 노드 탐색
	}
	cout << v->at(pos).first; // 탐색 위치 출력
	if (right != '.') {
		inorder(v, findPos(right, v)); // 다음(오) 노드 탐색
	}
}

void postorder(vector<pair<char, pair<char, char>>>* v, int pos) {
	cnt--;
	if (cnt < 0) return;

	char left = v->at(pos).second.first;
	char right = v->at(pos).second.second;
	if (left != '.') {
		postorder(v, findPos(left, v)); // 다음(왼) 노드 탐색
	}
	if (right != '.') {
		postorder(v, findPos(right, v)); // 다음(오) 노드 탐색
	}
	cout << v->at(pos).first; // 탐색 위치 출력
}

int main() {
	int N{}, pos{};
	cin >> N;
	vector<pair<char, pair<char, char>>> v; // 부모 노드, 왼쪽 노드, 오른쪽 노드

	// 입력
	for (int i = 0; i < N; i++) {
		char node{}, left{}, right{};
		cin >> node >> left >> right;
		v.push_back({ node, {left, right}});
		if (node == 'A') pos = i;
	}

	cnt = N;
	preorder(&v, pos);

	cout << "\n";
	cnt = N;
	inorder(&v, pos);

	cout << "\n";
	cnt = N;
	postorder(&v, pos);

	return 0;
}
