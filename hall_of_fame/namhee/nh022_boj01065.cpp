// BOJ 1065 ÇÑ¼ö (22:18~22:33) 
#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int count = 0;
	for (int i = N; i >= 1; i--) {
		string X = to_string(i);
		int len = X.length();
		
		if (len <= 2) count++;
		else {
			int diff = X[1] - X[0];
			count++;
			for (int j = 1; j < len-1; j++) {
				if (X[j+1]-X[j] == diff)
					continue;
				else {
					count--;
					break;
				}
			}			
		}
	}
	
	cout << count;
}

