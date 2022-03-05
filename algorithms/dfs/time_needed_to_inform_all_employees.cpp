/*
 *https://leetcode.com/problems/time-needed-to-inform-all-employees/
 */

#include <vector>
#include <iostream>

using namespace std;

void recurse(vector<int>& timeToHear, int u, const vector<int>& manager, const vector<int>& informTime);
int numOfMinutes(int n, int headID, const vector<int>& manager, const vector<int>& informTime) {
    vector<int> timeToHear(n, -1);
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (timeToHear[i] == -1) {
            recurse(timeToHear, i, manager, informTime);
            if (timeToHear[i] > max) max = timeToHear[i];
        }
    }
    return max;
}

//Time to hear from root = time to hear from direct manager + time for direct man to hear from root
void recurse(vector<int>& timeToHear, int u, const vector<int>& manager, const vector<int>& informTime) {
    auto my_manager = manager[u];
    if (my_manager == -1) {
        timeToHear[u] = 0;
        return;
    }

    auto my_man_time = informTime[my_manager];
    timeToHear[u] = my_man_time;

    if (timeToHear[my_manager] == -1) {
        recurse(timeToHear, my_manager, manager, informTime);
    }
    timeToHear[u] += timeToHear[my_manager];
    return;
}

int main() {
    cout << numOfMinutes(1, 0, {-1}, {0}) << '\n';
    cout << numOfMinutes(6, 2, {2, 2, -1, 2, 2, 2}, {0, 0, 1, 0, 0, 0}) << '\n';
}
