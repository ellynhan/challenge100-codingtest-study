#include <cstdio>
#include <vector>
using namespace std;

int main(void) {
	int k, n;
	scanf("%d %d", &k, &n);
	unsigned long long sum = 0;
	int maxValue = 0;
	vector<int> inputData(k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &inputData[i]);
		sum += inputData[i];

		if (maxValue < inputData[i])
			maxValue = inputData[i];
	}

	int answer = sum / n;
	while (answer >= 1) {
		int count = 0;
		for (int iter : inputData)
			count += iter / answer;
		
		if (count >= n)
			break;
		else
			answer-= n - count;
	}

	if (answer < 1)
		answer = 1;

	while (true) {
		int count = 0;
		for (int iter : inputData)
			count += iter / (answer + 1);
		if (count < n)
			break;
		else
			answer++;
	}

	printf("%d",answer);

	return 0;
}