#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void) {
	int N;
	map<string, int> inputData;
	cin >> N;
	string str;
	int c;
	while (N--) {
		inputData.clear();
		cin >> c;
		for (int i = 0; i < c; i++) {
			cin >> str >> str;
			inputData[str]++;
		}

		int answer = 1;

		for (const pair<const string, int> iter : inputData)
			answer *= iter.second + 1;

		cout << answer - 1 << '\n';
	}
	
	return 0;
}