#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int& a, int& b){
    return a > b;
}

int main()
{
    int num, i, max, chk;
    int rope[100000]={0,};

    cin >> num;

    for(i=0; i<num; i++)
        cin >> rope[i];

    sort(rope, rope+num, cmp);
    max = 0;

    for(i=0; i<num; i++){
        chk = rope[i] * (i+1);

        if(max < chk) max = chk;
    }

    cout << max;

    return 0;
}
