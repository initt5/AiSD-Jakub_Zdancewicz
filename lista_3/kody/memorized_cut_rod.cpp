#include <iostream>
using namespace std;

unsigned long long int assignments = 0;
unsigned long long int comparisons = 0;

bool TEST_MODE = true;

int memorized_cut_rod(int p[], int n, int r[], int s[])
{
  comparisons += 1;
  if (r[n] >= 0)
  {
    return r[n];
  }
  assignments += 1;
  int q = -1;
  comparisons += 1;
  if (n == 0)
  {
    assignments += 1;
    q = 0;
  }
  else
  {
    assignments += 1;
    comparisons += 1;
    for (int i = 1; i <= n; ++i)
    {
      assignments += 1;
      comparisons += 2;
      if (q < memorized_cut_rod(p, n - i, r, s) + p[i - 1])
      {
        assignments += 2;
        q = memorized_cut_rod(p, n - i, r, s) + p[i - 1];
        s[n] = i;
      }
    }
  }
  assignments += 1;
  r[n] = q;
  return q;
}

void print_solution(int p[], int n, int r[], int s[])
{
  cout << n << " ";
  cout << memorized_cut_rod(p, n, r, s) << " ";
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
  for (int i = 0; i <= n; ++i)
  {
    r[i] = -1;
  }
  print_solution(p, n, r, s);
  return 0;
}