#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N;
    vector<int> v;
    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for(auto i=v.begin(); i != v.end(); i++)
        cout << *i << '\n';
}
