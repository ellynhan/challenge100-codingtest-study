#include <iostream>
#include <string>
#include <sstream>

using namespace std;
bool isVisited[2500] = {false, };

string msg = "";
string key = "";
int count = 0;


void showVisited() {
	for (int i = 0; i < msg.size(); i++) {
		cout << isVisited[i] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	getline(cin, msg);
	getline(cin, key);
	
	for (int i = 0; i < msg.size(); i++) {
		
		// showVisited();
		
		if ( msg[i] == key[0] ) {
			string tmp = "";
			tmp += key[0];
			for (int j = 1; j < key.size(); j++) {
				tmp += msg[i + j];
			}
			
			if (!key.compare(tmp)) {
				for (int j = 0; j < key.size(); j++) {
					isVisited[i + j] = true;
				}
				
				i += key.size() - 1;
				count++;
			}
			
			else { 
				continue;
			}
		}
	}
	
	cout << count << endl;
	
	return 0;
}
