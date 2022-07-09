#include <iostream>
#define SIZE 1001

using namespace std;
int trr[SIZE];

void print(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void merge(int* arr, int start, int end, int n) { // [start, end)
	//00. base condition
	if (start >= end) return;

	//01. divide
	int mid = (start + end) / 2;

	//02. conquer
	merge(arr, start, mid, n);
	merge(arr, mid + 1, end, n);

	//03. merge
	int i = start, j = mid + 1;
	for (int k = start; k <= end; k++) {
		if (j > end) trr[k] = arr[i++];
		else if (i > mid) trr[k] = arr[j++];
		else if (arr[i] <= arr[j]) trr[k] = arr[i++];
		else trr[k] = arr[j++];
	}

	//04. copy
	for (int k = start; k <= end; k++) {
		arr[k] = trr[k];
	}
	
	print(arr, n);
}

int main() {
	int n;
	cin >> n;
	int arr[1001];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	merge(arr, 0, n - 1, n);
}