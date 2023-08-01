#include <iostream>
#include <string>
#include <vector>
#define MAX 2147483647

using namespace std;

int calc(int pick, int mineral){
    if(pick <= mineral) return 1;
    if(pick == 1 || mineral == 1) return 5;
    return 25;
}

int routing(vector<int> picks, vector<int> minerals, int tired, int idx){
    int sum = 0;
    for(auto a : picks) sum += a;
    if(sum == 0 || idx >= minerals.size()) return tired;
    
    int result = MAX, tmp, i, j;
    for(i=0; i<3; i++){
        if(picks[i]){
            picks[i]--;
            tmp = 0;
            
            for(j=idx; j<idx+5 && j < minerals.size(); j++){
                tmp += calc(i, minerals[j]);
            }
            result = min(result, routing(picks, minerals, tired + tmp, j));
            picks[i]++;
        }
    }
    return result;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    vector<int> temp;
    for(auto str : minerals){
        if(str == "diamond") temp.push_back(0);
        if(str == "iron")    temp.push_back(1);
        if(str == "stone")   temp.push_back(2);
    }
    
    answer = routing(picks, temp, 0, 0);
    return answer;
}
