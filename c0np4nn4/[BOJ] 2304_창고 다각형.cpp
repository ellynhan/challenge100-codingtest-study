#include <iostream>
#include <stack>

using namespace std;

int sticks[1001] = {0, };
stack<int> st;

int main() {
	int N, L, H;
	cin >> N;
	
	int startPoint = 1000;
	int endPoint = 0;
	int tallestPoint = 0;
	int tallest = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> L >> H;
		sticks[L] = H;
		
		if (startPoint > L) { 
			startPoint = L;
		}
		if (endPoint < L) {
			endPoint = L;
		}
		if (sticks[L] == tallest) {
			// leftmost
			if (L < tallestPoint) {
				tallestPoint = L;
			}
		}
		if (sticks[L] > tallest) {
			tallestPoint = L;
			tallest = H;
		}
	}
	
	// after 75min, re-start
	
	int result = 0;
	
	// left
	for (int i = startPoint; i < tallestPoint; i++) {
		if (sticks[i]) {
			if (st.empty()) {
				st.push(sticks[i]);
			}
			
			else {
				if (st.top() < sticks[i]) {
					st.push(sticks[i]);
				}
			}
		}
		result += st.top();
	}

	
	// middle
	int anotherTP = 0;
	for (int i = tallestPoint; i <= endPoint; i++) {
		if (sticks[i] == tallest) {
			anotherTP = i;
		}
	}
	result = result + (anotherTP - tallestPoint + 1) * tallest;
	

	// init stack
	while (!st.empty()) st.pop();
	
	// right
	for (int i = endPoint; i >= anotherTP+1; i--) {
		if (sticks[i]) {
			if (st.empty()) {
				st.push(sticks[i]);
			}
			
			else {
				if (st.top() < sticks[i]) {
					st.push(sticks[i]);
				}
			}
		}
		result += st.top();
	}
	
	cout << result << endl;
	return 0;
}
