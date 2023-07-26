#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	// 1. INPUT DATA
	int N;
	cin >> N;
	
	vector<int> A(N);
	vector<int> B(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];

	// 2. GET min S (A sort(asc.)* B sort(desc.))
	// However, B should not be rearranged.
	
	// 2-1. sort A(asc.)
	sort(A.begin(), A.end());
	// 2-2. copy B
	vector<int> tmpB(N);
	copy(B.begin(), B.end(), tmpB.begin());
	// 2-3. get desc sort tmpB index
	sort(tmpB.begin(), tmpB.end(), greater<int>());

	// 2-4. get S
	int S = 0;
	for (int i = 0; i < N; i++)
		S += A[i]*tmpB[i];
	
	// 3. OUTPUT DATA
	cout << S;
}
