#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}
vector<string> solution(vector<string> record) {
    map<string, string> m;
    string enter = "님이 들어왔습니다.";
    string leave = "님이 나갔습니다.";
    vector<pair<string, int>> v;//id, enter1/leave0
    for(int i=0; i<record.size(); i++){
        vector<string> result = split(record[i], ' ');
        if(result[0]=="Enter"){
            v.push_back({result[1],1});
            m[result[1]]=result[2];
        }else if(result[0]=="Leave"){
            v.push_back({result[1],0});
        }else{
            m[result[1]]=result[2];
        }      
    }
    vector<string> answer;
    for(int i=0; i<v.size(); i++){
        string name = m[v[i].first];
        if(v[i].second == 0){
            answer.push_back(name+leave);
        }else{
            answer.push_back(name+enter);
        }
    }
    return answer;
}
