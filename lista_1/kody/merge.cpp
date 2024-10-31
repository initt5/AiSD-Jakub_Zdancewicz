#include <iostream>
#include <limits>
using namespace std;

void merge(float A[], int p, int s, int k)
{
  int n1 = s - p + 1;
  int n2 = k - s;
  float L[n1 + 1];
  float R[n2 + 1];
  L[n1] = numeric_limits<float>::infinity();
  R[n2] = numeric_limits<float>::infinity();
  for (int i = 0; i < n1; ++i)
  {
    L[i] = A[i + p];
  }
  for (int j = 0; j < n2; ++j)
  {
    R[j] = A[j + s + 1];
  }
  int i = 0;
  int j = 0;
  for (int l = p; l <= k; ++l)
  {
    if (L[i] <= R[j])
    {
      A[l] = L[i];
      ++i;
    }
    else
    {
      A[l] = R[j];
      ++j;
    }
  }
}

void merge_sort(float A[], int p, int k)
{
  if (p < k)
  {
    int s = p + (k - p) / 2;
    merge_sort(A, p, s);
    merge_sort(A, s + 1, k);
    merge(A, p, s, k);
  }
}

int main()
{
  int n;
  cin >> n;
  float A[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> A[i];
  }
  merge_sort(A, 0, n - 1);
  for (int i = 0; i < n; ++i)
  {
    cout << A[i] << " ";
  }
  return 0;
}