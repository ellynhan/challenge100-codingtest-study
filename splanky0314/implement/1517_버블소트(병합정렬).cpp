#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<int> v;
vector<int> tmpv;
ll sum = 0;

void merge_sort(int start, int end) {
	if(start+1 >= end) return;

	int mid = start + (end-start)/2;
	merge_sort(start, mid);
	merge_sort(mid, end);

	for(int i=start; i<end; i++) {
		tmpv[i] = v[i];
	}

	int k = start;
	int i = start, j = mid;
	while(i<mid && j<end) {
		if(tmpv[i]<=tmpv[j]) {
			v[k] = tmpv[i];
			k++; i++;
		}
		else {
			v[k] = tmpv[j];
			k++; j++;
			sum+= j-k;
		}
	}
	while(i<mid) {
		v[k] = tmpv[i];
		k++; i++;
	}
	while(j<end) {
		v[k]= tmpv[j];
		k++; j++;
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	v.resize(n);
	tmpv.resize(n);
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}

	merge_sort(0, n);

	// for(int i=0; i<n; i++) {
	// 	cout << v[i] << " ";
	// } cout << endl;

	cout << sum;
}