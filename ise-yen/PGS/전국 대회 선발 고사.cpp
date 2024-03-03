#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    vector<pair<int, int>> v;
    for(int i = 0; i < rank.size(); i++){
        if(attendance[i]){
            v.push_back({rank[i], i});
        }
    }
    
    sort(v.begin(), v.end());
    int a, b, c;
    a = v[0].second;
    b = v[1].second;
    c = v[2].second;
    
    answer = 10000*a + 100*b + c;
    return answer;
}
