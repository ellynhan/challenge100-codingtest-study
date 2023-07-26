#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	// 1. INPUT N - the number of commend
	int N;
	cin >> N;
	
	// 2. INPUT & PROCESS COMMEND - push, pop, size, empty, front, back
	string commend;
	queue<int> q;
	for (int i = 0; i < N; i++) {
		cin >> commend;
		
		if (commend == "push") {
			int element;
			cin >> element;
			q.push(element);
		}		
		else if (commend == "pop") {
			if (q.empty())
				cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();				
			}
		}
		
		else if (commend == "size")
			cout << q.size() << endl;
			
		else if (commend == "empty")
			cout << q.empty() << endl;
			
		else if (commend == "front") {
			if (q.empty())
				cout << -1 << endl;
			else
				cout << q.front() << endl;			
		}	
		else if (commend == "back") {
			if (q.empty())
				cout << -1 << endl;
			else
				cout << q.back() << endl;
		}
	}
}
