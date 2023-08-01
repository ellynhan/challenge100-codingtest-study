#include <iostream>

using namespace std;

int main() {
	// 1. INPUT DATA
	long long S;
	cin >> S;
	
	// 2. GET N
	int N = 0;
	long long sum = 0;
	for (int i = 1; i<=100000; i++) {
		N++;
		sum += i;
		if (sum <= S && S < sum+i+1)
			break;
	}
	
	// 3. OUTPUT DATA
	cout << N;
}

