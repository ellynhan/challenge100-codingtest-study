#include<iostream>

using namespace std;

int main() {
	int n{}, answer{};
	cin >> n;

	int five{};
	if (n / 5 > 0) {
		five = n / 5;
		answer += five;
		n %= 5;
	}
	while (n > 0) {
		if (n % 2 != 0) {
			if (five > 0) {
				n += 5;
				answer--;
				five--;
			}
			else {
				answer = -1;
				break;
			}
		}
		else {
			answer += n / 2;
			n %= 2;
		}
	}
	cout << answer;
	return 0;
}
