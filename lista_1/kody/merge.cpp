#include <iostream>
#include <limits>
using namespace std;

int assignments = 0;
int comparisons = 0;

void merge(float A[], int p, int s, int k)
{
  int n1 = s - p + 1;
  int n2 = k - s;
  float L[n1 + 1];
  float R[n2 + 1];
  L[n1] = numeric_limits<float>::infinity();
  R[n2] = numeric_limits<float>::infinity();
  assignments += 6;
  comparisons += 1;
  assignments += 1;
  for (int i = 0; i < n1; ++i)
  {
    assignments += 1;
    L[i] = A[i + p];
    assignments += 1;
    comparisons += 1;
  }
  comparisons += 1;
  assignments += 1;
  for (int j = 0; j < n2; ++j)
  {
    assignments += 1;
    R[j] = A[j + s + 1];
    assignments += 1;
    comparisons += 1;
  }
  int i = 0;
  int j = 0;
  assignments += 2;
  comparisons += 1;
  assignments += 1;
  for (int l = p; l <= k; ++l)
  {
    assignments += 1;
    comparisons += 2;
    if (L[i] <= R[j])
    {
      A[l] = L[i];
      ++i;
      assignments += 2;
    }
    else
    {
      A[l] = R[j];
      ++j;
      assignments += 2;
    }
  }
}

void merge_sort(float A[], int p, int k)
{
  comparisons += 1;
  if (p < k)
  {
    int s = p + (k - p) / 2;
    assignments += 1;
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
  cout << n << " ";
  cout << assignments << " ";
  cout << comparisons << " ";
  for (int i = 0; i < n; ++i)
  {
    cout << std::fixed << A[i] << " ";
  }
  return 0;
}