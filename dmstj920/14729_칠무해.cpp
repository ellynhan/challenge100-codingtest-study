#include <iostream>
#include <algorithm>
#define MAX 10000000

using namespace std;

double score[MAX];

int main()
{
    int num, i;
    cin >> num;

    for(i=0; i<num; i++){
        cin >> score[i];
    }

    sort(score, score+num);

    for(i=0; i<7; i++){
        cout.setf(ios::fixed);
        cout.precision(3);
        cout << score[i] << "\n";
    }

    return 0;
}
