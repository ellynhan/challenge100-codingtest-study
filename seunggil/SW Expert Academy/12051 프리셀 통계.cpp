#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {

        long long N;
        int today, total;
        cin >> N >> today >> total;
        bool answer;
        if (today == 0) {
            if (total == 100)
                answer = false;
            else
                answer = true;
        }
        else {
            if (100 / gcd(today, 100) > N)
                answer = false;
            else if (today == 100 && total == 100)
                answer = true;
            else
                answer = (total == 0 || total == 100) ? false : true;
        }

        cout << "#" << test_case << " " << (answer ? "Possible" : "Broken") << endl;

    }
    return 0;
}