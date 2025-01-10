#include <iostream>
using namespace std;

unsigned long long int assignments = 0;
unsigned long long int comparisons = 0;

int naive_cut_rod(int p[], int n)
{
  comparisons += 1;
  if (n == 0)
  {
    return 0;
  }
  assignments += 1;
  int q = -1;
  assignments += 1;
  comparisons += 1;
  for (int i = 1; i <= n; ++i)
  {
    assignments += 2;
    comparisons += 1;
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
  cout << n << " ";
  cout << naive_cut_rod(p, n) << " ";
  cout << assignments << " ";
  cout << comparisons;
  return 0;
}