#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;
map<string, vector<int>> condition_map;

void make_condition_map(int index, vector<string> &sub_str, int score, string curr_str){
    if(index == sub_str.size()){
        condition_map[curr_str].push_back(score);
        return;
    }
    make_condition_map(index + 1, sub_str, score, curr_str + '-');
    make_condition_map(index + 1, sub_str, score, curr_str + sub_str[index]);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<string> sub_str(4);
    int score = 0;
    for(auto &info_str : info){
        istringstream ss(info_str);
        ss >> sub_str[0] >> sub_str[1] >> sub_str[2] >> sub_str[3];
        ss >> score;
        make_condition_map(0, sub_str, score, "");
    }
    
    for(auto iter = condition_map.begin(); iter!=condition_map.end(); iter++)
    {
        sort(iter->second.begin(), iter->second.end());
    }
    
    for(auto & query_str : query){
        istringstream ss(query_str);
        string and_str;
        ss >> sub_str[0] >> and_str >> sub_str[1] >> and_str >> sub_str[2] >> and_str >> sub_str[3];
        ss >> score;
        
        vector<int> scores = condition_map[sub_str[0] + sub_str[1] + sub_str[2] + sub_str[3]];
        
        if(scores.size() > 0){
            int lower_bound_index = lower_bound(scores.begin(), scores.end(), score) - scores.begin();
            answer.push_back(scores.size() - lower_bound_index);
        }
        else answer.push_back(0);
    }
    
    return answer;
}