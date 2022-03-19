#include <iostream>

using namespace std;

int main()
{
    int num, cnt=99, first, second, third;
    cin >> num;

    if(num <= 99){
        cout << num;
    }

    else{
        for(int i=100; i<=num; i++){
            first = i/100;
            second = (i/10) % 10;
            third = i % 10;

            if((first - second) == (second - third))
                cnt += 1;
        }

        cout << cnt;
    }

    return 0;
}
