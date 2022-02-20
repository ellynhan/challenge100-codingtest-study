#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N, M;
    string name;
    map<string, bool> m;
    vector<string> ans;
    
    cin >> N >> M;
    while(N--){
        cin >> name;
        m.insert({name, true});
    }
    while(M--){
        cin >> name;
        if(m.find(name) != m.end()) {
            ans.push_back(name);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto i=ans.begin(); i!=ans.end(); i++) cout << *i << '\n';
}   
