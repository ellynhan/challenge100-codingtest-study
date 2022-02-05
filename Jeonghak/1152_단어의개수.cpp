#include <iostream>
#include <vector>

using namespace std;

int main(){
    int count=0;
    string stat;
    getline(cin, stat, '\n');
    if((stat.size() == 0) || (stat.size() == 1 && stat[0]==' ')){
        cout<<0;
        return 0;
    }
    for(int i=1; i<stat.size()-1; i++){
        if(stat[i] == ' ' && stat[i-1]!= ' ' && stat[i+1] != ' ')
            count++;
    } 
    cout << count+1;
}
