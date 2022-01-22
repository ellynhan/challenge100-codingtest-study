#include <iostream>

using namespace std;

int N, M;
unsigned long long num[100001];
unsigned long long minTree[400001];
unsigned long long maxTree[400001];

unsigned long long maxNum = 0;
unsigned long long minNum = 1000000000;
int a, b;




unsigned long long findMin(const int node, const int s, const int e, const int a, const int b) {
	if (e < a || b < s) return 1000000000;
	
	if (a <= s && e <= b) return minTree[node];
	
	int mid = (s + e) / 2;
	return min(findMin(2 * node, s, mid, a, b), findMin(2 * node + 1, mid + 1, e, a, b));
}

unsigned long long findMax(const int node, const int s, const int e, const int a, const int b) {
	if (e < a || b < s) return 0;
	
	if (a <= s && e <= b) return maxTree[node];
	
	int mid = (s + e) / 2;
	return max(findMax(2 * node, s, mid, a, b), findMax(2 * node + 1, mid + 1, e, a, b));
}


unsigned long long initMin(int node, int s, int e) {
	if (s == e) {
		return minTree[node] = num[s];
	}
	
	int mid = (s + e) / 2;
	
	return minTree[node] = min( initMin(2 * node, s, mid), initMin(2 * node + 1, mid + 1, e) );
}

unsigned long long initMax(int node, int s, int e) {
	if (s == e) return maxTree[node] = num[s];
	
	int mid = (s + e) / 2;
	
	return maxTree[node] = max( initMax(2 * node, s, mid), initMax(2 * node + 1, mid + 1, e) );

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	
	for (int i = 1; i < N+1; i++) {
		cin >> num[i];
	}
	
	initMin(1, 1, N);	
	initMax(1, 1, N);
	
	for (int i = 0; i < M; i++) {
		minNum = 1000000000;
		maxNum = 0;

		cin >> a >> b;
		
		minNum = findMin(1, 1, N, a, b);
		maxNum = findMax(1, 1, N, a, b);
		
		cout << minNum << " " << maxNum << '\n';
	}
	
	
	return 0;
}
