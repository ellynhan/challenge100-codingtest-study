#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> answer;
    
    for(int i = 0; i < numbers.size() - 1; i++)
        for(int j = i + 1; j < numbers.size(); j++)
            answer.insert(numbers[i] + numbers[j]);
    
    vector<int> result(answer.size());
    copy(answer.begin(), answer.end(), result.begin());
    
    return result;
}