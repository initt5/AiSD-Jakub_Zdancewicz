#include <iostream>
using namespace std;

unsigned long long int assignments = 0;
unsigned long long int comparisons = 0;

bool TEST_MODE = true;

struct Activity
{
  int start;
  int end;
};

int iterative_activity_selector(Activity activities[], int n, Activity selected[])
{
  assignments += 4;
  comparisons += 1;
  int k = 0;
  selected[0] = activities[k];
  int selected_count = 1;
  for (int m = 1; m < n; ++m)
  {
    assignments += 1;
    comparisons += 2;
    if (activities[m].start >= activities[k].end)
    {
      assignments += 2;
      selected[selected_count++] = activities[m];
      k = m;
    }
  }
  return selected_count;
}

int main()
{
  int n;
  cin >> n;
  Activity activities[n];
  for (int i = 0; i < n; i++)
  {
    cin >> activities[i].start >> activities[i].end;
  }
  Activity selected[n];
  int selected_count = iterative_activity_selector(activities, n, selected);
  cout << n << " ";
  cout << selected_count << " ";
  cout << assignments << " ";
  cout << comparisons << " ";
  if (!TEST_MODE)
  {
    cout << "Zajecia: ";
    for (int i = 0; i < selected_count; i++)
    {
      cout << "(" << selected[i].start << ", " << selected[i].end << ") ";
    }
    cout << endl;
  }
  return 0;
}