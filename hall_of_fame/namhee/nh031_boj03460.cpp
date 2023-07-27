#include <iostream>

using namespace std;

int main() {
	// INPUT DATA & OUTPUT DATA
	int d;
	cin >> d;
	
	int n;
	for (int i = 0; i < d; i++) {
		cin >> n;
		int digit = 0;
		for (int j = n; j > 0; j/=2) {
			if (j%2 == 1)
				cout << digit << ' ';
			digit++;
		}
		cout << endl;
	}
}
