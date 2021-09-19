#include <bits/stdc++.h>

using namespace std;

string *movie;

void solve(int y, int x, int size)
{
    bool bAllSame = true;
    char firstCell = movie[y][x];
    for(int i=y; i<y+size; i++)
    {
        for(int j = x; j<x+size; j++)
        {
            if(movie[i][j] != firstCell){
                bAllSame = false;
                break;
            }
        }
    }
    
    if(bAllSame)
        cout << firstCell;
    else
    {
        cout << '(';
        for (int i = y; i < y + size; i+=size/2)
        {
            for (int j = x; j < x + size; j += size / 2)
            {
                solve(i,j,size/2);
            }
        }
        cout << ')';
    }
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    movie = new string[n];

    for(int i=0; i<n; i++)
        cin >> movie[i];

    solve(0,0,n);
    cout << '\n';
    return 0;
}