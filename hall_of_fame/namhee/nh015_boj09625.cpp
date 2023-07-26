#include <iostream>

using namespace std;

int numA[46];
int numB[46];
void setValue(int K);

int main() {	
	// 1. INPUT DATA
	int K;
	cin >> K;
	
	// 2. SET VALUE(num of A,B)
	setValue(K);
	
	// 3. OUTPUT DATA
	cout << numA[K] << ' ' << numB[K];
}

void setValue(int K) {
	// base case
	numA[0] = 1; numA[1] = 0;
	numB[0] = 0; numB[1] = 1;
	
	for (int i = 2; i <= K; i++) {
		numA[i] = numA[i-1] + numA[i-2];
		numB[i] = numB[i-1] + numB[i-2];
	}
}
