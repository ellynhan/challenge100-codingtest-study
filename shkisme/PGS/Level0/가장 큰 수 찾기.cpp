#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;

    auto iter = max_element(array.begin(), array.end());

    int index = 0;
    for(int a : array){
        if (a == (*iter)){
            answer.push_back(a);
            answer.push_back(index);
        }
        index++;
    }

    return answer;
}
