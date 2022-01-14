
/*
    그리디 알고리즘.
*/

#include <iostream>

using namespace std;

int main()
{
    long long small_num, big_num;
    int cnt = 0;

    cin >> small_num >> big_num;
    if( small_num >=1 && small_num < big_num && big_num <= 1000000000){
    while(1){

        if(small_num > big_num ){
            cout << -1 << '\n';
            break;
        }
        if(small_num == big_num){
            cout << cnt + 1 << '\n';
            break;
        }

        if(big_num % 10 == 1){
            big_num = big_num/10;

        }
        else if(big_num % 2 == 0){
            big_num = big_num/2;

        }
        else{
            cout <<"-1" << '\n';
            break;
        }
        cnt++;

    }
    }
    return 0;
}
