#include <bits/stdc++.h>

using namespace std;

int x, y;
vector<int> moving;
vector<int> result;

void input() {
    int testCase;
    cin >> testCase;
    while(testCase--) {
        cin >> x >> y;
        moving.push_back(y-x);
    }
}

void solve() {
    for(auto m : moving) {
        int root = sqrt(m);
        if (root*root == m) result.push_back(root*2-1);
        else if (root*root < m && m <= root*root + root) result.push_back(root*2);
        else result.push_back(root*2+1);
    }
}

void output() {
    for(auto r : result)
        cout << r << endl;
}


int main() {
    input();
    solve();
    output();
    return 0;
}
