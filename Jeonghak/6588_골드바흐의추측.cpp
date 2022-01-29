#include<iostream>
#include<cmath>
#define MAX 1000000
using namespace std;

int prime[MAX];

void init()
{
    fill_n(prime, MAX, true);
    prime[0] = prime[1] = false;
    for(int i=2; i<sqrt(MAX); i++)
        if(prime[i] == true)
            for(int j=i*2; j<MAX; j+=i) prime[j] = false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    init();
    while ((cin >> N) && (N != 0))
    {
        int a, b;
        for(int i=3; i<=N; i++){
            if(prime[i] == true)
                b = N - i;
            if(prime[b] == true)
            {
                a = i;
                break;
            }
        }
        cout << N << " = " << a << " + " << b << "\n";
    }
    return 0;
}
