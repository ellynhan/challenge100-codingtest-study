#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	// INPUT N
	int N;
	cin >> N;
	
	// GET MIN, MAX
	int min = 1000001, max = -1000001, num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (min > num) min = num;
		if (max < num) max = num;
	}
	
	// OUTPUT
	cout << min << ' ' << max;
}

