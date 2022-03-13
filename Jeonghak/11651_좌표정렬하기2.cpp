#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({y, x});
    }
    sort(v.begin(), v.end());
    for(int i=0;i<N;i++)
        cout << v[i].second << ' ' << v[i].first << '\n';
}