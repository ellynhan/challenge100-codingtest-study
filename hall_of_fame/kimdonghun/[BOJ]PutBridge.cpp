#include <iostream>

using namespace std;

int T;

long long num[30][30];

long long binomial(int n, int k) {

    if (num[n][k] > 0) return num[n][k];
    if(n == k || k == 0) {
        return num[n][k] = 1;
    }

    return num[n][k] = binomial(n-1, k) + binomial(n-1, k-1);
}


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// ******* INPUT *******
	cin >> T;

	int N;
    int M;

	// ******* PROCESS *******
	for(int i = 0; i < T; i++) {
        cin >> N;
        cin >> M;


        long long res = binomial(M,N) ;

        // ******* OUTPUT *******
        cout << res << "\n";
	}

	return 0;
}
