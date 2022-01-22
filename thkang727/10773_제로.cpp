#include <iostream>
#include <stack>

#define MAX_Command_SIZE 100000

using namespace std;

int main()
{
    stack <int> stack_com;

    int num_com;
    int input_num;
    int sum = 0;
    cin >> num_com;

    if(num_com >=1 && num_com <= 100000){
        for(int i=0; i < num_com; i++){
            cin >> input_num;

            if(input_num == 0 ){
                if(!stack_com.empty()){
                    stack_com.pop();
                }

            }
            else{
                stack_com.push(input_num);
            }
        }

        while(!stack_com.empty()){
            sum += stack_com.top();
            stack_com.pop();

        }
        cout << sum ;
    }


    return 0;
}
