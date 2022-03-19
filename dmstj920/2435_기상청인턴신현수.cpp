#include <iostream>

using namespace std;

int main()
{
    int num, day, max=-400, sum=0, i, j;
    int temp[100]={0,};

    cin >> num >> day;

    for(i=0; i<num; i++)
        cin >> temp[i];

    for(i=0; i<=num-day; i++){
        sum = 0;
        for(j=i; j<i+day; j++){
            sum += temp[j];
        }

        if(max < sum) max = sum;
    }

    cout << max;

    return 0;
}
