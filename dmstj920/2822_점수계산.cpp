#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Quiz{
    int score;
    int num;
};

bool cmp(const Quiz& a, const Quiz& b){
    if(a.score == b.score)
        return a.num < b.num;
    return a.score > b.score;
}

int main()
{
    vector<Quiz> v;
    Quiz quiz;
    int i, total=0;
    int sortNum[5];

    for(i=0; i<8; i++){
        cin >> quiz.score;
        quiz.num = i+1;

        v.push_back(quiz);
    }

    sort(v.begin(), v.end(), cmp);

    for(i=0; i<5; i++){
        total += v[i].score;
        sortNum[i] = v[i].num;
    }

    sort(sortNum, sortNum+5);

    cout << total << "\n";
    for(i=0; i<5; i++){
        cout << sortNum[i] << " ";
    }


    return 0;
}
