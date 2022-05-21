#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string word, suffix="";
    string suffixList[1000];
    int len, i, j;

    cin >> word;

    len = word.length();

    for(i=0; i<len; i++){
        for(j=i; j<len; j++)
            suffix += word[j];

        suffixList[i] = suffix;
        suffix = "";
    }

    sort(suffixList, suffixList+len);

    for(i=0; i<len; i++){
        cout << suffixList[i] << "\n";
    }


    return 0;
}
