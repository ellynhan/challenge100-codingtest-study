#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool check[1001]={};
int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n, tmp, cnt=0;
	cin >> n;
	check[1]=1;
	for(long long i=2; i<=1000; i++) {
		if(check[i]) continue;
		for(long long j=2; i*j<=1000; j++) {
			check[i*j]=1;
		}
	}
	for(int i=0; i<n; i++) {
		cin >> tmp;
		if(!check[tmp]) cnt++; 
	}
	cout << cnt;
}