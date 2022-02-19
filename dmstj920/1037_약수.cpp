#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int num, i;
    int divisor[50];

    cin >> num;

    for(int i=0; i<num; i++){
        cin >> divisor[i];
    }

    if(num == 1){
        cout << divisor[0] * divisor[0];
    }
    else{
        sort(divisor, divisor+num);
        cout << divisor[0] * divisor[num-1];
    }


    return 0;
}
