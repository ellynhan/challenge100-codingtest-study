#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int n;
list<char> inputData;
int ans = (1 << 31);

int cal(string expression) {
	char oper = -1;
	bool precal = false;
	int start = 0;
	int end = 0;

	int result = 0;
	for (size_t i = 0; i < expression.length(); i++) {
		if (expression[i] == '(') {
			precal = true;
			start = i;
		}
		else if (expression[i] == ')') {
			end = i;
			int res = cal(expression.substr(start + 1, end-start-1));
			switch (oper)
			{
			case '+':
				result += res;
				break;
			case '-':
				result -= res;
				break;
			case '*':
				result *= res;
				break;
			default:
				result = res;
				break;
			}

			precal = false;
		}
		else {
			if (precal)
				continue;

			if (expression[i] >= '0' && expression[i] <= '9') {
				int num = expression[i] - '0';
				switch (oper)
				{
				case '+':
					result += num;
					break;
				case '-':
					result -= num;
					break;
				case '*':
					result *= num;
					break;
				default:
					result = num;
					break;
				}
			}
			else { // 연산자
				oper = expression[i];
			}
		}
	}
	return result;
}

// close : true면 닫는 괄호 삽입
void dfs(list<char>::iterator iter) {
	if (iter == inputData.end()) {

		string result = "";
		for (char c : inputData) {
			result.push_back(c);
		}
		ans = max(ans, cal(result));
	}
	else {
		// 괄호 넣는 경우
		if (*next(iter, -1) != ')' && *next(iter, 1) != '(') {
			inputData.insert(next(iter, -1), '(');
			inputData.insert(next(iter, 2), ')');
			dfs(next(iter, 3));

			inputData.erase(next(iter, -2));
			inputData.erase(next(iter, 2));
		}

		dfs(next(iter, 2));
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		char a;
		cin >> a;
		inputData.push_back(a);
	}

	dfs(++inputData.begin());

	cout << ans;

	return 0;
}