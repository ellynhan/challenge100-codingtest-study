#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Word{
    string word;
    int len;
};

bool cmp(Word &a, Word &b){
    if(a.len == b.len)
        return a.word < b.word;

    return a.len < b.len;
}

int main()
{
    int num, i;
    string alpha, chk;

    Word wordList;
    vector<Word> v;

    cin >> num;

    for(i=0; i<num; i++){
        cin >> alpha;
        wordList.word = alpha;
        wordList.len = alpha.size();

        v.push_back(wordList);
    }


    sort(v.begin(), v.end(), cmp);

    for(i=0; i<num; i++){
        if(chk == v[i].word){
            continue;
        }

        else{
            cout << v[i].word << "\n";
            chk = v[i].word;
        }

    }

    return 0;
}
