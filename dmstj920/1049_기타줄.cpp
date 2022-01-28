#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int guitar, num, setPrice, indiPrice, price, i;
    vector<int> setGuitar;
    vector<int> indiGuitar;

    cin >> guitar >> num;

    for(i=0; i<num; i++){
        cin >> setPrice >> indiPrice;
        setGuitar.push_back(setPrice);
        indiGuitar.push_back(indiPrice);
    }

    sort(setGuitar.begin(), setGuitar.end());
    sort(indiGuitar.begin(), indiGuitar.end());

    if(guitar <= 6)
        price = min(setGuitar.front(), indiGuitar.front() * guitar);

    else
        price = ((guitar/6) * min(setGuitar.front(), indiGuitar.front() * 6))
                    + min(setGuitar.front(), (guitar - (6 * (guitar/6))) * indiGuitar.front());


    cout << price;

    return 0;
}
