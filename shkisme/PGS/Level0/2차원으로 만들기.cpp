#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    vector<int> save;
    for (int i = 0; i < num_list.size(); i++){
        save.push_back(num_list.at(i));
        if ((i+1) % n == 0){
            answer.push_back(save);
            save.clear();
        }
    }
    
    return answer;
}
