#include <list>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str, bomb;
	cin >> str >> bomb;

	list<char> inputData(str.begin(), str.end());

	list<char>::iterator inputDataIter = inputData.begin();
	string::iterator bombIter = bomb.begin();

	while (inputDataIter != inputData.end()) {
		if (*bombIter == *inputDataIter)
			bombIter++;
		else {
			bombIter = bomb.begin();
			if (*bombIter == *inputDataIter)
				bombIter++;
		}
		
		inputDataIter++;

		if (bombIter == bomb.end()) {
			inputDataIter = inputData.erase(next(inputDataIter, -static_cast<int>(bomb.size())), inputDataIter);
			for (int i = 0; i < bomb.size() - 1; i++) {
				if(inputDataIter != inputData.begin())
					inputDataIter--;
			}
			bombIter = bomb.begin();
		}
	}

	if (inputData.empty())
		cout << "FRULA";
	else
		for (char c : inputData)
			cout << c;

	return 0;
}