#include <iostream>
#include <algorithm>

using namespace std;

int sugarBag[5001];
void getSugarBagNum();

int main() {
	// 1. GET ARRAY - fill the array
	getSugarBagNum();
	
	// 2. INPUT & OUTPUT DATA
	int N;
	cin >> N;
	
	cout << sugarBag[N];
}

// set array value - min num of bag
void getSugarBagNum() {
	// set value (base case)
	sugarBag[3] = 1;
	sugarBag[4] = -1;
	sugarBag[5] = 1;
	
	// set array
	for (int i = 6; i <= 5000; i++) {
		if (sugarBag[i-3] > 0 && sugarBag[i-5] <= 0)
			sugarBag[i] = sugarBag[i-3] + 1;
		else if (sugarBag[i-3] <= 0 && sugarBag[i-5] > 0)
			sugarBag[i] = sugarBag[i-5] + 1;
		else if (sugarBag[i-3] > 0 && sugarBag[i-5] > 0)
			sugarBag[i] = min(sugarBag[i-3], sugarBag[i-5]) + 1;
		else
			sugarBag[i] = -1;
	}
}
