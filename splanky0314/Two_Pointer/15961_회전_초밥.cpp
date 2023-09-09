#include <iostream>
#include <vector>
using namespace std;

int check[3000]={};
int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n, d, k, c, cnt=0;
	cin >> n >> d >> k >> c;
	vector<int> v(n);
	check[c]++;
	for(int i=0; i<n; i++) {
		cin >> v[i];
		if(i<k) {
			check[v[i]]++;
			if(check[v[i]]>1) cnt++;
		}
	}

	int fir=0, sec=k-1, min=cnt;

	while(fir<=n-2) {
		if(check[v[fir]]>1) {
			cnt--;
		}
		check[v[fir]]--;
		fir++; sec++;
		check[v[sec%n]]++;
		if(check[v[sec%n]]>1) cnt++;
		
		if(cnt<min) min = cnt;
	}

	cout << (k+1)-min;
}