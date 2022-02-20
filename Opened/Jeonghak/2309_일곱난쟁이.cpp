#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 9
using namespace std;

int main(void)
{
    vector<int> dwarfs;
    int sum=0, answer;
    for(int i=0; i<SIZE; i++)
    {
        int a;
        cin >> a;
        dwarfs.push_back(a);
        sum += a;
    }
    sort(dwarfs.begin(), dwarfs.end());

    for(int i=0; i<SIZE-1; i++)
    {
        for(int j=i+1; j<SIZE; j++)
        {
            answer = sum - dwarfs[i] - dwarfs[j];
            if(answer == 100){
                dwarfs[i] = dwarfs[j] = -1;
                break;
            }
        }
        if(answer == 100) break;    
    }
    for(int i=0; i < dwarfs.size(); i++)
        if(dwarfs[i]>=0)
            cout << dwarfs[i] << "\n";
    return 0;
}
