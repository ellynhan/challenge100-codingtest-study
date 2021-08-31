#include <iostream>
#include <utility>
#include <unordered_map>
#include <functional>
#include <string>

using namespace std;

struct bigNumber {
	long long  b; // b * 10^18
	long long  c; // c * 1;

	bigNumber(long long b = 0, long long c = 0) {
		this->b = b;
		this->c = c;
	}

	bigNumber operator+ (bigNumber addValue) {
		bigNumber result;
		result.b = b + addValue.b;
		result.c = c + addValue.c;
		if (result.c >= 1000000000000000000) {
			result.b++;
			result.c %= 1000000000000000000;
		}
		return result;
	}
};
struct pair_hash {
	template<class T1, class T2>
	size_t operator() (const pair<T1, T2>& p) const {
		auto a = hash<T1>{}(p.first);
		auto b = hash<T2>{}(p.second);

		return a ^ b;
	}
};
unordered_map<pair<int, int>, bigNumber, pair_hash> datas;

bigNumber com(pair<int,int> n) {
	if (n.second == 1)
		return bigNumber(0LL, n.first);

	if (n.first == n.second)
		return bigNumber(0LL, 1LL);
	
	if (datas.count({ n }))
		return datas[n];

	
	bigNumber result = com({ n.first - 1, n.second -1 }) + com({ n.first - 1, n.second});
	datas[n] = result;

	return result;
}


int main(void) {
	int n, m;
	cin >> n >> m;
	bigNumber result = com({ n,m });

	if(result.b == 0)
		cout << result.c;
	else {
		cout << result.b;

		for (int i = 0; i < 18 - to_string(result.c).length(); i++)
			cout << '0';
		cout << result.c;
	}


	return 0;
}