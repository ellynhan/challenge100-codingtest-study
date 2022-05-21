#include <bits/stdc++.h>
using namespace std;
#define NUM 26

int alphabets[NUM];

int main()
{
    string word;
    int cnt=0, result=0, idx=0;
    cin >> word;
    transform(word.begin(), word.end(), word.begin(), ::toupper);

    for(int i=0; i<word.size(); i++)
    {
        alphabets[word[i]-'A']++;
    }
    for(int i=0; i<NUM; i++){
        if(result < alphabets[i]){
            result = alphabets[i];
            cnt=0;
            idx=i;
        }
        if(result == alphabets[i]) cnt++;
    }
    if(cnt > 1) cout << '?';
    else cout<< (char)(idx + 'A');
}
