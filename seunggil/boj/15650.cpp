#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int n, m;

void print(int maxNum, int count) {
	if (count == m) {
		for (int iter : arr)
			cout << iter << " ";
		cout << '\n';
	}
	else {
		for (int i = maxNum + 1; i <= n; i++) {
			arr[count] = i;
			print(i, count + 1);
		}
	}
}


int main(void) {
	cin >> n >> m;
	arr = vector<int>(m);

	print(0, 0);

	return 0;
}