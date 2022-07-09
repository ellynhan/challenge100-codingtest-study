#include<iostream>
#include<algorithm>

using namespace std;
int N, M;
int* input_arr;
int* output_arr;
int* visit;

void dfs(int depth)
{
    if(depth == N){
        for(int i=0; i<N; i++) 
            cout << output_arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0; i<M; i++){
        if(!visit[i]){
            output_arr[depth] = input_arr[i];
            visit[i] = true;
            dfs(depth+1);
            visit[i] = false;
        }
    }
}
int main()
{
    cin >> M >> N;
    input_arr = new int[M];
    output_arr = new int[M];
    visit = new int[M];
    for(int i=0; i<M; i++) cin >> input_arr[i];
    sort(input_arr, input_arr+M);

    dfs(0);
    delete[] output_arr;
    delete[] input_arr;
    delete[] visit;
}