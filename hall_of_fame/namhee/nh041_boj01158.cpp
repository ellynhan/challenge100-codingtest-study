#include <iostream>
#include <queue>

using namespace std;

int main() {
	// 1. INPUT DATA - N(num of person), K(order)
	int N, K;
	cin >> N >> K;
	
	// 2. Set queue <- 1~N
	queue<int> q;
	for (int i = 1; i <= N; i++)
		q.push(i);
	
	// 3. Get Josephus permutation using Q 
	int josephus[N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K-1; j++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		josephus[i] = q.front();
		q.pop();
	}
		
	// 4. OUTPUT DATA - Josephus permutation
	cout << '<';
	for (int i = 0; i < N; i++) {
	 	if (i < N-1)
			cout << josephus[i] << ", ";
		else
			cout << josephus[i] << '>';
	}
}
