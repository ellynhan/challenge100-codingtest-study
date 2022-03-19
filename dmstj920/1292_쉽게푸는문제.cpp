#include <iostream>

using namespace std;

int main()
{
    int n=1, i, first, last, cnt=0, sum=0;
    int num[1000];

    cin >> first >> last;

    for(i=1; i<=last; i++){
        num[i] = n;
        cnt += 1;

        if(cnt == n){
            n += 1;
            cnt = 0;
        }
    }

    for(i=first; i<=last; i++){
        sum += num[i];
    }

    cout << sum;
    return 0;
}
