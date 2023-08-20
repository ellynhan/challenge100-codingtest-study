//1111 ~ 1117
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	unordered_map<string,int> m1;
	unordered_map<int,string> m2;
	for(int i=0; i<n; i++){
		string name;
		cin >> name;
		m1[name] = i+1;
		m2[i+1]=name;
	}
	while(m--){
		string a;
		cin >> a;
		if(a[0]>='0' && a[0]<='9'){
			int anum = stoi(a);
			cout<<m2[anum]<<'\n';
		}else{
			cout<<m1[a]<<'\n';
		}
	}
}

//문자열 -> 숫자변환이 필요하겠는데?