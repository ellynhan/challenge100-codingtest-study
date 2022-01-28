#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{

    int noHear, noSee, i, j, cnt=0;
    string noSeeName, noHearName;
    cin >> noHear >> noSee;

    vector<string> noHearList;
    vector<string> noHearSeeList;

    for(i=0; i<noHear; i++){
        cin >> noHearName;
        noHearList.push_back(noHearName);
    }

    sort(noHearList.begin(), noHearList.end());

    for(j=0; j<noSee; j++){
        cin >> noSeeName;

        if(binary_search(noHearList.begin(), noHearList.end(), noSeeName)){
            noHearSeeList.push_back(noSeeName);
        }
    }

    sort(noHearSeeList.begin(), noHearSeeList.end());

    cout << noHearSeeList.size() << '\n';
    for(i=0; i<noHearSeeList.size(); i++){
        cout << noHearSeeList[i] << '\n';
    }

    return 0;
}
