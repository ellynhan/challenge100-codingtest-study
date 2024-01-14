#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    int N = board.size();
    int M = board[0].size();
    
    vector<stack<int>> v;
    for(int j = 0; j < M; j++){
        stack<int> s;
        for(int i = N-1; i >= 0; i--){
            if(board[i][j] > 0) s.push(board[i][j]);
        }
        v.push_back(s);
    }
    
    stack<int> result;
    for(int i = 0; i < moves.size(); i++){
        int m = moves[i]-1;
        if(v[m].empty()) continue;
        
        if(result.empty()) result.push(v[m].top());
        else{
            if(result.top() == v[m].top()){
                result.pop();
                answer += 2;
            }
            else result.push(v[m].top());
        }
        v[m].pop();
    }
    
    return answer;
}
