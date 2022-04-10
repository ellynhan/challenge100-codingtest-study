#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> user_map;
    map<string, set<string>> report_map;
    
    for(int i=0; i<id_list.size(); i++) user_map[id_list[i]]=i;
    
    for(auto one_rep : report){
        string user, reporter;
        stringstream ss;
        ss.str(one_rep);
        ss >> reporter >> user;
        report_map[user].insert(reporter);
    }
    
    for(auto id: id_list){
        for(auto reporter:report_map[id]);
        if(report_map[id].size() >= k)
        {
            for(auto reporter:report_map[id])
                answer[user_map[reporter]]++;
        }
    }
    
    return answer;
}