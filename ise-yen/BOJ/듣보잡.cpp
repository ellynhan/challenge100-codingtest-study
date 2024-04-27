#include<iostream>
#include<string>
#include<unordered_set>
#include<queue>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N{}, M{}; // 듣X, 보X
	cin >> N >> M;
	
	unordered_set<string> s;
	priority_queue<string, vector<string>, greater<string>> pq; // 듣보

	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		s.insert({ name });
	}

	for (int i = 0; i < M; i++) {
		string name;
		cin >> name;
		unordered_set<string>::iterator iter = s.find(name);
		if (iter != s.end()) pq.push(name);
	}

	cout << pq.size() << "\n";
	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}

	return 0;
}
