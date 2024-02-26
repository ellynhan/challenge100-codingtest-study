#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(int a : arr){
        if(a % divisor == 0) answer.push_back(a);
    }
    if(answer.empty()) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    return answer;
}
