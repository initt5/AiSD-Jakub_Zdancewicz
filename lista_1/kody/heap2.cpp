#include <iostream>
using namespace std;

int assignments = 0;
int comparisons = 0;

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
    assignments += 1;
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
  assignments += 4;
  comparisons += 2;
  if (l < A.heap_size && A[l] > A[i])
  {
    largest = l;
    assignments += 1;
  }
  comparisons += 2;
  if (m < A.heap_size && A[m] > A[largest])
  {
    largest = m;
    assignments += 1;
  }
  comparisons += 2;
  if (r < A.heap_size && A[r] > A[largest])
  {
    largest = r;
    assignments += 1;
  }
  comparisons += 1;
  if (i != largest)
  {
    float temp = A[i];
    A[i] = A[largest];
    A[largest] = temp;
    assignments += 3;
    heapify(A, largest);
  }
}

void build_heap(heap &A, int n)
{
  A.heap_size = n;
  assignments += 1;
  assignments += 1;
  comparisons += 1;
  for (int i = (n / 3); i >= 0; --i)
  {
    assignments += 1;
    comparisons += 1;
    heapify(A, i);
  }
}

void heap_sort(heap &A, int n)
{
  build_heap(A, n);
  assignments += 1;
  comparisons += 1;
  for (int i = n - 1; i > 0; --i)
  {
    assignments += 1;
    comparisons += 1;
    float temp = A[i];
    A[i] = A[0];
    A[0] = temp;
    --A.heap_size;
    assignments += 4;
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
  cout << n << " ";
  cout << assignments << " ";
  cout << comparisons << " ";
  for (int i = 0; i < n; ++i)
  {
    cout << std::fixed << A[i] << " ";
  }
  return 0;
}