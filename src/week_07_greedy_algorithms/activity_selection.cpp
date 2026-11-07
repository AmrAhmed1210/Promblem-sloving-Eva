#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Task
{
    int start;
    int end;
};

vector<Task> selectTasks(vector<Task> tasks)
{
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) { return a.end < b.end; });

    vector<Task> selected;
    int lastEnd = -1;

    for (const Task& task : tasks)
    {
        if (task.start >= lastEnd)
        {
            selected.push_back(task);
            lastEnd = task.end;
        }
    }
    return selected;
}

int main()
{
    vector<Task> tasks = {{1, 3}, {2, 5}, {3, 9}, {6, 8}, {5, 7}};
    vector<Task> selected = selectTasks(tasks);

    cout << "Maximum tasks: " << selected.size() << endl;
    for (const Task& task : selected)
        cout << "(" << task.start << ", " << task.end << ") ";
    cout << endl;
}
