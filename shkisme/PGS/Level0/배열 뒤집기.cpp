#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    for (auto iter = num_list.rbegin(); iter != num_list.rend(); iter++){
        answer.push_back(*iter);
    }
    return answer;
}
