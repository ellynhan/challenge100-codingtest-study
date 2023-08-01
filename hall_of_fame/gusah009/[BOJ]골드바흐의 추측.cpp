#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX_TARGET 1000000

//1 ~ 100을 체크하기 위한 배열, 0번째 인덱스는 사용하지 않았다.
int isPrimeNumber[MAX_TARGET+1];
vector<int> primeNumber;

void getPrime()
{
	//1은 소수가 아니라 가정
	isPrimeNumber[1] = 0;
	//1외에는 모두 소수라고 가정
	for (int i = 2; i < MAX_TARGET+1; i++)
	{
		isPrimeNumber[i] = 1;
	}
 
	//에라토스테네스의 체
	for (int n = 2; n <= floor(sqrt(MAX_TARGET)); n++)
	{
		//n이 소수가 아닌 경우 continue
		if (!isPrimeNumber[n]) 
		{
			continue;
		}
		//소수인 n의 배수들 모두 제거
		for (int mult = 2; n * mult <= MAX_TARGET; mult++) {
			isPrimeNumber[n*mult] = 0;
		}
	}
 
	//에라토스테네스의 체를 이용하여 소수들만 남은 배열 출력
	for (int i = 3; i < MAX_TARGET+1; i++)
	{
		//소수인 숫자들 모두 출력
		if (isPrimeNumber[i]) 
		{
      primeNumber.push_back(i);
		}
	}
}

void input_solve_print()
{
  getPrime();

  int N;
  while(true) {
    cin >> N;
    if (N == 0) break;
    FOR(i, primeNumber.size()) {
      if (primeNumber[i] > N / 2) {
        cout << "Goldbach's conjecture is wrong.\n";
        break;
      }
      if (isPrimeNumber[N - primeNumber[i]]) {
        cout << N << " = " << primeNumber[i] << " + " << N - primeNumber[i] << '\n';
        break;
      }
    }
  }
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input_solve_print();
}