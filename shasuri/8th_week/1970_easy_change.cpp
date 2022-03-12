#include<iostream>

using namespace std;

int N;
const int moneyType[] = {50000,10000,5000,1000,500,100,50,10};

void input(void);
void solve(int);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

		input();
        solve(test_case);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void input(void){
    cin >> N;
}

void solve(int testCase){
    int money, moneyNum;

    cout << "#" << testCase << endl;

    for(int i = 0;i < 8;i++){
        money = moneyType[i];
        if(N >= money){
            moneyNum = N / money;
            N -= money * moneyNum;
            cout << moneyNum << " ";
        }
        else{
            cout << 0 << " ";
        }
    }

    cout << endl;
}