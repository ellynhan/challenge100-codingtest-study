#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string ins;
	cin >> ins;

	int answer = 0;
	int number = 0;
	bool sign = true;

	for (char c : ins) {
		switch (c) {
		case '+':
		case '-':
			answer += sign ? number : -number;
			number = 0;

			if(c == '-')
				sign = false;
			break;

		default:
			number *= 10;
			number += c - '0';
			break;
		}
	}

	answer += sign ? number : -number;

	cout << answer << endl;

	return 0;
}