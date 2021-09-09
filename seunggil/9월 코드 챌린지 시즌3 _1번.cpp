#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int,int> result;
int solution(vector<int> numbers) {
    for(int i : numbers)
        result[i]++;
    
    int answer = 0;
    for(int i = 0; i <10; i++)
        if(result[i] == 0)
            answer += i;
    
    return answer;
}