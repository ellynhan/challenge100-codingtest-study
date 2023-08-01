#include <iostream>

using namespace std;

int fibo[21];
void dp();

int main() {
	// 1. INPUT DATA
	int n;
	cin >> n;
	
	// 2. GET FIBONACCI NUMBER
	dp();
	
	// 3. OUTPUT DATA
	cout << fibo[n];
}

void dp() {
	fibo[0] = 0;
	fibo[1] = 1;
	
	for (int i = 2; i <= 20; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
	
}
