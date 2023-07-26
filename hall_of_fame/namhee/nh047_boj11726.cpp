#include <iostream>

using namespace std;

int num[1001];
void tiling();

int main() {
	int n;
	cin >> n;
	
	tiling();
	
	cout << num[n];
}

void tiling() {
	num[1] = 1; 
	num[2] = 2;
	
	for (int i = 3; i <= 1000; i++)
		num[i] = (num[i-1] + num[i-2])%10007;
}
