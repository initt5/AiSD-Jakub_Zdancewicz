#include <iostream>
#include <limits>
using namespace std;

int assignments = 0;
int comparisons = 0;

void merge(float A[], int p, int s1, int s2, int k)
{
  int n1 = s1 - p + 1;
  int n2 = s2 - s1;
  int n3 = k - s2;
  float L[n1 + 1];
  float M[n2 + 1];
  float R[n3 + 1];
  L[n1] = numeric_limits<float>::infinity();
  M[n2] = numeric_limits<float>::infinity();
  R[n3] = numeric_limits<float>::infinity();
  assignments += 9;
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
  for (int z = 0; z < n2; ++z)
  {
    assignments += 1;
    M[z] = A[z + s1 + 1];
    assignments += 1;
    comparisons += 1;
  }
  comparisons += 1;
  assignments += 1;
  for (int j = 0; j < n3; ++j)
  {
    assignments += 1;
    R[j] = A[j + s2 + 1];
    assignments += 1;
    comparisons += 1;
  }
  int i = 0;
  int j = 0;
  int z = 0;
  assignments += 3;
  comparisons += 1;
  assignments += 1;
  for (int l = p; l <= k; ++l)
  {
    assignments += 1;
    comparisons += 4;
    if (L[i] <= R[j] && L[i] <= M[z])
    {
      A[l] = L[i];
      ++i;
      assignments += 2;
    }
    else if (M[z] <= R[j] && M[z] <= L[i])
    {
      A[l] = M[z];
      ++z;
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
    int s1 = p + (k - p) / 3;
    int s2 = p + 2 * ((k - p) / 3);
    assignments += 2;
    merge_sort(A, p, s1);
    merge_sort(A, s1 + 1, s2);
    merge_sort(A, s2 + 1, k);
    merge(A, p, s1, s2, k);
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
    cout << A[i] << " ";
  }
  return 0;
}