#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    stack<int> s;
    stack<int> tmp;
    // 1 2 3 1
    vector<int> need = {1, 3, 2, 1};
    for(int i = 0; i < ingredient.size(); i++){
        s.push(ingredient[i]);
        if(s.size() >= 4 && s.top() == need[0]){
            bool isPerfect = false;
            for(int p = 0; p < need.size(); p++){
                if(s.top() == need[p]){
                    tmp.push(s.top()); // 햄버거 완성이 아닐 때를 대비해서
                    s.pop();
                    if(p == need.size() - 1) isPerfect = true;
                }
                else{
                    break;
                }
            }
            while(!tmp.empty()){
                if(!isPerfect) s.push(tmp.top());
                tmp.pop();
            }
            if(isPerfect) answer++;
        }
    }
    
    
    return answer;
}
