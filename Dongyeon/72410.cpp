#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    //1단계
    for(int i=0 ; i < new_id.length() ; i ++){
        new_id[i] = tolower(new_id[i]);
    }
    cout << new_id << endl;
    //2단계
    for(int i = 0; i < new_id.length(); ) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || (new_id[i] == '-') || (new_id[i] == '_') || (new_id[i] == '.'))
        {
            i++;
            continue;
        }
        new_id.erase(new_id.begin() + i);
    }
    cout << new_id << endl;
    //3단계
    for(int i=0 ; i < new_id.length()-1 ; ){
        if ((new_id[i] == '.') && (new_id[i+1] =='.')){
            new_id.erase(new_id.begin() + i);
            continue;
        }
        i++;
    }
    cout << new_id << endl;
    //4단계
    if (new_id[0] == '.') new_id.erase(new_id.begin());
    if (new_id[new_id.length()-1] == '.') new_id.erase(new_id.end()-1);
    //5단계
    if (new_id.length() == 0) new_id = 'a';
    cout << new_id << endl;
    //6단계
    if (new_id.length() >=16){
        while( new_id.length() >15){
            new_id.erase(new_id.begin() + 15);
        }
    }
    if (new_id[new_id.length()-1] == '.') new_id.erase(new_id.end()-1);
    cout << new_id << endl;
    //7단계
    while (new_id.length() <= 2){
        new_id += new_id.back();
    }
    
    cout << new_id << endl;
    answer = new_id;
    return answer;
}
