#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> player = {
        {1, 2, 3, 4, 5}, 
        {2, 1, 2, 3, 2, 4, 2, 5}, 
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    vector<pair<int, int>> sums; // sum, index
    for(int p = 0; p < player.size(); p++){
        int sum = 0;
        for(int i = 0; i < answers.size(); i++){
            if(answers[i] == player[p][i % player[p].size()]) sum++;
        }
        sums.push_back({sum, p+1});
    }
    
    sort(sums.begin(), sums.end(), compare);
    
    for(int i = 1; i < sums.size(); i++){
        if(sums[i-1] > sums[i]){
            answer.push_back(sums[i-1].second);
            break;
        }
        else{
            answer.push_back(sums[i-1].second);
            if(i == sums.size()-1)
                answer.push_back(sums[i].second);
        }
    }
    return answer;
}
