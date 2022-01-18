#include <iostream>

using namespace std;
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main(void)
{
    int T;
    cin >> T;

    while(T--){
        int N, M, x, y, year=0;
        cin >> M >> N >> x >> y;
        int i=0;
        int max_year = M*N/gcd(M, N);
        int currY;
        while(i<=max_year){
            if((i+x)%N==0)
                currY = N;
            else
                currY = (i+x)%N;

            if(currY==y){
                cout << i+x << '\n';
                break;
            }
            i+=M;
        }
        if(i > max_year) cout << -1 << '\n';
    }
    return 0;
}
