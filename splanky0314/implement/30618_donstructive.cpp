#include <iostream>
using namespace std;
int arr[200001];
int main() {
	int n, cnt;
	cin >> n;
	cnt = n;

	for(int i=0; i<=n/2; i++) {
		arr[n/2+i+1] = cnt;
		arr[n/2-i] = cnt-1;
		cnt-=2;
	}
	
	
	//
	for(int i=1; i<=n; i++) {
		cout << arr[i] << " ";
	}
}