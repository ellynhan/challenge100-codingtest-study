#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	// 1. INPUT DATA
	int dwarf[9];
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		sum += dwarf[i];
	}

	// 2. SORT
	sort(dwarf, dwarf+9);

	// 3. SEARCH
	int noDwarf1 = -1, noDwarf2 = -1;
	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) {
			if (sum-dwarf[i]-dwarf[j] == 100) {
				noDwarf1 = i;
				noDwarf2 = j;
				break;
			}			
		}
	}
	
	// 4. OUTPUT DATA
	for (int i = 0; i < 9; i++) {
		if (i != noDwarf1 && i != noDwarf2)
			cout << dwarf[i] << '\n';		
	}
}

