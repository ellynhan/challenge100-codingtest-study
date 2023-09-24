#include <iostream>
#include <vector>
using namespace std;

vector<bool> check;
vector<int> prime;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n;
	cin >> n;
	check.resize(n+1);
	if(n==1) {
		cout << 0;
		return 0;
	}
	// 에라토스테네스의 채
	for(long long i=2; i<=n; i++) {
		if(!check[i]) {
			prime.push_back(i);
			for(long long j=2; i*j<=n; j++) {
				check[i*j]=1;
			}
		}
	}

	// 투 포인터
	long long fir=0, sec=0, sum=prime[fir], cnt=0;
	while(fir<=sec && sec<=prime.size()-1) {
		if(sum==n) {
			cnt++;
			sum -= prime[fir];
			fir++;
			if(fir==sec+1) {
				sec++;
				if(sec>=prime.size()) break;
				sum += prime[sec];
			}
		}
		else if(sum>n) {
			sum -= prime[fir];
			fir++;
		}
		else {
			sec++;
			if(sec>=prime.size()) break;
			sum += prime[sec];
		}
	}
	cout << cnt;	
}