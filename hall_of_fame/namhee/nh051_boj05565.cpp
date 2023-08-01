#include <iostream>

using namespace std;

int main() {
	int price;
	cin >> price;
	
	int other;
	for (int i = 0; i < 9; i++) {
		cin >> other;
		price -= other;
	}
	
	cout << price;
}
