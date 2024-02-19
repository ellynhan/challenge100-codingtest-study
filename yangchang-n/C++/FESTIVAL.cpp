#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
  
  	cout.setf(ios::fixed);
  	cout.precision(11);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int N, L;
		cin >> N >> L;

		vector<int> cost(N, 0);
		for (int i = 0; i < N; ++i)
		{
			cin >> cost[i];
		}	

		double answer = 1000;
		double temp;

		for (int j = L; j <= N; ++j)
		{
			for (int k = 0; k <= N - j; ++k)
			{
				temp = 0;
				for (int l = k; l < k + j; ++l)
				{
				  	temp += cost[l];
				}
				temp = (double)temp / j;
				if (answer > temp)
				{
				  	answer = temp;
				}
			}
		}

		cout << answer << endl;
	}

	return 0;
}
