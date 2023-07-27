#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> factor;
    while(N--){
        int tmp; cin >> tmp;
        factor.push_back(tmp);
    }
    sort(factor.begin(), factor.end());

    cout << factor[0] * factor[factor.size()-1];
}
