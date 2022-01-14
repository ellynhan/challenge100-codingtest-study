#include <iostream>

using namespace std;

int main(void) {

    int n,m, i, j, ans;

    cin >> n >> m;

    long long** mat = (long long**)malloc(sizeof(long long*) * n);

    for(i=0; i<n; i++){
    	mat[i] = (long long*)malloc(sizeof(long long) * m );
	}

    for(i=0; i<n; i++){
    	mat[i][0] = 1;
        for(j=0; j<m; j++){
            mat[0][j] = 1;
            
            if(i>0 && j>0){
            	mat[i][j] = (mat[i-1][j] + mat[i][j-1] + mat[i-1][j-1])%1000000007;
			}
        }
    }

    ans = mat[n-1][m-1];

    cout << ans;

	for(i=0; i<m; i++){
		free(mat[i]);
	}

	free(mat);

    return 0;
}
