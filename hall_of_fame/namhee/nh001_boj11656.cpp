#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

int main() {
	// 1. INPUT DATA(string S)
	string S;
	cin >> S;
	
	// 2. GET ALL SUFFIXES
	// 2-1. get S's length
	int Slen = S.length();
	
	// 2-2. get S's suffixes array
	string suffixArray[Slen];
	
	suffixArray[0] = S;
	for (int i = 1; i < Slen; i++)
		suffixArray[i] = S.erase(0, 1);
	
	// 3. SORT : sort suffixes array (Ascending)
	sort(suffixArray, suffixArray+Slen);
	
	// 4. OUTPUT DATA(suffixes array)
	for (int i = 0; i < Slen; i++)
		cout << suffixArray[i] << endl;
		
}
