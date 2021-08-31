#include <iostream>
#include <utility>
#include <map>
using namespace std;

long long result = 0;

int main(void) {
	int n;
	map<int,int> inputData;
	
	cin >> n;

	int num;
	cin >> num;
	inputData[num] = 1;
	result++;
	for (int i = 1; i < n; i++) {
		cin >> num;
		map<int, int>::iterator iter = inputData.insert({ num, 0 }).first;
		int a = 0, b = 0;
		
		if (iter != inputData.begin()) {
			a = (--iter)->second;
			iter++;
		}
		if (iter != --inputData.end()) {
			b = (++iter)->second;
			iter--;
		}
		iter->second = a > b ? a + 1 : b + 1;
		result += iter->second;
	}

	cout << result;
	return 0;	

}