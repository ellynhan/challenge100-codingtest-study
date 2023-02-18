#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>

#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
	if(a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}
int main()
{
    unordered_map<int, int> _map;
    vector<int> v;
    map<int, int, greater<int>> m;
    vector<int> mode;
    int N, sum=0, range, mid, avg, modeV = 0;
    cin >> N;

    for(int i=0; i<N; i++){
        int t;
        cin >> t;
        m[t]++;
        _map[t]++;
        sum+=t;
        v.push_back(t);
    }
    avg = int(round(double(sum)/N));
    sort(v.begin(), v.end());
    mid = v[N/2];
    range = v[N-1] - v[0];
    
    // 최빈 값 구하기
    for(auto it = m.begin(); it!=m.end(); it++){
        if(it->second > modeV) modeV = it->second;
    }
    for(auto it = m.begin(); it!=m.end(); it++){
        if(it->second == modeV) mode.push_back(it->first);
    }
    sort(mode.begin(), mode.end());

    if(mode.size() == 1) modeV = mode[0];
    else modeV = mode[1];
    cout << avg << '\n' << mid << '\n' << modeV << '\n' << range;
}