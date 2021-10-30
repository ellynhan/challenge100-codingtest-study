#include <bits/stdc++.h>

using namespace std;

class P
{
public:
    P(int _z, int _y, int _x)
        : z(_z), y(_y), x(_x)
    {
    }
    P(const P &p)
        : x(p.x), y(p.y), z(p.z)
    {
    }
    int x;
    int y;
    int z;
};

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dx[6] = {-1, 1, 0, 0, 0, 0};
    int dy[6] = {0, 0, -1, 1, 0, 0};
    int dz[6] = {0, 0, 0, 0, -1, 1};

    int ***tomato;
    int n, m, h;
    int res = 0;
    bool is_full = true;
    queue<P> q;
    P p_tmp = P(0,0,0);

    cin >> m >> n >> h;
    tomato = new int **[h];

    for (int i = 0; i < h; i++)
    {
        tomato[i] = new int*[n];
        for (int j = 0; j < n; j++) {
            tomato[i][j] = new int[m];
            for(int k=0; k<m; k++) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) {
                    q.push(P(i,j,k));
                }
            }
        }
    }

    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            p_tmp = q.front();
            q.pop();

            for(int j=0; j<6; j++)
            {
                int x = p_tmp.x+dx[j];
                int y = p_tmp.y+dy[j];
                int z = p_tmp.z+dz[j];

                if (x >= 0 && y >= 0 && z >= 0 && x < m && y < n && z < h) {
                    if(tomato[z][y][x] == 0) {
                        tomato[z][y][x] = 1;
                        q.push(P(z, y, x));
                    }
                }
            }
        }
        res ++;
    }

    for (int i = 0; i < h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                if(tomato[i][j][k] == 0){
                    is_full = false;
                    break;
                }
            }
        }
    }
    if(is_full)
        cout << res-1 << '\n';
    else
        cout << -1 << '\n';
    return 0;
}
