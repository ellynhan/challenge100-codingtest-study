#include <iostream>
#include <list>

using namespace std;

int maxN = -1000000000;
int minN = 1000000000;

int cal(int n1, int n2, char c);
void backtracking1(int num, list<int>& numbers, int plus, int multi, int minus, int div);
void backtracking2(int num, list<int>& numbers, int plus, int multi, int minus, int div);
int main(void) {
	int N;

	cin >> N;
	list<int> numsData;
	int plus, minus, multiple, divisor;

	while (N > 0) {
		int n;
		cin >> n;
		numsData.push_back(n);
		N--;
	}
	cin >> plus >> minus >> multiple >> divisor;
	N = numsData.front();
	numsData.pop_front();
	backtracking1(N, numsData, plus, multiple, minus, divisor);
	backtracking2(N, numsData, plus, multiple, minus, divisor);

	cout << maxN << endl << minN << endl;

	return 0;
}

int cal(int n1, int n2, char c) {
	switch (c)
	{
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	case '/':
		return n1 / n2;
	case '*':
		return n1 * n2;
	default:
		return -1;
	}
}

void backtracking1(int num, list<int>& numbers, int plus, int multi, int minus, int div) {
	if (numbers.size()) {
		if (plus == 0 && multi == 0 && num < maxN)
			return;

		int n = numbers.front();
		numbers.pop_front();

		if (plus)
			backtracking1(cal(num, n, '+'), numbers, plus - 1, multi, minus, div);
		if (multi)
			backtracking1(cal(num, n, '*'), numbers, plus, multi - 1, minus, div);
		if (minus)
			backtracking1(cal(num, n, '-'), numbers, plus, multi, minus - 1, div);
		if (div)
			backtracking1(cal(num, n, '/'), numbers, plus, multi, minus, div - 1);

		numbers.push_front(n);
	}
	else {
		if (num > maxN)
			maxN = num;
	}
}

void backtracking2(int num, list<int>& numbers, int plus, int multi, int minus, int div) {
	if (numbers.size()) {
		if (num > 0 && minus == 0 && div == 0 && num > minN)
			return;
		if (num < 0 && minus == 0 && multi == 0 && num > minN)
			return;

		int n = numbers.front();
		numbers.pop_front();

		if (plus)
			backtracking2(cal(num, n, '+'), numbers, plus - 1, multi, minus, div);
		if (multi)
			backtracking2(cal(num, n, '*'), numbers, plus, multi - 1, minus, div);
		if (minus)
			backtracking2(cal(num, n, '-'), numbers, plus, multi, minus - 1, div);
		if (div)
			backtracking2(cal(num, n, '/'), numbers, plus, multi, minus, div - 1);

		numbers.push_front(n);
	}
	else {
		if (num < minN)
			minN = num;
	}
}