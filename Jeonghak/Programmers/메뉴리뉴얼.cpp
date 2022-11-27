#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#define MAX_ORDER_SIZE 10
using namespace std;

map<string, int> substr_maps[MAX_ORDER_SIZE + 1];
int max_count[MAX_ORDER_SIZE + 1];

void dfs(int index, string orgstr, string substr){
    if(orgstr.size() == index){
        int length = substr.length();
        substr_maps[length][substr]++;
        
        if(substr_maps[length][substr] >= max_count[length]){
            max_count[length] = substr_maps[length][substr];
        }
        return;
    }
    
    dfs(index + 1, orgstr, substr + orgstr[index]);
    dfs(index + 1, orgstr, substr);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto &order : orders){
        sort(order.begin(), order.end());
        dfs(0, order, "");
    }
    
    for(auto &num_of_course : course){
        for(auto &substr_map : substr_maps[num_of_course]){
            if(substr_map.second == max_count[num_of_course] && max_count[num_of_course] >= 2)
                answer.push_back(substr_map.first);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}