#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int num, len, i;
    int fruit[1000];

    cin >> num >> len;

    for(i=0; i<num; i++){
        cin >> fruit[i];
    }

    sort(fruit, fruit+num);

    for(i=0; i<num; i++){
        if(fruit[i] <= len)
            len += 1;

        else break;
    }

    cout << len;

    return 0;
}
