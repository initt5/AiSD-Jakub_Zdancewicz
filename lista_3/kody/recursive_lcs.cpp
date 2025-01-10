#include <iostream>
using namespace std;

unsigned long long int assignments = 0;
unsigned long long int comparisons = 0;

bool TEST_MODE = true;

int recursive_lcs(string X, string Y, int m, int n, int **c, int **b)
{
  comparisons += 1;
  if (c[m][n] != -1)
  {
    return c[m][n];
  }
  comparisons += 2;
  if (m == 0 || n == 0)
  {
    assignments += 1;
    c[m][n] = 0;
    return c[m][n];
  }
  comparisons += 1;
  if (X[m - 1] == Y[n - 1])
  {
    assignments += 2;
    c[m][n] = recursive_lcs(X, Y, m - 1, n - 1, c, b) + 1;
    b[m][n] = 3;
    return c[m][n];
  }
  comparisons += 1;

  int left = recursive_lcs(X, Y, m - 1, n, c, b);
  int up = recursive_lcs(X, Y, m, n - 1, c, b);

  if (left >= up)
  {
    assignments += 2;
    c[m][n] = left;
    b[m][n] = 2;
  }
  else
  {
    assignments += 2;
    c[m][n] = up;
    b[m][n] = 1;
  }
  return c[m][n];
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
      c[i][j] = -1;
      b[i][j] = 0;
    }
  }
  cout << n << " ";
  cout << recursive_lcs(X, Y, m, n, c, b) << " ";
  cout << assignments << " ";
  cout << comparisons << " ";
  if (!TEST_MODE)
  {
    cout << "LCS: ";
    print_lcs_solution(X, b, m, n);
    cout << endl;
  }

  for (int i = 0; i <= m; ++i)
  {
    delete[] c[i];
    delete[] b[i];
  }
  delete[] c;
  delete[] b;
  return 0;
}