#include <string>
#include <vector>

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 6

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int minimum = 0;
    vector<int> answer;
    FOR(i, MAX) {
        FOR(j, MAX) {
            if (lottos[i] == win_nums[j]) minimum++;
        }
    }
    
    int maximum = minimum;
    FOR(i, MAX) {
        if (lottos[i] == 0) maximum++;
    }
    
    if (maximum >= 2) {
        answer.push_back(7 - maximum);
    } else {
        answer.push_back(6);
    }
    
    if (minimum >= 2) {
        answer.push_back(7 - minimum);
    } else {
        answer.push_back(6);
    }
    return answer;
}