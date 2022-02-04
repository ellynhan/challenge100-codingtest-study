#include <bits/stdc++.h>

using namespace std;
int total_count = 0;
int cow_count = 0;
vector<string> area;
bool **v;
bool **cow_v;
int n;

void findArea(int y, int x, char color, bool is_first)
{
    if( x < 0 || y < 0 || x >= n || y >= n 
        || v[y][x] || area[y][x] != color ) {
        return;
    }
    v[y][x] = true;
    if( is_first ) 
        total_count ++;
    findArea(y+1, x, color, false);
    findArea(y, x+1, color, false);
    findArea(y-1, x, color, false);
    findArea(y, x-1, color, false);
}

void findAreaCow(int y, int x, char color, bool is_first)
{
    if( x < 0 || y < 0 || x >= n || y >= n )
        return;
    if( (color == 'R' || color == 'G') 
        && (area[y][x] == 'R' || area[y][x] == 'G') ) {
            color = area[y][x];
        }
    if( cow_v[y][x] || area[y][x] != color ) {
        return;
    }
    cow_v[y][x] = true;
    if( is_first ) 
        cow_count ++;
    findAreaCow(y+1, x, color, false);
    findAreaCow(y, x+1, color, false);
    findAreaCow(y-1, x, color, false);
    findAreaCow(y, x-1, color, false);
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    cin >> n;

    v = new bool*[n];
    cow_v = new bool*[n];
    for( int i=0; i<n; i++ ) {
        cin >> s;
        area.push_back(s);

        v[i] = new bool[n];
        memset(v[i], 0, n);
        cow_v[i] = new bool[n];
        memset(cow_v[i], 0, n);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            findArea(i,j,area[i][j], true);
            findAreaCow(i,j,area[i][j], true);
        }
    }
    
    cout << total_count << " " << cow_count << endl;

    return 0;
}