#include<iostream>
#include<vector>
using namespace std;

int seq[100001];
vector<int> v;
vector<char> ans;

int main(){
	int N; cin >> N;
	for(int i=0; i<N; i++)
        cin >> seq[i];

    int curr = 0;
	for(int i=1; i<=N; i++){
		v.push_back(i);
		ans.push_back('+');

		while (!v.empty() && v.back() == seq[curr]){
			v.pop_back();
			ans.push_back('-');
			curr++;
		}
	}

	if (!v.empty()) cout << "NO";
	else{
        for(int i=0; i<ans.size(); i++)
            cout << ans[i] <<  "\n";
	}
}
