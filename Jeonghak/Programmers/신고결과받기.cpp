#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> reports, int k) {
    vector<int> answer;
    unordered_map<string, set<string>> result_map;
    unordered_map<string, int> result_count;
    

    for(auto& report : reports){
        stringstream in(report);
        string reporter, reported;
        in >> reporter >> reported;
        result_map[reported].insert(reporter);
    }
    
    for(auto& result : result_map){
        auto reporters = result.second;
        if(reporters.size() >= k){
            for(auto& reporter : reporters){
                result_count[reporter]++;
            }
        }
    }
    
    for(auto& id: id_list){
        answer.push_back(result_count[id]); 
    }
    
    return answer;
}