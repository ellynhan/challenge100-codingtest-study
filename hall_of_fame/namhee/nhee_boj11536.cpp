#include <iostream>
#include <string>
using namespace std;

int main() {
	
	int N;
	cin >> N;
	
	string name1, name2;
	cin >> name1 >> name2;
	bool inc = (name1.compare(name2) < 0) ? true : false;
	string order = (inc == true) ? "INCREASING" : "DECREASING";
	
	for (int i = 0; i < N-2; i++) {
		name1 = name2;		
		cin >> name2;
		
		if ((name1.compare(name2) < 0 && inc == false) ||
			(name1.compare(name2) > 0 && inc == true)) {
				order = "NEITHER";
				break;
		}
	}
	
	cout << order << endl;
}
