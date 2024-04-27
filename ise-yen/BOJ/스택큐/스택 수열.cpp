// 스택 수열
#include <iostream>
#include <stack>
#include <deque>
#include <string>

using namespace std;

int main() {
	int N{};
	cin >> N;

	deque<int> dq;
	for (int i = 0; i < N; i++) {
		int num{};
		cin >> num;
		dq.push_back(num);
	}

	stack<int> s;
	string answer;
	int n = 1;
	while (!dq.empty()) {
		if (n > N + 1) break;
		if (s.empty() || dq.front() != s.top()) {
			s.push(n);
			answer += "+";
			n++;
		}
		else { // dq.front() == s.top()
			s.pop();
			answer += "-";
			dq.pop_front();
		}
	}

	if (dq.empty()) {
		for (int i = 0; i < answer.length(); i++) cout << answer[i] << "\n";
	}
	else cout << "NO";
}
