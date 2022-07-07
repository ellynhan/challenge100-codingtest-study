#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100000000
#define MIN -100000000

using namespace std;
int N, min_result = MAX, max_result=MIN;
int OP[4];
int sequence[100];
vector<int> op_sequence;

void Input()
{
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> sequence[i];
    }
    for(int i=0; i<4; i++){
        cin >> OP[i];
        for(int j=0; j<OP[i]; j++)
            op_sequence.push_back(i);
    }
}

void Operation()
{
    int result = sequence[0];
    for(int i=0; i<N-1; i++){
        switch(op_sequence[i]){
            case 0: 
                result += sequence[i+1];
                break;
            case 1:
                result -= sequence[i+1];
                break;
            case 2:
                result *= sequence[i+1];
                break;
            case 3:
                result /= sequence[i+1];
                break;
        }
    }
    min_result = min(min_result, result);
    max_result = max(max_result, result);
}

void Solve()
{
    do {
        for(auto it = op_sequence.begin(); it != op_sequence.end(); ++it){
            Operation();
        }
    }while(next_permutation(op_sequence.begin(), op_sequence.end()));
}

int main(){
    Input();
    Solve();
    cout << max_result << " " << min_result;
}