#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> dd;
    vector<int> origin;
    int testcase; cin >> testcase;
    while(testcase--){
        int x; cin >> x;
        dd.push_back(x);
        origin.push_back(x);
    }
    sort(dd.begin(), dd.end());
    dd.erase(unique(dd.begin(), dd.end()), dd.end());

    for(int a :origin){
        cout << lower_bound(dd.begin(), dd.end(), a) - dd.begin() << " ";
    }
}
