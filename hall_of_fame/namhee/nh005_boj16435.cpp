#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	// 1. INPUT DATA
	int N, L;
	cin >> N >> L;
	
	int h[N];
	for (int i = 0; i < N; i++)
		cin >> h[i];
	
	// 2. SORT
	sort(h, h+N);
	
	// 3. GET MAX LENGTH
	for (int i = 0; i < N; i++)
		if (h[i] <= L)	
			L++;
		else
			break;
	
	// 4. OUTPUT DATA
	cout << L << endl;	
}
