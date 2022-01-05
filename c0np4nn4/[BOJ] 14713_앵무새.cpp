#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int N;
string msg;
stack<string> bird[100];
stack<string> pt;
bool ret = true;


int main() {

	
	cin >> N;
	cin.ignore();
	
	for (int i = 0; i < N + 1; i++) {
		getline(cin, msg);
		istringstream ss(msg);
		string buffer;
		while (getline(ss, buffer, ' ')) {
			if (i == N) { pt.push(buffer); }
			else { bird[i].push(buffer); }
		}	
	}

	while (!pt.empty()) {
		int ptLen = pt.size();
		
		for (int i = 0; i < N; i++) {
			if (!bird[i].empty()) {
//				cout << "[+] bird[" << i << "] top : " << bird[i].top() << endl;
//				cout << "[+] orign pt : " << pt.top() << endl << endl;
		
				if (!pt.top().compare(bird[i].top())) {
					pt.pop();
					bird[i].pop();
				}
			}
		}
		
		if (ptLen == pt.size()) {
			ret = false;
			break;
		}
	}

	
	if (ret) { cout << "Possible" << endl; }
	else { cout << "Impossible" << endl; }
	
	
	return 0;
}
