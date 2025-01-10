#include <iostream>
using namespace std;

unsigned long long int assignments = 0;
unsigned long long int comparisons = 0;

bool TEST_MODE = true;

void extended_bottom_up_cut_rod(int p[], int n, int r[], int s[])
{
  assignments += 1;
  r[0] = 0;
  assignments += 1;
  comparisons += 1;
  for (int j = 1; j <= n; ++j)
  {
    assignments += 2;
    comparisons += 1;
    int q = -1;
    assignments += 1;
    comparisons += 1;
    for (int i = 1; i <= j; ++i)
    {
      assignments += 1;
      comparisons += 2;
      if (q < p[i - 1] + r[j - i])
      {
        assignments += 2;
        q = p[i - 1] + r[j - i];
        s[j] = i;
      }
    }
    assignments += 1;
    r[j] = q;
  }
}
void print_solution(int p[], int n, int r[], int s[])
{
  extended_bottom_up_cut_rod(p, n, r, s);
  cout << n << " ";
  cout << r[n] << " ";
  cout << assignments << " ";
  cout << comparisons << " ";
  if (!TEST_MODE)
  {
    cout << "Optymalne ciecia: ";
    while (n > 0)
    {
      if (n - s[n] != 0)
      {
        cout << s[n] << " ";
      }
      else
      {
        cout << s[n];
      }
      n = n - s[n];
    }
  }
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
  int r[n + 1];
  int s[n + 1];
  print_solution(p, n, r, s);
  return 0;
}