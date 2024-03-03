#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n;
	string a = "IJKLABCDEFGH"; 
	cin >> n;
	cout << a[n%12] << ((n+6)%10);
}