#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    int num, i, flag = 0, cnt=0, sixNine=0, maxCount=0;
    int room[10] = {};
    string roomNum;
    cin >> roomNum;

    for(i=0; i<roomNum.size(); i++){
        num = roomNum[i] - 48;
        if(num == 6 || num == 9){
            sixNine += 1;
            continue;
        }
        room[num] += 1;
    }

    room[6] = ceil(double(sixNine) / 2);

    for(i=0; i<10; i++){
       if(maxCount < room[i])
            maxCount = room[i];
    }


    cout << maxCount;

    return 0;
}
