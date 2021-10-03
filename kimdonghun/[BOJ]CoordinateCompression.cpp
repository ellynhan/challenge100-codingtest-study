#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int N;
vector<int> arr;
vector<int> original;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	// ******* INPUT *******
	cin >> N;

	int num = 0;
	for(int i = 0; i < N; i++) {
        cin >> num;
        original.push_back(num);
	}

	arr = original;

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());


	for(int i = 0; i < N; i++) {
       cout << lower_bound(arr.begin(), arr.end(), original[i]) - arr.begin() << " ";
	}

	return 0;
}
