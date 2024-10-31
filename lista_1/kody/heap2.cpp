#include <iostream>
using namespace std;

struct heap
{
  float *array;
  int heap_size = 0;

  float &operator[](int idx)
  {
    return array[idx];
  }
  heap(float *arr)
  {
    array = arr;
  }
};

int left(int i)
{
  return 3 * i + 1;
}

int mid(int i)
{
  return 3 * i + 2;
}

int right(int i)
{
  return 3 * i + 3;
  ;
}

void heapify(heap &A, int i)
{
  int l = left(i);
  int m = mid(i);
  int r = right(i);
  int largest = i;

  if (l < A.heap_size && A[l] > A[i])
  {
    largest = l;
  }
  if (m < A.heap_size && A[m] > A[largest])
  {
    largest = m;
  }
  if (r < A.heap_size && A[r] > A[largest])
  {
    largest = r;
  }
  if (i != largest)
  {
    float temp = A[i];
    A[i] = A[largest];
    A[largest] = temp;
    heapify(A, largest);
  }
}

void build_heap(heap &A, int n)
{
  A.heap_size = n;
  for (int i = (n / 3); i >= 0; --i)
  {
    heapify(A, i);
  }
}

void heap_sort(heap &A, int n)
{
  build_heap(A, n);
  for (int i = n - 1; i > 0; --i)
  {
    float temp = A[i];
    A[i] = A[0];
    A[0] = temp;
    --A.heap_size;
    heapify(A, 0);
  }
}

int main()
{
  int n;
  cin >> n;
  float Array[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> Array[i];
  }
  heap A(Array);
  heap_sort(A, n);
  for (int i = 0; i < n; ++i)
  {
    cout << A[i] << " ";
  }
  return 0;
}