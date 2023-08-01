#include <iostream>

using namespace std;

int main() {
	// 1. INPUT DATA
	int E, S, M;
	cin >> E >> S >> M;
	
	// 2. SEARCH YEAR
	int year = E;
	while(!((year-1)%28+1 == S && (year-1)%19+1 == M)) 
		year += 15;
	
	// 3. OUTPUT DATA
	cout << year;
}

