#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int count = 0;
string word;
vector<string> msg;

string ones [9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string ten_ones[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tens [8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string hunds [9] = {"onehundred", "twohundred", "threehundred", "fourhundred", "fivehundred", "sixhundred", "sevenhundred", "eighthundred", "ninehundred"};

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word;
		
		if (word != "$")
		count += word.size();
		
		msg.push_back(word);
	}
	
	
//	cout << "[+] current Count : " << count << endl;
	
	string newWord = "";
	for (unsigned int i = 1; i < 1000; i++) {
		string tmpWord = "";
		int tmpCount = count;
		
		int tmpI = i;
		
		// 100
		if (tmpI / 100) {
			tmpWord += hunds[tmpI/100 - 1];
			tmpCount += hunds[tmpI/100 - 1].size();
		}
		tmpI %= 100;
		
		// 10
		bool do_ones = true;
		if (tmpI / 10) {
			if (tmpI > 19) { // not i, but tmpI
				tmpWord += tens[tmpI/10 - 2];
				tmpCount += tens[tmpI/10 - 2].size();
			}
			else if (tmpI >= 10) {
				tmpWord += ten_ones[tmpI - 10];
				tmpCount += ten_ones[tmpI - 10].size();
				do_ones = false;
			}
		}
		tmpI %= 10;
		
		// 1
		if (do_ones) {
			if (tmpI) {
				tmpWord += ones[tmpI - 1];
				tmpCount += ones[tmpI - 1].size();
			}
		}
		
		if (tmpCount == i) {
			for (int j = 0; j < msg.size(); j++) {
				if (msg[j] == "$") {
					msg[j] = tmpWord;
				}
			}
//			cout << "GOOD! : " << i << endl;
//			cout << "[-] tmpWord : " << tmpWord << endl;
//			cout << "[-] tmpword.size : " << tmpWord.size() << endl;
			break;
		}
	}
	
	for (int i = 0; i < msg.size() - 1; i++) {
		cout << msg[i] << " ";
	}
	cout << msg[msg.size() - 1] << endl;
	
	return 0;
}
