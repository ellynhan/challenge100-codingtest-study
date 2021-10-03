#include <bits/stdc++.h>

using namespace std;

int **paper;
int n;
int res_white = 0;
int res_blue = 0;

void solve(int y, int x, int size)
{
    int first = paper[y][x];
    bool is_same = true;
    for(int i=y; i<y+size; i++)
    {
        for (int j = x; j < x + size; j ++)
        {
            if(paper[i][j] != first){
                is_same = false;
            }
        }
        if(!is_same)
            break;
    }

    if(!is_same)
    {
        solve(y, x + size / 2, size / 2);
        solve(y + size / 2, x, size / 2);
        solve(y + size / 2, x + size / 2, size / 2);
        solve(y, x, size / 2);
    }
    else{
        if(first == 1){
            res_blue ++;
        }
        else{
            res_white ++;
        }
    }
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    paper = new int*[n];
    for(int i=0; i<n; i++)
    {
        paper[i] = new int[n];
        for(int j=0; j<n; j++)
            cin >> paper[i][j];
    }

    solve(0,0,n);
    cout << res_white << '\n' << res_blue << '\n';

    return 0;
}
