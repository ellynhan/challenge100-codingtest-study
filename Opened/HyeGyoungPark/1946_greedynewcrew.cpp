#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int>> person;
vector <int> score;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,num,doc,speech,ans;

    cin >> t;

    while(t>0){
        cin >> num;
        ans = 1;

        for(int i=0; i<num; i++){
            cin >> doc >> speech;
            score.push_back(doc);
            score.push_back(speech);
            person.push_back(score);
            score.clear();
        }

        sort(person.begin(),person.end());

        int standard = person[0][1];

        for(int i=1; i<num; i++){
            if(person[i][1]<standard){
                ans++;
                standard = person[i][1];
            }
        }

        cout << ans << "\n";

        person.clear();
        t--;
    }

    return 0;
}
