#include <iostream>

using namespace std;

long long t[36];
void setValue(int n);

int main() {
	// 1. INPUT DATA
	int n;
	cin >> n;
	
	// 2. SET VALUE(sequence t)
	setValue(n);
	
	// 3. OUTPUT DATA
	cout << t[n];
}

void setValue(int n) {
	t[0] = 1;
	
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			t[i] += t[j]*t[i-j-1];
}

