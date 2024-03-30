#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string num;
    cin >> num;
    
    sort(num.begin(), num.end(), greater<>());
    cout << num;
}