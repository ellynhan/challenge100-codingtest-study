#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int num, primeNum = 0;
	while(N--) {
		cin >> num;
		if (num >= 2)
			primeNum++; 
		for (int i = 2; i*i <= num; i++)
			if (num%i == 0) {
				primeNum--;
				break;
			}
	}
	cout << primeNum;
}
