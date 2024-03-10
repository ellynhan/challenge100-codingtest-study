#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<int> v;
vector<int> tmpv;

void mergeSort(int start, int end) {
	if(start+1 > end) {
		return;
	}

	int mid = start + (end-start)/2;
	mergeSort(start, mid);
	mergeSort(mid+1, end);

	// 병합 과정
	for(int i=start; i<=end; i++) {
		tmpv[i] = v[i];
	}
	
	int k = start;
	int i = start, j = mid+1;
	while(i<=mid && j<=end) {
		if(tmpv[i]<=tmpv[j]) {
			v[k] = tmpv[i];
			k++; i++;
		}
		else {
			v[k] = tmpv[j];
			k++; j++;
		}
	}
	while(i<=mid) {
		v[k] = tmpv[i];
		k++; i++;
	}
	while(j<=end) {
		v[k] = tmpv[j];
		k++; j++;
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp;
	
	cin >> n;
	v.resize(n+1);
	tmpv.resize(n+1);
	for(int i=1; i<=n; i++) {
		cin >> v[i];
	}

	mergeSort(1, n);

	for(int i=1; i<=n; i++) {
		cout << v[i] << "\n";
	}
}