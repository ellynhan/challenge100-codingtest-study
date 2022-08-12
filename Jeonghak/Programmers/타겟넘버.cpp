#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int currValue, int depth){
    if(depth == numbers.size()-1){
        if(target == currValue){
            answer++;
        }
        return;
    }
    
    dfs(numbers, target, currValue + numbers[depth+1], depth+1);
    dfs(numbers, target, currValue - numbers[depth+1], depth+1);
}    


int solution(vector<int> numbers, int target) {    
    dfs(numbers, target, numbers[0], 0);
    dfs(numbers, target, -numbers[0], 0);
    return answer;
}