#include <string>
#include <vector>

using namespace std;

int cumulative_sum [1002][1002];

void makeCumulativeSum(int type, int r1, int c1, int r2, int c2, int degree){
    if(type == 1) degree = -degree;
    
    cumulative_sum[r1][c1] += degree;
    cumulative_sum[r1][c2 + 1] -= degree;
    cumulative_sum[r2 + 1][c1] -= degree;
    cumulative_sum[r2 + 1][c2 + 1] += degree;

}

int solution(vector<vector<int>> board, vector<vector<int>> skills) {
    int answer = 0;
    int row_size = board.size(), col_size = board[0].size();
    
    for(auto &skill : skills){
        makeCumulativeSum(skill[0], skill[1], skill[2], skill[3], skill[4], skill[5]);
    }
    
    for(int i=0; i<row_size + 1; i++){
        for(int j=0; j<col_size + 1; j++){
            cumulative_sum[i+1][j] += cumulative_sum[i][j];
        }
    }
    
    for(int i=0; i<row_size + 1; i++){
        for(int j=0; j<col_size + 1; j++){
            cumulative_sum[i][j+1] += cumulative_sum[i][j];
        }
    }
    
    for(int i=0; i<row_size; i++){
        for(int j=0; j<col_size; j++){
            if(board[i][j] + cumulative_sum[i][j] > 0)
                answer++;
        }
    }
    
    return answer;
}