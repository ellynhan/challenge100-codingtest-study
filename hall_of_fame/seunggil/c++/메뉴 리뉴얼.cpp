#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <iostream>

using namespace std;

map<set<char>, int> result[11];

char menus[11];

string charSetToString(const set<char>& data) {
    string result = "";
    result.reserve(data.size());
    for(char c : data)
        result += c;
    return result;
}

void combi(const string& input, int total, int count = 0, int pos = 0){
    if(total == count){
        set<char> res;
        for(int i = 0; i < total; i++)
            res.insert(menus[i]);
        result[total][res]++;
        
    }
    else{
        for(int i = pos; i<input.size(); i++){
            menus[count] = input[i];
            combi(input, total, count+1, i+1);
        }
    }
    
}


vector<string> solution(vector<string> orders, vector<int> course) {
    for(const string& order : orders)
        for(int courseSize : course)
            combi(order, courseSize);
    set<string> answerset;
    for(int i : course){
        unordered_set<string> candi;
        int size = 0;
        
        for(const auto& iter : result[i]){
            if(iter.second == size)
                candi.insert(charSetToString(iter.first));
            else if(iter.second > 1 && iter.second > size){
                candi.clear();
                candi.insert(charSetToString(iter.first));
                size = iter.second;
            }
        }
        
        answerset.insert(candi.begin(), candi.end());
    }
    
    vector<string> answer;
    for(const string& str : answerset)
        answer.push_back(str);
    
    return answer;
}