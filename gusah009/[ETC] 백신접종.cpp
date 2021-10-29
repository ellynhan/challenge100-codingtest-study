#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

class Old
{
public:
  int on, oa, os, index;

  Old(int num, int age, int sex, int index) : on(num), oa(age), index(index)
  {
    if (sex == 'M')
      os = 1;
    else
      os = 2;
  }

  bool operator<(const Old o) const
  {
    if (this->os != o.os) return this->os > o.os;
    else                  return this->index > o.index;
  }
};

class Child
{
public:
  int cn, ca, cs, index;

  Child(int num, int age, int sex, int index) : cn(num), ca(age), index(index)
  {
    if (sex == 'M')
      cs = 1;
    else
      cs = 2;
  }
  
  bool operator<(const Child c) const
  {
    return this->index > c.index;
  }
};

class Adult
{
public:
  int an, aa, as, index;

  Adult(int num, int age, int sex, int index) : an(num), aa(age), index(index)
  {
    if (sex == 'M')
      as = 1;
    else
      as = 2;
  }

  bool operator<(const Adult a) const
  {
    if (this->as != a.as) return this->as < a.as;
    else                  return this->index > a.index;
  }
};

int main()
{
  priority_queue<Old> O;
  priority_queue<Child> C;
  priority_queue<Adult> A;

  ifstream ifs("5.inp");
  int N;
  ifs >> N;
  //cin>> N;

  int number, age;
  char sex;
  for (int i = 0; i < N; i++)
  {
    ifs >> number >> age;
    ifs >> sex;
    //cin>> number >> age;
    //cin>> sex;

    if (age >= 61)
    {
      O.push(Old(number, age, sex, i));
    }
    else if (age <= 15)
    {
      C.push(Child(number, age, sex, i));
    }
    else
    {
      A.push(Adult(number, age, sex, i));
    }
  }

  while (!O.empty())
  {
    Old O2 = O.top();
    O.pop();
    cout << O2.on << ' ' << (O2.os == 1 ? 'M' : 'F') << endl;
  }
  while (!C.empty())
  {
    Child C2 = C.top();
    C.pop();
    cout << C2.cn << ' ' << (C2.cs == 1 ? 'M' : 'F') << endl;
  }
  while (!A.empty())
  {
    Adult A2 = A.top();
    A.pop();
    cout << A2.an << ' ' << (A2.as == 1 ? 'M' : 'F') << endl;
  }

  return 0;
}