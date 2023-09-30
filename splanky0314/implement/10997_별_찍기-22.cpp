#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool arr[400][400]={0,};
	int n;
	cin >> n;
	int len1 = 1+4*(n-1);
	int len2 = len1+2;

	if(n==1) {
		cout << "*";
		return 0;
	}

	for(int i=0; i<n*2; i+=2) {
		for(int j=i; j<len1-i; j++) {
			arr[i][j]=1;
			arr[len2-1-i][j]=1;
		}
		for(int j=i; j<len2-i; j++) {
			arr[j][i]=1;
			arr[j][len1-1-i]=1;
		}
		if(i!=n*2-2) arr[i+1][len1-1-i]=0;
		arr[i][len1-i]=1;
	}
	
	for(int i=0; i<len2; i++) {
		for(int j=0; j<len1; j++) {
			if(arr[i][j]) cout << "*";
			if(i!=1 && arr[i][j]==0) {
				cout << " ";
			}			
		}
		cout << "\n";
	}
}