#include <iostream>

using namespace std;

char treeStruct[150];

void input(void);
int solve(void);
int getMaxDepth(void);

int main(void)
{
    int testCase;

    cin >> testCase;
    cin.ignore(4,'\n');

    for (int i = 0; i < testCase; i++)
    {
        input();
        cout << solve() << endl;
    }
}

void input(void)
{
    cin.getline(treeStruct,150,'\n');
}

int solve(void){
    return (1 << getMaxDepth());
}

int getMaxDepth(void)
{
    int i = 0;
    int maxDepth = 0;
    int depth = 0;
    while(treeStruct[i] != '\0'){
        
        if(treeStruct[i] == '[')
            depth++;
        
        if(treeStruct[i] == ']')
            depth--;
        
        maxDepth = max(depth,maxDepth);

        i++;
    }

    return maxDepth;
}