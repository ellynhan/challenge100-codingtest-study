#include <bits/stdc++.h>

using namespace std;

int **paper;
int n;

int count_n[3] = {0,};

void solve(int y, int x, int size)
{
    int number = paper[y][x];
    bool all_same = true;
    for(int i=y; i<y+size; i++)
    {
        for(int j=x; j<x+size; j++)
        {
            if(paper[i][j] != number){
                all_same = false;
                break;
            }
        }
    }

    if(!all_same){
        for (int i = y; i < y+size; i+=size/3)
        {
            for (int j = x; j < x+size; j += size / 3)
            {
                solve(i,j,size/3);
            }
        }
    }
    else{
        count_n[1+number] ++;
    }

}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> n;
    
    // 입력받아 2차원배열에 저장
    paper = new int*[n];
    for(int i=0; i<n; i++)
    {
        paper[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> t;
            paper[i][j] = t;
        }
    }

    solve(0,0,n);

    for(int i=0; i<3; i++)
        cout << count_n[i] << '\n';

    return 0;
}