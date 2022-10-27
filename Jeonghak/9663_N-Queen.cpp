#include<iostream>
#include<vector>

using namespace std;
int column[15];
int N, answer;

bool isPromising(int curr_col)
{
    for(int k = 0;  k < curr_col; k++)
    {
        if(column[curr_col] == column[k] || abs(column[curr_col] - column[k]) == curr_col-k)
            return false;
    }
    return true;
}

void Queens(int curr_col)
{
    if(curr_col == N) answer++;
    else{
        for(int i=0; i<N; i++){
            column[curr_col] = i;
            if(isPromising(curr_col))
                Queens(curr_col+1);
        }
    }
}

int main()
{
    cin >> N;
    Queens(0);
    cout << answer;
}