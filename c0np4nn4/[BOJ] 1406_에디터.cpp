#include <iostream>
#include <stack>

using namespace std;

char initLine[600001] = {'\x00', };
stack<char> bStack;	// base stack
stack<char> lStack;	// stack for operation char 'L' 

int main() {
	cin >> initLine;
	for (int i = 0; initLine[i] != '\x00'; i++) {
		bStack.push(initLine[i]);
	}
	
	int opCount;
	cin >> opCount;
	
	char opChar;
	while (opCount > 0) {
		cin >> opChar;
		// L
		if (opChar == 'L') {
			if (!bStack.empty()) {
				lStack.push(bStack.top());
				bStack.pop();
			}
		}
		
		// D
		if (opChar == 'D') {
			if (!lStack.empty()) {
				bStack.push(lStack.top());
				lStack.pop();
			}
		}
		
		// B
		if (opChar == 'B') {
			if (!bStack.empty())
				bStack.pop();
		}
		
		// P
		if (opChar == 'P') {
			char data;
			cin >> data;
			bStack.push(data);
		}
		
		opCount--;
	}
	
	// reassemble the stacks
	// lStack + bStack(upside-down)
	while (!bStack.empty()) {
		lStack.push(bStack.top());
		bStack.pop();
	}
	
	// print out lStack
	while (!lStack.empty()) {
		cout << lStack.top();
		lStack.pop();
	}
	
	
	
	return 0;
}
