#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, int> id_index;
    int i = 0;
    for (auto id: id_list) {
        id_index.insert({id, i});
        i++;
    }
    vector<int> answer(id_list.size());
    map<string, set<string>> result;
    for (auto id: id_list) {
        set<string> tmp;
        result.insert({id, tmp});
    }
    for (auto r: report) {
        int blankIndex = r.find(' ');
        result[r.substr(blankIndex + 1)].insert(r.substr(0, blankIndex));
    }
    for (auto it = result.begin(); it != result.end(); it++) {
        if (it->second.size() >= k) {
            for(auto reporter: it->second) {
                answer[id_index[reporter]]++;
            }
        }
    }
    return answer;
}