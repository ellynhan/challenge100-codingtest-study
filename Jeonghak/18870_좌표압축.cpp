#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<int, int> m;
vector<int> v;
vector<int> v_copy;
int pr;
int main()
{
    int N; 
    cin >> N;
    while(N--){
        int n;
        cin >> n;
        v.push_back(n);
        v_copy.push_back(n);
    }
    sort(v_copy.begin(), v_copy.end());
    v_copy.erase(unique(v_copy.begin(),v_copy.end()),v_copy.end());
    for(auto i=0; i<v_copy.size(); i++){
        m.insert({v_copy[i], i});
    }
    for(auto i=v.begin(); i!=v.end(); i++) cout << m[*i] << ' ';
}
