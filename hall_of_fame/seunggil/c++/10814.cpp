#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

struct c {
	int age;
	char name[101];
	int index = 0;

	bool operator < (const c& other) const {
		if (age != other.age)
			return age < other.age;
		else
			return index < other.index;
	}

	c(int a, char* n, int i) {
		age = a;
		strcpy(name, n);
		index = i;
	}
};

int main(void) {
	int n;
	scanf("%d", &n);
	vector<c> inputData;
	inputData.reserve(n);

	int a;
	char s[101];
	for (int i = 0; i < n; i++) {
		scanf("%d %s", &a, s);
		inputData.emplace_back(a,s,i);
	}

	sort(inputData.begin(), inputData.end(), less<c>());

	for (const c& iter : inputData)
		printf("%d %s\n", iter.age, iter.name);

	return 0;
}