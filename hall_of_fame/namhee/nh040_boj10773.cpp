#include <iostream>
#include <stack>

using namespace std;

int main() {
	int K;
	cin >> K;
	
	int num;
	stack<int> s;
	for (int i = 0; i < K; i++) {
		cin >> num;
		
		if (num != 0)
			s.push(num);
		else if (!s.empty())
			s.pop();
	}
	
	int sum = 0, size = s.size();
	for (int i = 0; i < size; i++) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
}
