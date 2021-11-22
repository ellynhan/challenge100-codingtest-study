#include <iostream>

using namespace std;

int main() {
	// INPUT DATA
	int N;
	cin >> N;
	
	// OUTPUT DATA
	for (int i = 0; i < N*2-1; i++) {
		// triangle (0~N-1)
		if (i < N) {
			for (int blank = N-1-i; blank > 0; blank--)
				cout << ' ';
			for (int asterisk = 1; asterisk <= 1+2*i; asterisk++)
				cout << '*';
		
		} else { // inverted triangle (N~2N-2)
			for (int blank = 1; blank <= i-N+1; blank++)
				cout << ' ';
			for (int asterisk = 4*N-2*i-3; asterisk > 0; asterisk--)
				cout << '*';
			
		}
		cout << endl;
	}
}

