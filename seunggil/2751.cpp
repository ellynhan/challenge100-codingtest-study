#include <cstdio>
#include <list>

using namespace std;

int main(void){
    int n, num;
    list<int> inputData;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        inputData.push_back(num);
    }
    
    inputData.sort();
    
    for(int i : inputData){
        printf("%d\n", i);
    }
    
    return 0;
}