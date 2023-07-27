#include <set>
#include <iostream>
#include <iterator>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	set<int> result;
	result.insert(666);

	// 4자리 숫자

	for (int i = 0; i < 10; i++) {
		result.insert(result.end(), i * 1000 + 666);
		result.insert(result.end(), 666 * 10 + i);
	}

	// 5자리 숫자
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			result.insert(result.end(), (i*10+j) * 1000 + 666);
			result.insert(result.end(), i * 10000 + 666 * 10 + j);
			result.insert(result.end(), 666 * 100 + (i * 10 + j));
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				result.insert(result.end(), (i * 100 + j * 10 + k) * 1000 + 666);
				result.insert(result.end(), (i * 10 + j) * 10000 + 666 * 10 + k);
				result.insert(result.end(), i * 100000 + 666 * 100 + (j * 10+ k));
				result.insert(result.end(), 666 * 1000 + (i * 100 + j * 10 + k));
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					result.insert(result.end(), (i * 1000 + j * 100 + k * 10 + l) * 1000 + 666);
					result.insert(result.end(), (i * 100 + j * 10 + k) * 10000 + 666 * 10 + l);
					result.insert(result.end(), (i * 10 + j) * 100000 + 666 * 100 + (k * 10 + l));
					result.insert(result.end(), i * 1000000 + 666 * 1000 + (j * 100 + k * 10 + l));
					result.insert(result.end(), 666 * 100000 + (i * 1000 + j * 100 + k * 10 + l));
				}
			}
		}
	}
	set<int>::const_iterator iter = result.begin();
	advance(iter, N - 1);
	cout << *iter;
	
	return 0;
}