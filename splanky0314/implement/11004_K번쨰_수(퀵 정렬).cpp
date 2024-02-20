#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
using ll = long long;

int n, k, tmp;
vector<int> v;

int partition(int start, int end) {
	if(start + 1 ==end) {
		if(v[start] > v[end]) {
			swap(v[start], v[end]);
		}
		return end;
	}

	int pivot = v[0];
	int fir = start+1, sec = end;

	while(fir < sec) {
		while(pivot < v[sec] && sec > 0) {
			sec--;
		}
		while(v[fir] < pivot && fir < n-1) {
			fir++;
		} 
		if(fir < sec) {
			swap(v[fir], v[sec]);
			fir++; sec--;
		}
	}
	swap(v[start], v[sec]);

	// cout << endl;
	// for(int i=0; i<v.size(); i++) {
	// 	cout << v[i] << " ";
	// }

	return sec;
}

void sort(int start, int end) {
	int pivot_idx = partition(start, end);
	if(pivot_idx == k) return;
	else if(pivot_idx > k) {
		sort(start, pivot_idx-1);
	}
	else {
		sort(pivot_idx+1, end);
	}
	
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	scanf("%d %d", &n, &k);
	k--;
	for(int i=0; i<n; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	sort(0, n-1);

	printf("%d", v[k]);

	// cout << endl;
	// for(int i=0; i<v.size(); i++) {
	// 	cout << v[i] << " ";
	// }
}