#include <iostream>
using namespace std;

void extended_bottom_up_cut_rod(int p[], int n, int r[], int s[])
{
  r[0] = 0;
  for (int j = 1; j <= n; ++j)
  {
    int q = -1;
    for (int i = 1; i <= j; ++i)
    {
      if (q < p[i - 1] + r[j - i])
      {
        q = p[i - 1] + r[j - i];
        s[j] = i;
      }
    }
    r[j] = q;
  }
}
void print_solution(int p[], int n, int r[], int s[])
{
  extended_bottom_up_cut_rod(p, n, r, s);
  cout << "Maksymalna wartosc: " << r[n] << endl;
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