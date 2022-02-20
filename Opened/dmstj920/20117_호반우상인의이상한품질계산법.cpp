#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int i,num, price, itemNum, sum=0;
    vector<int> item;

    cin >> num;

    for(i=0; i<num; i++){
        cin >> price;
        item.push_back(price);
    }

    sort(item.begin(), item.end());

    if(num % 2 == 1)
        itemNum = num / 2 + 1;
    else
        itemNum = num / 2;

        
    for(i=num-1; i>=itemNum; i--)
        sum += item[i] * 2;
    
    if(num % 2 == 1)
        sum += item[i];

    cout << sum;

    return 0;
}
