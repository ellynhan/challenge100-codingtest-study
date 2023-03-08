#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    if (direction == "right"){
        answer.push_back(numbers.at(numbers.size()-1));
        for (auto iter = numbers.begin(); iter != numbers.end() - 1; iter++){
            answer.push_back(*iter);
        }
    }
    else{
        answer = {numbers.begin() + 1, numbers.end()};
        answer.push_back(numbers.at(0));
    }
    return answer;
}
