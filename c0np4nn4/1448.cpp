#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int stick;
	
	int result = -1;
	vector<int> sticks;
	
	// get length of sticks and push it to vec<int> sticks
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> stick;
		sticks.push_back(stick);
	}
	
	// sort vect<int> sticks
	sort(sticks.begin(), sticks.end(), greater<int>());
//	for (int i = 0; i < sticks.size(); i++) {
//		cout << sticks[i] << " ";
//	}
//	cout << endl;
	
	// iteration
	for (int i = 0; i < N-2; i++) {
		if (result != -1) break;
		for (int j = i+1; j < N-1; j++) {
			if (result != -1) break;
			
			// sticks[j] should be longer than half of the sticks[i]
			if (sticks[j] <= (sticks[i] / 2)) break;
			
			for (int k = j+1; k < N; k++) {
				
				// i < j + k
				if ( sticks[i] < sticks[j] + sticks[k] ) {
					result = (sticks[i] + sticks[j] + sticks[k]);
					break;
				}
        // sticks[k] is bigger than sticks[k + a].
        // sticks[i] >= sticks[j] + sticks[k] >= sticks[j] + sticks[k + a]
        // not worth doing it
				else {
					break;
				}
			}
		}
	}
	
	cout << result << endl;
	return 0;
}
