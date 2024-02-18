#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp;
	int index = 1;
	stack<int> st;
	vector<char> ans;


	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		
		while(1) {
			if(st.empty() || st.top() < tmp) {
				st.push(index);
				ans.push_back('+');
				index++;
			}
			else if(st.top() == tmp) {
				st.pop();
				ans.push_back('-');
				break;
			}
			else {
				st.pop();
				ans.push_back('-');
				cout << "NO";
				return 0;
			}
		} 

	}	

	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	
}