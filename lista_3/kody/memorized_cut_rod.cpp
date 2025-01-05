#include <iostream>
using namespace std;

int memorized_cut_rod(int p[], int r[], int s[], int n)
{
  if (r[n] >= 0)
  {
    return r[n];
  }
  int q = -1;
  if (n == 0)
  {
    q = 0;
  }
  else
  {
    for (int i = 1; i <= n; ++i)
    {
      if (q < memorized_cut_rod(p, r, s, n - i) + p[i - 1])
      {
        q = memorized_cut_rod(p, r, s, n - i) + p[i - 1];
        s[n] = i;
      }
    }
  }
  r[n] = q;
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

  int r[n + 1];
  int s[n + 1];
  for (int i = 0; i <= n; ++i)
  {
    r[i] = -1;
  }
  cout << "Maksymalna wartosc: " << memorized_cut_rod(p, r, s, n) << endl;
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
  return 0;
}