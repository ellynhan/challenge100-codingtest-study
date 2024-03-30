#include <bits/stdc++.h>
using namespace std;

int counts[1000000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> v;
    vector<int> v1;
    
    int N, value;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> value;
        v.push_back(value);
        v1.push_back(value);
    }
    
    //벡터 중복 제거
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for (int i = 0; i < v1.size(); i++) {
        cout << lower_bound(v.begin(), v.end(), v1[i]) - v.begin() << " ";
    }
}