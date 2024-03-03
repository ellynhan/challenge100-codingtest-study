#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	bool v[401][401]={0,};
	cin >> n;
	int len = 1+(n-1)*4;

	for(int i=0; i<2*n; i+=2) {
		for(int j=i; j<len-i; j++) {
			v[i][j]=1;
			v[len-1-i][j]=1;
			v[j][i]=1;
			v[j][len-1-i]=1;
		}
	}

	for(int i=0; i<len; i++) {
		for(int j=0; j<len; j++) {
			if(v[i][j]) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
}