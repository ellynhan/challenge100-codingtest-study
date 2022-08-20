#include <string>
#include <vector>
#include <sstream>
#include <map>
#define MAX_TIME 1439

using namespace std;

struct Time{
    int in;
    int out;
    int used;
};

int getTotalMinute(string time){
    stringstream ss(time);
    string hour;
    int minute;
    
    getline(ss, hour, ':');
    ss >> minute;
    
    return stoi(hour) * 60 + minute;
}

int getFee(int usedTime, vector<int> &fees){
    int fee = 0;
    if(usedTime <= fees[0]) 
        fee = fees[1];
    else 
        fee = fees[1] + (usedTime - fees[0] + fees[2] - 1) / fees[2] * fees[3];
    return fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, Time> timeReport;
        
    for(auto record: records){
        stringstream ss(record);
        int totalMinute = 0;
        string time, carNumber, inOrOut;
        
        ss >> time >> carNumber >> inOrOut;
        totalMinute = getTotalMinute(time);
        
        if(inOrOut == "OUT"){
            timeReport[carNumber].used += totalMinute - timeReport[carNumber].in;
            timeReport[carNumber].in = -1;
        } else {
            timeReport[carNumber].in = totalMinute;
        }
    }
    
    for(auto& [carNumber, time] : timeReport ){
        if(time.in >= 0){
            time.used += MAX_TIME - time.in;
        }
        
        answer.push_back(getFee(time.used, fees));
    }
    return answer;
}