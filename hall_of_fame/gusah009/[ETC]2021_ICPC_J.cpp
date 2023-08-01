#include <iostream> 
#include <bits/stdc++.h> 
#define MAX 301
/*
    단축키 

    ctrl+shft+B     : compile / execute 
    F5              : mingw/bin/gdb.exe debugging 
*/

//team066
//pyy7yp6r 

using namespace std; 

int M, N;
int land[MAX][MAX] = {0};
int acc[MAX][MAX] = {0};
int ans = 0;

int get_cost(int m, int d, int r) {
    int cost;
    if (m==0) {
        cost = acc[d][r];
    } else {
        cost = acc[d][r] - acc[m-1][r];
    }
    // cout << "add: " << cost << endl;
    return cost;
}

int find_down(int m, int n) {
    int d = 0;
    for (d=m; d<M; ++d) {
        int cost = get_cost(m, d, n);

        if (cost == 10) {
            ans += 1;
            // cout << m << " " << n << " " << d << " " << n <<endl;
            d -= 1;
            return d;
        } else if (cost > 10) {
            d -= 1;
            return d;
        }
    }
    d = M-1;
    return d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    
    cin >> M >> N;
    for (int m=0; m<M; ++m) {
        for (int n=0; n<N; ++n) {
            cin >> land[m][n];
        }
    }

    for (int n=0; n<N; ++n) {
        acc[0][n] = land[0][n];
    }
    for (int m=1; m<M; ++m) {
        for (int n=0; n<N; ++n) {
            acc[m][n] = acc[m-1][n] + land[m][n];
        }
    }
    
    // for (int m=0; m<M; ++m) {
    //     for (int n=0; n<N; ++n) {
    //         cout << acc[m][n] << " ";
    //     }
    //     cout << endl;
    // }

    for (int m=0; m<M; ++m) {
        for (int n=0; n<N; ++n) {
            // Down
            int d = find_down(m, n);
            // cout << d << " ";
            if (d == -1) {
                continue;
            }

            // Right
            for(int j=d; j>=m; --j) {
                // cout << "j: " << j << endl;
                int cost = 0;
                for(int r=n; r<N; ++r) {
                    // cout << "r: " << r << endl;
                    cost += get_cost(m, j, r);
                    // cout << "cost: " << cost << endl;
                    
                    if (cost == 10) {
                        ans += 1;
                        // cout << m << " " << n << " " << j << " " << r << endl;
                        break;
                    } else if (cost > 10) {
                        break;
                    }
                }
            }
        }
        // cout << endl;
    }

    cout << ans;
    return 0; 
}

