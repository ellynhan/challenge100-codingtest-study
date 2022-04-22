#include <iostream>

using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;

	if (b > a) {
		int temp = b;
		b = a;
		a = temp;
	}

	int c = a, d = b, r;

	do {
		r = c % d;
		c = d;
		d = r;
	}while (r);

	cout << c << '\n' << a * (b / c);


	return 0;
}