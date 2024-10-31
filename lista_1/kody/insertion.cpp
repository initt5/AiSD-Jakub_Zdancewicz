#include <iostream>
using namespace std;

void insertion_sort(float A[], int n)
{
  for (int i = 1; i < n; ++i)
  {
    float x = A[i];
    int j = i - 1;
    while (j > -1 && A[j] > x)
    {
      A[j + 1] = A[j];
      --j;
    }
    A[j + 1] = x;
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
  insertion_sort(A, n);
  for (int i = 0; i < n; ++i)
  {
    cout << A[i] << " ";
  }
  return 0;
}