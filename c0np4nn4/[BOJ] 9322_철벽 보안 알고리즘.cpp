#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int T;
int N;
string msg;
vector<string> pubKey;
vector<string> priKey;
vector<string> pt;
vector<string> ct;

unsigned int map[1001];


int main() {
	cin >> T;
	
	while (T > 0) {
		
		// init
		for (int i = 0; i < 1001; i++) map[i] = -1;
		pubKey.clear();
		priKey.clear();
		pt.clear();
		ct.clear();
		
		cin >> N;
		cin.ignore();
		
		getline(cin, msg);
		istringstream pub(msg);
		string buffer;
		while (getline(pub, buffer, ' ')) {
			pubKey.push_back(buffer);
		}
		
		getline(cin, msg);
		istringstream pri(msg);
		while (getline(pri, buffer, ' ')) {
			priKey.push_back(buffer);
		}
		
		// test
//		for (int i = 0; i < N; i++) {
//			cout << pubKey[i] << " ";
//		}
//		cout << endl;
//		for (int i = 0; i < N; i++) {
//			cout << priKey[i] << " ";
//		}
//		cout << endl;
//		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (pubKey[i] == priKey[j]) {
					map[i] = j;
				}
			}
		}
		
		getline(cin, msg);
		istringstream cipher(msg);
		while (getline(cipher, buffer, ' ')) {
			ct.push_back(buffer);
			pt.push_back(buffer);
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				pt[i] = ct[ map[i] ];
			}
		}
		
		for (int i = 0; i < N; i++) {
			cout << pt[i] << " ";
		}
		cout << endl;
		
		
		T--;
	}
	return 0;
}
