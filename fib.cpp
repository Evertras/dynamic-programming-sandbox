#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<int> fibCache = vector<int>{1, 1};
int callCount = 0;
int callCountBad = 0;

int getFib(int n)
{
  callCount++;
  if (n <= (int)fibCache.size())
  {
    return fibCache[n-1];
  }

  int fib = getFib(n-2) + getFib(n-1);

  fibCache.push_back(fib);

  return fib;
}

int getFibBad(int n)
{
  callCountBad++;
  if (n <= 2)
  {
    return 1;
  }

  return getFibBad(n-1) + getFibBad(n-2);
}

void say()
{
  for (auto i : fibCache)
  {
    cout << i << " ";
  }

  cout << endl;
}

int main()
{
  say();
  getFib(10);
  say();

  for (int i = 1; i <= 10; i++)
  {
    cout << getFib(i) << endl;
    cout << getFibBad(i) << endl;
  }

  cout << callCount << " " << callCountBad << endl;
  cout << fibCache.size() << endl;
  return 0;
}

