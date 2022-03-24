#include<iostream>
#include<vector>
using namespace std;
int N, adj_mat[101][101];
void Input()
{
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N; j++){
            cin >> adj_mat[i][j];
        }
    }
}

void Solve()
{
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(adj_mat[i][k] && adj_mat[k][j])
                    adj_mat[i][j] = 1;
            }
        }
    }
}

void Output()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N; j++)
        {
            cout << adj_mat[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    Input();
    Solve();
    Output();
}