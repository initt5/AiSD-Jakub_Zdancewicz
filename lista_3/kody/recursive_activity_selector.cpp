#include <iostream>
using namespace std;

struct Activity
{
  int start;
  int end;
};

void recursive_activity_selector(Activity activities[], int n, int k, Activity selected[], int &selected_count)
{
  int m = k + 1;
  while (m < n && activities[m].start < activities[k].end)
  {
    m++;
  }

  if (m < n)
  {
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
  cout << "Dlugosc: " << selected_count << endl;
  cout << "Zajecia: ";
  for (int i = 0; i < selected_count; i++)
  {
    cout << "(" << selected[i].start << ", " << selected[i].end << ") ";
  }
  cout << endl;
  return 0;
}