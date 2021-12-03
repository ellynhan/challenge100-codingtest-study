#include <iostream>
#include <algorithm>

using namespace std;

int num[1001];

int main() {
	// INPUT DATA
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> num[i];
	
	// SORT
	sort(num, num+N);
	
	// OUTPUT DATA
	for (int i = 0; i < N; i++)
		cout << num[i] << '\n';
}
