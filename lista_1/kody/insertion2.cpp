#include <iostream>
using namespace std;

void insertion_sort2(float A[], int n)
{
  int size = n;
  if (n % 2 == 0)
  {
    size -= 1;
  }
  for (int i = 1; i < size; i += 2)
  {
    float max = A[i];
    float min = A[i + 1];
    if (max < min)
    {
      float temp = max;
      max = min;
      min = temp;
    }
    int j = i - 1;
    while (j > -1 && A[j] > max)
    {
      A[j + 2] = A[j];
      --j;
    }
    A[j + 2] = max;
    while (j > -1 && A[j] > min)
    {
      A[j + 1] = A[j];
      --j;
    }
    A[j + 1] = min;
  }
  if (n % 2 == 0)
  {
    int j = n - 2;
    float key = A[n - 1];
    while (j > -1 && A[j] > key)
    {
      A[j + 1] = A[j];
      --j;
    }
    A[j + 1] = key;
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
  insertion_sort2(A, n);
  for (int i = 0; i < n; ++i)
  {
    cout << A[i] << " ";
  }
  return 0;
}