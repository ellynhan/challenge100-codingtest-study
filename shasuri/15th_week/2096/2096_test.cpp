// Set comment 2096.cpp main function before testing.

#include <assert.h>
#include "2096.cpp"

void test(int);

int main(void)
{
    int testCase;
    freopen("2096_input.txt", "r", stdin);

    cin >> testCase;

    for (int i = 1; i <= testCase; i++)
        test(i);
}

void test(int tcNum)
{
    cout << "# " << tcNum;

    writeTable();
    initDP();
    getDownTable();

    int maxValue, minValue;
    cin >> maxValue >> minValue;
    assert(maxValue == getMaxValue());
    assert(minValue == getMinValue());

    cout << " complete." << endl;
}