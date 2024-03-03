#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string S{};
	cin >> S;

	vector<int> v;
	char c{};
	int pos = -1;
	bool isSame = false;
	for (int i = 0; i < S.length(); i++) {
		if (!isSame) {
			c = S[i];
			pos = i;
			isSame = true;
			continue;
		}
		if (c != S[i]) {
			v.push_back(i - pos);
			isSame = false;
			i--;
		}
	}

	if (pos == -1) {
		cout << 0;
		return 0;
	}
	if (pos != -1 && isSame) {
		v.push_back(S.length() - pos);
	}

	int a{}, b{};
	for (int i = 0; i < v.size(); i++) {
		if (i % 2 == 0) a++;
		else b++;
	}

	a > b ? cout << b : cout << a;

	return 0;
}
