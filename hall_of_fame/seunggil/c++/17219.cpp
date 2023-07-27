#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, string> inputData;

	int site, testCase;
	cin >> site >> testCase;

	for (int i = 0; i < site; i++) {
		string name, password;
		cin >> name >> password;
		inputData[name] = password;
	}
	for (int i = 0; i < testCase; i++) {
		string name;
		cin >> name;
		cout << inputData[name] << '\n';
	}

	return 0;
}