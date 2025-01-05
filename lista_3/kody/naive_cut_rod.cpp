#include <iostream>
using namespace std;

int naive_cut_rod(int p[], int n)
{
  if (n == 0)
  {
    return 0;
  }
  int q = -1;
  for (int i = 1; i <= n; ++i)
  {
    q = max(q, naive_cut_rod(p, n - i) + p[i - 1]);
  }
  return q;
}

int main()
{
  int n;
  cin >> n;
  int p[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> p[i];
  }
  cout << naive_cut_rod(p, n) << endl;
  return 0;
}