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

void recursive_activity_selector(Activity activities[], int n, int k, Activity selected[], int &selected_count)
{
  assignments += 1;
  int m = k + 1;
  comparisons += 2;
  while (m < n && activities[m].start < activities[k].end)
  {
    comparisons += 2;
    assignments += 1;
    m++;
  }
  comparisons += 1;
  if (m < n)
  {
    assignments += 1;
    selected[selected_count++] = activities[m];
    recursive_activity_selector(activities, n, m, selected, selected_count);
  }
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
  int selected_count = 0;
  selected[selected_count++] = activities[0];
  recursive_activity_selector(activities, n, 0, selected, selected_count);
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