#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> s;
string commend;

int main() {
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> commend;
		
		if (commend == "push") {
			int num;
			cin >> num;
			s.push(num);
		}			
		else if (commend == "pop") {
			if (s.empty()) 
				cout << -1 << endl;
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (commend == "size")
			cout << s.size() << endl;
			
		else if (commend == "empty")
			cout << s.empty() << endl;
			
		else if (commend == "top") {
			if (s.empty()) 
				cout << -1 << endl;
			else 
				cout << s.top() << endl;
		}	
	}
}

