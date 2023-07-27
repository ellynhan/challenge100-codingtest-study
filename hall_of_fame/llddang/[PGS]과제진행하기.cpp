#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct study{
    study(string s, int t, int d):
        subject(s), time(t), during(d){};
    string subject;
    int time;
    int during;
};

int convertTime(string str){
    int time = 0;
    time += stoi(str.substr(0,2)) * 60;
    time += stoi(str.substr(3,2));
    return time;
}

bool comp(study a, study b){
    return a.time < b.time;
}

vector<study> vec;
stack<study> vec_rest;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    for(auto plan : plans){
        vec.push_back(study(plan[0], convertTime(plan[1]), stoi(plan[2])));
    }
    
    sort(vec.begin(), vec.end(), comp);
    
    study tmp = {"", 0, 0};
    int check_time, i;
    for(i=0; i<vec.size() - 1; i++){
        if(vec[i].time + vec[i].during <= vec[i+1].time){
            answer.push_back(vec[i].subject);
            check_time = vec[i].time + vec[i].during;
            while(!vec_rest.empty()){
                tmp = vec_rest.top(); vec_rest.pop();
                check_time += tmp.during;
                if(check_time <= vec[i+1].time) 
                    answer.push_back(tmp.subject);
                else {
                    tmp.during = check_time - vec[i+1].time;
                    vec_rest.push(tmp);
                    break;
                } 
            }
        } else {
            tmp = vec[i];
            tmp.during = vec[i].time + vec[i].during - vec[i+1].time;
            vec_rest.push(tmp);
        }
    }
    answer.push_back(vec[i].subject);
    while(!vec_rest.empty()){
        answer.push_back(vec_rest.top().subject);
        vec_rest.pop();
    }
    
    
    return answer;
}
