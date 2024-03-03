#include <iostream>
using namespace std;

int check[3000]={};
int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int g; bool flag=0;
	long long fir=1, sec=2;
	cin >> g;
	while(fir<sec) {
		if((sec*sec-fir*fir)==g) {
			flag=1;
			cout << sec << "\n";
			fir++;
			if(fir==sec) sec++;
		}
		else if((sec*sec-fir*fir)>g) fir++;
		else sec++;
	}
	if(!flag) cout << -1;	
}