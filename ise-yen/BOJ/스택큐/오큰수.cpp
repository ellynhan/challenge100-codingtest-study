#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	// 수 입력
	int N{};
	cin >> N;
	// 뒤에서부터 집어넣기
	stack<int> s;
	for (int i = 0; i < N; i++) {
		int n{};
		cin >> n;
		s.push(n);
	}

	stack<int> ans; // 정답용
	ans.push(-1); // 마지막은 무조건 -1

	stack<int> tmp; // 크기 비교용
	tmp.push(s.top());
	s.pop();
	while (!s.empty()) {
		bool isFind = false;
		// 오큰수 찾기
		while (!tmp.empty()) {
			if (s.top() < tmp.top()) {
				ans.push(tmp.top());
				isFind = true;
				break;
			}
			else tmp.pop();
		} 
		// 못 찾으면 == tmp가 empty한 상태
		if (!isFind) ans.push(-1);
		tmp.push(s.top());
		s.pop();
	}

	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
	return 0;
}
