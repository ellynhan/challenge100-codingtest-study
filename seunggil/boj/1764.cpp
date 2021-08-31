#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(void) {
	int notListen, notSee;

	cin >> notListen >> notSee;

	set<string> inputData;
	set<string> answer;

	while (notListen--) {
		string in;
		cin >> in;
		inputData.insert(in);
	}

	while (notSee--) {
		string in;
		cin >> in;

		if (inputData.count(in))
			answer.insert(in);
	}

	cout << answer.size() << '\n';
	for (const string& iter : answer)
		cout << iter << '\n';

	return 0;
}