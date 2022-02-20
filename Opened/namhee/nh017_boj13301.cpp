#include <iostream>

using namespace std;

long long tile[81];
void setValue(int N);

int main() {
	// 1. INPUT DATA
	int N;
	cin >> N;
	
	// 2. SET VALUE(tile value)
	setValue(N);
	
	// 3. OUTPUT DATA
	long long perimeter = 2*(tile[N]*2 + tile[N-1]);
	cout << perimeter;
}

void setValue(int N) {
	// base case
	tile[1] = 1;
	tile[2] = 1;
	
	for (int i = 3; i <= N; i++)
		tile[i] = tile[i-1] + tile[i-2];
}
