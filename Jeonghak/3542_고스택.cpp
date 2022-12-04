#include<iostream>
#include<vector>
#include<queue>
#define INTMAX 1000000000

using namespace std;
vector<long long> goStack;
vector<string> instructions;
vector<long long> numbers;
int numCnt = 0;

bool Excute(string instruction){
    long long first;
    if(instruction == "NUM"){
        goStack.push_back(numbers[numCnt++]);
    }
    else if(instruction == "INV"){
        if(goStack.empty()){
            return true;
        }
        goStack.back() = -goStack.back();
    }
    else if(instruction == "POP"){
        if(goStack.empty()){
            return true;
        }
        goStack.pop_back();
    }
    else if(instruction == "DUP"){
        if(goStack.empty()){
            return true;
        }
        goStack.push_back(goStack.back());
    }
    else if(instruction == "SWP"){
        if(goStack.empty()){
            return true;
        }
        long long x = goStack.back();
        goStack.pop_back();

        if(goStack.empty())
            return true;
        long long y = goStack.back();
        goStack.pop_back();

        goStack.push_back(x);
        goStack.push_back(y);
    }
    else if(instruction == "ADD"){
        if(goStack.empty()){
            return true;
        }
        first = goStack.back();
        goStack.pop_back();
        if(goStack.empty())
            return true;
        long long result = first + goStack.back();
        goStack.back() = result;
    }    
    else if(instruction == "SUB"){
        if(goStack.empty()){
            return true;
        }
        first = goStack.back();
        goStack.pop_back();
        if(goStack.empty())
            return true;
        long long result = goStack.back() - first;
        goStack.back() = result;
    }    
    else if(instruction == "MUL"){
        first = goStack.back();
        goStack.pop_back();
        if(goStack.empty())
            return true;
        long long result = first * goStack.back();
        goStack.back() = result;
        return false;
    }
    else if(instruction == "DIV"){
        if(goStack.empty()){
            return true;
        }
        first = goStack.back();
        goStack.pop_back(); 
        if(goStack.empty())
            return true;       
        if(first == 0) return true; 
        long long result = abs(goStack.back()) / abs(first) ;
        if(first > 0 && goStack.back() <0 || first < 0 && goStack.back() > 0)
            result = -result;
        goStack.back() = result;
    }
    else if(instruction == "MOD"){
        if(goStack.empty()){
            return true;
        }
        first = goStack.back();
        goStack.pop_back();
        if(goStack.empty())
            return true;
        if(first == 0) return true; 
        long long result = goStack.back() % first;
        if(goStack.back() < 0){
            result = -abs(result);
        }else{
            result = abs(result);
        }
        goStack.back() = result;
    }
    return false;
}   

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
    while(true){
        string instruction;
        int N = 0;
        long long V = 0, num = 0;
        while(true){
            cin >> instruction;
            if(instruction == "QUIT")
                return 0;
            if(instruction == "END")
                break;
            if(instruction == "NUM"){
                cin >> num;
                numbers.push_back(num);
            }
            instructions.emplace_back(instruction);
        }

        cin >> N;

        for(int i=0; i< N; i++){
            bool isError = false;
            numCnt = 0;
            cin >> V;
            goStack.push_back(V);

            for(string inst: instructions){
                isError = Excute(inst);
                if(goStack.front() > INTMAX || goStack.front() < -INTMAX)
                    isError = true;
                if(isError) break;
            }
            if(isError || goStack.size() != 1){
                cout << "ERROR\n";
            } else cout << goStack.front() << endl;
            goStack.clear();
        }
        cout << endl;
        instructions.clear();
        numbers.clear();
    }
}