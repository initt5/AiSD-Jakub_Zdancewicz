#include <iostream>
using namespace std;

void iterative_lcs(string X, string Y, int m, int n, int **c, int **b)
{
  for (int i = 1; i <= m; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      if (X[i - 1] == Y[j - 1])
      {
        c[i][j] = c[i - 1][j - 1] + 1;
        b[i][j] = 3;
      }
      else if (c[i - 1][j] >= c[i][j - 1])
      {
        c[i][j] = c[i - 1][j];
        b[i][j] = 2;
      }
      else
      {
        c[i][j] = c[i][j - 1];
        b[i][j] = 1;
      }
    }
  }
}

void print_lcs_solution(string X, int **b, int m, int n)
{
  if (m == 0 || n == 0)
  {
    return;
  }
  if (b[m][n] == 3)
  {
    print_lcs_solution(X, b, m - 1, n - 1);
    cout << X[m - 1];
  }
  else if (b[m][n] == 2)
  {
    print_lcs_solution(X, b, m - 1, n);
  }
  else if (b[m][n] == 1)
  {
    print_lcs_solution(X, b, m, n - 1);
  }
}

int main()
{
  int m;
  int n;
  string X;
  string Y;
  cin >> m;
  cin >> n;
  cin >> X;
  cin >> Y;
  int **c;
  int **b;

  c = new int *[m + 1];
  b = new int *[m + 1];
  for (int i = 0; i <= m; ++i)
  {
    c[i] = new int[n + 1];
    b[i] = new int[n + 1];
  }

  for (int i = 0; i <= m; ++i)
  {
    for (int j = 0; j <= n; ++j)
    {
      c[i][j] = 0;
      b[i][j] = 0;
    }
  }

  iterative_lcs(X, Y, m, n, c, b);

  cout << "Length of LCS: " << c[m][n] << endl;

  cout << "LCS: ";
  print_lcs_solution(X, b, m, n);
  cout << endl;

  for (int i = 0; i <= m; ++i)
  {
    delete[] c[i];
    delete[] b[i];
  }
  delete[] c;
  delete[] b;

  return 0;
}