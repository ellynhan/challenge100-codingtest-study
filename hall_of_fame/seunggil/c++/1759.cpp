#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

list<string> result;
vector<char> inputData;
string str = "";
int passwordLength, charCount;

void dfs(int index, int length) {
	if (length == passwordLength) {
		result.push_back(str);
	}
	else {
		for (int i = index; i < charCount; i++) {
			str[length] = inputData[i];
			dfs(i + 1, length + 1);
		}
	}
}

bool check(string s) {
	int vowel = 0;
	int consonant = 0;

	for (char c : s) {
		switch (c){
			case 'a':
				vowel++;
				break;
			case 'e':
				vowel++;
				break;
			case 'i':
				vowel++;
				break;
			case 'o':
				vowel++;
				break;
			case 'u':
				vowel++;
				break;
			default:
				consonant++;
				break;
		}
	}

	if (vowel > 0 && consonant > 1)
		return true;
	else
		return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> passwordLength >> charCount;

	inputData = vector<char>(charCount);

	for (int i = 0; i < charCount; i++)
		cin >> inputData[i];

	sort(inputData.begin(), inputData.end());
	str.resize(passwordLength);

	dfs(0, 0);

	for (string s : result)
		if (check(s))
			cout << s << '\n';

	return 0;
}