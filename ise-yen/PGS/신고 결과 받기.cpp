#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> split(string input, char del){
    vector<string> answer;
    stringstream ss(input);
    string tmp;
    
    while(getline(ss, tmp, del)){
        answer.push_back(tmp);
    }
    return answer;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer; // 자기가 신고한 상대 처리 결과를 받아야함
    
    unordered_map<string, vector<string>> um;
    unordered_map<string, int> count;
    unordered_map<string, int> ans;
    
    for(int i = 0; i < id_list.size(); i++){
        vector<string> v;
        um.insert({id_list[i], v});
        count.insert({id_list[i], 0});
        ans.insert({id_list[i], 0});
    }
    
    for(int i = 0; i < report.size(); i++){
        vector<string> v = split(report[i], ' ');
        string user = v[0]; // 유저
        string villian = v[1]; // 신고 대상
        vector<string> vils = um[user];
        
        auto it = find(vils.begin(), vils.end(), villian);
        if(it == vils.end()){
            um[user].push_back(v[1]);
            count[villian]++;
        }
    }
    
    // count 중에 k개 이상 신고 받은 빌런 찾기
    for(auto it : count){
        if(it.second >= k){
            // 빌런을 신고했던 유저 찾기
            for(auto user : um){
                // 신고 목록 중에 빌런이 있는지 확인
                vector<string> vils = user.second; // 신고 목록
                auto f = find(vils.begin(), vils.end(), it.first);
                if(f != vils.end()){
                    ans[user.first]++;
                }
            }
        }
    }
    
    for(int i = 0; i < id_list.size(); i++){
        string user = id_list[i];
        answer.push_back(ans[user]);
    }
    
    return answer;
}
