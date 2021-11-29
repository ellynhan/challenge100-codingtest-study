#include <iostream>

using namespace std;

int main() {
	// 1. INPUT DATA - any integer n
	int n;
	while (cin >> n) {
		int mod = 1; // mod of sequence of 1
		int digit = 1;
		
		// 2. Get digits of smallest such a multiple of n
		while (true) {
			if (mod%n == 0)
				break;
			else {
				mod = (mod*10+1)%n;
				digit++;
			}
		}
		// 3. OUTPUT DATA - digits
		cout << digit << endl;		
	}
}

