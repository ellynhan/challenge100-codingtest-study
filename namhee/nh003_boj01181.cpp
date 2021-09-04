#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string words[20001];
bool compare(string s1, string s2);
 
int main() {
	// 1. INPUT DATA (num N & string[N])
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> words[i];
	
	// 2. SORT WORDS
	sort(words, words+N, compare);

	// 3. OUTPUT DATA (sorted array)
	// if the same word is entered several times, 
	// it is printed only once.
	for (int i = 0; i < N; i++) {
		if (i == 0 || words[i-1] != words[i])
			cout << words[i] << endl;		
	}

}

bool compare(string s1, string s2) {
	// if length is short, forward
	//   or if length is equal, sort in lexicographical order
	return s1.length() < s2.length() 
			|| (s1.length() == s2.length() && s1 < s2);
}
