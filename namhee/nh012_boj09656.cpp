#include <iostream>

using namespace std;

char winner[1001];
void getWinner();

int main() {
	// 1. GET ARRAY
	getWinner();
	
	// 2. INPUT & OUTPUT DATA
	int N;
	cin >> N;
	
	if (winner[N] == 'S')
		cout << "SK";
	else
		cout << "CY";
}

void getWinner() {
	for (int i = 1; i <= 1000; i++)
		if (i%2 == 0)
			winner[i] = 'S';
		else
			winner[i] = 'C';
}
