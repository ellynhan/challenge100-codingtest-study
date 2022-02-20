#include <iostream>
#include <string>

using namespace std;

string msgA = "";
string msgB = "";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> msgA;
	cin >> msgB;
	
	int minCount = 10000;
	for (int i = 0; i < msgB.length() - msgA.length() + 1; i++) {
		int count = 0;
		for (int j = 0;  j < msgA.length(); j++) {
//			if (!msgA.compare( msgB.substr(i + j, i + j + msgA.length()) )
			if (msgA[j] != msgB[i + j]) {
				count++;
			}
		}
		if (count < minCount) {
			minCount = count;
		}
	}
	
	cout << minCount << '\n';
	
	return 0;
}
