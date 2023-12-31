#include <iostream>
#include <vector>

using namespace std;

vector<int> A, tmp;

int answer = -1, N{}, K{};
void merge(int left, int mid, int right);
void merge_sort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid+1, right);
		merge(left, mid, right);
	}
}

void merge(int left, int mid, int right) {
	int i = left, j = mid + 1, t = 0;
	while (i <= mid && j <= right) {
		if (A[i] <= A[j]) {
			tmp[t++] = A[i++];
		}
		else {
			tmp[t++] = A[j++];
		}
	}
	while (i <= mid) tmp[t++] = A[i++];
	while (j <= right) tmp[t++] = A[j++];
	i = left;
	t = 0;
	while (i <= right) {
		A[i] = tmp[t];
		K--;
		if (K == 0) answer = A[i];
		i++;
		t++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	tmp.resize(N);
	for (int i = 0; i < N; i++) {
		int a{};
		cin >> a;
		A.push_back(a);
	}

	merge_sort(0, A.size()-1);
	cout << answer;
}
