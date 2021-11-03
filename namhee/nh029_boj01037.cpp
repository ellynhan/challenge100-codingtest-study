#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	// INPUT DATA
	int num;
	cin >> num;
	
	int divisor[num];
	for (int i = 0; i < num; i++)
		cin >> divisor[i];
	
	// SORT
	sort(divisor, divisor+num);
	
	// OUTPUT DATA
	int N = divisor[0]*divisor[num-1];
	cout << N;
}
