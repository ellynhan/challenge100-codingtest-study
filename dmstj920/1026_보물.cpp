#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    return a > b;
}

int main()
{
    int num, i, res=0;
    int a[50];
    int b[50];
    cin >> num;

    for(i=0; i<num; i++)
        cin >> a[i];

    for(i=0; i<num; i++)
        cin >> b[i];

    sort(a, a+num);
    sort(b, b+num, desc);

    for(i=0; i<num; i++)
        res += a[i] * b[i];


    cout << res;

    return 0;
}
