#include<iostream>
#define MAX 100000000
#define MIN -100000000

using namespace std;

int N, min_result = MAX, max_result=MIN;
int operators[4];
int sequence[100];

void Input()
{
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> sequence[i];
    }
    for(int i=0; i<4; i++){
        cin >> operators[i];
    }
}

void Solve(int result, int idx)
{
    if(idx == N){
        min_result = min(min_result, result);
        max_result = max(max_result, result);
        return;
    }

    for(int i=0; i<4; i++){
        if(operators[i] > 0){
            operators[i]--;
            switch(i){
                case 0: 
                    Solve(result + sequence[idx], idx + 1);
                    break;
                case 1:
                    Solve(result - sequence[idx], idx + 1);
                    break;
                case 2:
                    Solve(result * sequence[idx], idx + 1);
                    break;
                case 3:
                    Solve(result / sequence[idx], idx + 1);
                    break;
            }
            operators[i]++;
        }
    }
}

int main(){
    Input();
    Solve(sequence[0], 1);
    cout << max_result << " " << min_result;
}