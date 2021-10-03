#include <bits/stdc++.h>

using namespace std;

int n;
bool **v;
string *maps;
int total_jar_count = 0;
vector<int> jar_count;

int solve(int y, int x)
{
    int jar_count = 0;
    if(x < 0 || y < 0 || x >= n || y >= n || v[y][x] || maps[y][x] == '0')
        return jar_count;

    jar_count ++;
    v[y][x] = true;
    jar_count += solve(y + 1, x);
    jar_count += solve(y, x + 1);
    jar_count += solve(y - 1, x);
    jar_count += solve(y, x - 1);

    return jar_count;
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    v = new bool*[n];
    maps = new string[n];

    for(int i=0; i<n; i++)
    {
        v[i] = new bool[n];
        memset(v[i], false, sizeof(bool) * n);
        cin >> maps[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int tmp = solve(i, j);
            if(tmp > 0) {
                jar_count.push_back(tmp);
                total_jar_count ++;
            }
        }
    }
    cout << total_jar_count << '\n';
    sort(jar_count.begin(), jar_count.end());

    for(int i=0; i<jar_count.size(); i++)
    {
        cout << jar_count[i] << '\n';
    }

    return 0;
}