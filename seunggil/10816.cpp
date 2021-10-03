#include <cstdio>
#include <unordered_map>

using namespace std;

int main(void) {
	unordered_map<int, int> result;
	int a, b;
	scanf("%d", &a);
	while (a--) {
		int n;
		scanf("%d", &n);
		result[n]++;
	}
	scanf("%d", &b);
	while (b--) {
		int n;
		scanf("%d", &n);
		printf("%d ", result[n]);
	}

	return 0;
}