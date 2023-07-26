#include <iostream>

using namespace std;

char win[1001];
void setWin();

int main() {
	// 1. GET ARRAY
	setWin();
	
	// 2. INPUT & OUTPUT DATA
	int N;
	cin >> N;
	
	if (win[N] == 'S')
		cout << "SK";
	else
		cout << "CY";
}

void setWin() {
	// set value (base case)
	win[1] = 'S';
	win[2] = 'C';
	win[3] = 'S';
	win[4] = 'S';
	
	for (int i = 5; i <= 1000; i++)
		// first person to carry a stone : 'SK', so follows.
		if (win[i-1] == 'S' && win[i-3] == 'S' && win[i-4] == 'S')
			win[i] = 'C';
		else
			win[i] = 'S';
}
