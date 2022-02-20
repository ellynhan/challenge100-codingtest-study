#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N;
    vector<pair<int,int>> v;
    cin >> N;
    while(N--){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    stable_sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
        cout << v[i].first << ' ' << v[i].second << '\n';
}
