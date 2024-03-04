#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(const pair<double, int> &a, const pair<double, int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> v(N+2);
    map<int, pair<int, int>> m; // 스테이지 번호, 개수, 도달수
    for(int i = 0; i <= N+1; i++){
        m.insert({-i, {0, 0}});
    }
    for(int s : stages){
        m[-s].first++;
    }
    
    vector<pair<double, int>> fail(N+2);

    for(auto it : m){
        int idx = it.first;
        int num = it.second.first;
        for(int i = idx; i < 0; i++){
            m[i].second += num;
        }
        int player = it.second.second;
    }
    
    for(auto it : m){
        int idx = it.first;
        int num = it.second.first;
        int player = it.second.second;
        if(player != 0) fail[-idx] = {num / (double)player, -idx};
        else fail[-idx] = {0, -idx};
    }
    
    sort(fail.begin(), fail.end(), compare);
    
    for(int i = 0 ; i < fail.size(); i++){
        if(fail[i].second > 0 && fail[i].second <=N) answer.push_back(fail[i].second);
    }
    
    return answer;
}
